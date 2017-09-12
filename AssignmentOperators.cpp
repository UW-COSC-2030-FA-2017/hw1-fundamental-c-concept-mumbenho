// Assignment Operators.cpp
// McKade Umbenhower
// COSC 2030
// 9-12-17
// A simple example showing copy and move assignment operators

#include <utility>

struct MoveExample
{
	// Create an object with some kind of data
	int data;

	// Constructor used to make objects with different data
	// Default the data value to 3 for this example
	MoveExample(int a=3) : data( a ) {}

	// Create a move assignment operator that move-assigns 'data' from
	// one object to another
	MoveExample& operator=(MoveExample&& other)
	{
		data = std::move(other.data);
		return *this;
	}
};

int main()
{
	int a, b = 5;		// Create a and b, and assign 5 to b
	a = b;				// Using the copy assignment operator to set a equal to b

	MoveExample X;		// Create a MoveExample object where data is defaulted to 3
	X = MoveExample(4);	// Move-assign X to some temporary object of the same type, but with data equal to 4

	return 0;
}