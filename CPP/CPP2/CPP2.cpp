// CPP2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include "HeapArray.h"
#include "DynamicArray.h"
#include "JavaStyleArray.h"

int main()
{
    using namespace std; 
    using namespace MyDataStructures;
    
    cout << "CPP2 is running. \n";
    {
        cout << "Creating An instance of HeapArray" << endl;
        HeapArray<int> Arr{ 10 };
        for (int II = 0; II < Arr.size(); II++)
        {
            Arr.set(II, new int(II + 1));
        }
        cout << Arr.toString() << endl; 
        cout << "Augmenting the size. " << endl; 
        cout << "And this is the new array: " << endl; 
        HeapArray<int> BiggerArr{ Arr, 2 * Arr.size() };
        cout << BiggerArr.toString() << endl; 
        cout << "And this is old array, pointers should be transferred: " << endl; 
        cout << Arr.toString() << endl; 
    }
   
    cout << "Creating a dynamic array. " << endl;
    DynamicArray<int> darr{ 1 };
    {
       
        cout << darr.toString() << endl; 

        cout << "appending element from dynamic mem" << endl; 
        for (int II = 0; II < 10; II++)
        { 
            darr.append(new int{II + 1});
        }
        cout << darr.toString() << endl; 

        cout << "appending element from stack or automatic vars" << endl; 
        for (int II = 10; II < 20; II++)
        {
            darr.append(&II, false);
        }
        cout << darr.toString() << endl; 

        cout << "inserting -1 element at front, and the 3rd index" << endl; 
        darr.insert(new int{ -1 }, 0);
        darr.insert(new int{ -1 }, 2);
        cout << darr.toString() << endl;

        cout << "pop out the 5th element" << endl; 
        cout << *darr.pop(4) << endl; 
        cout << darr.toString() << endl;

    }

    cout << "Dynamic array are outside of scope, let's see what happened: " << endl; 
    cout << darr.toString() << endl;

    {
        cout << "Passing pointers to vector" << endl; 
        vector<int*> vec{};
        for (int II = 0; II < 10; II++)
        {
            vec.push_back(&II);
        }
        for (const int* element : vec)
        {
            cout << *element << endl; 
        }
        cout << "There are like, one address in forloop, all pointing to the last iterative value." << endl;

    }

    {
        cout << "Let's try something on the smart pointers" << endl; 
        unique_ptr<int> x(new int{ 5 }); 
        cout << "x: " << to_string(*x) << endl; 
        cout << "Moving unique_ptr ownership from x to y. " << endl; 
        unique_ptr<int> y(move(x)); 
        cout << "x (Ptr value): " << x.get()<< endl; 
        cout << "y: " << to_string(*y) << endl; 
    }

    {
        cout << "Testing simple array" << endl; 
        SimpleArray<int> arr{ 10 };
        for (int II = 0; II < 10; II++)
        {
            arr.DataBlock[II] = new int{ II + 1};
        }

        for (int II = 0; II < 10; II++)
        {
            cout << to_string(*(arr.DataBlock[II])) << endl; 
        }

    }



}





// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
