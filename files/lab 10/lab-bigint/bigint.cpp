#include "bigint.h"
#include <iostream>
#include <stdexcept>
using namespace std;
BigInt::BigInt(string s, int base1)
{
	base = base1;
	for (int i = s.size()-1; i >= 0; i--)
	{
		if (s[i] >= '0' && s[i]  <= '9')
		{
			myVector.push_back(s[i] - '0');
		}
		else
		{
			myVector.push_back((s[i] - 'A')+10);
		}
	} 	
}   
BigInt::BigInt(string s)
{
	base = 10;
	for (int i = s.size()-1; i >= 0; i--)
	{
		myVector.push_back(s[i] - '0');
	}		 	
} 
string BigInt::to_string()
{
	string tempString;
	for (int i = myVector.size() - 1; i >= 0; i--)
	{
		char c;
		if (myVector[i] >= 0 && myVector[i]  <= 9)
		{
			 c = (char) myVector[i] + '0';
		}
		else
		{
			 c = (char) (myVector[i] - 10) + 'A' ;
		}
		tempString.push_back(c);
	}
	return tempString;
}
void BigInt::add(BigInt b)
{
	int carry=0;
	if (myVector.size() < b.size())
	{
		int sizeDiff;
		sizeDiff = b.size() - myVector.size();
		for(int i = 0; i < sizeDiff; i++)
		{
			myVector.push_back(0);
		}
	}
	else 
	{
		int sizeDiff;
		sizeDiff = myVector.size() - b.size();
		for(int i = 0; i < sizeDiff; i++)
		{
			b.myVector.push_back(0);
		}
	}	

	for (int i = 0; i < b.size(); i++) 
	{
		int sum;
		sum = myVector[i] + b.get(i) + carry;
		myVector[i] = sum % base;
		if (sum > base - 1)
		{
			carry = 1;
		}
		else 
		{
			carry = 0;
		}	
	}
	if (carry != 0)
	{
		myVector.push_back(carry);
	}
}		
int BigInt::size(){
	return myVector.size();
}
int BigInt::get(int i){
	return myVector[i];
}
