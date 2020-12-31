#pragma once
// A class/struct is a reference to a block memory with a set of values init. 

#include <string>;


namespace ExampleClasses // put thing under namespace for imports. 
{

	class Rectangle {
		public:
			int width, height;         // actual value. 
			void set_values(int, int); // member funciton. 
			int area();                // member function 
			std::string toString();
	};

}

namespace DataStructureClasses
{
	template <class T> class ArrayList
	{
		unsigned int size; 
		T data[];
		public: 
			unsigned int size();
			void append(T);
			T get(int);
			void insert(T, int);
			T remove_at(int);
	};
}


