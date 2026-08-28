	//Lab Task 9: Dynamic Jagged Array with Row-Based Processing
	//Create a dynamic jagged array in which the user
	//specifies the number of rows and the size of every
	//row independently. After entering the values, display
	//the jagged array and perform row-wise analysis by
	//finding the maximum value of every row. In
	//addition, display the size of each row along with its
	//maximum value. Your program must use a pointer-
	//to-pointer structure, dynamically allocate each row
	//according to its individual size, traverse every row
	//using its own size, and correctly deallocate all
	//memory at the end. Be careful not to assume that all
	//rows have the same number of columns, because the
	//
	//defining feature of a jagged array is that each row
	//may have a different size.
	
	#include <iostream>
	using namespace std;
	
	int main()
	{
		int rows;
		
		cout<<"Enter Number of Rows: ";
		cin>>rows;
		
		int *size = new int[rows];
		
		int **arr = new int*[rows];
	
		for(int i = 0 ; i<rows;i++)
		{
			cout<<"Enter Column Size For Row "<<i+1<<" : ";
			cin>>size[i];
			
			arr[i] = new int[size[i]];
		}
		
		cout<<endl;
		
		cout<<"\n===Entering Elements====\n";	
		for(int i=0;i<rows;i++)
		{
			cout<<"\n===Row "<<i+1<<" ===\n";
			for(int j=0;j<size[i];j++)
			{
				cout<<"Enter Element "<<j+1<<" : ";
				cin>>arr[i][j];
				
			}
			cout<<endl;
		}
		
		cout<<endl;
		
		cout<<"\n===Display Elements====\n";	
		
		for(int i=0;i<rows;i++)
		{
			for(int j=0;j<size[i];j++)
			{
				cout<<arr[i][j] << " ";
				
			}
			cout<<endl;
		}
		
		cout<<endl;
		cout << "\n=== Row Summary ===\n";
		
		for(int i = 0 ; i<rows; i++)
		{
			int maximum= arr[i][0];
			for(int j=0; j<size[i];j++)
			{
				
				if(maximum<arr[i][j])
				{
					maximum = arr[i][j];
					
				}
			}
			
			cout<<"Size of Row "<<i+1<<" : "<<size[i]<<endl;
			cout<<"Maximum of Row "<<i+1<<" : "<<maximum<<endl;
		}
		
		for(int i=0; i<rows; i++)
		{
			delete[] arr[i];
		}
		
		delete[] arr;
		delete[] size;
	}