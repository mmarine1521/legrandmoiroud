#include "Client.h"
#include "state.h"
#include "ai.h"
#include "engine.h"
#include "render.h"
#include <iostream>
#include "string.h"
#include <unistd.h>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Window.hpp>
#include <SFML/Network.hpp>
#include <thread>
#include <json/json.h>


using namespace ai;
using namespace render;
using namespace state;
using namespace std;
using namespace engine;
using namespace client;


/*Client::Client()
{
}*/


/*void run_ai(ai::HeuristicAI& ctrl, state::State* s, int n){
	while(1) {
		std::this_thread::sleep_for (std::chrono::seconds(1));
		std::cout << "run_ai " << n << " !!!" << std::endl;
		ctrl.aiRemplirCommandes(s) ;
	}
}*/



/*void run_tourdejeu(state::State* s) {
	while(1) {
		TourDeJeu::run(*s) ;
		std::this_thread::sleep_for (std::chrono::seconds(1));
	}
}*/

sf::Http::Request sendGet(std::string uri){
  sf::Http::Request request;
  request.setMethod(sf::Http::Request::Get);
  request.setUri(uri);
  request.setHttpVersion(1, 0); // HTTP 1.0
  request.setField("Content-Type", "application/json; charset=utf-8");
  request.setBody("");
  return request;
}

sf::Http::Request sendPut(std::string uri, std::string body){
  sf::Http::Request request;
  request.setMethod(sf::Http::Request::Put);
  request.setUri(uri);
  request.setHttpVersion(1, 1); // HTTP 1.0
  request.setField("Content-Type", "application/json; charset=utf-8");
  request.setBody(body);
  return request;
}


sf::Http::Request sendDelete(std::string uri){
  sf::Http::Request request;
  request.setMethod(sf::Http::Request::Delete);
  request.setUri(uri);
  request.setHttpVersion(1, 1); // HTTP 1.0
  request.setField("Content-Type", "application/x-www-form-urlencoded");
  request.setBody("");
  return request;
}


void Client::run()
{
	ElementTab tabArmee = ElementTab() ;
	tabArmee.ElementTab::remplirArmeeTab() ;
	ElementTab tabCartePioche = ElementTab();
	tabCartePioche.ElementTab::remplirCartePiocheTab();
	ElementTab tabCarteEnjeu = ElementTab();
	ElementTab tabCarteDefausse = ElementTab();
	ElementTab tabPays = ElementTab();
	tabPays.ElementTab::remplirPaysTab();
	ElementTab tabContinent = ElementTab();
	tabContinent.ElementTab::remplirContinentTab();

	State currentState = state::State() ;
	currentState.setStepId(state::DISTRIBUTION_s);
	currentState.setArmeeTab(tabArmee);
	currentState.setCartePiocheTab(tabCartePioche);
	currentState.setCarteEnjeuTab(tabCarteEnjeu);
	currentState.setCarteDefausseTab(tabCarteDefausse);
	currentState.setPaysTab(tabPays);
	currentState.setContinentTab(tabContinent);
	currentState.setTourId(1);
	currentState.setIdJoueur(1);
	currentState.setNbCartes(3);
	currentState.initializeArmeesRepartition();

	sf::RenderWindow window(sf::VideoMode(1280,720),"RISK", sf::Style::Close | sf::Style::Resize);
			window.setVerticalSyncEnabled(true);
			window.setActive() ;
			window.setKeyRepeatEnabled(false) ;

			//std::thread th_tdj(run_tourdejeu, &currentState);

			while (window.isOpen()){
				window.clear();

				Affichage::AfficheMap(currentState,window) ;
				Affichage::AfficheChoixNbrArmees(currentState, window) ;
				Affichage::AfficheNombre(currentState, window) ;
				window.display() ;

				//std::cout << "state : " << currentState.getStepId() << std::endl;
				//std::this_thread::sleep_for (std::chrono::seconds(1));
				//window.display() ;
				sf::Event event;
				while (window.pollEvent(event)){
				}
			}
}

void Client::connect()
{
		sf::Http http;
		http.setHost("http://localhost", 8080) ;
		Json::Value body ;
		Json::Reader reader ;

		sf::Http::Request request = sendGet("/user/");
		http.setHost("http://localhost",8080);

	  sf::Http::Response response = http.sendRequest(request);
	  reader.parse(response.getBody(), body);
	  std::cout << "begining : " << std::endl;
	  std::cout << "status: " << response.getStatus() << std::endl;
	  std::cout << "body: " << response.getBody() << std::endl;

	  request = sendPut("/user", "{\"name\": \"Joueur1\", \"type\": 0}");
	  response = http.sendRequest(request);

	  reader.parse(response.getBody(), body);
	  int idPlayer = body["id"].asInt();

	  std::cout << "status: " << response.getStatus() << std::endl;
	  std::cout << "body: " << response.getBody() << std::endl;
	  std::cout << "id: " << idPlayer << std::endl;

	  request = sendGet("/user/");
	  response = http.sendRequest(request);
	  std::cout << "Added to the game : " << std::endl;
	  std::cout << "status: " << response.getStatus() << std::endl;
	  std::cout << "body: " << response.getBody() << std::endl;

	  cout << "Pressez <entrée> pour sortir" << endl;
	  (void) getc(stdin);

	  request = sendDelete("/user/"+to_string(idPlayer));
	  response = http.sendRequest(request);

	  request = sendGet("/user/");
	  response = http.sendRequest(request);
	  std::cout << "Deleted : " << std::endl;
	  std::cout << "status: " << response.getStatus() << std::endl;
	  std::cout << "body: " << response.getBody() << std::endl;
}
