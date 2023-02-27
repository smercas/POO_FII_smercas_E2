//#define vName(a) #a

#include <iostream>
#include "NumberList.h"

using namespace std;

void main() {
	NumberList nl;
	nl.Print(); //error, nl not initialised
	nl.Add(100); //same here
	nl.Sort(); //you can probably guess
	nl.Init();
	nl.Print(); //empty array message
	nl.Add(55);
	nl.Print();
	nl.Add(0);
	nl.Add(30);
	nl.Add(-25);
	nl.Add(5);
	nl.Add(100);
	nl.Print(); //"55, 0, 30, -25, 5, 100 \n"
	nl.Sort();
	nl.Print(); //"-25,0, 5, 30, 55, 100 \n"
}