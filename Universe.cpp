
#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include <memory>

#include "Universe.hpp"
#include "CelestialBody.hpp"

using namespace sf;

//Constructor
Universe::Universe(){}

//Destructor
Universe::~Universe(){}

void Universe::_setVSPtr(const CelestialBody& a)
{
    this->vSPtr.emplace_back(std::make_shared<CelestialBody>(a));

}

 