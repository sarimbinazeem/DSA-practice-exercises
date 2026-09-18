/*
You are developing an Emergency Room Game in which patients arrive at a hospital and wait to
be treated. Each patient has a unique Patient ID and a severity level, where 1 represents Critical,
2 represents Serious, and 3 represents Normal. Patients normally arrive and wait in the order in
which they enter the hospital; however, when the doctor is ready to treat a patient, a Critical patient
must always be treated before a Serious or Normal patient, and a Serious patient must always be
treated before a Normal patient. If two or more patients have the same severity level, the patient
who arrived first must be treated first.
The input consists of a sequence of ARRIVE ID SEVERITY and TREAT operations. When an
ARRIVE operation is encountered, the patient must be added to the appropriate queue, and when
a TREAT operation is encountered, the patient with the highest severity must be removed
according to the above rules. You are not allowed to use a priority queue; instead, implement
the solution using normal queues implemented with an array. You may use multiple queues to
maintain the required priority and FIFO order.

At the end, display the treatment order, the total number of patients treated, the total number of
patients remaining, and the number of Critical, Serious, and Normal patients still waiting. Do not
use STL queue, priority_queue, vector, deque, or any other built-in data structure.*/

#include <iostream>
#include <string>
#include <cctype>
using namespace std;

class Patient
{
    public:
        int id;
        int severity;

        Patient()
        {
            id = 0;
            severity = 0;
        }
        Patient(int ID, int sev)
        {
            id = ID;
            severity = sev;
        }
};

class Queue
{
    public:
        Patient array[100]; //we cap the limit to 100
        int front; 
        int rear;
        int count;

        Queue(){
            front = 0; //STARTING From the start
            rear = -1; // when we enqueu it moves forward to 0th index
            count = 0;
            
        }
        bool isEmpty()
        {
            return count == 0;
        }
        bool isFull()
        {
            return count == 100;
        }

        void enqueue(Patient p)
        {
            if(isFull())
            {
                cout<<"Queue is Full..\n";
                return;
            }

            rear = (rear+1)%100;
            array[rear] = p;
            count++;
        }

        Patient dequeue()
        {
            Patient temp;
            if(isEmpty())
            {
                return temp;
            }

            temp = array[front];
            front = (front+1) %100;
            count--;
            return temp;

        }

        int getSize()
        {
            return count;
        }
};

int main()
{
    int operations,totalTreated =0;
    int order[100];

    Queue criticial,serious, normal;
    
    cout<<"Enter Number of Operations: ";
    cin>>operations;

    for(int i=0;i<operations;i++)
    {
        string operation;
        cout<<"Enter Operation (ARRIVE or TREAT): ";
        cin>>operation;

        for(int i =0 ;i< operation.length() ; i++)
        {
            operation[i] = tolower(operation[i]);
        }

        if(operation == "arrive")
        {
            int id,severity;

            cout<<"Enter Patient ID: ";
            cin>>id;
            cout<<"Enter Patient Severity: ";
            cin>>severity;
            while(severity <1 || severity >3)
            {
                cout<<"Invalid Severity! Enter From (1 to 3): ";
                cin>>severity;
            }

            Patient p(id,severity);
            if(severity == 1)
            {
                criticial.enqueue(p);
            }
            else if(severity == 2)
            {
                serious.enqueue(p);
            }
            else
            {
                normal.enqueue(p);
            }
        }
        else if(operation == "treat")
        {
            Patient p;

            //we go from most important to least improtant
            if(!criticial.isEmpty())
            {
                p = criticial.dequeue();
            }
            else if(!serious.isEmpty())
            {
                 p = serious.dequeue();
            }
            else if(!normal.isEmpty())
            {
                p = normal.dequeue();
            }
            else
            {
                cout<<"All Patients are Treated! \n";
                continue;
            }
            order[totalTreated] = p.id;
            totalTreated++;
        }
        else{
            cout<<"Invalid Operation! \n";
        }
    }

    //final result
    int remainingCritical = criticial.getSize();
    int remainingSerious = serious.getSize();
    int remainingNormal = normal.getSize();

    int totalRemaining =remainingCritical +remainingSerious +remainingNormal;

    cout << "================FINAL RESULT================\n";
    cout<<"The Order of Treatment is: ";

    if(totalTreated == 0)
    {
        cout << "None";
    }
    else
    {
        for(int i = 0; i < totalTreated; i++)
        {
            cout << order[i];

            //to get arrow in between , but not at the end
            if(i < totalTreated - 1)
            {
                cout << " -> ";
            }
        }
    }

    cout << endl;


    cout << "Total Patients Treated: " << totalTreated << endl;


    cout << "Total Patients Remaining: "<< totalRemaining << endl;


    cout << "\nPatients Still Waiting:\n";

    cout << "Critical: " << remainingCritical << endl;

    cout << "Serious: "<< remainingSerious << endl;

    cout << "Normal: "<< remainingNormal << endl;


    return 0;
}