#include "state.h"
#include "render.h"
#include "engine.h"
//#include "ai.h"

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <chrono>
#include <thread>
#include <time.h>
#include <memory>

#include <thread>
#include <mutex>

using namespace state;
using namespace std ;
using namespace engine ;
using namespace render ;
//using namespace ai ;

std::chrono::system_clock::time_point a = std::chrono::system_clock::now();
std::chrono::system_clock::time_point b = std::chrono::system_clock::now();

int main(int argc,char* argv[])
{/*
	 //testSFML();
		srand (time(0)); //initialisation une fois pour toute du srand ;



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


						std::vector<std::shared_ptr<state::Element>> listeArmee = tabArmee.getElementList();
						state::Element* e1 = 0;
						state::Element* e2 = 0;
						state::Element* e3 = 0;
						state::Element* e4 = 0;

						e1 = listeArmee[32].get(); //test islande
						e2 = listeArmee[35].get(); //test europe du sud
						e3 = listeArmee[33].get(); //test europe du nord
						e4 = listeArmee[37].get(); //test europe occidentale



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
	        						int i = 0 ;
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
												std::cout<<"pour sélectionner un pays : clic gauche, pour lui affecter un nombre d'armées clic droit" << std::endl ;
															//PlacementArmees::placerNouvellesArmees (1, 40, currentState,window,event);
															AttributionTerritoires::repartitionArmees(1, currentState, window, event);
														//}
												//}
												//TourDeJeu::jouer(0,1,currentState,window,event);

												std::cout <<"Placement Terminé"<<std::endl ;
											}

											if(event.key.code == sf::Keyboard::C)
											{
												std::cout<<"AI RANDOM" << std::endl ;
												i+= 1 ;
												intelligence->RandomAI::aiJouer(i, 1, currentState);
												std::cout << "test" << std::endl ;
												//std::cout << e1 -> getNombre() << std::endl ;
												//std::cout << e2 -> getNombre() << std::endl ;
												//std::cout << e2 -> getNombre() << std::endl ;
												//std::cout << e2 -> getNombre() << std::endl ;

												//AttributionTerritoires::repartitionArmees(3, state);
												//std::cout <<"Placement Terminé"<<std::endl ;
											}
									break;
										default:
									break;
									}

									if (event.type == sf::Event::MouseButtonPressed)
										{
											if(event.mouseButton.button ==sf::Mouse::Left)
												{
													Affichage::NombreClic(window, event);
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
	        	        						int j=0 ;
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

	        												for(int i = 0 ; i<40 ; i++)
	        												{
	        													if(i==0)
	        													{
	        														intelligence->RandomAI::aiJouer(i, 1, currentState);
	        													}

	        													else
	        														intelligence->RandomAI::aiJouer(i, 1, currentState);
	        														intelligence->RandomAI::aiJouer(i, 3, currentState);

	        												}
	        												//AttributionTerritoires::repartitionArmees(3, state);
	        												std::cout <<"Placement Terminé"<<std::endl ;
	        											}
	        											if(event.key.code == sf::Keyboard::M)
	        											{
	        												std::cout<<"pour sélectionner un pays : clic gauche, pour lui affecter un nombre d'armées clic droit" << std::endl ;

	        												TourDeJeu::jouer(0,1,currentState, window,event);
	        												//AttributionTerritoires::repartitionArmees(3, state);
	        												std::cout <<"Placement Terminé"<<std::endl ;
	        											}

	        											if(event.key.code == sf::Keyboard::C)
														{
															std::cout<<"AI RANDOM" << std::endl ;
															intelligence->RandomAI::aiJouer(0, 1, currentState);
														}

	        											if(event.key.code == sf::Keyboard::V)
														{
															j+= 1 ;
															intelligence->RandomAI::aiJouer(j, 1, currentState);

															std::cout << "test" << std::endl ;
															//std::cout << e1 -> getNombre() << std::endl ;
															//std::cout << e2 -> getNombre() << std::endl ;
															//std::cout << e2 -> getNombre() << std::endl ;
															//std::cout << e2 -> getNombre() << std::endl ;

															//AttributionTerritoires::repartitionArmees(3, state);
															//std::cout <<"Placement Terminé"<<std::endl ;
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
	        else if (strcmp(argv[1],"heuristic_ai")==0){
	        	            //Test Map
	        	        			std::cout << "Pour initialiser les pays : cliquez sur 'espace'" << std::endl ;
	        	        			std::cout << "Pour l'AI HEURISTIC : cliquez sur 'P'"<< std::endl;
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
	        						HeuristicAI* intelligence  = new ai::HeuristicAI() ;

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
	        	        						int j = 0;
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
	        												std::cout<<"AI HEURISTIC" << std::endl ;

	        												intelligence->HeuristicAI::aiJouer(0, 1, currentState);
	        												for(int i = 1 ; i<40 ; i++)
	        												{
	        													intelligence->HeuristicAI::aiJouer(i,1,currentState);

	        												}
	        												//AttributionTerritoires::repartitionArmees(3, state);
	        												std::cout <<"40 tours terminés"<<std::endl ;
	        											}
	        											if(event.key.code == sf::Keyboard::M)
	        											{
	        												std::cout<<"pour sélectionner un pays : clic gauche, pour lui affecter un nombre d'armées clic droit" << std::endl ;

	        												TourDeJeu::jouer(0,1,currentState, window,event);
	        												//AttributionTerritoires::repartitionArmees(3, state);
	        												std::cout <<"Placement Terminé"<<std::endl ;
	        											}
	        											if(event.key.code == sf::Keyboard::C)
														{
															std::cout<<"AI HEURISTIC" << std::endl ;
															intelligence->HeuristicAI::aiJouer(0, 1, currentState);
														}

														if(event.key.code == sf::Keyboard::V)
														{
															j+= 1 ;
															intelligence->HeuristicAI::aiJouer(j, 1, currentState);

															std::cout << "test" << std::endl ;

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

	    }*/
 return 0;
}
