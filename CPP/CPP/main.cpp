// CPP.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <regex>
#include <string>
#include <vector>
#include <map>
#include "example_classes.h"
#include "Array.h"
#include "DynamicArray.h"

using namespace std;

void test();
map<string, int> counter(string&);
map<string, int>* another_counter(string&);
template<class T> T add_2_things(T, T);

int main()
{
    using namespace ExampleClasses;
    using namespace DataStructureClasses;
    test();
    {
        cout << "--------------------" << endl;
        string InputString = "This is a long ass sentence...";
        map<string, int> Results = counter(InputString);
        for (const auto& kvp : Results)
        {
            cout << kvp.first << " = " << kvp.second << endl;
        }
    }
    {
        cout << "--------------------" << endl;
        string InputString = "This is a long ass sentence...";
        map<string, int>* Results = another_counter(InputString);

        for (const auto& kvp : *Results)
        {
            cout << kvp.first << " = " << kvp.second << endl;
        }
    }
    {
        cout << "--------------------" << endl; 
        Rectangle Rect{2, 3};  // Into the stack. 
        cout << Rect.toString() << endl; 
    }

    {
        cout << "Using template functions" << endl; 
        cout << add_2_things<float>(1.4, 5.0) << endl;
        cout << add_2_things<int>(1, 3) << endl; 
        cout << add_2_things<string>("woah, ", "That is cool") << endl; 
    }

    {
        cout << "Let's use a java style array. " << endl; 
        Array<int> arr{10};
        for (int II = 0; II < arr.size; II++)
        {
            arr[II] = II + 1;
        }
        cout << arr.toString() << endl;
        cout << arr[0] << endl; 
        cout << "Using copy constructure to make a deepcopy of that array. " << endl; 
        Array<int> arr2 = arr;
        Array<int> arr3 = arr;
        cout << arr2.toString() << endl; 
        cout << "Mutating the copied array and then print both of them out. " << endl; 
        arr2[0] = -1; 
        cout << arr.toString() << endl; 
        cout << arr2.toString() << endl; 
    }

    {
        cout << "Ok, now we are going to start messing with the dynamic array. " << endl; 
        DynamicArray<int> arr{ 2 };
        for (int II = 0; II < arr.size(); II++)
        {
            arr.append(II);
        }
    }
}

void test() 
{
    regex pat("\\w+");
    string s = "dlf:fkdj jdlf:dlfk ldkf:dlas"; 
    smatch m;
    map<string, string> themap();
    regex_iterator<string::iterator> rit(s.begin(), s.end(), pat), rend;
    while (rit != rend)
    {
        cout << rit->str() << endl;
        ++rit;
    }
}

/*
 * Produce statistics from a string of words
 * 
 */
map<string, int> counter(string& theString)
{
    regex  Pattern(R"(\w+)");
    smatch Matches; 
    map<string, int> TheMap{};  // In stack. pointer points to string. 
    regex_iterator<string::iterator> 
    Iterator(theString.begin(), theString.end(), Pattern), EmptyRegItr;
    while (Iterator != EmptyRegItr)
    {
        string Word = Iterator->str();
        if (TheMap.count(Word) <= 0)
        {
            TheMap[Word] = 1;
        }
        else
        {
            TheMap[Word]++;
        }
        Iterator++;
    }
    return TheMap;
}

map<string, int>* another_counter(string& theString)
{
    regex  Pattern(R"(\w+)");
    smatch Matches;
    map<string, int>* TheMap = new map<string, int>();  // heap.
    // map<string, int> TheMap         = *TheMapPointer;  // Deep copy??? 
    regex_iterator<string::iterator>
    Iterator(theString.begin(), theString.end(), Pattern), EmptyRegItr;
    while (Iterator != EmptyRegItr)
    {
        string Word = Iterator->str();
        if (TheMap->count(Word) <= 0)
        {
            (*TheMap)[Word] = 1;
        }
        else
        {
            (*TheMap)[Word]++;
        }
        Iterator++;
    }
    return TheMap;
}


template <class T> T add_2_things(T a, T b)
{
    return a + b;
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
