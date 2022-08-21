#include <bits/stdc++.h>
using namespace std;

class BinarySearch
{
	// Intialising array 
	int *arr;

	// Size element
	int x;

	// Current indx;
	int y;

public:
	// Constructor : intialising size of the binary vector
	BinarySearch(int x)
	{	
		y = 0;
		this->x = x;
		arr = new int[x];
	}

	// Destructor
	~BinarySearch()
	{
		delete []arr;
	}

	// IF the input array given by the user is not sorted
	// in binary search we needed sorted array.
	// We are supposing this operation as a O(1) time complexity
	// As it is not using in our main algorithm.
	
	// Note - Indexing will change as it sorts the function.
	void helper()
	{
		if(y==x)
		{
			sort(arr,arr+x);
		}
	}

	// This function is used to input elements
	void inputElements(int ele)
	{	
		if(y < x)
		{
			arr[y++] = ele;
		}

		helper();
	}

	// This function is used to print the current array
	void printCurrentArray()
	{
		for(int i = 0 ; i < x ; i++)
			cout << arr[i] << " ";

		cout << endl;
	}

	// This function return the size of our array.
	int Size()
	{
		return x;
	}

	// main function of our binary search
	// this function will return the index of element
	// else it will return -1 if the element is not found
	// This algorithm is O(logN) time complexity.
	int searchElement(int ele)
	{
		int start = 0;
		int end = x - 1;

		while(start <= end)
		{
			int mid = start + (end - start)/2;

			if(arr[mid] == ele)
			{
				return mid;
			}
			else if(arr[mid] > ele)
			{
				end = mid -1;
			}else{
				start = mid + 1;
			}
		}

		return -1;
	}

	// This function returns the first occurence of the given element 
	// if not found then it returns -1
	int lowerBound(int num)
    {
        int start = 0;
        int end = x - 1;

        if(arr[0] == num)
            return 0;

        while(start <= end)
        {
            int mid = start + (end - start)/2;

            if(mid - 1 != -1 and arr[mid] == num and arr[mid-1] != num)
                return mid;
            else if(arr[mid] == num and arr[mid-1] == num || arr[mid] > num )
            {
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }

	    return -1;
    }
    
	// This function returns the last occurence of the given element 
	// if not found then it returns -1
    int upperBound(int num)
    {
        int start = 0;
        int end = x - 1;

        if(arr[x-1] == num)
            return x-1;

        while(start <= end)
        {
            int mid = start + (end - start)/2;

            if(mid + 1 != x and arr[mid] == num and arr[mid+1] != num)
                return mid;
            else if(arr[mid] == num and arr[mid+1] == num || arr[mid] < num )
            {
                start = mid + 1;
            }else{
                end = mid-1;
            }
        }

	    return -1;
    }
    
};

int main(int argc, char const *argv[])
{	
	int size ;
	cin >> size;

	BinarySearch b = BinarySearch(size);
	for(int i = 0 ; i < b.Size() ; i++)
	{
		int ele;
		cin >> ele;

		b.inputElements(ele);
	}

	b.printCurrentArray();

	cout <<"upperBound of element : ";
	int ub ;
	cin >> ub;
	cout << b.upperBound(ub);
	cout << endl;

	cout <<"lowerBound of element : ";
	int lb;
	cin >> lb;
	cout << b.lowerBound(lb);
	

	return 0;
}