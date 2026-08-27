//  Create a C++ program using an array of  student objects containing Roll No., Name, and Marks. Sort the students using insertion sort based on their marks in descending order and display the sorted records.

#include <iostream>
using namespace std;

class Student
{
	private:
		int rollNo;
		string name;
		int marks;
		
	public:
		Student()
		{
			rollNo = 0;
			name = "";
			marks = 0;
			
		}
		
		Student(int r, string n , int m)
		{
			rollNo = r;
			name = n;
			marks = m;
		}
		
		void display()
		{
			cout<<"Roll Number: "<<rollNo<<endl;
			cout<<"Student Name: "<<name<<endl;
			cout<<"Student Marks: "<<marks<<endl;
		}
		
		int getMarks()
		{
			return marks;
		}
		
};

void insertionSort(Student s[],int size)
{
	//Insertion Sort Starts from first index 
	for(int i=1;i<size;i++)
	{
		Student key = s[i];
		
		int j = i-1;
		
		//j goes to the left by comparing itself with the key
		// If the current student marks are lesser than the key marks then shift the current student to the right
		while(j>=0 && s[j].getMarks() < key.getMarks() )
		{
			//Shift the smaller student to the right
			s[j+1] = s[j];
			j--; // go the left
		}
		
		//copy the key element to its correct position
		s[j+1] = key; 
		
		
	}
	
}
int main()
{
	int number,roll,marks;
	string name;
	cout<<"Enter Number of Students: ";
	cin>>number;
	
	Student *s = new Student[number];
	
	cout<<"\n===Student Information Input==\n";
	for(int i=0;i<number;i++)
	{
		cout<<"\n===Student "<<i+1<<" : ===\n";
		
		cout<<"Enter Roll Number: ";
		cin>> roll;
		
		cout<<"Enter Student Name: ";
		cin>>name;
		
		cout<<"Enter Student Marks: ";
		cin>>marks;
		
		cout<<endl;
		s[i] =  Student(roll,name,marks);
	}
	
	cout<<endl;
	
	cout<<"\n===Student Display (Before Sorting)===\n";
	for(int i=0;i<number;i++)
	{
		cout<<"\n===Student "<<i+1<<" : ====\n";
		s[i].display();
		
		cout<<endl;
		
	}
	
	insertionSort(s,number);
	cout<<"\n===Student Display (After Sorting)===\n";
	for(int i=0;i<number;i++)
	{
		cout<<"\n===Student "<<i+1<<" : ====\n";
		s[i].display();
		
		cout<<endl;
		
	}
	
	delete[] s;
	
}