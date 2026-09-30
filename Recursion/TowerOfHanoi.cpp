#include <iostream>
using namespace std;

void towerOfHanoi(int count,char source,char aux, char dest)
{
    if(count == 1){
        cout<<source<<" -> "<<dest<<endl;
        return;
    }

    towerOfHanoi(count-1, source, dest, aux);
    cout<<source<<" -> "<<dest<<endl;
    towerOfHanoi(count-1, aux, source, dest);
}

int main()
{
    int count;

    cout << "Enter number of disks: ";
    cin >> count;

    towerOfHanoi(count, 'A', 'B', 'C');

    return 0;
}