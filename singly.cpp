



#include<iostream>
using namespace std;


class student{
public:
  int roll;
  float per;
  student *next;
};


class linkedlist{
 private: student *head;


 public: linkedlist(){
  head = NULL;
 }


 student* getdata(){


  student *t = new student();
  cout<<"Enter the roll no: ";
  cin>>t->roll;
  cout<<"Enter the percentage : ";
  cin>>t->per;
  t->next =NULL;
 return t;
 }
 void addNew(){


  student *nn = getdata();
  if (head == NULL)
  {
      head = nn;
  }
  else{
      student *temp = head;
      while (temp->next!=NULL)
      {
          temp = temp->next;
      }
      temp->next= nn;
    
  }
  }


void display(){
      student *temp = head;
      while (temp!=NULL)
      {
          cout<<"*******************"<<endl;
          cout<<"the roll no: "<<temp->roll<<endl;
          cout<<"the percentage : "<<temp->per<<endl;
          cout<<"*******************"<<endl;
          temp = temp->next;
      }
 }


 void search(int rollno){
      student *temp = head;
      while (temp!=NULL)
      {
        
          if(temp->roll==rollno){
          cout<<"*******************"<<endl;
          cout<<"Details of student is"<<endl;
          cout<<"the roll no: "<<temp->roll<<endl;
          cout<<"the percentage : "<<temp->per<<endl;
          cout<<"*******************"<<endl;
          break;
          }
           temp = temp->next;
      }
 }


 void cut(){
  int rollno;
  cout<<"Enter the roll no which you want to delete";
  cin>>rollno;
   student *temp = head;
      while (temp->next!=NULL)
      {
        
          if((temp->next)->roll==rollno){
              cout<<"****************"<<endl;
              cout<<"Deleting roll no "<<(temp->next)->roll<<endl;
              student *t = temp->next;
               temp->next= (temp->next)->next;
               delete t;
             
               break;
          }
          temp = temp->next;
         
      }
 }

 void deletehead(){
   student* temp = head;
   head = head->next;
   delete temp;
 }

void disprev(student *temp){
   if(temp->next!=NULL)
   disprev(temp->next);

   cout<<temp->roll<<" "<<temp->per<<endl;
}
void inserthead(){

   student *nn = getdata();
   nn->next = head;
   head =nn;

}

void reverse(){
   disprev(head);
}

void insertMiddle(){
   int position = 1;
  cout<<"Enter the position at which you want to insert : ";
  cin>>position;
   student *nn = getdata();
   student *temp = head;
   if(position==1){
       inserthead();
   }
   int cnt =2;
      while (temp->next!=NULL&&cnt<position)
         {
          temp = temp->next;
          cnt++;
         }
     nn->next = temp->next;
     temp->next = nn;
     display();

     
}




};




int main(){


  linkedlist ll;
  int ch;
  do
  {
      cout<<"Enter the 1 to add 2 to display 3 to search and 4 to delete 5 to exit:  ";
      cin>>ch;
      switch (ch)
      {
      case 1:
      int choice;

          do
          {
           cout<<"Enter the 1 for insertion at end 2 for insertion at begining and 3 for insertion at position 4 for exit"<<endl;
           cout<<"Enter your choice : ";
           cin>>choice;
           switch (choice)
           {
           case 1:
               ll.addNew();
               break;
           case 2:
               ll.inserthead();
               break;
           case 3:
               ll.insertMiddle();
           break;
           case 4 : cout<<"*******************"<<endl;
                   cout<<"Element successfully added"<<endl;
                   break;
           default:
               break;
           }
          } while (choice!=4);
         
        
          break;


      case 2:
          ll.display();
          break;
    
      case 3:int rollno;
      cout<<"Enter the roll no you want to search : ";
      cin>>rollno;
          ll.search(rollno);
          break;
    
      case 4: ll.cut();
      ll.display();
      break;
    
      case 5:
          cout<<"*******************"<<endl;
          cout<<"Thank YOu!!!"<<endl;
          break;
      default:
      cout<<"You entered wrong choice...."<<endl;
          break;
      }
  } while (ch!=5);




  return 0;
 }








OUTPUT


Enter the 1 to add 2 to display 3 to search and 4 to delete 5 to exit:  1
Enter the 1 for insertion at end 2 for insertion at begining and 3 for insertion at position 4 for exit
Enter your choice : 1
Enter the roll no: 255
Enter the percentage : 99
Enter the 1 for insertion at end 2 for insertion at begining and 3 for insertion at position 4 for exit
Enter your choice : 2
Enter the roll no: 258
Enter the percentage : 99
Enter the 1 for insertion at end 2 for insertion at begining and 3 for insertion at position 4 for exit
Enter your choice : 33
Enter the 1 for insertion at end 2 for insertion at begining and 3 for insertion at position 4 for exit
Enter your choice : 3
Enter the position at which you want to insert : 2
Enter the roll no: 249
Enter the percentage : 99
*******************
the roll no: 258
the percentage : 99
*******************
*******************
the roll no: 249
the percentage : 99
*******************
*******************
the roll no: 255
the percentage : 99
*******************
Enter the 1 for insertion at end 2 for insertion at begining and 3 for insertion at position 4 for exit
Enter your choice : 4
*******************
Element successfully added
Enter the 1 to add 2 to display 3 to search and 4 to delete 5 to exit:  3
Enter the roll no you want to search : 255
*******************
Details of student is
the roll no: 255
the percentage : 99
*******************
Enter the 1 to add 2 to display 3 to search and 4 to delete 5 to exit:  4
Enter the roll no which you want to delete258
*******************
the roll no: 249
the percentage : 99
*******************
*******************
the roll no: 255
the percentage : 99
*******************
Enter the 1 to add 2 to display 3 to search and 4 to delete 5 to exit:  2
*******************
the roll no: 249
the percentage : 99
*******************
*******************
the roll no: 255
the percentage : 99
*******************
Enter the 1 to add 2 to display 3 to search and 4 to delete 5 to exit:  5
*******************
Thank You!!!


