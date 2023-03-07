#include <iostream>
#include "Canvas.h"
using namespace std;

#define F 254u

void main() {
	Canvas C(100, 100);
	C.FillCircle(-10, -10, 30, F);
	C.DrawCircle(75, 25, 20, F);
	C.Clear();
	C.DrawLine(50, 50, 70, 80, F);
	C.DrawLine(50, 50, 80, 70, F);
	C.Print();
}