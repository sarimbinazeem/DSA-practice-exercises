/*
You are building a sophisticated music playlist manager using a singly linked list where each node
contains a Song object. Your task is to implement a complete C++ program that can store songs
in a linked list and perform all fundamental operations—insertion at any position, deletion at any
position, and searching.
The Song class contains the song's title, genre (pop, rock, jazz, classical, or electronic), duration
in seconds, and a special Boolean flag indicating if the song contains explicit content.
Explicit songs are marked with the flag set to true. Explicit songs cannot be deleted directly. They
first require not to be explicit, then should be deleted.
Songs of the same genre cannot be placed next to each other in the playlist. When you try to insert
a song at a position where it would be adjacent to another song of the same genre, your

implementation must automatically find the next valid position where this genre conflict doesn't
occur.
The total duration of any three consecutive songs in the playlist cannot exceed 10 minutes
(600 seconds). When adding a new song, if placing it at the desired position would violate this
duration limit with its neighbors, your code must find an alternative position that maintains
balanced listening sessions.
Every time you perform 3 operations on the playlist (any combination of insert, delete, or search),
above constraints must be satisfied.
*/

#include <iostream>
#include <string>
using namespace std;

class Song
{
    public:
        string title;
        string genre;
        int duration; 
        bool explicitContent;

        Song()
        {
            title = "";
            genre = "";
            duration = 0;
            explicitContent = false;
        }
        Song(string t, string g, int d, bool exp)
        {
            title = t;
            genre = g;
            duration = d;
            explicitContent = exp;
        }
};

class Node
{
    public:
        Song data;
        Node*next;

        Node(Song s){
            data= s;
            next = nullptr;
        }
};

class Playlist
{
    public:
        Node*head;
        int operations;

        Playlist()
        {
            head = NULL;
            operations = 0;
        }
    
        int getSize()
        {
            int size = 0;
            Node*temp = head;
            while(temp != NULL)
            {
                size++;
                temp = temp->next;
            }
            return size;
        }

        //checking valid genre at a specific position insertion  according to constraint 
        bool checkGenre(Node* prev, Node*next, Song s)
        {
            if(prev != NULL)
            {
                if(prev->data.genre == s.genre ) return false;

            }
            if(next !=NULL)
            {
                if(next->data.genre == s.genre) return false;
            }
            return true;
        }
        
        //checking valid genre normally on list
        bool validGenre()
        {
            if(head == NULL) return true;

            Node*curr = head;
            while(curr->next != NULL)
            {
                if(curr->data.genre == curr->next->data.genre)
                {
                    return false;
                }
                curr = curr->next;
            }
            return true;

        }
        //constraint -> checking 3 consecutiv songs duration
        bool checkDuration()
        {
            //we check every 3 song group
            Node*first = head;

            while(first!= NULL && first->next != NULL && first->next->next != NULL)
            {
                Node*second = first->next;
                Node*third = first->next->next;

                int total = first->data.duration + second->data.duration + third->data.duration;
                if(total > 600) return false;

                first = first->next;
            }

            return true;
        }

        //check complete playlist
        bool checkPlaylist()
        {
            if(!validGenre()) return false;
            if(!checkDuration()) return false;
            return true;
        }

        //get node function
        Node* getNode(int pos)
        {
            Node*temp = head;
            for(int i =0; i<pos && temp!=NULL ; i++)
            {
                temp = temp->next;

            }
            return temp;
        }
        //if the songs in the playlist are'nt in the right position we swap them
        void repairPlaylist()
        {
            int size = getSize();

            for(int i=0 ;i<size ;i++)
            {
                for(int j=i+1; j<size;j++)
                {
                    //we swap the two nodes 
                    Node*first = getNode(i);
                    Node*second = getNode(j);
                    if(first == NULL || second == NULL)    return;

                    //we swap song data
                    Song temp = first->data;
                    first->data = second->data;
                    second->data = temp;
                    
                    //if the swapping gives invalid playlist, we swap back
                    if(checkPlaylist())
                    {
                        return; 
                    }
                    
                     temp = first->data;
                    first->data = second->data;
                    second->data = temp;

                }
            }
        }

    void operationDone()
    {
        operations++;

        cout << "Total Operations: " << operations << endl;

        // Constraint: After every 3 operations check the playlist
        if(operations == 3)
        {
            cout << "\n=== 3 Operations Completed ===\n";

            if(checkPlaylist())
            {
                cout << "Playlist Requirement already satisfied...\n";
            }
            else
            {
                cout << "Playlist Violates Requirement, Repairing It...\n";

                repairPlaylist();

                if(checkPlaylist())
                {
                    cout << "Playlist Repaired.\n";
                }
                else
                {
                    cout << "Playlist Did not Repair.\n";
                }
            }

            // Reset only after completing 3 operations
            operations = 0;

            cout << "Operations Counter Resetted.\n";
        }
    }

