//BY:
//1) Marwan Ashraf / 20200116
//2) Yasser Saad / 20200140
//3) Youssef Nassar / 20201133
//4) Ismail Elhussien / 20200092
//5) Ziad Ahmed/ 20200297

#include <iostream>
#include "06 PBTree.cpp"
#include <string>
using namespace std;

void thankyou(void);


int main()
{
    Tree pb;//Create a tree from classes called pb(PhoneBook)
    contact *temp, *root = pb.root;
    
    // -----(Test data)-----
    temp = pb.createNode ("Marwan","Ashraf","123");
    root = pb.insertNode (root, temp);
    temp = pb.createNode ("Ziad","Ahmed","456");
    root = pb.insertNode (root, temp);
    temp = pb.createNode  ("Yasser","Saad","789");
    root = pb.insertNode (root, temp);
    temp = pb.createNode  ("Ismail","Elhussin","147");
    root = pb.insertNode (root, temp);
    temp = pb.createNode  ("Youssef","Nassar","357");
    root = pb.insertNode (root, temp);
    
    int x;
    string fName, lName, number;

    //Menu
    while(1){

        //Main menu page
        cout<<"Welcome to the MAIN MENU :"<<endl;
        cout<<"1) Search \t 2) Insert \t 3) Update \t 4) Show Contacts \t 5) Delete Contact \a 6) EXIT"<<endl;
        cin >> x;

        if(x == 1){
            //Search page
            cout<<"Enter the first name : ";
            getline(cin,fName);
            cin>> x;
            cout<<"Enter the last name : ";
            getline(cin,lName);
            temp = pb.search(fName,lName,root);
            if(temp != NULL){
            cout<<"Name : "<<temp->firstName<<" "<< temp->lastName<<endl;
            cout<<"Number : "<<temp->number<<endl<<endl;
            delete temp;
            }
        }
        else if(x == 2){
            //Insert page
            cout<<"Enter the first name : ";
            getline(cin,fName);
            cout<<"Enter the last name : ";
            getline(cin,lName);
            cout<<"Enter the phone number : ";
            getline(cin,number);
            temp = pb.createNode(fName, lName, number);
            pb.insertNode(root, temp);
            delete temp;
        }
        else if(x == 3){
            //Update page
            cout<<"Enter the first name : ";
            getline(cin,fName);
            cout<<"Enter the last name : ";
            getline(cin,lName);
            temp = pb.search(fName,lName,root);
            cout<<"Enter the new number : ";
            getline(cin,number);
            temp->number = number;
            delete temp;
        }
        else if(x == 4){
            //Display page
            pb.inorder(root);
        }
        else if(x == 5){
            //Delete page
            cout<<"Enter the first name : ";
            getline(cin,fName);
            cout<<"Enter the last name : ";
            getline(cin,lName);
            temp = pb.search(fName,lName,root);
            pb.deleteNode(fName,lName,root);
        }
        else if(x == 6){
            //EXIT the program
            thankyou();
            break;
        }

    }
}


void thankyou(void)
{
cout<<"           _____ _           _                  \n";
cout<<"          |_   _| |_ ___ ___| |_    _ _ ___ _ _ \n";
cout<<"            | | |   | .'|   | '_|  | | | . | | |\n";
cout<<"            |_| |_|_|__,|_|_|_,_|  |_  |___|___|\n";
cout<<"                                   |___|        \n";
}
