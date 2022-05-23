//BY:
//1) Marwan Ashraf / 20200116
//2) Yasser Saad / 20200140
//3) Youssef Nassar / 20201133
//4) Ismail Elhussien / 20200092
//5) Ziad Ahmed/ 20200297


#include<iostream>
#include<cstring>
#include "PalindromeClasses.cpp"
#include<cctype>
using namespace std;

int main(){

    string line;
    int counter=0,s=0;
    cout<<"Enter a line: ";
    getline(cin,line);
    int size = line.length() ;
    Stack stack;
    Queue q;
    
    for(int i = 0; i < size; i++){
    		// We converted all characters into smaller case characters.
    		// To make the camporision valid for all test cases.
    		char c;
    		c = tolower(line[i]);
    		// Here we only inserted characters or numbers
    		// in the the stack and queue to avoid adding spaces or any special characters
    		// To reach an optimal solution for all test cases.
    		if(c>='a' && c <='z' || c >='0' && c<='9'){
        		// The counter to know the length of the line without special characters.
        		counter++;
        		stack.push(c);
        		q.enQueue(c);
    		}
  
		}

		int x =0;
		for(int i = 0; i < counter; i++){
    		// x to know then numbers of characters that have checked the condition.
    		if(stack.pop() == q.dequeue()) x++;
		}

		if(x == counter) cout<<"Palindrome";
		else cout<<"Not Palindrome";
		return 0;
}
