// CPP2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Array.h"

int main()
{
    using namespace std; 
    using namespace MyDataStructures;
    
    cout << "CPP2 is running. \n";
    {
        cout << "Creating An instance of Array" << endl;
        Array<int> Arr{ 10 };
        for (int II = 0; II < Arr.size(); II++)
        {
            Arr.set(II, new int(II + 1));
        }
        cout << Arr.toString() << endl; 
        cout << "Augmenting the size. " << endl; 
        cout << "And this is the new array: " << endl; 
        Array<int> BiggerArr{ Arr, 2 * Arr.size() };
        cout << BiggerArr.toString() << endl; 
        cout << "And this is old array, pointers should be transferred: " << endl; 
        cout << Arr.toString() << endl; 
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
