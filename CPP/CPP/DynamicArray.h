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
		int Length;  // in the class. 
		int MaxSize; // in the class. 
		Array<T>* DataArray;  // in the heap. 
		void automaticResize();
		public:
			DynamicArray(int initialSize)
			{
				if (initialSize <= 0)
				{
					throw(335);
				}
				this->DataArray = new Array<T>(initialSize);
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
			}
			
			void append(const T& element);
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
			Array<T>* NewArr = new Array<T>( 2 * MaxSize );
			Array<T> OldArr = *DataArray;
			for (int II = 0; II < OldArr.size; II++)
			{
				(*NewArr)[II] = OldArr[II];
			}
			this->MaxSize = 2 * MaxSize;
			this->DataArray = NewArr;
			return;
		}
	}

	template<typename T>
	inline void DynamicArray<T>::append(const T& element)
	{
		automaticResize();
		this->DataArray[Length++] = element;
	}

	template<typename T>
	inline T& DynamicArray<T>::pop(int idx)
	{
		automaticResize();
		if (idx >= this->Length || idx <= 1)
		{
			throw (111); // index out of range error. 
		}

		T elementPopped = DataArray[idx]; // should be a deep copy of that element. 
		for (int II = idx; II < this->Length - 1; II++)
		{
			DataArray[idx] = DataArray[idx + 1]; 
		}
		this->Length--;
		return elementPopped;
	}

	template<typename T>
	inline void DynamicArray<T>::insert(int idx)
	{
		automaticResize();
	}

	template<typename T>
	inline std::string DynamicArray<T>::toString()
	{
		using namespace std; 
		string s{}; 
		s += "[";
		for (int II = 0; II < this->Length; II++)
		{
			s += to_string((*DataArray)[II]) + " ";
		}
		return s + "]";
	}


}

