#include <iostream>
using namespace std;

int getMax(int arr[],int  size)
{
    int max = arr[0];
    for(int i=1; i<size;i++){
        if(arr[i] > max)
        {
            max = arr[i];
        }
    }

    return max;
}

void CountSort(int arr[], int size, int div)
{
    //div is the number that is to be divided (ones, tens, hundreds)
    int output[size]; //output array
    int count[10] = {0};  //this is the array that counts the digits (0-9)

    //now we count the digits
    for(int i =0 ;i<size ; i++)
    {
        //we extract that digit and increment that index
        count[(arr[i] /div) %10]++;
    }   

    //we then find the actual index of the elements according to their occurances
    //if 1 exists 2 times and 2 exits 1 time 
    //then 1 exists till 1 index (2-1), and 2 exits till 2 index(3-1)
    for(int i=1; i<10; i++)
    {
        count[i] += count[i-1];
    }

    //we go reverse and put the elemnts according to their occruances
    for(int i = size-1; i>=0 ;i--)
    {
        //-1 is for the index so we put the element on the right position
        output[count[(arr[i]/div)%10] -1] = arr[i];
        count[(arr[i]/div)%10]--; //we decrease the occurance
    }

    //copy into array
    for (int i = 0; i < size; i++){
        arr[i] = output[i]; 
    }
}

void RadixSort(int arr[], int size) 
{ 
    int m = getMax(arr, size); 
    //the div starts from one then ten then hundereds
    for (int div = 1; m/div > 0; div *= 10) 
    {
        CountSort(arr, size, div); 

    }
} 

int main() 
{ 
	int size;
	cout<<"Enter the size of the array: "<<endl;
	cin>>size;
	int arr[size];
	cout<<"Enter "<<size<<" integers in any order"<<endl;
	for(int i=0;i<size;i++)
	{
		cin>>arr[i];
	}
   cout<<endl<<"Before Sorting: "<<endl;
   for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	}
	
	RadixSort(arr, size); 
   
	cout<<endl<<"After Sorting: "<<endl;
   for(int i=0;i<size;i++)
	{
		cout<<arr[i]<<" ";
	} 
    
    return 0; 
}