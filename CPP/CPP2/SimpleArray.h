#pragma once


namespace MyDataStructures {
	
	/*
		A simple array for managing type T pointers, it will destruct all the pointers 
		of type T given to this array. 
	*/
	template <typename T>
	struct SimpleArray
	{
		T** DataBlock; 
		SimpleArray() = delete;
		SimpleArray(unsigned int Size)
		{
			if (Size == 0) throw (333);
			DataBlock = new T * [Size] {nullptr};
			MaxSize = Size;
		}
		~SimpleArray()
		{
			for (unsigned int II = 0; II < MaxSize; II++)
			{
				delete DataBlock[II]; // delete nulptr is ok.
			}
			delete[] DataBlock; 
		}
		int size() { return MaxSize;}
		void size_double() {
			T** NewDataBlock = new T * [MaxSize*2] {nullptr};
			for (int II = 0; II < MaxSize; II++)
			{
				NewDataBlock[II] = DataBlock[II];
			}
			delete[] DataBlock;
			DataBlock = NewDataBlock;
		}
		private: int MaxSize;
		
	};

}

