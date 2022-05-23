//BY:
//1) Marwan Ashraf / 20200116
//2) Yasser Saad / 20200140
//3) Youssef Nassar / 20201133
//4) Ismail Elhussien / 20200092
//5) Ziad Ahmed/ 20200297

#include<iostream>
#include<cstring>
#include "PBQueue.cpp"
#include<cctype>

using namespace std;

int main(){
    //---------Test data-----///
    Queue queue;
    queue.enQueue("Ahmed","2912212");
    queue.enQueue("Bassel","21311231");
    queue.enQueue("Christine","122121321");
    queue.enQueue("David","2121031121");
    int choice;
    string name,phoneNumber;
    while(1)
    {
        // Entering a choice
        cout<<"Enter \n 1) Search a contact  \n 2) Create new contact\n 3) Update a contact\n 4) Delete a contact\n 5)Delete all contacts\n 6) Show all contacts \n 7) To exit the program\n";
        cin>>choice;
        if(choice == 1){
            // Search a contact
            cout<<"Enter the name of the contact: ";
            cin>>name;
            queue.search(name,queue,false);

        }
        else if(choice == 2){
            // Create new contact.
            cout<<"Please enter the name of the contact: ";
            cin>>name;
            cout<<"Please enter the phone number of the contact: ";
            cin>>phoneNumber;
            queue.enQueue(name,phoneNumber);
    
            cout<<"Contact has been added successfully\n";
        }
        else if(choice == 3){
            // Update a contact.
            cout<<"Please enter the name of the contact you want to update: ";
            cin>>name;
            queue.search(name,queue,true);
        }
        else if(choice == 4){
            // Delete a contact.
            cout<<"Please enter the name of the contact you want to delete: ";
            cin>>name;
            queue.remove(name,queue);
        }
        else if(choice == 5){
            // Deleting all contact.
            cout<<"Deleting all contacts......\n";
            queue.destroy();
            cout<<"Done"<<endl;
        }
        else if(choice == 6){
            // Display Queue.
            queue.displayQueue();
        }
        else{
            break;
        }
    }
    return 0;
}
