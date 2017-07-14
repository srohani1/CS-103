#include "draw.h"
class Turtle{
public:
	void move(double dist); // move the Turtle forward dist steps
	void turn(double deg); //  turn the Turtle counterclockwise/left deg degree
	Turtle(double x0, double y0, double dir0); // construct new Turtle with this state
	void setColor(Color c); // change line color that this Turtle draws from now on 
	void off(); // make this Turtle stop drawing lines when it moves
	void on(); // make this Turtle resume drawing lines when it moves
private:
	double posx;
	double posy;
	double selfDir;
	bool selfOn;
	Color myColor;
};
