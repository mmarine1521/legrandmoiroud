#include <iostream>

using namespace std;

int main(int argc,char* argv[]){
	if (argc > 1){ // vérifie s'il y a un argument
		string av(argv[1]);
		if (av == "hello") {   // vérification que l'argument est le bon
	  	cout << "Bonjour le monde !" << endl;
	  }
	}
}
