#pragma once
#include <string>
namespace MyDataStructures
{

	/*
		Stores a pointer to an array of pointers; and other things to help with this. 

		Constructors: 
			1. Default constructors: Empty array. 
			2. Array(int): Create an array of NULLs with a given size, allocated in heap. 
			3. Array(Array<T>&, const int&): 
				Given an old array, and a new size, move everything in old array to this new array.
				NOTE: The old array will be full of NULLs, because the new array must take ownership of the 
				old one. 
				NOTE: Memory leak if the new array is smaller than the old one. 

		Destructor: 
			1. Delete the array of pointers and the enetity it's pointing to.

		Exception Codes: 
			111: Index out of range. 
			112: Null pointer is not accessible, there is nothing in here, use set to set up a value for 
			that index first. 

		Behavior: 
			1. Takes in pointers to the data you want and put them into an array of fixed size. 
			2. Destruct all pointers and the things it points to afterwards. 
		
		Extra Things: 
			1. Template specialization needed for non-primitive data types for "toString()" method. 

		WARNING: 
			1. When using set(const int&, T*) or set(const int&, T&), always pass in a dynamically allocated type, and don't 
			delete that in OTHER PLACES. 
	*/
	template<typename T>
	class Array
	{
		unsigned int MaxSize; 
		T** DataBlock; 
		bool DataBlockOwnerShip = true;
		public: 
			Array():Array<T>{0} {};
			Array(const int&);
			Array(Array<T>&, const int&);
			~Array() {delete[] DataBlock;};
			T& operator [] (const int&);
			std::string toString();
			int size() { return MaxSize;};
			void set(const int&, T*);
			void set(const int&, T&); 
	};
	
	template<typename T>
	inline T& MyDataStructures::Array<T>::operator[](const int& index)
	{
		if (index < 0 || index >= this->MaxSize) throw(111); 
		T TheData = (*DataBlock)[index];
		if ((*DataBlock)[index] == NULL) throw (112);
		return TheData; 
	}

	template<typename T>
	inline MyDataStructures::Array<T>::Array(const int& initialLength)
	{
		this->MaxSize = initialLength;
		T** TheArray = new T * [initialLength] {NULL};
		DataBlock = TheArray;
	}

	template<typename T>
	inline Array<T>::Array(Array<T>& oldArray, const int& newArraySize) : Array<T>{newArraySize}
	{
		for (unsigned int II = 0; II < oldArray.size(); II++)
		{
			DataBlock[II] = oldArray.DataBlock[II];
			oldArray.DataBlock[II] = NULL; 
		}
	}
	
	template<typename T>
	inline std::string MyDataStructures::Array<T>::toString()
	{
		using namespace std;
		string s{};
		s += "[";
		{
			int II = 0;
			while (++II < MaxSize)
			{
				string Sep = (II == MaxSize - 1 ? "" : ", ");
				if (!DataBlock[II - 1]) {
					s += "NULL" + Sep; 
					continue;
				}
				T TheData = *(DataBlock[II - 1]);
				s += to_string(TheData) + Sep;
			}
		}
		s += "]";
		return s;
	}
	
	template<typename T>
	inline void Array<T>::set(const int& index, T* data)
	{
		if (index < 0 || index >= MaxSize) throw(111); 
		DataBlock[index] = data;
	}
	template<typename T>
	inline void Array<T>::set(const int& index , T& data)
	{
		if (index < 0 || index >= MaxSize) throw(111);
		DataBlock[index] = &data;
	}
}