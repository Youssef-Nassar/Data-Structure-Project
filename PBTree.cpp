//BY:
//1) Marwan Ashraf / 20200116
//2) Yasser Saad / 20200140
//3) Youssef Nassar / 20201133
//4) Ismail Elhussien / 20200092
//5) Ziad Ahmed/ 20200297

#include <iostream>
#include<string>
using namespace std;

//This struct represent a single node which hold contact info
struct contact{
	string firstName;
	string lastName ;
	string number;
	contact *left;
	contact *right;
};


//________________________________(Class)________________________________
class Tree{
	public:
        struct contact *root = NULL ;
        Tree(){
        root=NULL;
        }

        contact* createNode(string firstName, string lastName, string number);
        contact* insertNode (contact *subRoot, contact *insertedNode);
        contact* search (string firstName, string lastName, contact *subRoot);
        void inorder(contact* subRoot);
        contact* deleteNode(string fName, string lName, struct contact* subRoot);
        contact* minValueNode(struct contact* node);
};




//________________________________(Functions)________________________________

//-----(Create a contact with its info)-----
contact* Tree :: createNode(string firstName, string lastName, string number){

    contact *createdNode = new contact;
    createdNode -> firstName = firstName;
    createdNode -> lastName = lastName;
    createdNode -> number = number;
    createdNode -> left = NULL;
    createdNode -> right = NULL;
    return createdNode;
}
	    
//-----(Insert a contact into the phonebook in order)-----
contact *Tree :: insertNode (contact *subRoot, contact *insertedNode){

    //if the Tree is empty then put the node as the root
    if (subRoot == NULL){
        subRoot = insertedNode;
    }

    //Compare With the first index from the firstName
    else if (subRoot->firstName[0] < insertedNode->firstName[0])
        subRoot->right = insertNode(subRoot->right, insertedNode);

	else if (subRoot->firstName[0] > insertedNode->firstName[0])
        subRoot->left = insertNode(subRoot->left, insertedNode);
	            
	else{
	    //Compare With the second index from the firstName
        if (subRoot->firstName[1] < insertedNode->firstName[1])
            subRoot->right = insertNode(subRoot->right, insertedNode);

        else if (subRoot->firstName[1] > insertedNode->firstName[1])
            subRoot->left = insertNode(subRoot->left, insertedNode);
            
        else{
            //Compare With the third index from the firstName
            if (subRoot->firstName[2] < insertedNode->firstName[2])
                subRoot->right = insertNode(subRoot->right, insertedNode);

            else if (subRoot->firstName[2] > insertedNode->firstName[2])
                subRoot->left = insertNode(subRoot->left, insertedNode);
            
            else 
                //Compare With the first index from the lastName
                if (subRoot->lastName[0] < insertedNode->lastName[0])
                    subRoot->right = insertNode(subRoot->right, insertedNode);

                else if (subRoot->lastName[0] > insertedNode->lastName[0])
                    subRoot->left = insertNode(subRoot->left, insertedNode);
        }
	}
	   
	return subRoot;
}

//-----(Insert a contact into the phonebook in order)-----
contact* Tree :: search (string firstName, string lastName, contact *subRoot){

    if( subRoot == NULL){
        cout<<"no contact found"<<endl;
        return subRoot;
    }
    
    else if (firstName == subRoot -> firstName || lastName == subRoot -> lastName)
        return subRoot ;
    
    else if(firstName[0] < subRoot -> firstName[0])
    return search (firstName, lastName, subRoot->left);

    else if(firstName[0] > subRoot -> firstName[0])
        return search (firstName, lastName, subRoot->right);
        
    else{

        if(firstName[1] < subRoot -> firstName[1])
            return search (firstName, lastName, subRoot->left);

        else if(firstName[1] > subRoot -> firstName[1])
            return search (firstName, lastName, subRoot->right);
            
        else{
            if(firstName[2] < subRoot -> firstName[2])
                return search (firstName, lastName, subRoot->left);

            else if(firstName[2] > subRoot -> firstName[2])
                return search (firstName, lastName, subRoot->right);
                
            else{
                if(lastName[0] < subRoot -> lastName[0])
                    return search (firstName, lastName, subRoot->left);

            else if(lastName[0] > subRoot -> lastName[0])
                    return search (firstName, lastName, subRoot->right);
            }       
        }
    }
    return subRoot;

}

//-----(Display contacts in the phonebook in alphabetic order)-----
void Tree :: inorder(contact* subRoot){
    if (subRoot != NULL) {
        inorder(subRoot->left);
        cout<<"Name : "<<subRoot->firstName<<" "<< subRoot->lastName<<endl;
        cout<<"Number : "<<subRoot->number<<endl<<endl;
        inorder(subRoot->right);
    }
}

//-----(Get the min value)-----
contact *Tree:: minValueNode(struct contact* node){
   struct contact* current = node;
   while (current && current->left != NULL)
      current = current->left;
   return current;
}

//-----(Delete Contact)-----
contact *Tree :: deleteNode(string fName, string lName,  contact* subRoot){
   if (subRoot == NULL) return root;
      if (fName < subRoot->firstName)
         subRoot->left = deleteNode(fName,lName,subRoot->left);
      else if (fName > subRoot->firstName)
         subRoot->right = deleteNode(fName,lName,subRoot->right);
   else{
      if (subRoot->left == NULL){
         struct contact *temp = subRoot->right;
         free(subRoot);
         return temp;
      }
      else if (subRoot->right == NULL){
         struct contact *temp = subRoot->left;
         free(subRoot);
         return temp;
      }
      contact* temp = minValueNode(subRoot->right);
      subRoot->firstName = temp->firstName;
      subRoot->right = deleteNode(temp->firstName,lName,subRoot->right);
   }
   return subRoot;
}