        //insert
        void insert(Song s, int pos)
        {
            int size = getSize();
            if(pos<0 || pos>size)
            {
                cout<<"Invalid Position..\n";
                return;
            }

            //we go from the given position, check if it is valid , if it is not we go move ahead
            int validPos = -1;
            for(int i =pos; i<=size; i++)
            {
                Node*previous = NULL;
                Node*curr = head;

                //to find nodes around node
                for(int j=0; j<i;j++)
                {
                    previous = curr;
                    curr = curr->next;
                }

                if(!checkGenre(previous,curr,s)) continue; //go to next iteration

                //we temporarliy add the node first then check if it is valid to add or not
                Node *temp = new Node(s);   
                //if at beginning
                if(previous == NULL)
                {
                    temp->next = head;
                    head = temp;
                }
                else
                {
                    temp->next = previous->next;
                    previous->next = temp;
                }

                //now check if it is valid
                if(checkPlaylist())
                {
                    validPos = i;
                    cout<<"Song Inserted at Index "<<i<<endl;
                    operationDone();
                    return;
                }

                //if the insertion is invalid the nremove the node
                if(previous == NULL )
                {
                    head = temp->next;
                }
                else{
                    previous->next = temp->next;
                }

                delete temp;
            }
            cout << "No valid position found.\n";
        }

        void remove(int pos)
        {
            int size = getSize();
            if(pos< 0 || pos>=size)
            {
                cout<<"Invalid Positin.\n";
                return;
            }

            Node*temp;
            Node*previous = NULL;

            if(pos == 0)
            {
                temp = head;
            }
            else{
                previous = head;
                for(int i =0 ;i<pos-1;i++)
                {
                    previous = previous->next;
                }
                temp = previous->next;
            }

            //temp have curr, previous have pre
            //checking EXPLICIT contne
            if(temp->data.explicitContent)
            {
                cout<<"SOng is explicit, Therefore turning the flag off..\n";
                temp->data.explicitContent = false;
            }

            //deleting
            if(pos==0)
            {
                head = temp->next;
            }
            else
            {
                previous->next = temp->next;

            }
            delete temp;
            cout<<"Song Deleted..\n";

            //if after deletion there is a constraint that is now invalid , we check
            if(!checkPlaylist())
            {
                cout<<"Deletion caused a constraint vioaltion..\n";
                cout<<"Repairing..\n";
                repairPlaylist();

                if(checkPlaylist())
                {
                    cout << "Playlist repaired successfully.\n";
                }
                else
                {
                    cout << "Playlist could not be repaired.\n";
                }
            }
            operationDone();
        }

            // SEARCH

    void search(string title)
    {
        Node* temp = head;

        int position = 0;

        while(temp != NULL)
        {
            if(temp->data.title == title)
            {
                cout << "\nSong found at position: "<<position<<"\n";

                cout << "Title: " << temp->data.title << endl;

                cout << "Genre: " << temp->data.genre << endl;

                cout << "Duration: "<< temp->data.duration<< " seconds\n";

                cout << "Explicit: "<< (temp->data.explicitContent? "Yes": "No")<< endl;

                operationDone();

                return;
            }

            temp = temp->next;
            position++;
        }


        cout << "Song not found.\n";

        operationDone();
    }

 void display()
    {
        if(head == NULL)
        {
            cout << "Playlist is empty.\n";
            return;
        }


        Node* temp = head;

        int position = 0;


        cout << "\n========== PLAYLIST ==========\n";


        while(temp != NULL)
        {
            cout << "\nPosition: "<< position << endl;

            cout << "Title: " << temp->data.title << endl;

            cout << "Genre: " << temp->data.genre << endl;

            cout << "Duration: "<< temp->data.duration<< " seconds\n";

            cout << "Explicit: "<< ((temp->data.explicitContent)? "Yes": "No") << endl;


            temp = temp->next;
            position++;
        }
    }

     ~Playlist()
    {
        Node* temp;

        while(head != NULL)
        {
            temp = head;
            head = head->next;

            delete temp;
        }
    }
};

int main()
{
    Playlist playlist;


    Song s1("Get Him Back!","pop",180,false);

    Song s2("Beat it","rock",150,false);

    Song s3("Cant help falling in love","jazz",120,true);

    Song s4("Sanskrit","classical",100,false);

    Song s5("Vampire","electronic",130,false);



    // INSERT SONGS
    
    playlist.insert(s1, 0);

    playlist.insert(s2, 1);

    playlist.insert(s3, 2);


    playlist.display();


    // SEARCH

    playlist.search("Beat it");


    
    // DELETE
    

    playlist.remove(2);


    playlist.display();


    // MORE INSERTION


    playlist.insert(s4, 1);

    playlist.insert(s5, 2);


    playlist.display();


    return 0;
}