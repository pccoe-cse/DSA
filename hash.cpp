 

Code 
#include<iostream> 
#include<string.h> 
usingnamespacestd; 
class employee { 
public: int Id; 
char name[20]; 
}; 
class HashTable{ 
private: employee s[10]; 
employee t; 
public : 
HashTable(); 
void accept(); 
void display(); 
void insert(); 
int hashfun(int id); 
void search(); 
};
HashTable :: HashTable(){ 
for (int i = 0; i < 10; i++) 
{ 
s[i].Id = -1; 
} 
}
void HashTable :: accept(){
cout<<"Enter the Name : "; 
cin>>t.name; 
cout<<"Enter the Employee ID : "; 
cin>>t.Id; 
insert(); 
} 
void HashTable ::display(){ 
int index,nindex; 
int j=0; 
for(int i=0;i<10;i++){ 
index =i; 
if (s[index].Id==-1) 
{ 
nindex = (index+1)%10; 
while (nindex!=index) 
{ 
if(s[nindex].Id==-1){ 
nindex = (nindex+1)%10; 
} 
else{ 
cout<<"The details of employee : "<<j+1<<endl; 
cout<<"The Name of employee : "<<s[nindex].name<<endl; 
cout<<"The Employee ID of employee : "<<s[nindex].Id<<endl; 
j++; 
break; 
} 
} 
i=nindex; 
} 
else{ 
cout<<"The details of employee : "<<j+1<<endl; 
cout<<"The Name of employee : "<<s[index].name<<endl;

cout<<"The Employee ID of employee : "<<s[index].Id<<endl; 
i=nindex; 
} 
j++; 
} 
} 
void HashTable::insert() 
{ 
int index,nindex; 
index =hashfun(t.Id); 
if (s[index].Id==-1) 
{ 
s[index].Id = t.Id; 
strcpy(s[index].name , t.name); 
} 
else{ 
nindex = (index+1)%10; 
while (nindex!=index) 
{ 
if(s[nindex].Id==-1){ 
s[nindex].Id = t.Id; 
strcpy(s[nindex].name , t.name); 
break; 
} 
else{ 
nindex = (nindex+1)%10; 
} 
} 
} 
} 
int HashTable::hashfun(int id) 
{ 
return id%10; 
}

void HashTable::search(){ 
int index,nindex,Id; 
cout<<"Enter the Id no you want to search : "; 
cin>>Id; 
int flag =1; 
index =hashfun(t.Id); 
if (s[index].Id==Id) 
{ 
cout<<"*************ROLL NUMBER FOUND************"<<endl; 
cout<<"Employee ID of employee is : "<<s[index].Id<<endl ; 
cout<<"Name of the employee is : "<<s[index].name<<endl; 
flag =0; 
} 
else{ 
nindex = (index+1)%10; 
while (nindex!=index) 
{ 
if(s[nindex].Id==Id){ 
cout<<"*************ROLL NUMBER FOUND************"<<endl; 
cout<<"Employee ID of employee is : "<<s[index].Id<<endl ; 
cout<<"Name of the employee is : "<<s[index].name<<endl; 
flag =0; 
break; 
} 
else{ 
nindex = (nindex+1)%10; 
} 
} 
if(flag==1){ 
cout<<"Element is not found"<<endl; 
} 
} 
} 
int main(){ 
HashTable s; 
int count =0,ch; 
while (count<10&&ch!=4) 
{ 
cout<<"Enter 1 for add employee \n 2 for displaying employees \n 3 for search\n4 for exit"; cout<<"Enter your choice : ";

cin>>ch; 
switch (ch) 
{ 
case 1: 
{ 
s.accept(); 
count++; 
} 
break; 
case 2 :{ 
s.display(); 
break; 
} 
case 3:{ 
s.search(); 
break; 
} 
case 4:{ 
cout<<"Thank you !!!!"; 
break; 
} 
default: 
cout<<"You entered wrong choice"; 
break; 
} 
} 
if(count==10){ 
cout<<"-----------------------------------------"; 
cout<<"Sorry but storage is full so printing the entered details"; 
s.display(); 
cout<<"----------------------------"; 
}

} 
OUTPUT 
Enter1foraddemployee 
2fordisplayingemployees 
3forsearch 
4forexitEnteryourchoice : 1 
EntertheName : sujit 
EntertheEmployee ID : 255678 
Enter1foraddemployee 
2fordisplayingemployees 
3forsearch 
4forexitEnteryourchoice : 1 
EntertheName : omkar 
EntertheEmployee ID : 258789 
Enter1foraddemployee 
2fordisplayingemployees 
3forsearch 
4forexitEnteryourchoice : 1 
EntertheName : Krushna 
EntertheEmployee ID : 249654 
Enter1foraddemployee 
2fordisplayingemployees 
3forsearch 
4forexitEnteryourchoice : 1 
EntertheName : Sameer 
EntertheEmployee ID : 251321 
Enter1foraddemployee 
2fordisplayingemployees 
3forsearch 
4forexitEnteryourchoice : 1 
EntertheName : Ashirwad 
EntertheEmployee ID : 133456 
Enter1foraddemployee 
2fordisplayingemployees 
3forsearch 
4forexitEnteryourchoice : 1 
EntertheName : Sahil 
Enter the Employee ID : 166156
7 
Enter1foraddemployee 
2fordisplayingemployees 
3forsearch 
4forexitEnteryourchoice : 1 
EntertheName : Akshay 
EntertheEmployee ID : 290357 
Enter1foraddemployee 
2fordisplayingemployees 
3forsearch 
4forexitEnteryourchoice : 3 
Enterthe Idnoyouwanttosearch : 255678 
*************ROLLNUMBERFOUND************ 
Employee IDofemployee is : 255678 
Nameoftheemployee is : Sujit 
Enter1foraddemployee 
2fordisplayingemployees 
3forsearch 
4forexitEnteryourchoice : 2 
Thedetailsofemployee : 1 
TheNameofemployee : Akshay 
TheEmployee IDofemployee : 290357 
Thedetailsofemployee : 2 
TheNameofemployee : Sameer 
TheEmployee IDofemployee : 251321 
Thedetailsofemployee : 3 
TheNameofemployee : Ashirwad 
TheEmployee IDofemployee : 133456 
Thedetailsofemployee : 4 
TheNameofemployee : Sujit 
TheEmployee IDofemployee : 255678 
Thedetailsofemployee : 5 
TheNameofemployee : Sahil 
The Employee ID of employee : 166156 
Thedetailsofemployee : 6 
TheNameofemployee : Omkar 
TheEmployee IDofemployee : 258789 
Thedetailsofemployee : 7 
TheNameofemployee : Krushna 
TheEmployee IDofemployee : 249654 
Enter1foraddemployee 
2fordisplayingemployees 
3forsearch 
4forexitEnteryourchoice :4 
Thankyou !!!
