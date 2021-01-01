#pragma once

#include "array.h"
#include <string>

namespace DataStructureClasses
{
	/*
		A dynamic array is an array that has more flexitbility and it's based on the Array class. 
		The definitions are also listed in the header files. 
		
		1. Dynamically resize the inner array if the length of the data is less than a half of the total size of the 
		inner array. 
		2. Dynamically shrinks if the inner data in the array is only a quarter of the size of the length of the array.  
		
		Assignment operator: 
			* It will performs a deep copy of the DynamicArray type on the right hand side of the expression. 

		Exceptions: 
			335: Invalid initial size for the dynamic array. 

	*/
	template <typename T>
	class DynamicArray
	{
		int Length;
		int MaxSize;
		Array<T>* data;
		void automaticResize();
		public:
			DynamicArray(int initialSize)
			{
				if (initialSize <= 0)
				{
					throw(335);
				}
				this->data = new Array<T>(initialSize);
				this->MaxSize = initialSize;
				this->Length = 0;
			}
			DynamicArray(DynamicArray<T>& anotherArray)
			{
				/*auto deepCopy = anotherArray.data;
				this->data = deepCopy;*/
			}
			~DynamicArray()
			{
				delete data;
			}
			
			void append(T& element);
			T& pop(int idx);
			void insert(int idx);
			std::string toString();
			unsigned int size() { return Length; };
	};
	
	// Call this method and the size of the array will get resized depending on the load factor. 
	template<typename T>
	inline void DynamicArray<T>::automaticResize()
	{
		if (Length == MaxSize)
		{
			T* destination = new T[2 * MaxSize];
			memcpy(destination, this->data->data, sizeof(destination[0]) * 2 * MaxSize);
			this->MaxSize = 2 * MaxSize;
			return;
		}
		if (4 * Length < MaxSize)
		{
			T* destination = new T[MaxSize / 2]; 
			memcpy(destination, this->data -> data, sizeof(destination[0]) * MaxSize / 4);
			this -> MaxSize = MaxSize / 4; 
		}	
	}

	template<typename T>
	inline void DynamicArray<T>::append(T& element)
	{
		automaticResize();
		this->data[++Length] = element;
	}

	template<typename T>
	inline T& DynamicArray<T>::pop(int idx)
	{
		automaticResize();
	}

	template<typename T>
	inline void DynamicArray<T>::insert(int idx)
	{
		automaticResize();
	}

	template<typename T>
	inline std::string DynamicArray<T>::toString()
	{
		return std::string("not yet implemented");
	}


}

