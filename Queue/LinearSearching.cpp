#include <iostream>
using namespace std;

class Queue{
    private:
        int queue[100];
        int front;
        int rear;
        int count;

    public:
        Queue() {
            front = 0;
            rear = -1;
            count = 0;
        }

        void enqueue(int num){
            if(count == 99) {
                cout<<"Queue Full...\n";
                return;
            }
            rear = (rear + 1)%100;
            queue[rear]= num;
        }

        int dequeue(){
            if(count <= 0 ){
                cout<<"Queue is Empty...\n";
                return;
            }
            int temp = queue[front];
            front = (front+1)%100;
            return temp;
        }

        bool search(int target){
             for(int i = front ; i<= rear ; i++){
                if(queue[i] == target) return true;

             }
             return false;
        }
};


int main()
{
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);

    int target;

    cout << "Enter target: ";
    cin >> target;

    if (q.search(target))
        cout << "Found";
    else
        cout << "Not found";

    return 0;
}