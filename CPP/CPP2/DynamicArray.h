#pragma once

#include "Array.h"
namespace MyDataStructures {
	
	/*
	
	*/
	template <typename T>
	class DynamicArray
	{
		Array<T> InnerArray; 
		unsigned int Length; 
	};
}

