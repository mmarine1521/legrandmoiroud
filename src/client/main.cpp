// Les lignes suivantes ne servent qu'à vérifier que la compilation avec SFML fonctionne
#include <SFML/Graphics.hpp>
#include "state.h"
#include <SFML/Window.hpp>
#include <iostream>

void testSFML() {
    sf::Texture texture;


}

// Fin test SFML



using namespace state;
using namespace std ;

int main(int argc,char* argv[])
{
	bool espace = false ;
	float fa_x = 0.9;
	float fa_y = 0.9 ;
	std::string pays_clic = "";
	std::cout<<espace<<endl ;
	sf::RenderWindow window(sf::VideoMode(1280,720),"RISK", sf::Style::Close | sf::Style::Resize);


	    while (window.isOpen())
	    {
	        sf::Event event;
	        sf::Keyboard clavier ;
	        window.setKeyRepeatEnabled(false) ; //annule la répétition des clics
	       //cas où la fenêtre est redimensionnée
	        if (event.type == sf::Event::Resized)
	        {
	            //std::cout << "new width: " << event.size.width << std::endl;
	            //std::cout << "new height: " << event.size.height << std::endl;
	            fa_x = float(0.9*(event.size.width/1280));
	            fa_y = float(0.9*(event.size.width/720));
	        }
	        if (event.type == sf::Event::MouseButtonPressed)
	        {
	        	if(event.mouseButton.button ==sf::Mouse::Right)
	        	{
	        		std::cout << "Bouton droit pressé" <<std::endl ;
	        		std::cout << "Position souris x: " << event.mouseButton.x << std::endl;
	        		std::cout << "Position souris y: " << event.mouseButton.y << std::endl;


	        	}
	        	if(event.mouseButton.button ==sf::Mouse::Left)
	        	{
	        		std::cout << "Bouton gauche pressé" <<std::endl ;
	        		std::cout << "Position souris x: " << event.mouseButton.x << std::endl;
	        		std::cout << "Position souris y: " << event.mouseButton.y << std::endl;
	        		if(event.mouseButton.x>(72*fa_x) && event.mouseButton.x <(134*fa_x) && event.mouseButton.y >(187*fa_y) && event.mouseButton.y<(230*fa_y))
										{
											pays_clic = "Alaska";
											std::cout << "Vous êtes en :" << pays_clic << std::endl ;

										}
	        		if(event.mouseButton.x>(179*fa_x) && event.mouseButton.x <(244*fa_x) && event.mouseButton.y >(241*fa_y) && event.mouseButton.y<(290*fa_y))
										{
											pays_clic = "Alberta";
											std::cout << "Vous êtes en :" << pays_clic << std::endl ;
										}
	        		if(event.mouseButton.x>(239*fa_x) && event.mouseButton.x <(258*fa_x) && event.mouseButton.y >(374*fa_y) && event.mouseButton.y<(396*fa_y))
	        			        		{
	        			        			pays_clic = "Amerique Centrale";
	        			        			std::cout << "Vous êtes en :" << pays_clic << std::endl ;
	        			        		}
	        		if(event.mouseButton.x>(271*fa_x) && event.mouseButton.x <(317*fa_x) && event.mouseButton.y >(317*fa_y) && event.mouseButton.y<(355*fa_y))
	        			        		{
	        			        			pays_clic = "Etat De L'Est";
	        			        			std::cout << "Vous êtes en :" << pays_clic << std::endl ;
	        			        		}
	        		if(event.mouseButton.x>(395*fa_x) && event.mouseButton.x <(480*fa_x) && event.mouseButton.y >(81*fa_x) && event.mouseButton.y<(171*fa_y))
	        			        		{
	        			        			pays_clic = "Groenland";
	        			        			std::cout << "Vous êtes en :" << pays_clic << std::endl ;
	        			        		}
	        		if(event.mouseButton.x>(166*fa_x) && event.mouseButton.x <(251*fa_x) && event.mouseButton.y >(200*fa_y) && event.mouseButton.y<(226*fa_y))
	        			        		{
	        			        			pays_clic = "Territoire Du Nord-Ouest";
	        			        			std::cout << "Vous êtes en :" << pays_clic << std::endl ;
	        			        		}
	        		if(event.mouseButton.x>(257*fa_x) && event.mouseButton.x <(315*fa_x) && event.mouseButton.y >(268*fa_y) && event.mouseButton.y<(294*fa_y))
	        			        		{
	        			        			pays_clic = "Ontario";
	        			        			std::cout << "Vous êtes en :" << pays_clic << std::endl ;
	        			        		}
	        		if(event.mouseButton.x>(335*fa_x) && event.mouseButton.x <(386*fa_x) && event.mouseButton.y >(256*fa_y) && event.mouseButton.y<(281*fa_y))
	        			        		{
	        			        			pays_clic = "Quebec";
	        			        			std::cout << "Vous êtes en :" << pays_clic << std::endl ;
	        			        		}
	        		if(event.mouseButton.x>(186*fa_x) && event.mouseButton.x <(244*fa_x) && event.mouseButton.y >(304*fa_y) && event.mouseButton.y<(341*fa_y))
	        			        		{
	        			        			pays_clic = "Etat De L'Ouest";
	        			        			std::cout << "Vous êtes en :" << pays_clic << std::endl ;
	        			        		}
	        		if(event.mouseButton.x>(350*fa_x) && event.mouseButton.x <(379*fa_x) && event.mouseButton.y >(587*fa_y) && event.mouseButton.y<(627*fa_y))
	        			        		{
	        			        			pays_clic = "Argentine";
	        			        			std::cout << "Vous êtes en :" << pays_clic << std::endl ;
	        			        		}
					if(event.mouseButton.x>(393*fa_x) && event.mouseButton.x <(441*fa_x) && event.mouseButton.y >(495*fa_y) && event.mouseButton.y<(555*fa_y))
										{
											pays_clic = "Brésil";
											std::cout << "Vous êtes en :" << pays_clic << std::endl ;
										}
					if(event.mouseButton.x>(333*fa_x) && event.mouseButton.x <(382*fa_x) && event.mouseButton.y >(445*fa_y) && event.mouseButton.y<(460*fa_y))
										{
											pays_clic = "Pérou";
											std::cout << "Vous êtes en :" << pays_clic << std::endl ;
										}
					if(event.mouseButton.x>(348*fa_x) && event.mouseButton.x <(373*fa_x) && event.mouseButton.y >(531*fa_y) && event.mouseButton.y<(560*fa_y))
										{
											pays_clic = "Vénézuela";
											std::cout << "Vous êtes en :" << pays_clic << std::endl ;
										}
					if(event.mouseButton.x>(593*fa_x) && event.mouseButton.x <(646*fa_x) && event.mouseButton.y >(503*fa_y) && event.mouseButton.y<(563*fa_y))
										{
											pays_clic = "Congo";
											std::cout << "Vous êtes en :" << pays_clic << std::endl ;
										}
					if(event.mouseButton.x>(652*fa_x) && event.mouseButton.x <(696*fa_x) && event.mouseButton.y >(442*fa_y) && event.mouseButton.y<(549*fa_y))
										{
											pays_clic = "Afrique De L'Est";
											std::cout << "Vous êtes en :" << pays_clic << std::endl ;
										}
					if(event.mouseButton.x>(610*fa_x) && event.mouseButton.x <(669*fa_x) && event.mouseButton.y >(398*fa_y) && event.mouseButton.y<(440*fa_y))
										{
											pays_clic = "Egypte";
											std::cout << "Vous êtes en :" << pays_clic << std::endl ;
										}
					if(event.mouseButton.x>(709*fa_x) && event.mouseButton.x <(729*fa_x) && event.mouseButton.y >(552*fa_y) && event.mouseButton.y<(602*fa_y))
										{
											pays_clic = "Madagascar";
											std::cout << "Vous êtes en :" << pays_clic << std::endl ;
										}
					if(event.mouseButton.x>(511*fa_x) && event.mouseButton.x <(595*fa_x) && event.mouseButton.y >(392*fa_y) && event.mouseButton.y<(507*fa_y))
										{
											pays_clic = "Afrique Du Nord";
											std::cout << "Vous êtes en :" << pays_clic << std::endl ;
										}
					if(event.mouseButton.x>(615*fa_x) && event.mouseButton.x <(660*fa_x) && event.mouseButton.y >(579*fa_y) && event.mouseButton.y<(616*fa_y))
										{
											pays_clic = "Afrique Du Sud";
											std::cout << "Vous êtes en :" << pays_clic << std::endl ;
										}
					if(event.mouseButton.x>(986*fa_x) && event.mouseButton.x <(1045*fa_x) && event.mouseButton.y >(609*fa_y) && event.mouseButton.y<(688*fa_y))
										{
											pays_clic = "Australie Orientale";
											std::cout << "Vous êtes en :" << pays_clic << std::endl ;
										}
					if(event.mouseButton.x>(857*fa_x) && event.mouseButton.x <(959*fa_x) && event.mouseButton.y >(499*fa_y) && event.mouseButton.y<(564*fa_y))
										{
											pays_clic = "Indonésie";
											std::cout << "Vous êtes en :" << pays_clic << std::endl ;
										}
					if(event.mouseButton.x>(990*fa_x) && event.mouseButton.x <(1056*fa_x) && event.mouseButton.y >(522*fa_y) && event.mouseButton.y<(565*fa_y))
										{
											pays_clic = "Nouvelle-Guinée";
											std::cout << "Vous êtes en :" << pays_clic << std::endl ;
										}
					if(event.mouseButton.x>(913*fa_x) && event.mouseButton.x <(985*fa_x) && event.mouseButton.y >(589*fa_y) && event.mouseButton.y<(674*fa_y))
										{
											pays_clic = "Australie Occidentale";
											std::cout << "Vous êtes en :" << pays_clic << std::endl ;
										}
					if(event.mouseButton.x>(734*fa_x) && event.mouseButton.x <(808*fa_x) && event.mouseButton.y >(324*fa_y) && event.mouseButton.y<(364*fa_y))
										{
											pays_clic = "Afghanistan";
											std::cout << "Vous êtes en :" << pays_clic << std::endl ;
										}
					if(event.mouseButton.x>(861*fa_x) && event.mouseButton.x <(940*fa_x) && event.mouseButton.y >(357*fa_y) && event.mouseButton.y<(402*fa_y))
										{
											pays_clic = "Chine";
											std::cout << "Vous êtes en :" << pays_clic << std::endl ;
										}
					if(event.mouseButton.x>(776*fa_x) && event.mouseButton.x <(852*fa_x) && event.mouseButton.y >(393*fa_y) && event.mouseButton.y<(472*fa_y))
										{
											pays_clic = "Inde";
											std::cout << "Vous êtes en :" << pays_clic << std::endl ;
										}
					if(event.mouseButton.x>(882*fa_x) && event.mouseButton.x <(957*fa_x) && event.mouseButton.y >(239*fa_y) && event.mouseButton.y<(297*fa_y))
										{
											pays_clic = "Tchita";
											std::cout << "Vous êtes en :" << pays_clic << std::endl ;
										}
					if(event.mouseButton.x>(994*fa_x) && event.mouseButton.x <(1046*fa_x) && event.mouseButton.y >(345*fa_y) && event.mouseButton.y<(412*fa_y))
										{
											pays_clic = "Japon";
											std::cout << "Vous êtes en :" << pays_clic << std::endl ;
										}
					if(event.mouseButton.x>(1044*fa_x) && event.mouseButton.x <(1134*fa_x) && event.mouseButton.y >(210*fa_y) && event.mouseButton.y<(310*fa_y))
										{
											pays_clic = "Kamtchatka";
											std::cout << "Vous êtes en :" << pays_clic << std::endl ;
										}
					if(event.mouseButton.x>(979*fa_x) && event.mouseButton.x <(1034*fa_x) && event.mouseButton.y >(239*fa_y) && event.mouseButton.y<(329*fa_y))
										{
											pays_clic = "Kamtchatka";
											std::cout << "Vous êtes en :" << pays_clic << std::endl ;
										}
					if(event.mouseButton.x>(686*fa_x) && event.mouseButton.x <(756*fa_x) && event.mouseButton.y >(371*fa_y) && event.mouseButton.y<(446*fa_y))
										{
											pays_clic = "Moyen-Orient";
											std::cout << "Vous êtes en :" << pays_clic << std::endl ;
										}
					if(event.mouseButton.x>(896*fa_x) && event.mouseButton.x <(955*fa_x) && event.mouseButton.y >(312*fa_y) && event.mouseButton.y<(339*fa_y))
										{
											pays_clic = "Mongolie";
											std::cout << "Vous êtes en :" << pays_clic << std::endl ;
										}
					if(event.mouseButton.x>(860*fa_x) && event.mouseButton.x <(890*fa_x) && event.mouseButton.y >(413*fa_y) && event.mouseButton.y<(492*fa_y))
										{
											pays_clic = "Siam";
											std::cout << "Vous êtes en :" << pays_clic << std::endl ;
										}
					if(event.mouseButton.x>(809*fa_x) && event.mouseButton.x <(875*fa_x) && event.mouseButton.y >(198*fa_y) && event.mouseButton.y<(276*fa_y))
										{
											pays_clic = "Sibérie";
											std::cout << "Vous êtes en :" << pays_clic << std::endl ;
										}
					if(event.mouseButton.x>(745*fa_x) && event.mouseButton.x <(790*fa_x) && event.mouseButton.y >(227*fa_y) && event.mouseButton.y<(303*fa_y))
										{
											pays_clic = "Oural";
											std::cout << "Vous êtes en :" << pays_clic << std::endl ;
										}
					if(event.mouseButton.x>(790*fa_x) && event.mouseButton.x <(818*fa_x) && event.mouseButton.y >(293*fa_y) && event.mouseButton.y<(318*fa_y))
										{
											pays_clic = "Oural";
											std::cout << "Vous êtes en :" << pays_clic << std::endl ;
										}
					if(event.mouseButton.x>(886*fa_x) && event.mouseButton.x <(1001*fa_x) && event.mouseButton.y >(159*fa_y) && event.mouseButton.y<(217*fa_y))
										{
											pays_clic = "Yakoutie";
											std::cout << "Vous êtes en :" << pays_clic << std::endl ;
										}
					if(event.mouseButton.x>(513*fa_x) && event.mouseButton.x <(567*fa_x) && event.mouseButton.y >(253*fa_y) && event.mouseButton.y<(297*fa_y))
										{
											pays_clic = "Grande-Bretagne";
											std::cout << "Vous êtes en :" << pays_clic << std::endl ;
										}
					if(event.mouseButton.x>(501*fa_x) && event.mouseButton.x <(571*fa_x) && event.mouseButton.y >(187*fa_y) && event.mouseButton.y<(230*fa_y))
										{
											pays_clic = "Islande";
											std::cout << "Vous êtes en :" << pays_clic << std::endl ;
										}
					if(event.mouseButton.x>(590*fa_x) && event.mouseButton.x <(639*fa_x) && event.mouseButton.y >(280*fa_y) && event.mouseButton.y<(316*fa_y))
										{
											pays_clic = "Europe Du Nord";
											std::cout << "Vous êtes en :" << pays_clic << std::endl ;
										}
					if(event.mouseButton.x>(589*fa_x) && event.mouseButton.x <(653*fa_x) && event.mouseButton.y >(205*fa_y) && event.mouseButton.y<(276*fa_y))
										{
											pays_clic = "Scandinavie";
											std::cout << "Vous êtes en :" << pays_clic << std::endl ;
										}
					if(event.mouseButton.x>(596*fa_x) && event.mouseButton.x <(655*fa_x) && event.mouseButton.y >(323*fa_y) && event.mouseButton.y<(374*fa_y))
										{
											pays_clic = "Europe Du Sud";
											std::cout << "Vous êtes en :" << pays_clic << std::endl ;
										}
					if(event.mouseButton.x>(658*fa_x) && event.mouseButton.x <(721*fa_x) && event.mouseButton.y >(214*fa_y) && event.mouseButton.y<(328*fa_y))
										{
											pays_clic = "Ukraine";
											std::cout << "Vous êtes en :" << pays_clic << std::endl ;
										}
					if(event.mouseButton.x>(537*fa_x) && event.mouseButton.x <(583*fa_x) && event.mouseButton.y >(306*fa_y) && event.mouseButton.y<(372*fa_y))
										{
											pays_clic = "Europe Occidentale";
											std::cout << "Vous êtes en :" << pays_clic << std::endl ;
										}
					}

	        }

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
	        				std::cout<<"Touche espace pressée"<<endl ;
	        				espace = true ;
	        				std::cout<<espace<<endl ;
	        			}


	        	}
	        }
	        sf::Texture texture ;
	        sf::Texture texture2 ;
	        if(!texture.loadFromFile("risk.jpg"))
	        {
	        	//erreur
	        }
	        texture2.loadFromFile("tank384px.png");
	        texture.setSmooth(true);
	        texture2.setSmooth(true);
	        sf::Sprite sprite ;
	        sf::Sprite sprite2 ;
	        sprite.setTexture(texture);
	        sprite.setScale(sf::Vector2f(0.9f, 0.9f));
	        sprite.setPosition(sf::Vector2f(0.f, 0.f));
	        sprite2.setTexture(texture2);
	        sprite2.setScale(sf::Vector2f(0.08f, 0.08f));
	        sprite2.setPosition(sf::Vector2f(95.f, 271.f));

	        //affichage armée : texture
	        sf::Texture textureArmee ;
	        textureArmee.loadFromFile("pion_blanc.png");

	        //armee afrique
	        sf::Sprite armeeCongo ;
	        armeeCongo.setTexture(textureArmee);
	        armeeCongo.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeCongo.setPosition(sf::Vector2f(541.f, 463.f));
			sf::Sprite armeeAfriqueDeLEst ;
			armeeAfriqueDeLEst.setTexture(textureArmee);
			armeeAfriqueDeLEst.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeAfriqueDeLEst.setPosition(sf::Vector2f(590.f, 429.f));
			sf::Sprite armeeEgypte ;
			armeeEgypte.setTexture(textureArmee);
			armeeEgypte.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeEgypte.setPosition(sf::Vector2f(559.f, 361.f));
			sf::Sprite armeeMadagascar ;
			armeeMadagascar.setTexture(textureArmee);
			armeeMadagascar.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeMadagascar.setPosition(sf::Vector2f(631.f, 503.f));
			sf::Sprite armeeAfriqueDuNord ;
			armeeAfriqueDuNord.setTexture(textureArmee);
			armeeAfriqueDuNord.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeAfriqueDuNord.setPosition(sf::Vector2f(481.f, 388.f));
			sf::Sprite armeeAfriqueDuSud ;
			armeeAfriqueDuSud.setTexture(textureArmee);
			armeeAfriqueDuSud.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeAfriqueDuSud.setPosition(sf::Vector2f(557.f, 521.f));

			//ARMEE AMERIQUE DU NORD
			sf::Sprite armeeAlberta ;
			armeeAlberta.setTexture(textureArmee);
			armeeAlberta.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeAlberta.setPosition(sf::Vector2f(174.f, 222.f));
			sf::Sprite armeeAmeriqueCentrale ;
			armeeAmeriqueCentrale.setTexture(textureArmee);
			armeeAmeriqueCentrale.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeAmeriqueCentrale.setPosition(sf::Vector2f(207.f, 330.f));
			sf::Sprite armeeEtatDeLEst ;
			armeeEtatDeLEst.setTexture(textureArmee);
			armeeEtatDeLEst.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeEtatDeLEst.setPosition(sf::Vector2f(248.f, 286.f));
			sf::Sprite armeeGroenland ;
			armeeGroenland.setTexture(textureArmee);
			armeeGroenland.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeGroenland.setPosition(sf::Vector2f(377.f, 97.f));
			sf::Sprite armeeTerritoireDuNordOuest ;
			armeeTerritoireDuNordOuest.setTexture(textureArmee);
			armeeTerritoireDuNordOuest.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeTerritoireDuNordOuest.setPosition(sf::Vector2f(171.f, 175.f));
			sf::Sprite armeeOntario ;
			armeeOntario.setTexture(textureArmee);
			armeeOntario.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeOntario.setPosition(sf::Vector2f(241.f, 236.f));
			sf::Sprite armeeQuebec ;
			armeeQuebec.setTexture(textureArmee);
			armeeQuebec.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeQuebec.setPosition(sf::Vector2f(308.f, 225.f));
			sf::Sprite armeeEtatDeLOuest ;
			armeeEtatDeLOuest.setTexture(textureArmee);
			armeeEtatDeLOuest.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeEtatDeLOuest.setPosition(sf::Vector2f(177.f, 274.f));
			sf::Sprite armeeAlaska ;
			armeeAlaska.setTexture(textureArmee);
			armeeAlaska.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeAlaska.setPosition(sf::Vector2f(76.f, 171.f));

			//armee AMERIQUE DU SUD
			sf::Sprite armeeArgentine ;
			armeeArgentine.setTexture(textureArmee);
			armeeArgentine.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeArgentine.setPosition(sf::Vector2f(312.f, 530.f));
			sf::Sprite armeeBresil ;
			armeeBresil.setTexture(textureArmee);
			armeeBresil.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeBresil.setPosition(sf::Vector2f(359.f, 456.f));
			sf::Sprite armeePerou ;
			armeePerou.setTexture(textureArmee);
			armeePerou.setScale(sf::Vector2f(0.2f, 0.2f));
			armeePerou.setPosition(sf::Vector2f(305.f, 391.f));
			sf::Sprite armeeVenezuela ;
			armeeVenezuela.setTexture(textureArmee);
			armeeVenezuela.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeVenezuela.setPosition(sf::Vector2f(308.f, 474.f));


			//armee EUROPE
			sf::Sprite armeeGrandeBretagne ;
			armeeGrandeBretagne.setTexture(textureArmee);
			armeeGrandeBretagne.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeGrandeBretagne.setPosition(sf::Vector2f(470.f, 231.f));
			sf::Sprite armeeIslande ;
			armeeIslande.setTexture(textureArmee);
			armeeIslande.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeIslande.setPosition(sf::Vector2f(466.f, 171.f));
			sf::Sprite armeeEuropeDuNord ;
			armeeEuropeDuNord.setTexture(textureArmee);
			armeeEuropeDuNord.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeEuropeDuNord.setPosition(sf::Vector2f(537.f, 252.f));
			sf::Sprite armeeScandinavie ;
			armeeScandinavie.setTexture(textureArmee);
			armeeScandinavie.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeScandinavie.setPosition(sf::Vector2f(542.f, 200.f));
			sf::Sprite armeeEuropeDuSud ;
			armeeEuropeDuSud.setTexture(textureArmee);
			armeeEuropeDuSud.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeEuropeDuSud.setPosition(sf::Vector2f(546.f, 297.f));
			sf::Sprite armeeUkraine ;
			armeeUkraine.setTexture(textureArmee);
			armeeUkraine.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeUkraine.setPosition(sf::Vector2f(604.f, 227.f));
			sf::Sprite armeeEuropeOccidentale ;
			armeeEuropeOccidentale.setTexture(textureArmee);
			armeeEuropeOccidentale.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeEuropeOccidentale.setPosition(sf::Vector2f(488.f, 289.f));


			//armee ASIE
			sf::Sprite armeeAfghanistan ;
			armeeAfghanistan.setTexture(textureArmee);
			armeeAfghanistan.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeAfghanistan.setPosition(sf::Vector2f(677.f, 293.f));
			sf::Sprite armeeChine ;
			armeeChine.setTexture(textureArmee);
			armeeChine.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeChine.setPosition(sf::Vector2f(794.f, 325.f));
			sf::Sprite armeeInde ;
			armeeInde.setTexture(textureArmee);
			armeeInde.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeInde.setPosition(sf::Vector2f(716.f, 373.f));
			sf::Sprite armeeTchita ;
			armeeTchita.setTexture(textureArmee);
			armeeTchita.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeTchita.setPosition(sf::Vector2f(811.f, 225.f));
			sf::Sprite armeeJapon ;
			armeeJapon.setTexture(textureArmee);
			armeeJapon.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeJapon.setPosition(sf::Vector2f(902.f, 324.f));
			sf::Sprite armeeKamtchatka ;
			armeeKamtchatka.setTexture(textureArmee);
			armeeKamtchatka.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeKamtchatka.setPosition(sf::Vector2f(964.f, 218.f));
			sf::Sprite armeeMoyenOrient ;
			armeeMoyenOrient.setTexture(textureArmee);
			armeeMoyenOrient.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeMoyenOrient.setPosition(sf::Vector2f(632.f, 351.f));
			sf::Sprite armeeMongolie ;
			armeeMongolie.setTexture(textureArmee);
			armeeMongolie.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeMongolie.setPosition(sf::Vector2f(816.f, 276.f));
			sf::Sprite armeeSiam ;
			armeeSiam.setTexture(textureArmee);
			armeeSiam.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeSiam.setPosition(sf::Vector2f(770.f, 391.f));
			sf::Sprite armeeSiberie ;
			armeeSiberie.setTexture(textureArmee);
			armeeSiberie.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeSiberie.setPosition(sf::Vector2f(741.f, 197.f));
			sf::Sprite armeeOural ;
			armeeOural.setTexture(textureArmee);
			armeeOural.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeOural.setPosition(sf::Vector2f(674.f, 222.f));
			sf::Sprite armeeYakoutie ;
			armeeYakoutie.setTexture(textureArmee);
			armeeYakoutie.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeYakoutie.setPosition(sf::Vector2f(833.f, 153.f));

			//armee AUSTRALIE
			sf::Sprite armeeAustralieOrientale ;
			armeeAustralieOrientale.setTexture(textureArmee);
			armeeAustralieOrientale.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeAustralieOrientale.setPosition(sf::Vector2f(897.f, 567.f));
			sf::Sprite armeeIndonesie ;
			armeeIndonesie.setTexture(textureArmee);
			armeeIndonesie.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeIndonesie.setPosition(sf::Vector2f(801.f, 462.f));
			sf::Sprite armeeNouvelleGuinee ;
			armeeNouvelleGuinee.setTexture(textureArmee);
			armeeNouvelleGuinee.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeNouvelleGuinee.setPosition(sf::Vector2f(904.f, 473.f));
			sf::Sprite armeeAustralieOccidentale ;
			armeeAustralieOccidentale.setTexture(textureArmee);
			armeeAustralieOccidentale.setScale(sf::Vector2f(0.2f, 0.2f));
			armeeAustralieOccidentale.setPosition(sf::Vector2f(838.f, 552.f));



	        if (espace)
	        	    {
	        			sf::RenderWindow window_attaque(sf::VideoMode(500,500), "ATTAQUE");
	        				while (window_attaque.isOpen())
	        					{
	        						// on inspecte tous les évènements de la fenêtre qui ont été émis depuis la précédente itération
	        						sf::Event event2;
	        						while (window_attaque.pollEvent(event2))
	        							{
	        							// évènement "fermeture demandée" : on ferme la fenêtre
	        							if (event2.type == sf::Event::Closed)
	        								window_attaque.close();
	        								espace = false ;
	        							}
	        					 }
	        				 window_attaque.clear();
	        				 window_attaque.display();
	        	    }

	        window.clear();
	        window.draw(sprite);
	       // window.draw(sprite2);
	        window.draw(armeeCongo);
	        window.draw(armeeAfriqueDeLEst);
	        window.draw(armeeEgypte);
	        window.draw(armeeMadagascar);
	        window.draw(armeeAfriqueDuNord);
	        window.draw(armeeAfriqueDuSud);
	        window.draw(armeeCongo);
			window.draw(armeeAlberta);
			window.draw(armeeAmeriqueCentrale);
			window.draw(armeeEtatDeLOuest);
			window.draw(armeeEtatDeLEst);
			window.draw(armeeGroenland);
			window.draw(armeeTerritoireDuNordOuest);
			window.draw(armeeOntario);
			window.draw(armeeQuebec);
			window.draw(armeeAlaska);
			window.draw(armeePerou);
			window.draw(armeeArgentine);
			window.draw(armeeBresil);
			window.draw(armeeVenezuela);
			window.draw(armeeGrandeBretagne);
			window.draw(armeeIslande);
			window.draw(armeeEuropeDuNord);
			window.draw(armeeScandinavie);
			window.draw(armeeEuropeDuSud);
			window.draw(armeeUkraine);
			window.draw(armeeEuropeOccidentale);
			window.draw(armeeMoyenOrient);
			window.draw(armeeMongolie);
			window.draw(armeeSiam);
			window.draw(armeeSiberie);
			window.draw(armeeOural);
			window.draw(armeeYakoutie);
			window.draw(armeeAfghanistan);
			window.draw(armeeChine);
			window.draw(armeeInde);
			window.draw(armeeTchita);
			window.draw(armeeJapon);
			window.draw(armeeKamtchatka);
			window.draw(armeeAustralieOrientale);
			window.draw(armeeAustralieOccidentale);
			window.draw(armeeNouvelleGuinee);
			window.draw(armeeIndonesie);
	        window.display();
	    }


    return 0;
}

