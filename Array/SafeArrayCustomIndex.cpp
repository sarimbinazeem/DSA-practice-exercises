// Lab Task 7: Safe Array with Custom Index Range
// Create a C++ safe array that allows the user to
// specify both the size of the array and a custom
// starting index. For example, the user may choose an
// index range beginning at -5 rather than the normal 0.
// The program should allocate the required memory
// dynamically, accept values according to the selected
// index range, display the values with their
// corresponding indexes, and validate every access
// before reading or modifying an element. Any index
// outside the defined range must be rejected safely.

#include  <iostream>
using namespace std;

void access(int *arr, int idx, int start, int size)
{
	
	int end = start + size;
	if(idx >=start && idx< end)
	{
		int index = idx - start;
		cout<<"Element Accessed At Index "<<idx<<" : "<<arr[index]<<endl;
	}
	else{
		cout<<"Index Out Of Bounds!\n";
		return;
	}
}

void modify(int*arr,int idx, int start, int size)
{
	int end = start + size ;
	if(idx<start || idx>=end )
	{
		cout<<"Index Out of Bounds!\n";
		return;
	}
	int val;
	
	cout<<"Enter Value To Replace: ";
	cin>>val;
	
	int index = idx - start;
	
	arr[index] = val;
}

int main()
{
	int size,start;
	
	cout<<"Enter Size of Array: ";
	cin>>size;
	
	cout<<"Enter Starting Index: ";
	cin>>start;
	
	int *array = new int[size];
	
	int end = start + size - 1;
	
	cout<<"\n===Input Element====\n";
	for(int i=0;i<size;i++)
	{
		int customIdx = start + i;
		
		cout<<"Enter Value for Index "<<customIdx<<" : ";
		cin>>array[i];
	}
	
    cout << "\n=== Display Array ===\n";

    for (int i = 0; i < size; i++)
    {
        int customIndex = start + i;

        cout << "Index " << customIndex << " : " << array[i] << endl;
    }
    
    int choice;
    do{
        cout << "\n=== Safe Custom Index Array ===\n";
        cout << "1. Access Element\n";
        cout << "2. Modify Element\n";
        cout << "3. Exit\n";
		
        cout << "Enter Your Choice: ";
        cin >> choice;
        
        int index;
        
        switch(choice)
        {
        	case 1:
        		cout<<"Enter Index To Access from ("<<start<<" to "<<end<<" ): ";
        		
        		cin>>index;
        		
        		access(array,index,start,size);
        		break;
        		
        	case 2:
        		cout<<"Enter Index To Modify from ("<<start<<" to "<<end<<" ): ";
        		
        		cin>>index;
        		
        		modify(array,index,start,size);
        		break;
        		
            case 3:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid Operation Entered!\n";
        		
		}
	}while(choice!=3);
	
	delete[] array;
	return 0;
}