//File name : tp.cpp
//Author    : Alec Lord
//Date      : 02/14/17
//Purpose   : Simulates the toilet-paper problem
//Notes     : None
#include <iostream>   // Basic I/O => cin, cout, etc.
#include <cstdlib>    // Other helpful functions => rand(), RANDMAX
#include <iomanip>
using namespace std;
// Prototype/declaration of a function that returns a
// uniform random number between [0,1]
double rand_uniform();
// Prototype/declaration of a function that will perform a single
// simulation of two rolls of paper and users
// Returns the number of squares left on the non-empty roll
int single_sim(int N, double p);
// Main function
int main(int argc, char *argv[])
{
  double average = 0;
  double sum = 0;
  double squaresleft = 0;
  srand(time(0));
  int N;                // initial number of squares on each roll
  double p;             // probability of a big-chooser
  int sims;             // number of trials for our simulation
  cout << "Enter a integer N, double p, and an integer sims: ";
  cin >> N >> p >> sims;
  for (int i = 0;i < sims;i++)
  {
  	squaresleft = single_sim(N,p);
  	sum = sum + squaresleft;
  }
  average  = sum/(double)sims ;
  cout << "Average: " << setprecision(4) <<average << endl;
  return 0;
}
// return the number of squares on the non-empty roll
// for this simulation of the problem
int single_sim(int N, double p)
{
	double r = 0;
	int numsquares1 = N - 1;
	int numsquares2 = N;
	while (numsquares1 != 0 && numsquares2 != 0)
	{
		r = rand_uniform();
		// Big Roll Chooser
		if (r < p) 
		{
			if (numsquares1 > numsquares2)
			{
				numsquares1 = numsquares1 -1;
			}
			else 
			{
			numsquares2 = numsquares2 -1;
	
			}
		}
		else 
		{
			if (numsquares2 < numsquares1)
			{
				numsquares2 = numsquares2 -1;
			}
			else 
			{
				numsquares1 = numsquares1 -1;
			}
		}

	}
		if (numsquares1 == 0)
		{
			return numsquares2;
		}
		return numsquares1;
}
// returns a uniformly-distributed number in the range [0,1]
//  The caller can use the return result to then determine
//  if it should treat it as a big- or little-chooser by 
//  also using the p parameter.  This code only needs to 
//  produce a random number in the range [0,1]
double rand_uniform()
{
return (double)rand ()/RAND_MAX;
}
