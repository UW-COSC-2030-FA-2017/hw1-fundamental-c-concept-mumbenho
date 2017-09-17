#include <iostream>
#include "Collection.h"

using namespace std;

// Testing the Collection class
int main()
{
    // Make a collection of integers
    Collection<int> intCol;

    // Test the IsEmpty function
    if(intCol.IsEmpty())
    {
        cout << "The list is empty.\n";
    }
    else
    {
        cout << "The list is not empty\n" << endl;
    }

    // Test the Insert function
    intCol.Insert(3);
    intCol.Insert(3);
    intCol.Insert(4);
    intCol.Insert(5);
    intCol.Insert(5);
    intCol.Insert(6);
    intCol.Insert(7);
    intCol.Insert(8);

    intCol.Print();

    cout << "Collection now contains " << intCol.ListLength() << " items, IsEmpty() returns " << intCol.IsEmpty() << "\n";

    // Test Remove
    cout << "Removing items 3, 7, and 555 if they exist\n";
    intCol.Remove(3);
    intCol.Remove(7);
    intCol.Remove(555); // Should not change the collection

    intCol.Print();

    // Test RemoveRandom
    cout << "Removing a random item\n";
    intCol.RemoveRandom();
    intCol.Print();
    cout << "Removing 2 random items\n";
    intCol.RemoveRandom();
    intCol.RemoveRandom();
    intCol.Print();

    intCol.Insert(56);
    intCol.Insert(19);
    intCol.Insert(42);
    intCol.Print();

    cout << "NotContained(32) returns " << intCol.NotContained(32) << "\n";
    cout << "NotContained(42) returns " << intCol.NotContained(42) << "\n";

    // Test MakeEmpty
    cout << "Emptying the list.\n";
    intCol.MakeEmpty();
    intCol.Print();

    // Testing a collection of a different object type
    cout << "\nMaking a collection of strings\n";
    Collection<string> stringCol;

    stringCol.Insert("Dog");
    stringCol.Insert("Cat");
    stringCol.Insert("Apple");
    stringCol.Insert("zzzzzzzzzz");
    stringCol.Print();

    return 0;
}
