#include "turtle.h"
#include <cmath>
using namespace std;
int main(){ 
	// get in position
	Turtle leonardo(80, -80, 90); 
	Turtle raphael(-80, -80, 90); 
	Turtle michaelangelo(80, -80, 0); 
	Turtle donatello(-80, -80, 0); 
	
	draw::setpenwidth(10); // thick lines
	draw::setrange(-100, 100); 
	
	michaelangelo.setColor(draw::ORANGE); 
	leonardo.setColor(draw::BLUE);
	donatello.setColor(draw::PURPLE);
	raphael.setColor(draw::RED);
	
	leonardo.move(100); 
	draw::show(1000);
	raphael.move(100); 
	draw::show(1000);
	michaelangelo.turn(148);
	michaelangelo.move(190); 
	draw::show(1000);
	donatello.turn(32);
	donatello.move(190);
	draw::show(1000); 
	return 0;
}
