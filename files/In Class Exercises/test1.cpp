#include <iostream>

double sqrt(double x, double lo, hi)
{
	double mid = (hi + lo)/2;
	if (mid * mid == x)
	{
	 return mid;
	}
	if  (mid*mid > x)
	{	
	 return sqrt(x, lo, mid);
	}
	else 
		return sqrt(x, mid, hi);
}
double sqrt(double x)
{
	return sqrt(x, 0, x + 1);
}