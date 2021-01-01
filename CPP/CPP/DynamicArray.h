#pragma once

namespace DataStructureClasses
{
	/*
		A dynamic array is an array that has more flexitbility and it's based on the Array class. 
		The definitions are also listed in the header files. 
	*/
	template <typename T>
	class DynamicArray
	{
		int Length;
		int MaxSize;
		Array<T> data;
		void automaticResize();
		public: 
			void append(T& element);
			T& pop(int idx);
			void insert(int idx);

	};

	template<typename T>
	inline void DynamicArray<T>::automaticResize()
	{
		
	}

	template<typename T>
	inline void DynamicArray<T>::append(T& element)
	{
	}

	template<typename T>
	inline T& DynamicArray<T>::pop(int idx)
	{
		
	}

	template<typename T>
	inline void DynamicArray<T>::insert(int idx)
	{
	}


}

