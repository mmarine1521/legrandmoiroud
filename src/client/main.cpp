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
{
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
			}
			else if (strcmp(argv[1],"render")==0){
			}
			else if (strcmp(argv[1],"random_ai")==0){
			}
			else if (strcmp(argv[1],"heuristic_ai")==0){
			}
			else if (strcmp(argv[1],"deep_ai")==0){
			}
		}
}
