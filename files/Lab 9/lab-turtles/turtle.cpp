#include "turtle.h"
#include <cmath>
using namespace std;
void Turtle::move(double dist){
	double currentposX = posx;
	double currentposY = posy;
	posx += dist * (cos(selfDir * M_PI/180));
	posy += dist * (sin(selfDir * M_PI/180));
	if (selfOn == true){
	draw::setcolor(myColor);
	draw::line(currentposX, currentposY, posx, posy);	
  }
}
void Turtle::turn(double deg){
	selfDir = selfDir + deg;	
}
Turtle::Turtle(double x0, double y0, double dir0){
	posx = x0;
	posy = y0;
	selfDir = dir0;
	myColor = draw::BLACK;
	selfOn = true;
}
void Turtle::on(){
	selfOn = true;
}
void Turtle::off(){
	selfOn = false;
}
void Turtle::setColor(Color c){
	myColor = c;
}
