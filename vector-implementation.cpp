#include <iostream>
using namespace std;

// Using template so that it can work with any data type
template <class T>
class myVector	// Implementing Vector like class
{
	// Intialising an pointer that will point to our
	// vector in heap
	T *arr;

	// Capacity will tell us the total capacity of our vector
	int capacity;

	// totalElements will tell us the total element present in our vector
	int totalElements;

public:
	// Constructor
	myVector(int t = 0)
	{	
		// intialising an array at heap 
		// arr will point to that array
		if(t == 0){
			arr = new T[1];
			capacity = 1; 
			totalElements = 0;
		}else{ // User can pre define the capacity of vector
			arr = new T[t];
			capacity = t;
			totalElements = 0;
		}  
	}

	//	Copy Constructor
	myVector(const myVector &vec)
	{
		arr = vec.arr;
		capacity = vec.capacity;
		totalElements = vec.totalElements;
	} 

	// Destructor
	~myVector()
	{
		delete []arr;
	}

	void push(T ele)
	{
		if(totalElements == capacity)
		{
			T *temp = new T[2*capacity];

			// Copying old array element to new array
			for(int i = 0 ; i < capacity ; i++)
			{
				temp[i] = arr[i];
			}

			// Deleting old array from heap
			delete []arr;
			capacity *= 2; //Increasing the capacity
			arr = temp;
		}
		arr[totalElements] = ele;
		totalElements++;
	}

	// Inserting element at given position
	void push(T ele, int idx )
	{
		if(idx == capacity)
			push(ele);
		else{
			arr[idx] = ele;
			totalElements++;
		}
	}

	// getSize() will return the total elements present in the vector
	int getSize()
	{
		return totalElements;
	}

	// This function will return the total capacity
	int getCapacity()
	{
		return capacity;
	}

	//function to remove an element from end;
	void pop()
	{
		totalElements--;
	}

	// function to print the elements
	void print()
	{
		for(int i = 0 ; i < totalElements ;i++)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
	}

};

int main(int argc, char const *argv[])
{
	myVector<int> v;
	v.push(1);
	v.push(2);
	v.push(3);
	v.push(4);
	v.push(5);

	v.print();
	cout << "capacity : " << v.getCapacity() << endl;
	cout << "size : " << v.getSize() << endl;

	// Working with different datatype:-
	myVector<char> v1;
	v1.push(71);
	v1.push(72);
	v1.push(73);
	v1.push(74);
	v1.push(75);

	v1.print();
	cout << "capacity : " << v1.getCapacity() << endl;
	cout << "size : " << v1.getSize() << endl;

	// Trying different operations :-
	v1.push(79,5);
	v1.print();
	v1.pop();
	v1.pop();
	v1.print();

	// Using predefine size
	myVector<int> v2(4);
	cout << v2.getCapacity() << endl;
	cout << v2.getSize() << endl;
	v2.push(71);
	v2.push(72);
	v2.push(73);
	v2.push(74);
	v2.push(75);
	v2.print();
	cout << v2.getCapacity() << endl;

	// Using copyConstrutor
	myVector<int> v3 = v2;
	v3.print();
	
	return 0;
}