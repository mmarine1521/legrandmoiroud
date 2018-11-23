#include "state.h"
#include "render.h"
#include "engine.h"
#include "ai.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <stdio.h>
#include <string.h>
#include <chrono>
#include <thread>
#include <memory>

#include <thread>
#include <mutex>

using namespace state;
using namespace std ;
using namespace engine ;
using namespace render ;
using namespace ai ; 

std::chrono::system_clock::time_point a = std::chrono::system_clock::now();
std::chrono::system_clock::time_point b = std::chrono::system_clock::now();

void testSFML()
	{


	}

int main(int argc,char* argv[])
{
	 //testSFML();
	    if (argc>1){                 // vérifie s'il y a un argument
	        if  (strcmp(argv[1],"hello")==0) {   // vérification que l'argument est le bon
	            cout << "Bonjour le monde!" << endl;
	        }
	        else if (strcmp(argv[1],"state")==0){
	                //Test_Unitaire();

	        }

	        else if (strcmp(argv[1],"engine")==0){
	            //Test Map
	        			std::cout << "Pour initialiser les pays : cliquez sur 'espace'" << std::endl ;
	        			std::cout << "Pour l'AI RANDOM : cliquez sur 'P'"<< std::endl;
	        			std::cout << "Pour jouer seul : cliquez sur 'M'"<< std::endl;
	        			std::cout << "JOUEUR 1 : Rouge" <<std::endl ;
	        			std::cout << "JOUEUR 2 : Vert" <<std::endl ; 
	        			std::cout << "JOUEUR 3 : Bleu" <<std::endl ; 

	        			
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
	        			currentState.setArmeeTab(tabArmee); 
						currentState.setCartePiocheTab(tabCartePioche);
						currentState.setCarteEnjeuTab(tabCarteEnjeu);
						currentState.setCarteDefausseTab(tabCarteDefausse);
						currentState.setPaysTab(tabPays);
						currentState.setContinentTab(tabContinent);
						
						//RandomAI *intelligence = new RandomAI::RandomAI();
						RandomAI* intelligence  = new ai::RandomAI() ; 
	        			
	        			sf::RenderWindow window(sf::VideoMode(1280,720),"RISK", sf::Style::Close | sf::Style::Resize);
	        			
	        			while (window.isOpen())
	        				{
								window.setVerticalSyncEnabled(true);
	        					window.setActive() ;	
	        					 
	        					
	        					Affichage::AfficheMap(currentState,window) ;
	        					Affichage::AfficheChoixNbrArmees(currentState, window) ; 
	        					//Affichage::AfficheNombre(currentState, window) ;
	        					
	        					sf::Event event;
	        					while (window.pollEvent(event))
	        					{
									switch (event.type)
									{
										case sf::Event::Closed :
											window.close();
											break ;
										case sf::Event::KeyPressed  :
											if(event.key.code == sf::Keyboard::Space)
											{
												std::cout<<"Touche espace pressée"<<std::endl ;
												AttributionTerritoires::distribution(currentState, 3);
												 
												std::cout <<"Initialisation Terminée"<<std::endl ; 
											}
											if(event.key.code == sf::Keyboard::P)
											{
												std::cout<<"AI RANDOM" << std::endl ; 
												 
												intelligence->RandomAI::aiJouer(0, 1, currentState); 
												//AttributionTerritoires::repartitionArmees(3, state);
												std::cout <<"Placement Terminé"<<std::endl ;	
											}
											if(event.key.code == sf::Keyboard::M)
											{
												std::cout<<"taper n'importe quoi pour démarrer" << std::endl ; 
												
												PlacementArmees::placerNouvellesArmees (1, 40, currentState,window,event); 
												//TourDeJeu::jouer(0,1,currentState,window,event);
												
												std::cout <<"Placement Terminé"<<std::endl ;	
											}
									break;
										default:
									break;
									}
									
									if (event.type == sf::Event::MouseButtonPressed)
										{
											if(event.mouseButton.button ==sf::Mouse::Left)
												{
													Affichage::PaysClic(window, event); 
												}
										}
	        					
	        				}
	        					window.display() ; 
	        				}  
	        		}
	        else if (strcmp(argv[1],"random_ai")==0){
	        	            //Test Map
	        	        			std::cout << "Pour initialiser les pays : cliquez sur 'espace'" << std::endl ;
	        	        			std::cout << "Pour l'AI RANDOM : cliquez sur 'P'"<< std::endl;
	        	        			std::cout << "Pour jouer seul : cliquez sur 'M'"<< std::endl;
	        	        			std::cout << "JOUEUR 1 : Rouge" <<std::endl ;
	        	        			std::cout << "JOUEUR 2 : Vert" <<std::endl ; 
	        	        			std::cout << "JOUEUR 3 : Bleu" <<std::endl ; 

	        	        			
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
	        	        			currentState.setArmeeTab(tabArmee); 
	        						currentState.setCartePiocheTab(tabCartePioche);
	        						currentState.setCarteEnjeuTab(tabCarteEnjeu);
	        						currentState.setCarteDefausseTab(tabCarteDefausse);
	        						currentState.setPaysTab(tabPays);
	        						currentState.setContinentTab(tabContinent);
	        						
	        						//RandomAI *intelligence = new RandomAI::RandomAI();
	        						RandomAI* intelligence  = new ai::RandomAI() ; 
	        	        			
	        	        			sf::RenderWindow window(sf::VideoMode(1280,720),"RISK", sf::Style::Close | sf::Style::Resize);
	        	        			
	        	        			while (window.isOpen())
	        	        				{
	        								window.setVerticalSyncEnabled(true);
	        	        					window.setActive() ;	
	        	        					 
	        	        					window.clear(); 
	        	        					Affichage::AfficheMap(currentState,window) ;
	        	        					Affichage::AfficheChoixNbrArmees(currentState, window) ; 
	        	        					
	        	        					window.display(); 
	        	        					//Affichage::AfficheNombre(currentState, window) ;
	        	        					
	        	        					sf::Event event;
	        	        					while (window.pollEvent(event))
	        	        					{
	        									switch (event.type)
	        									{
	        										case sf::Event::Closed :
	        											window.close();
	        											break ;
	        										case sf::Event::KeyPressed  :
	        											if(event.key.code == sf::Keyboard::Space)
	        											{
	        												std::cout<<"Touche espace pressée"<<std::endl ;
	        												AttributionTerritoires::distribution(currentState, 3);
	      	        												 
	        												std::cout <<"Initialisation Terminée"<<std::endl ; 
	        											}
	        											if(event.key.code == sf::Keyboard::P)
	        											{
	        												std::cout<<"AI RANDOM" << std::endl ; 
	        												
	        												//for(int i = 0 ; i<20 ; i++)
	        												//{
	        													
	        															intelligence->RandomAI::aiJouer(0, 1, currentState); 
	        															intelligence->RandomAI::aiJouer(1, 1, currentState); 
	        														
	        												//}	
	        												//AttributionTerritoires::repartitionArmees(3, state);
	        												//std::cout <<"Placement Terminé"<<std::endl ;	
	        											}
	        											if(event.key.code == sf::Keyboard::M)
	        											{
	        												std::cout<<"taper n'importe quoi pour démarrer" << std::endl ; 
	        												
	        												TourDeJeu::jouer(0,1,currentState, window,event);
	        												//AttributionTerritoires::repartitionArmees(3, state);
	        												std::cout <<"Placement Terminé"<<std::endl ;	
	        											}
	        									break;
	        										default:
	        									break;
	        									}
	        									
	        									if (event.type == sf::Event::MouseButtonPressed)
	        										{
	        											if(event.mouseButton.button ==sf::Mouse::Left)
	        												{
	        													Affichage::PaysClic(window, event); 
	        												}
	        										}
	        	        					
	        	        				}
	        	        					//swindow.display() ; 
	        	        				}  
	        	        		}
	    
	    }
 return 0;
}
