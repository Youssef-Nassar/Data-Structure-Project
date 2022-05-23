//BY:
//1) Marwan Ashraf / 20200116
//2) Yasser Saad / 20200140
//3) Youssef Nassar / 20201133
//4) Ismail Elhussien / 20200092
//5) Ziad Ahmed/ 20200297

#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
using namespace std;

struct contact
{
    string Name;
    string phoneNumber;
    contact *next;
};


//Queue
class Queue
{
    private:
         contact* front;
         contact* rear; 
         contact* temp;
         int size;
    public:
        Queue();
        void enQueue (string contactName, string contactPhoneNumber); 
        contact dequeue (); 
        void displayQueue(); 
        void search(string name, Queue queue, bool update);
        void remove(string name, Queue queue);
        bool isEmpty();
        void destroy();
};
Queue :: Queue()
{
    front = NULL;
    rear = NULL;
    size = 0;
}
void Queue ::  enQueue (string contactName , string contactPhoneNumber) 
{
        if (rear == NULL) 
        {
            rear = new contact;
            rear -> next = NULL;
            rear ->Name = contactName;
            rear -> phoneNumber = contactPhoneNumber;
            front = rear;
            size ++;
        }
        else 
        {
            temp = new contact;
            rear -> next = temp;
            temp -> Name = contactName;
            temp ->phoneNumber = contactPhoneNumber;
            temp -> next = NULL;
            rear = temp;
            size++;
        }
}
void Queue :: displayQueue()
{
        temp = front;
        if (isEmpty())
            cout<<"The phone book is empty"<<endl;
        else 
        {
            while (temp != NULL) 
            {
                cout<<temp -> Name << " Phone Number is: ";
                cout<<temp -> phoneNumber << endl;
                temp = temp -> next;
            }
            cout<<endl;
        }
}
 contact Queue :: dequeue()
{
        temp = front;
        contact deletedcontact;
        contact empty;
        if (isEmpty()){
            cout<<"Queue is empty!!" << endl;
            return empty;
        }
        
        else if (temp->next != NULL) 
        {
            temp = temp->next;
            deletedcontact = *front;
            size --;
            delete front;
            front = temp;
        }
        else 
        {
            deletedcontact = *front;
            size--;
            delete front;
            front = NULL;
            rear = NULL;
        }
        return deletedcontact;
}
// The boolean is to check if we want to search
// OR to update the number of the given name.
void Queue :: search(string name, Queue queue, bool update){
        int s = queue.size;
        Queue temQueue;
        contact searchContact;
        bool notfound;
        if (queue.isEmpty())
            cout<<"Phone book is empty"<<endl;
        else 
        {
            while (s--) 
            { 
                searchContact = queue.dequeue();
                string tempname= searchContact.Name;
                // Here we made both words lower to be sure that the search..
                // willn't be case sensitive.
                transform(name.begin(), name.end(), name.begin(), ::tolower);
                transform(tempname.begin(), tempname.end(), tempname.begin(), ::tolower);
                if(name.compare(tempname) == 0){
                    // If update equal true then we will update the contact
                    // with the new number
                    if(update){
                        string num;
                        cout<<"Enter the new number for "<<searchContact.Name<<" : ";
                        cin>>num;
                        searchContact.phoneNumber = num;
                        cout<<"\n The number has been successfully updated\n";
                        notfound = true;
                    }
                    // Then we will just traverse the desired contact.
                    else{
                        cout<<searchContact.Name<<" Phone Number is : "<<searchContact.phoneNumber;
                        notfound = true;
                    }
                }
               temQueue.enQueue(searchContact.Name,searchContact.phoneNumber); 
            }
            if(!notfound){
                cout<<"Sorry "<<name<<" not found in the phone book.";

            }
            int x = temQueue.size;
            while(x--){
                contact searched;
                searched = temQueue.dequeue();
                queue.enQueue(searched.Name,searched.phoneNumber);
            }
            cout<<endl;
        }
       
}
void Queue :: remove(string name, Queue queue){
    // Create a temporary queue.
    // then dequeue all the data from our main queue
    // checking if it's our desired data
    // then deleting it and puting it back to the main queue
        int s = queue.size;
        Queue temQueue;
        contact searchContact;
        if (isEmpty())
            cout<<"Phone book is empty"<<endl;
        else 
        {
            while (s--) 
            { 
                searchContact = queue.dequeue();    
                string tempname= searchContact.Name;
                transform(name.begin(), name.end(), name.begin(), ::tolower);
                transform(tempname.begin(), tempname.end(), tempname.begin(), ::tolower);
                if(name.compare(tempname) != 0){
                    temQueue.enQueue(searchContact.Name,searchContact.phoneNumber);
                }
            }
            
            int x  = temQueue.size;
            while(x--){
                contact searched;
                searched = temQueue.dequeue();
                queue.enQueue(searched.Name,searched.phoneNumber);
            }
        }
}
// Check whethter the queue is empty or not
bool Queue:: isEmpty(){
    if(front == NULL && rear == NULL) return true;
    else return false;
}
// Destroy the whole queue
void Queue :: destroy(){
        temp = front;
        if (isEmpty())
            cout<<"Phone book is empty"<<endl;
        else 
        {
            while (!isEmpty()) 
            {   
                dequeue();
                
            }
            cout<<endl;
        }
}
