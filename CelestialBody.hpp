// Name: Hout Tang
// Summary: PS3-a
// FileName: CelestialBody.HPP
// Due date : Mar 2, 2020
// Time spend on project: 15 hours
// **For more details: Please, refers to ps3_ReadMe documentation.


#ifndef CELESTIALBODY_HPP_
#define CELESTIALBODY_HPP_

#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <iostream>

using namespace std;

class CelestialBody : public sf::Drawable, sf::Transformable {
public:
	//Constructor:
	CelestialBody();
	CelestialBody(double pX,double pY,double vX, double vY,double m,std::string& fileName);
	
	//Destructor
	~CelestialBody();

	//set
	void _setRad(double r);
   	void _setWinSize(int wScale);
	void _setImg(std::string iName);
	void _setXpos(double new_px);
	void _setYpos(double new_py);
	void _setXvel(double new_vx);
	void _setYvel(double new_vy);
	void calculate_acc_X(double force);
    void calculate_acc_Y(double force);
	void step(double second);

	//accessor
	double _getXpos();
    double _getYpos();
	double _getXvel();
	double _getYvel();
	double _getXacc();
    double _getYacc();
    double _getMass();

	//draw 
	void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

 	// Pixel conversion functions
   	sf::Vector2f dPixel() const;

	//streams
    friend std::istream &operator>> (std::istream &input, CelestialBody &cb);
	friend std::ostream &operator<< (std::ostream &out, CelestialBody &cb);

public:
	//variables
	int w_scale;
	double rad;
	double mass;
	double _Xpos,_Ypos;
	double _Xvel,_Yvel;
	double _Xacc,_Yacc;

	//sfml variables
	sf::Texture image_Texture;
	sf::Sprite pic_Sprite;
	std::string img_Name; 
	sf::Image image; 
};

#endif /* CELESTIALBODY_HPP_ */
