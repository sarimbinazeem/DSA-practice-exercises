//Lab Task 4: 2D Dynamic Array: Runtime Rows and Columns
//Develop a C++ program that asks the user to enter
//the number of rows and columns at runtime and
//creates a 2D dynamic array using pointers. Store
//user-provided integer values in the dynamically
//allocated matrix and display the complete matrix
//using nested loops. Then calculate and display the
//sum of all elements. Finally, correctly deallocate the
//dynamically allocated memory. Pay particular
//attention to allocating and releasing the memory for
//the rows and the complete structure correctly.

#include <iostream>
using namespace std;


int main()
{
	int rows, columns,sum =0;
	
	cout<<"Enter Rows: ";
	cin>>rows;
	
	cout<<"Enter Columns: ";
	cin>>columns;
	
	int **array = new int* [rows];
	
	for(int i=0;i<rows;i++)
	{
		array[i] = new int[columns];
	}
	
	cout<<"\n===Input The Value===\n";
	for(int i=0;i<rows;i++)
	{
		cout<<"\n===Row "<<i+1<<" ===\n";
		for(int j=0;j<columns;j++)
		{
			cout<<"Enter Value "<<j+1<<" : ";
			cin>>array[i][j];
		}
		
		cout<<endl;
	}
	
	cout<<"\n===Display The Value===\n";
	for(int i=0;i<rows;i++)
	{
		for(int j=0;j<columns;j++)
		{
			cout<<array[i][j]<<" ";
			sum+= array[i][j];
		}
		
		cout<<endl;
	}
	
	cout<<"\n===Sum Summary===\n";
	cout<<"Sum: "<<sum<<endl;
	
	for(int i=0;i<rows;i++)
	{
		delete[] array[i];
	}
	
	delete[] array;
	
}