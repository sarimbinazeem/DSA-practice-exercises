#include <iostream>
using namespace std;

const double RECTOR = 4.00;
const double DEAN = 3.5;

class Student
{
    public:
        int id;
        string name;
        string department;
        double CGPA;
};

void merge(Student arr[],int low, int mid ,int high)
{
    int i = low;
    int j = mid+1;
    int k = 0;
    int size = high - low + 1;

    Student *temp = new Student[size];

    while(i<= mid && j <= high)
    {
        if(arr[i].CGPA >= arr[j].CGPA){
            temp[k++] = arr[i];
            i++;
        }
        else{
            temp[k++] = arr[j];
            j++;
        }
    }

    //copy remaining
    while(i<=mid){
        temp[k++] = arr[i];
        i++;
    }

    while(j<=high)
    {
        temp[k++] = arr[j];
        j++;
    }

    //copy into original array
    for (int x = 0; x<size ; x++)
    {
        arr[low+x] = temp[x];
    }   
    delete[] temp; 
}

void mergeSort(Student arr[],int low,int high)
{
    if(low>=high){
        return;
    }

    int mid = low + (high-low)/2;

    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

string getAward(double cgpa)
{
    if (cgpa >= RECTOR)
    {
        return "Rector's List";
    }
    else if (cgpa >= DEAN)
    {
        return "Dean's List";
    }
    else
    {
        return "No Award";
    }
}
void display(Student arr[],int size)
{
    cout<<"\n=====FAST NUCES MERIT LIST=====\n";
    cout<<"Rank\tID\t\tName\t\t\tDepartment\t\tCGPA\t\tAward\n";
    int rank = 1;
    
    for(int i = 0 ; i<size; i++)
    {
        //increase rank if the cgpa differs
        if(i>0 && arr[i].CGPA != arr[i-1].CGPA)
        {
            rank = i+1;

        }
    
        cout << rank << "\t" << arr[i].id << "\t\t" << arr[i].name;
        if (arr[i].name.length() < 8) cout << "\t"; 
        
        cout << "\t\t" << arr[i].department << "\t\t" << arr[i].CGPA << "\t\t" << getAward(arr[i].CGPA) << "\n";
        
    }
}

int main()
{
    const int n = 30;

    // 30 sample student records
    Student students[n] =
    {
        {101, "Sarim", "CS", 3.92},
        {102, "Ahmed", "CS", 3.33},
        {103, "Aden", "CS", 3.25},
        {104, "Kamran", "SE", 3.20},
        {105, "Farhan", "CE", 3.00},
        {106, "Ayousha", "SE", 3.50},
        {107, "Nehal", "AI", 2.00},
        {108, "Hassan", "CS", 3.15},
        {109, "Ayan", "EE", 3.91},
        {110, "Hira", "CS", 3.35},
        {111, "Javaria", "CS", 3.25},
        {112, "Ayesha", "DS", 3.21},
        {113, "Hunza", "DS", 3.90},
        {114, "Mariam", "SE", 3.70},
        {115, "Usama", "CS", 2.75},
        {116, "Aina", "FT", 3.88},
        {117, "Hassan", "DS", 3.10},
        {118, "Amna", "SE", 3.75},
        {119, "Talha", "CS", 3.39},
        {120, "Zoya", "AI", 3.00},
        {121, "Kashif", "DS", 3.60},
        {122, "Areeba", "SE", 3.80},
        {123, "Abdullah", "CS", 3.25},
        {124, "Zuhair", "CS", 3.31},
        {125, "Omar", "CS", 3.75},
        {126, "Tehreem", "CS", 3.50},
        {127, "Shaheer", "CY", 3.12},
        {128, "Maaz", "CY", 3.67},
        {129, "Areeb", "CE", 2.43},
        {130, "Moosa", "CS", 1.75}
    };



    mergeSort(students, 0, n - 1);

    display(students, n);

    return 0;
}