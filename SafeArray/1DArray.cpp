//Lab Task 6: Safe 1D Array with Bounds Validation
//Implement a safe 1D array in C++ that dynamically
//stores a user-specified number of integers. The
//program should ask the user for an index whenever
//they want to access or modify an element and must
//first validate whether that index is within the valid
//range. If the index is valid, perform the requested
//operation; otherwise, display an appropriate message
//instead of accessing memory outside the array.

#include <iostream>
using namespace std;

void access(int *arr,int index,int size)
{
	if(index<size && index>=0)
	{
		cout<<"Element At Index "<<index<<" is: "<<arr[index]<<endl;
	}
	else
	{
		cout<<"Bounds Error! No Element at Index "<<index<<endl;
	}
}

void modify(int *arr,int index,int size)
{
	if(index>=size || index<0)
	{
		cout<<"Bounds Error! No Element at Index "<<index<<endl;
		return;
	}
	
	int elem;
	
	cout<<"Enter New Value For Index "<<index<<" : ";
	cin>>elem;
	arr[index] = elem;
	
	cout<<"Array Element Successfuly Modified! \n";
}

int main()
{
	int size;
	
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
	
	//Menu based system
	int choice;
	do{
        cout << "\n=== Safe Array ===\n";
        cout << "1. Access\n";
        cout << "2. Modify\n";
        cout << "3. Exit\n";
        
        cout<<"Enter Your Operation Number: ";
        cin>>choice;
        int idx;
        
        switch(choice)
        {
        	case 1:
        		cout<<"Enter Index of Array to access (0 to "<<size-1<<"): ";
        		cin>>idx;
        		
        		access(array,idx,size);
        		break;
        		
        	case 2:
        		cout<<"Enter Index of Array to Modify (0 to "<<size-1<<"): ";
        		cin>>idx;
        		
        		modify(array,idx,size);
        		break;
        		
        	case 3:
        		cout<<"exiting...\n";
        		break;
        		
        	default:
        		cout<<"Invalid Operation Number!\n";
		}
	} while(choice!=3);
	
	delete[] array;
}