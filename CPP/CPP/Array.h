#include "..\CPP2\Array.h"
#include "..\CPP2\Array.h"
#include "..\CPP2\Array.h"
#include "..\CPP2\Array.h"
#pragma once

#include <string>

namespace DataStructureClasses
{
	/*
		By Separation of Compilations, all members of the class will be defined in this header file. 

		Exceptions Types: 
			111: Index out of range error. The index given to get the elements of the array is out of the size of the 
			array. 
	*/
	
	template <typename T> class Array
	{
		
		public:
			unsigned int size;
			T* data;

		public:
			Array()
			{
				this->data = new T[0];
				this->size = 0;
			}
			Array(int size)               // ctor
			{
				this->data = new T[size]; // in the heap 
				this->size = size;
			};
			~Array() // dtor
			{
				delete[] this->data;      // Default destructor won't delete the array from heap, maual deletion is needed. 
			}
			
			Array(const Array<T>& anotherArray) // cctor
			{
				this->data = new T[anotherArray.size];
				this->size = anotherArray.size;
				memcpy(this->data,
					anotherArray.data,
					anotherArray.size * sizeof(this->data[0]));
				// Note that: it's the length in byte, not the number of elements. 
			}
			std::string toString();
			T& operator [](int n);        // returns a reference because it's both an getter and a setter. 

			
	};

	template<typename T>
	inline std::string Array<T>::toString()
	{
		using namespace std;
		string s{};
		s += "[";
		{
			int II = 0;
			while (++II < this->size)
			{
				s += to_string(this->data[II - 1]) + (II == this->size - 1? "":", ");
			}
		}
		s += "]";
		return s;
	}

	template<typename T>
	inline T& DataStructureClasses::Array<T>::operator[](int n)
	{
		if (n < 0 || n > this->size) throw (111);
		return this->data[n];
	}





}
