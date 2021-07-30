// CPP3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

#include "DynamicArray.h"

int main()
{
    using namespace std; 
    using namespace MyDataStructures;
    cout << "CPP3 is running...\n";

    {
        cout << "Changing value via dereferencing the shared_ptr" << endl; 
        auto arr = DynamicArray<shared_ptr<int>>(10); 
        for (int II = 0; II < 10; II++)
        {
            shared_ptr<int>* integer = new shared_ptr<int>(new int{ II + 1 });
            arr.append(integer);
        }
        auto arr2 = DynamicArray<shared_ptr<int>>{arr};
        *arr[0] = -1;

        cout << "printing out the first array: " << endl; 
        for (int II = 0; II < 10; II++)
        {
            cout << *arr[II] << endl; 
        }
        cout << "printing out the second array: " << endl; 
        for (int II = 0; II < 10; II++)
        {
            cout << *arr2[II] << endl; 
        }
        
    }
    {
        auto arr = DynamicArray<shared_ptr<int>>(10);
        for (int II = 0; II < 10; II++)
        {
            shared_ptr<int>* integer = new shared_ptr<int>(new int{ II + 1 });
            arr.append(integer);
        }
        auto arr2 = DynamicArray<shared_ptr<int>>{ arr };
        *arr[0] = -1;

        cout << "printing out the first array: " << endl;
        for (int II = 0; II < 10; II++)
        {
            cout << *arr[II] << endl;
        }
        cout << "printing out the second array: " << endl;
        for (int II = 0; II < 10; II++)
        {
            cout << *arr2[II] << endl;
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
