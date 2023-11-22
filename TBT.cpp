CODE 
#include <iostream> 
using namespace std; 
class node 
{ 
public: 
int data; 
node *left, *right; 
int lth, rth; 
node(int n) 
{ 
data = n; 
lth = 1; 
rth = 1; 
} 
}; 
class TBT 
{ 
public: 
node *root; 
TBT() 
{ 
root = NULL; 
} 
void insert(int n) 
{ 
node *nn = new node(n); 
if (root == NULL) 
{ 
root = nn; 
}
else 
{ 
node *temp = root; 
while (true) 
{ 
if (n < temp->data) 
{ 
if (temp->lth == 0) 
{ 
temp = temp->left; 
} 
else 
{ 
nn->left = temp->left; 
nn->right = temp; 
temp->lth = 0; 
temp->left = nn; 
break; 
} 
} 
else if (n > temp->data) 
{ 
if (temp->rth == 0) 
{ 
temp = temp->right; 
} 
else 
{ 
nn->right = temp->right; 
nn->left = temp; 
temp->rth = 0; 
temp->right = nn; 
break; 
} 
} 
else 
{ 
break; 
} 
}
} 
} 
node *inorderSuccessor(node *ptr) { 
if (ptr->rth == 1) 
return ptr->right; 
ptr = ptr->right; 
while (ptr->lth == 0) 
ptr = ptr->left; 
return ptr; 
} 
void inorder(node *root) 
{ 
if (root == NULL) 
cout << "Tree is empty"; 
node *ptr = root; 
while (ptr->lth == 0) 
{ 
ptr = ptr->left; 
} 
while (ptr != NULL) 
{ 
cout << ptr->data << " "; 
ptr = inorderSuccessor(ptr); 
} 
} 
}; 
int main() 
{ 
TBT tbt; 
char ch; 
do{ 
cout<<"Enter the value : "; 
int n; 
cin>>n; 
tbt.insert(n); 
cout<<"Do you Want to continue (Y/n) : ";
cin>>ch; 
}while(ch!='n'); 
tbt.inorder(tbt.root); 
return 0; 
} 
Output 
/tmp/244VE6QJyb.o 
Enter the value : 100 
Do you Want to continue (Y/n) : Y 
Enter the value : 50 
Do you Want to continue (Y/n) : Y 
Enter the value : 20 
Do you Want to continue (Y/n) : Y 
Enter the value : 70 
Do you Want to continue (Y/n) : Y 
Enter the value : 60 
Do you Want to continue (Y/n) : Y 
Enter the value : 200 
Do you Want to continue (Y/n) : Y 
Enter the value : 150 
Do you Want to continue (Y/n) : Y 
Enter the value : 180 
Do you Want to continue (Y/n) : Y 
Enter the value : 250 
Do you Want to continue (Y/n) : n 
20 50 60 70 100 150 180 200 250
