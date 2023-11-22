#include <iostream>
using namespace std;
class node
{
public:
int data;
node *left;
node *right;
node(int data);
~node();
};
node::node(int data = 0)
{
this->data = data;
left = NULL;
right = NULL;
}
node::~node()
{
cout << "Deleting node " << data << endl;
}
class BST
{
public:
node *root;

BST()
{

root = NULL;
}
node *insertbody(node *root, int data)
{
node *nn = new node(data);
if (root == NULL)
{
root = nn;
return root;
}
if (nn->data < root->data)
{
root->left = insertbody(root->left, data);
}
else
{
root->right = insertbody(root->right, data);
}
return root;
}
void insert(int data)
{
root = insertbody(root, data);
}
void inOrder(node *root)
{
if (root == NULL)
{
return;
}
inOrder(root->left);
cout << root->data << " ";
inOrder(root->right);
}
void display()
{

inOrder(root);
cout << endl;
}
void Delete(node* root,int data)
{
node *temp = root;
node *par = NULL;
while (temp->data != data && temp != NULL)
{
cout<<"s"<<endl;
par = temp;
if (temp->data < data)
{
temp = temp->right;
}
else
{
temp = temp->left;
}
}
if (temp == NULL)
{
cout << "Data is not pesent in the tree" << endl;
}
else if (temp->left == NULL)
{
if (par->left == temp)
{
par->left = temp->right;
}
else
{
par->right = temp->right;
}
}
else if (temp->right == NULL)
{
if (par->left == temp)
{
par->left = temp->left;

}
else
{
par->right = temp->left;
}
}
else
{
node *succ = temp->right,*succpar = NULL;
while (succ->left != NULL)
{
succpar = succ;
succ = succ->left;
}
int t = temp->data;
cout<<succ->data<<endl;
temp->data = succ->data;
succ->data = t;
cout<<succ->data<<endl;
if(succpar==NULL)
{temp->right = temp->right->right;}
else
succpar->left = NULL;
}
}
};
int main()
{
BST bst;
int choice;
do
{
cout << "1. Insert\n";
cout << "2. Display\n";
cout << "3. Exit\n";
cout << "\nEnter your Choice: \t";
cin >> choice;
switch (choice)
{

case 1:
{
int x;
cout << "enter the number to be inserted:";
cin >> x;
bst.insert(x);
}
break;
case 2:
{
cout << "\nthe elements of binary search tree are:\n";
bst.display();
}
break;
case 3:
cout<<"Enter the data you want to delete : ";
int data;
cin>>data;
bst.Delete(bst.root,data);
bst.display();
break;
case 4:
cout << "Thank you!!!!" << endl;
break;
default:
cout << "Invalid Choice" << endl;
break;
}
} while (choice != 4);
return 0;
}