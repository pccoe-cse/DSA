
CODE 
#include<iostream> 
usingnamespacestd; 
class node 
{
public: 
char ch; 
node *next; 
node(char ch) 
{
this->ch = ch; 
next = NULL; 
} 
};
class stack 
{
public: 
node *top; 
stack() 
{
top = NULL; 
}
void push(charch) 
{
node*nn=newnode(ch); 
nn->next = top; 
top = nn; 
}
void pop(){


if (top == NULL) 
{
cout<<"STACKUNDERFLOW !!!!!"; 
return; 
}
node* temp = top; 
top = top->next; 
delete temp; 
}
char Top(){ 
return top->ch; 
} 
};
intprec(charch){ 
if (ch=='*'||ch=='/') 
{
return2; 
}
else if (ch== '+'||ch=='-') 
{
return1; 
}
else if (ch== '^') 
{
return3; 
}
else 
{
return 0; 
} 
}
intmain() 
{
stringexp; 
cout<<"Enteryourexpression"; 
cin>>exp; 
stack st; 
char ans[50] = ""; 
int j = 0; 
for (int i = 0; i < exp.length(); i++) 
{
charch=exp[i]; 
if (ch=='(') 
{
st.push('('); 
continue; 
}
else if (ch == ')') 
{
while (st.Top()!='(') 
{ 
ans[j] = ch; 
j++; 
st.pop(); 
}
st.pop(); //toremove( 
continue; 
}
int prece=prec(ch); 
if (prece==0) 
{
ans[j] = ch; 
j++; 
continue; 
}
else{ 
while (st.top!=NULL&&prece<=prec(st.Top())) 
{ 
ans[j]=st.Top(); 
j++; 
st.pop(); 
}


st.push(ch); 
} 
} 
ans[j]=='\0'; 
char c = ans[0]; 
int i=0; 
while(c!='\0'){ 
cout<<ans[i]; 
i++; 
c = ans[i]; 
} 
return 0; 
} 
OUTPUT 
Enter your expression a+b*c-d 
abc*+d 
Enter your expression(A+B) 
AB+ 
Enter your expressionA^B+C 
AB^C+
