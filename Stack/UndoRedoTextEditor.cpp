// You are building a very small text editor that only supports appending words to a document,
// but it still has to feel like a real editor when the user makes a mistake. Every time the user
// calls type(word), that word is appended to the end of the document. The user can call undo()
// at any time to reverse the most recent typing action, and redo() to bring back an action that
// was just undone. The catch is that once the user types something new after an undo, every
// action that could have been redone is permanently lost exactly like undo/redo works in a real
// editor such as Word or VS Code, you cannot redo into a history branch that no longer exists
// once new history has been written over it. For example, calling type(&quot;Hello&quot;) and then
// type(&quot;World&quot;) leaves the document as &quot;Hello World&quot;; calling undo() removes &quot;World&quot;,
// leaving &quot;Hello&quot;; calling redo() restores it to &quot;Hello World&quot;; calling undo() again returns to
// &quot;Hello&quot;; but if the user now calls type(&quot;There&quot;), the document becomes &quot;Hello There&quot; and
// any further call to redo() must do nothing, because the &quot;World&quot; branch of history has been
// erased by the new action.
// Your Task (C++): Implement this as a C++ class with type(string), undo(), redo(), and
// print() methods, using two stacks to manage the undo and redo history. Write a main() that
// reproduces the exact sequence of calls above and prints the document state after each call.

#include <iostream>
#include <string>
using namespace std;

const int SIZE = 100;

class TextEditor
{
    private:
        string undoStack[SIZE];
        string redoStack[SIZE];

        int undoTop;
        int redoTop;

    public:
        TextEditor()
        {
            undoTop = -1;
            redoTop = -1;
        }

        void type(string word)
        {
            //type in UNDOSTACK
            if(undoTop == SIZE -1 )
            {
             cout << "Undo stack is full!" << endl;
                return;
            }

            undoTop++;
            undoStack[undoTop] = word;

            //new word clears the redo history
            redoTop = -1;
        }

        void undo()
        {
            if(undoTop == -1)
            {
                cout<<"Nothing to undo! \n";
                return;
            }

            string word = undoStack[undoTop--];
            if(redoTop < SIZE -1 )
            {
                redoStack[++redoTop] = word;
            }
        }

        void redo()
        {
            if (redoTop == -1)
            {
                cout << "Nothing to redo!" << endl;
                return;
            }

            if (undoTop == SIZE - 1)
            {
                cout << "Undo stack is full!" << endl;
                return;
            }    
            
            string word = redoStack[redoTop--];
            undoStack[++undoTop] = word;
        }

         void print()
        {
            cout << "Document: ";

            for (int i = 0; i <= undoTop; i++)
            {
                cout << undoStack[i] << " ";
            }

            cout << endl;
        }
};

int main()
{
    TextEditor editor;

    editor.type("Hello");
    editor.print();

    editor.type("World");
    editor.print();

    editor.undo();
    editor.print();

    editor.redo();
    editor.print();

    editor.undo();
    editor.print();

    editor.type("There");
    editor.print();

    editor.redo();
    editor.print();

    return 0;
}