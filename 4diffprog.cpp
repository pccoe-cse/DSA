

CODE 
#include<iostream> 
using namespace std; 
class node 
{ 
public: 
int data; 
node* next; 
public: 
node(int val) 
{ 
data = val; 
next = NULL; 
} 
~node() 
{ 
cout<< this->data <<" is deleted "<<endl; 
} 
}; 
class STACK 
{ 
public: 
node* top; 
public: 
STACK() 
{ 
top = NULL; 
} 
void push(); //insert at head in the linked list 
void pop(); //delete at head in the liked list 
void display(); //display the linked list starting from head 
};
2 

void STACK :: push() 
{ 
int val; 
cout<<"Enter the data "<<endl; 
cin>>val; 
node*n= new node(val); 
if(top == NULL) 
{ 
top= n; 
} 
else 
{ 
n->next= top; 
top= n; 
}
} 
void STACK :: display() 
{ 
node* temp= top; 
while(temp != NULL) 
{ 
cout<<temp->data<<" "; 
temp= temp->next; 
} 
cout<<"printing done "<<endl; 
} 
void STACK :: pop() 
{ 
node* temp= top; 
top= top->next; 
delete temp; 
} 
int main() 
{ 
STACK s1; 
int ch; 
A: 
cout<<"Enter the choice "<<endl;
 
Name : SUJIT SACHIN SHAHA 
Roll no. : SYCOD255 
PRN :- 122B1B255 
cout<<"1.push() \n2.pop() \n3.display()\n"<<endl; 
cin>>ch; 
switch (ch) 
{ 
case 1: 
s1.push(); 
break; 
case 2: 
s1.pop(); 
break; 
case 3: 
s1.display(); 
break; 
default: 
return 0; 
} 
goto A; 
} 
OUTPUT 
Enter the choice 
1.push() 
2.pop() 
3.display() 
1 
Enter the data 
25 
Enter the choice 
1.push() 
2.pop() 
3.display() 
1 
Enter the data 
99
 

Enter the choice 
1.push() 
2.pop() 
3.display() 
1 
Enter the data 
111 
Enter the choice 
1.push() 
2.pop() 
3.display() 
3
111 99 25 printing done 
Enter the choice 
1.push() 
2.pop() 
3.display() 
2
111 is deleted 
Enter the choice 
1.push() 
2.pop() 
3.display() 
3 
99 25 printing done 
Enter the choice 
1.push() 
2.pop() 
3.display() 
2 
99 is deleted 
Enter the choice 
1.push() 
2.pop() 
3.display() 
3 
25 printing done
 

// (Queue) 
#include<iostream> 
using namespace std; 
class Node 
{ 
public: 
int data; 
Node* prev; 
Node* next; 
public: 
Node(int val) 
{ 
data= val; 
} 
}; 
//adding the element to Que means insert AtTail 
void insert(Node* &front, Node* &rear) 
{ 
int val ; 
cout<<"Enter the value "<<endl; 
cin>>val; 
Node* node1= new Node(val); 
if(front == NULL) 
{ 
front= node1; 
rear= node1; 
} 
else // rear != NULL 
{ 
rear->next= node1; 
rear= node1; 
}
} 
void deleteElement(Node* &front, Node* &rear) 
{ 
if(front == NULL) 
{ 
cout<<"Underflow"<<endl; 
}

else //front != NULL 
{ 
Node* temp = front; 
front = front->next; 
delete temp; 
} 
} 
void display(Node* &front) 
{ 
Node* temp = front; 
while (temp != NULL) 
{ 
cout<<temp->data<<" -> "; 
temp = temp->next; 
} 
cout<<endl; 
} 
int main() 
{ 
Node* front = NULL; 
Node* rear = NULL; 
int ch; 
A: 
cout<<"Enter the choice \n1.insert an element \n2.delete an element \n3.Display the Que \n4.exit "<<endl; 
cin>>ch; 
switch (ch) 
{ 
case 1: 
insert(front, rear); 
break; 
case 2: 
deleteElement(front, rear ); 
break; 
case 3: 
display(front); 
break; 
default: 
return 0; 
}

goto A; 
} 
OUTPUT: 
Enter the choice 
1.insert an element 
2.delete an element 
3.Display the Queue 
4.exit 
1 
Enter the value 
55 
Enter the choice 
1.insert an element 
2.delete an element 
3.Display the Queue 
4.exit 
1 
Enter the value 
66 
Enter the choice 
1.insert an element 
2.delete an element 
3.Display the Queue 
4.exit 
1 
Enter the value 
99 
Enter the choice 
1.insert an element 
2.delete an element 
3.Display the Queue 
4.exit 
3 
55 66 99 
Enter the choice 
1.insert an element 
2.delete an element 
3.Display the Queue 
4.exit 
2 
Enter the choice 
1.insert an element

2.delete an element 
3.Display the Queue 
4.exit 
3 
66 99 
Enter the choice 
1.insert an element 
2.delete an element 
3.Display the Queue 
4.exit 
2 
Enter the choice 
1.insert an element 
2.delete an element 
3.Display the Queue 
4.exit 
3 
99 
Enter the choice 
1.insert an element 
2.delete an element 
3.Display the Queue 
4.exit 
4
