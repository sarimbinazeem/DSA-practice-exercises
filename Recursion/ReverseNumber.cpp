#include <iostream>
using namespace std;

int reverse(int n, int previous)
{
    if(n ==0 ) return previous;
    return reverse(n/10, previous*10 + n%10);

}
int main()
{
    int n;

    cout << "Enter a number: ";
    cin >> n;

    cout << "Reversed number: " << reverse(n, 0) << endl;

    return 0;
}