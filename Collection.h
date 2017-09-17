#ifndef COLLECTION_H
#define COLLECTION_H

#include <stdlib.h>
#include <iostream>
using std::cout;

#define MAX_SIZE 50

template <typename objType>
class Collection
{
    public:
        Collection();
        ~Collection();
        bool IsEmpty();
        bool IsFull();
        void MakeEmpty();
        bool Insert(objType obj);
        bool Remove(objType obj);
        bool RemoveRandom();
        bool NotContained(objType obj);
        int ListLength();
        void Print(void);
    protected:

    private:
        int head;
        objType theList[MAX_SIZE];
};

#endif // COLLECTION_H

// Creates an empty collection
template <typename objType>
Collection<objType>::Collection()
{
    head = -1;
}

// Destructor
template <typename objType>
Collection<objType>::~Collection()
{

}


// Return whether or not the head is -1
// If the head is -1, the list is empty
template <typename objType>
bool Collection<objType>::IsEmpty()
{
    return (head == -1);
}

// Return whether or not the head is at
// the last possible index (head - 1). If it is,
// the collection is full
template <typename objType>
bool Collection<objType>::IsFull()
{
    return (head == MAX_SIZE - 1);
}

// Reset the head of the collection to (sort of)
// empty the collection
template <typename objType>
void Collection<objType>::MakeEmpty()
{
    head = -1;
}

// Inserts the given object to the
// end of the collection
template <typename objType>
bool Collection<objType>::Insert(objType obj)
{
    if(!IsFull())
    {
        head++;
        theList[head] = obj;
        return true;
    }
    return false;
}

// Removes the first matching object
// found and shifts the objects after it
// to the previous index to avoid gaps
// in the collection
// Returns true if an object was removed
template <typename objType>
bool Collection<objType>::Remove(objType obj)
{
    for(int i = 0; i < ListLength(); i++)
    {
        if(obj == theList[i])
        {
            for(int j = i; j < ListLength(); j++)
            {
                theList[j] = theList[j+1];
            }

            head--;
            return true;
        }
    }

    return false;
}

// Removes some object in the collection
// via the Remove(obj) function
template <typename objType>
bool Collection<objType>::RemoveRandom()
{
    int randomIndex = rand() % ListLength();
    return Remove(theList[randomIndex]);
}

// Returns whether or not the given object
// exists within the collection
template <typename objType>
bool Collection<objType>::NotContained(objType obj)
{
    for(int i = 0; i < ListLength(); i++)
    {
        if(obj == theList[i])
        {
            return false;
        }
    }

    return true;
}

// Returns the number of items the collection
// currently holds
template <typename objType>
int Collection<objType>::ListLength()
{
    return (head + 1);
}

// Print the contents of the container
template <typename objType>
void Collection<objType>::Print()
{
    cout << "Collection Contains: ";
    if(IsEmpty())
    {
        cout << "\n";
    }
    for(int i = 0; i < ListLength(); i++)
    {
        if( i < ListLength() - 1)
        {
            cout << theList[i] << ", ";
        }
        else
        {
            cout << theList[i] << "\n";
        }
    }
}
