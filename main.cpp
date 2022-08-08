
#include <iostream>
#include <fstream> 
#include <iomanip> 
#include <string>
#include <sstream> 
#include <cmath> 

#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#include "CelestialBody.hpp"
#include "Universe.hpp"

using namespace sf;

int usage(){

    std::cout<<"Usage:\n\tNBody<time_limit> <time_delta>" "< <universe_file>\n"<<std::endl;
    std::cout<<"Value:\n\tNBody 15778800.0 25000.0""< planets.txt\n>" <<std::endl;
    return 0;
}

int main(int argc,char* argv[]) {

	if(argc !=3 )
    {
        std::cerr<<"\n Please, enter two argurments\n";

    }

    //initialize variables to store time-related arguments-NEW
    double time_limit, time_delta,timer;
	timer=0; 

    //check first argument
    std::istringstream arg_limit(argv[1]);
    if(!(arg_limit>>time_limit))
    {
        std::cerr << "\n'" <<argv[1] <<"' "
        "ist not a valid double value." << std::endl;
        return usage();
    }

    //check first argument
    std::istringstream arg_delta(argv[2]);
    if(!(arg_delta>>time_delta))
    {
        std::cerr << "\n'" <<argv[2] <<"' "
        "ist not a valid double value." << std::endl;
        return usage();
    }

	//create object of class
	CelestialBody a;
	Universe u;
	u._setVSPtr(a);

	//vaiables
	unsigned int window = 512;
	unsigned int numOfParticle;
	double radius_uni;  

	//input
	std::cin>>numOfParticle;
	std::cin>>radius_uni;

	// Create sharepointer of vector which point to CelestialBody
    for(unsigned int i=0; i<numOfParticle; i++){
		std::shared_ptr<CelestialBody> ptr(new CelestialBody());
		u.vSPtr.push_back(ptr);
	}
    	
	//function to use load information from planet.txt
	for(unsigned int i=0; i<numOfParticle; i++){
        std::cin >> (*u.vSPtr[i]);(*u.vSPtr[i])._setWinSize(window);(*u.vSPtr[i])._setRad(radius_uni);
    }

    //Window display and set frame
    RenderWindow windowDiplay({window,window}, "PS3a_N-Body Simulation");
    windowDiplay.setFramerateLimit(30);

    //Music
    sf::Music m;
    m.openFromFile("planet.ogg");
    m.play();

	//extra credit-Display image background
    sf::Image bk_image;
    sf::Sprite bk_sprite;
	sf::Texture bk_texture;
    bk_image.loadFromFile("starfield.jpg");
    bk_texture.loadFromImage(bk_image);

    // //scale new window size
    sf::Vector2u bk_dimension = bk_texture.getSize();
    double scale_factor =((double)window/bk_dimension.x);
    bk_sprite.setScale(scale_factor,scale_factor);
    bk_sprite.setTexture(bk_texture);

	//text
    sf::Font font;
    if(!font.loadFromFile("Aller.ttf"))
        std::cout <<"Error loading font." <<std::endl;

    std::ostringstream ss;
    sf::Text text;
    text.setFont(font);
    text.setCharacterSize(18);
    text.setStyle(sf::Text::Bold);
    text.setFillColor(sf::Color::White);

	//addition
    double gravity = 6.67e-11;
    double delta_x,delta_y;
    double radius,radius_squared;
    double forceRadius;
    double force_x,force_y;
    double i_mass,j_mass;	

	Event event;
	while(windowDiplay.isOpen()) 
	{
		while(windowDiplay.pollEvent(event)) 
		{
			if(event.type == Event::Closed) 
			{
				windowDiplay.close();
				break;
			}		
		}
		if(timer<= time_limit)
    	{
            windowDiplay.clear(sf::Color::Black);
            windowDiplay.draw(bk_sprite);

            //loop for physic calculation
            for(unsigned int i=0;i<numOfParticle;i++)
            {
                forceRadius=0;
                force_x=0;
                force_y=0;
                i_mass=(*u.vSPtr[i])._getMass();

                for(unsigned int j=0; j<numOfParticle;j++)
                    {
                        if(j==i)
                           { continue; }

                        //chage in x and y position
                        delta_x =(*u.vSPtr[j])._getXpos()-(*u.vSPtr[i])._getXpos();
                        delta_y =(*u.vSPtr[j])._getYpos()-(*u.vSPtr[i])._getYpos();
                        radius_squared =(delta_x * delta_x) + (delta_y * delta_y);
                        radius = sqrt(radius_squared);
                        j_mass=(*u.vSPtr[j])._getMass();

                        //accumluate the forces acting on this i body
                        forceRadius =(gravity * (i_mass * j_mass))/radius_squared;
                        force_x += forceRadius * (delta_x / radius);
                        force_y += forceRadius * (delta_y / radius);                    
                    }
						//internally calculate
						(*u.vSPtr[i]).calculate_acc_X(force_x);
                        (*u.vSPtr[i]).calculate_acc_Y(force_y);
                        (*u.vSPtr[i]).step(time_delta);
                        
            } //end

                    //draw planets
                    for(unsigned int i=0; i<numOfParticle; i++)
                        {windowDiplay.draw((*u.vSPtr[i]));}

                        //draw the text
                        ss.str("");
                        ss.clear();
                        ss<<timer;
                        text.setString(ss.str());
                        windowDiplay.draw(text);
                        timer +=time_delta;
                        windowDiplay.display();
        } else
            {
                ss.str("");
                ss.clear();
                ss << timer;
                text.setString(ss.str());
                windowDiplay.draw(text);
            }
	}

    std::cout<< " Time Limit -> " << time_limit << std::endl;
    std::cout<< " Time Delta -> " << time_delta << std::endl;

    //draw planets
    for(unsigned int i=0; i<numOfParticle; i++)
         std::cout << (*u.vSPtr[i]);

    //stop music
    m.stop();     
    
    return 0;
}

