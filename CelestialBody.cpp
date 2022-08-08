#include <iostream>
#include <cmath>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>
#include "CelestialBody.hpp"

using namespace std;
using namespace sf;

//Constructor
CelestialBody::CelestialBody()
{
	this->_Xpos = 0;
    this->_Ypos = 0;
	this->_Xvel = 0;
    this->_Yvel = 0;
	this->mass  = 0;
	this->img_Name=std::string();
}

CelestialBody::CelestialBody(double pX,double pY,double vX, double vY,double m,std::string& fileName)
{
    this->_Xpos = pX;
    this->_Ypos = pY;
    this->_Xpos = vX;
    this->_Ypos = vY;
    this->mass  = m;
    this->img_Name= fileName;
    _setImg(img_Name);
}

//destructor
CelestialBody::~CelestialBody(){}

//load image to sprite
void CelestialBody::_setImg(std::string iName)
{
    img_Name = iName;
    image.loadFromFile(img_Name);
    if(!image_Texture.loadFromImage(image))
       {exit(1);}
    pic_Sprite.setTexture(image_Texture);
}

void CelestialBody::_setWinSize(int wScale)
{
     this->w_scale = wScale;
}

void CelestialBody::_setRad(double r)
{ 
    this->rad = r;
}

void CelestialBody::_setXpos(double new_px)
{
    this->_Xpos = new_px;
}
void CelestialBody::_setYpos(double new_py)
{
    this->_Ypos = new_py;
}
void CelestialBody::_setXvel(double new_vx)
{
    this->_Xvel = new_vx;
}
void CelestialBody::_setYvel(double new_vy)
{
    this->_Yvel = new_vy;
}

void CelestialBody::calculate_acc_X(double force)
{
    this->_Xacc = force/mass;
}

void CelestialBody::calculate_acc_Y(double force)
{
    this->_Yacc = force/mass;
}

double CelestialBody::_getXpos()
{
     return _Xpos;
}

double CelestialBody::_getYpos()
{
     return _Ypos;
}

double CelestialBody::_getXvel()
{
    return _Xvel;
}
double CelestialBody::_getYvel()
{
    return _Yvel;
}

double CelestialBody::_getXacc()
{
    return _Xacc;
}

double CelestialBody::_getYacc()
{
    return _Yacc;
}

double CelestialBody::_getMass()
{
     return mass;
}

void CelestialBody::step(double second)
 {
    //creat new variable    
    double new_vel_X,new_vel_Y;
    double new_pos_X,new_pos_Y;

    new_vel_X = _Xvel + (_Xacc*second); 
    new_vel_Y = _Yvel + (_Yacc*second);
    
    new_pos_X = _Xpos + (new_vel_X*second); 
    new_pos_Y = _Ypos + (new_vel_Y*second);

    //update variables
    _Xvel = new_vel_X;
    _Yvel = new_vel_Y;
    _Xpos = new_pos_X;
    _Ypos = new_pos_Y; 
 }

// set pixel coordinates.
sf::Vector2f CelestialBody::dPixel() const 
{
    double x_pixel, y_pixel; 

    //scale the pixel 
    double pixel = rad/(w_scale/2.0);  
   
    //set x's pixel coordinates
    x_pixel = (w_scale/2.0) + (_Xpos/pixel);
    
    //set y's pixel coordinates
    y_pixel = (w_scale/2.0) - (_Ypos/pixel);
    
    return sf::Vector2f(x_pixel,y_pixel);    
}

//Draw function
void CelestialBody::draw(RenderTarget& target, RenderStates states) const 
{
    sf::Sprite _allImg = pic_Sprite;
    _allImg.setPosition(dPixel());
    states.transform *=getTransform();
    target.draw(_allImg,states);
}

//StreamInput
istream &operator >> (istream &input, CelestialBody &cb){

    input >> cb._Xpos >> cb._Ypos >> cb._Xvel >>cb._Yvel >>cb.mass >>cb.img_Name;
    cb._setImg(cb.img_Name);
    return input;
}

ostream &operator<< (ostream &out, CelestialBody &cb)
{
    out << cb._Xpos <<" ";
    out << cb._Ypos <<" ";
    out << cb._Xvel <<" ";
    out << cb._Yvel <<" ";
    out << cb.mass <<" ";
    out << cb.img_Name << endl;

    return out;
}

