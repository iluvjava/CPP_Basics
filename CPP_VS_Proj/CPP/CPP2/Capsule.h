#pragma once
#include <memory>

namespace MyDataStructures{
	
	/*
		This is class for encapsuling a generic type into a raw array, 
		This can be easily initialized. 

		1. Assignment Operator: 
			The pointer ownership is moved to the new instance, and 
			the old instance loses the pointer. 
	*/
	template<typename T>
	class TypeCapsule
	{
		T* TheThing; 
		bool ToDestruct;
		public: 
			TypeCapsule()
			{
				TheThing = nullptr;
				ToDestruct = false; 
			}
			TypeCapsule(T* arg, bool destruct=true) 
			{
				TheThing = arg; ToDestruct = destruct; 
			}
			~TypeCapsule() {
				if (ToDestruct) delete TheThing; 
			}
			/*
				This will delete the thing in the memory. 
			*/
			void Reset(T* anotherType, bool destruct=true)
			{
				if (ToDestruct) delete TheThing; 
				ToDestruct = destruct;
				TheThing = anotherType; 
			}
			T* GetPtr() { return TheThing;  };

			// Old one is destoryed. 
			TypeCapsule<T>& operator = (const TypeCapsule<T>& anotherCap)
			{
				TheThing = anotherCap.TheThing; 
				anotherCap.TheThing = nullptr; 
				ToDestruct = anotherCap.ToDestruct; 
				anotherCap = false; 
				return this; 
			}
			

	};

	/*
		Only accepts referenes to stuff, no pointer allowed. 
		Exception Code: 
			111: Index out of range for the array. 
	*/
	template<typename T>
	class CapsuleDynamicArray
	{
		std::shared_ptr<TypeCapsule<T>[]> CapsuleArray;
		unsigned int Count; 
		unsigned int MaxLen; 
		void Resize();
		public: 
			CapsuleDynamicArray()
			{
				Count = 0; 
				MaxLen = 2;
				CapsuleArray = std::shared_ptr<TypeCapsule<T>[]>(new TypeCapsule<T>[2]);
			}
			void Append(T&, bool = true);
			void Insert(T&, int,  bool = true);
			T& pop(int);
	};


	template<typename T>
	inline void CapsuleDynamicArray<T>::Resize()
	{
		using namespace std; 
		if (Count == MaxLen) 
		{
			TypeCapsule<T>* NewArray = TypeCapsule<T>[MaxLen * 2];
			for (unsigned int II = 0; II < Count; II++)
			{
				NewArray[II] = (*CapsuleArray)[II];
			}
			CapsuleArray = share_ptr( NewArray );
			MaxLen = 2 * MaxLen;
		}
	}

	template<typename T>
	inline void CapsuleDynamicArray<T>::Append(T& data, bool toDestruct)
	{
		Insert(data, Count, toDestruct);
	}

	template<typename T>
	inline void CapsuleDynamicArray<T>::Insert(T& data, int index, bool toDestruct)
	{
		if (index <= 0 || index > Count)
		{
			throw (111); 
		}
		Resize();
		for (unsigned int II = Count; II > index; II--)
		{
			(*CapsuleArray)[II] = (*CapsuleArray)[II - 1];
		}
		(*CapsuleArray)[index] = TypeCapsule<T>(&data, toDestruct);
		Count++; 
		
	}

	template<typename T>
	inline T& CapsuleDynamicArray<T>::pop(int index)
	{
		T* ToReturn = ((*CapsuleArray)[index]).GetPtr();
		for (unsigned int II = index; II < Count; II++)
		{
			*CapsuleArray[II] = *CapsuleArray[II + 1]; 
		}
		Count--; 
		return *ToReturn;

	}



}

