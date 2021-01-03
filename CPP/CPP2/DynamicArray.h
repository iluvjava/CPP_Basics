#pragma once
#include <string>
namespace MyDataStructures {
	
	
	/*
		A dynamic array that take care of all the pointers that references to objects. 
		Exception Code: 
			111: Index out of arange. 
	*/
	template <typename T>
	
	class DynamicArray {
		int MaxSize; 
		int Count = 0; 
		T** DataBlock;
		bool* ToDestruct;
		void resize();
		public: 
			DynamicArray() = delete;
			DynamicArray(const int&);
			~DynamicArray() {
				for (unsigned int II = 0; II < Count; II++)
					if (ToDestruct[II])delete DataBlock[II];
				delete[] DataBlock;
				delete[] ToDestruct; 
			};
			void append(T*, bool=true);
			void insert(T*, int, bool = true);
			T* pop(int);
			std::string toString();
	};

	template<typename T>
	inline void DynamicArray<T>::resize()
	{
		if (Count == MaxSize)
		{
			T** NewArray = new T* [MaxSize * 2];
			bool* NewInHeap = new bool[MaxSize * 2];
			for (unsigned int II = 0; II < Count; II++)
			{
				NewArray[II] = DataBlock[II];
				NewInHeap[II] = ToDestruct[II];
			}
			delete DataBlock;
			delete[] ToDestruct;
			DataBlock = NewArray; 
			ToDestruct = NewInHeap;
			MaxSize = 2 * MaxSize;
		}
	}

	template<typename T>
	inline DynamicArray<T>::DynamicArray(const int& initialSize)
	{
		DataBlock = new T*[initialSize];
		ToDestruct = new bool[initialSize];
		MaxSize = initialSize;
	}

	template<typename T>
	inline void DynamicArray<T>::append(T* element, bool autoDestruct)
	{
		insert(element, Count, autoDestruct);
	}

	template<typename T>
	inline void DynamicArray<T>::insert(T* element, int index, bool toDestruct)
	{
		if (index < 0 || index > Count) throw (111);
		resize();
		for (unsigned int II = Count; II > index; II--)
		{
			DataBlock[II] = DataBlock[II - 1];
			ToDestruct[II] = ToDestruct[II - 1]; 
		}
		DataBlock[index] = element; 
		ToDestruct[index] = toDestruct;
		Count++;
	}

	template<typename T>
	inline T* DynamicArray<T>::pop(int index)
	{
		T* popped = DataBlock[index];
		for (unsigned int II = index; II < Count; II++)
		{
			DataBlock[II] = DataBlock[II + 1];
			ToDestruct[II] = ToDestruct[II + 1];
		}
		Count--;
		return popped;
	}

	template<>
	inline std::string DynamicArray<int>::toString()
	{
		using namespace std; 
		string s{ "[" }; 
		for (int II = 0; II < Count; II++)
		{
			string sep = II == Count - 1 ? "" : ", ";
			s += to_string(*(DataBlock[II])) + sep;
		}
		return s + "]";
	}

	template<typename T>
	inline std::string DynamicArray<T>::toString()
	{
		using namespace std;
		string s{ "[" };
		for (int II = 0; II < Count; II++)
		{
			string sep = II == Count - 1 ? "" : ", ";
			std::ostringstream address;
			address << (void const*)DataBlock[II];
			std:string name = address.str();
			s += address + sep;
		}
		return s + "]";
	}

	

}

