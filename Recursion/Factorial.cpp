#include <iostream>
using namespace std;

int factorial(int number, int previous)
{
    if(number==0) return 1;

    return factorial(number-1,previous *number);
}

int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Factorial: " << factorial(n,1) << endl;

    return 0;
}