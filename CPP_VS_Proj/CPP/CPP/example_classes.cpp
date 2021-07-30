// The header files define what the class is, and the actual stuff is in a .ccp file. 
// In the cpp class, we include the header file and then we use the namespace to 
// tell the compiler which memeber of which class of which namespace we 

// I think there is some VS Socery here, it knows where to include the header file, which is not 
// Techinically in side of the current directory. 

#include "example_classes.h"

void ExampleClasses::Rectangle::set_values(int arg1, int arg2)
{
	this->height = arg1;
	this->width = arg2;
}

int ExampleClasses::Rectangle::area()
{
	return this->width*this->height;
}

std::string ExampleClasses::Rectangle::toString()
{
	using namespace std;
	string s{ "This is a triangle with width: " }; 
	s += to_string(this->width); 
	s += " and the height is: "; 
	s += to_string(this->height); 
	s += " and the area is: "; 
	s += to_string(this->area()); 
	return s;
}





