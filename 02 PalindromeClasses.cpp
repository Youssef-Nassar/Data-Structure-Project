//BY:
//1) Marwan Ashraf / 20200116
//2) Yasser Saad / 20200140
//3) Youssef Nassar / 20201133
//4) Ismail Elhussien / 20200092
//5) Ziad Ahmed/ 20200297


#include<iostream>
using namespace std;

struct Node
{
    char data;
    Node *next;
};


//Queue
class Queue
{
    private:
         Node* front;
         Node* rear; 
         Node* temp;
    public:
        Queue();
        void enQueue (char val); 
        char dequeue (); 
        void displayQueue(); 
};
Queue :: Queue()
{
    front = NULL;
    rear = NULL;
}
void Queue ::  enQueue (char val) 
{
        if (rear == NULL) 
        {
            rear = new Node;
            rear -> next = NULL;
            rear -> data = val;
            front = rear;
        }
        else 
        {
            temp = new Node;
            rear -> next = temp;
            temp -> data = val;
            temp -> next = NULL;
            rear = temp;
        }
}

void Queue :: displayQueue()
{
        temp = front;
        if ((front == NULL) && (rear == NULL))
            cout<<"Queue is empty"<<endl;
        else 
        {
            while (temp != NULL) 
            {
                cout<<temp -> data << " ";
                temp = temp -> next;
            }
            cout<<endl;
        }
    }
char Queue :: dequeue ()
{
        temp = front;
        char deletedData;
        if (front == NULL)
        cout<<"Queue is empty!!" << endl;
        else if (temp->next != NULL) 
        {
            temp = temp->next;
            deletedData = front -> data;
            delete (front);
            front = temp;
        }
        else 
        {
            deletedData = front->data;
            delete (front);
            front = NULL;
            rear = NULL;
        }
        return deletedData;
    }



//Stack
class Stack 
{
    private:
        Node *top;
        Node *head;
        Node *temp;   
    public: 
        void push (char value);
        char pop ();
        void display();
};
void Stack :: push (char value)
{
        Node *newNode = new Node();
        newNode->data = value;
        newNode->next = top;
        top = newNode;
}
char Stack :: pop () 
{
    Node* deletedNode;

    deletedNode = top;

    char x = top->data;

    top = top->next;

    delete deletedNode;
    return x;

}
void Stack :: display()
{
    Node *temp;
    if(top == NULL)
    {
        cout<< "\n stack overflow";
    }
    else
    {
        cout<<"the stacK contains: \n";
        while(temp->next != NULL)
        {
            cout<<temp->data;
            temp = temp->next;
            cout<<"\n";
            
        }
    }
}
