//Lab Task 3: 1D Dynamic Array Using Pointers
//Write a C++ program that asks the user for the size
//of a 1D array at runtime and then dynamically
//allocates the required memory using a pointer and
//
//the new operator. Take the elements from the user,
//display them with their indexes, and calculate the
//sum of all elements. After completing the
//operations, properly release the dynamically
//allocated memory using delete[].

#include <iostream>
using namespace std;

int main()
{
	int size;
	int sum=0;
	
	cout<<"Enter Size of Array: ";
	cin>>size;
	
	int *array = new int[size];
	
	cout<<"\n===Input Elements===\n";
	for(int i=0; i<size; i++)
	{
		cout<<"Enter Element "<<i+1<<": ";
		cin>>array[i];
		cout<<endl;
	}
	
	cout<<"\n===Display Elements===\n";
	for(int i=0; i<size; i++)
	{
		cout<<"Element "<<i<<" : "<<array[i]<<endl;
		sum +=array[i];
	}
	
	cout<<"\n===Array Summary===\n";
	cout<<"Sum Of Array: "<<sum<<endl;
	delete[] array;
	
	
	
}