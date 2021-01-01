#pragma once

#include <string>

namespace DataStructureClasses
{
	/*
		By Separation of Compilations, all members of the class will be defined in this header file. 

		1. Assignment Operator:
			* Deep copy of all the pointers to type T stores in the heap memory. 
			* This is achieved via a copyconstructor that makes a deep copy of any given instance of the same type. 
	*/
	template <typename T> class Array
	{
		public:
			unsigned int size;
			T* data;

		public:
			Array(int size)               // ctor
			{
				this->data = new T[size]; // in the heap 
				this->size = size;
			}
			Array(Array<T>& anotherArray) // cctor 
			{
				this->data = new T[anotherArray.size]; 
				this->size = anotherArray.size; 
				memcpy(this->data, anotherArray.data, anotherArray.size*sizeof(this->data[0]));
			}
			~Array() // dtor
			{
				delete[] this->data; // Default destructor won't delete the array from heap, maual deletion is needed. 
			}

			std::string toString();
			T& operator [](int n);   // returns a reference because it's both an getter and a setter. 
			Array<T>& operator = (const Array<T>& anotherArr);
			
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
		if (n < 0 || n > this->size) throw ("IndexOutOfRange Error");
		return this->data[n];
	}

	template<typename T>
	inline Array<T>& Array<T>::operator=(const Array<T>& anotherArr)
	{
		return Array<T>(anotherArr);
	}

}
