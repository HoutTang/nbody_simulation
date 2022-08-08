#ifndef UNIVERSE_HPP_
#define UNIVERSE_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <memory>
#include <iostream>

#include "CelestialBody.hpp"

using namespace std;

class Universe: public CelestialBody {
public:
	//Constructor
	Universe();

	//Destructor
	~Universe();

	void _setVSPtr(const CelestialBody& a);

public:
	//shared pointer 
	std::vector<std::shared_ptr<CelestialBody>> vSPtr;
	
};

#endif /* UNIVERSE_HPP_ */
