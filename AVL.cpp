Code 
#include <iostream> 
using namespace std; 
class node { 
public: 
int data; 
node *left; 
node *right; 
node(int n) { 
data = n; 
left = NULL; 
right = NULL; 
} 
}; 
class AVL { 
public: 
node *root; 
AVL() { 
root = NULL; 
} 
node *LL(node *parent) { 
node *temp = parent->left; 
parent->left = temp->right; 
temp->right = parent; 
return temp; 
} 
node *RR(node *parent) { 
node *temp = parent->right; 
parent->right = temp->left; 
temp->left = parent;
return temp; 
} 
node *LR(node *parent) { 
parent->left = RR(parent->left); 
return LL(parent); 
} 
node *RL(node *parent) { 
parent->right = LL(parent->right); 
return RR(parent); 
} 
int Height(node *root) { 
if (root == NULL) 
return 0; 
int leftN = Height(root->left); 
int rightN = Height(root->right); 
return max(leftN, rightN) + 1; 
} 
node *insert(node *root, int n) { 
if (root == NULL) { 
node *nn = new node(n); 
root = nn; 
return root; 
} 
if (n < root->data) { 
root->left = insert(root->left, n); 
if (Height(root->left) - Height(root->right) == 2) { if (n < root->left->data) { 
root = LL(root); 
} else { 
root = LR(root); 
} 
} 
} else { 
root->right = insert(root->right, n); 
if (Height(root->right) - Height(root->left) == 2) { if (n > root->right->data) {
root = RR(root); 
} else { 
root = RL(root); 
} 
} 
} 
return root; 
} 
void inorder(node *root) { 
if (root != NULL) { 
inorder(root->left); 
cout << root->data << " "; 
inorder(root->right); 
} 
} 
void create(int n) { 
root = insert(root, n); 
} 
void search(int n, node *root) { 
if (root == NULL) { 
cout << "Data not found!" << endl; return; 
} 
if (n < root->data) { 
search(n, root->left); 
} else if (n > root->data) { 
search(n, root->right); 
} else if (n == root->data) { 
cout << "Data found!" << endl; 
return; 
} 
} 
}; 
int main() { 
AVL avl; 
int choice, value;
do { 
cout << "---------------------------" << endl; 
cout << "AVL Tree Menu:" << endl; 
cout << "1. Insert" << endl; 
cout << "2. Inorder Traversal" << endl; 
cout << "3. Search" << endl; 
cout << "4. Exit" << endl; 
cout << "---------------------------" << endl; 
cout << "Enter your choice: "; 
cin >> choice; 
switch (choice) { 
case 1: 
cout << "Enter the value to insert: "; 
cin >> value; 
avl.create(value); 
break; 
case 2: 
cout << "Inorder Traversal: "; 
avl.inorder(avl.root); 
cout << endl; 
break; 
case 3: 
cout << "Enter the value to search: "; 
cin >> value; 
avl.search(value, avl.root); 
break; 
case 4: 
cout << "Exiting..." << endl; 
break; 
default: 
cout << "Invalid choice! Please try again." << endl; } 
} while (choice != 4); 
return 0; 
}
Output 
/tmp/xdVvCFsjBt.o 
--------------------------- 
AVL Tree Menu: 
1. Insert 
2. Inorder Traversal 
3. Search 
4. Exit 
--------------------------- 
Enter your choice: 1 
Enter the value to insert: 30 
--------------------------- 
AVL Tree Menu: 
1. Insert 
2. Inorder Traversal 
3. Search 
4. Exit 
--------------------------- 
Enter your choice: 1 
Enter the value to insert: 20 
--------------------------- 
AVL Tree Menu: 
1. Insert 
2. Inorder Traversal 
3. Search 
4. Exit 
--------------------------- 
Enter your choice: 1 
Enter the value to insert: 10 
--------------------------- 
AVL Tree Menu: 
1. Insert 
2. Inorder Traversal 
3. Search 
4. Exit 
--------------------------- 
Enter your choice: 1 
Enter the value to insert: 40
--------------------------- 
AVL Tree Menu: 
1. Insert 
2. Inorder Traversal 
3. Search 
4. Exit 
--------------------------- 
Enter your choice: 1 
Enter the value to insert: 50 --------------------------- 
AVL Tree Menu: 
1. Insert 
2. Inorder Traversal 
3. Search 
4. Exit 
--------------------------- 
Enter your choice: 1 
Enter the value to insert: 60 --------------------------- 
AVL Tree Menu: 
1. Insert 
2. Inorder Traversal 
3. Search 
4. Exit 
--------------------------- 
Enter your choice: 1 
Enter the value to insert: 70 --------------------------- 
AVL Tree Menu: 
1. Insert 
2. Inorder Traversal 
3. Search 
4. Exit 
--------------------------- 
Enter your choice: 1 
Enter the value to insert: 80 --------------------------- 
AVL Tree Menu: 
1. Insert 
2. Inorder Traversal
3. Search 
4. Exit 
--------------------------- 
Enter your choice: 1 
Enter the value to insert: 90 
--------------------------- 
AVL Tree Menu: 
1. Insert 
2. Inorder Traversal 
3. Search 
4. Exit 
--------------------------- 
Enter your choice: 1 
Enter the value to insert: 11 
--------------------------- 
AVL Tree Menu: 
1. Insert 
2. Inorder Traversal 
3. Search 
4. Exit 
--------------------------- 
Enter your choice: 1 
Enter the value to insert: 100 
--------------------------- 
AVL Tree Menu: 
1. Insert 
2. Inorder Traversal 
3. Search 
4. Exit 
--------------------------- 
Enter your choice: 2 
Inorder Traversal: 10 11 20 30 40 50 60 70 80 90 100 --------------------------- 
AVL Tree Menu: 
1. Insert 
2. Inorder Traversal 
3. Search 
4. Exit 
--------------------------- 
Enter your choice: 3
Enter the value to search: 50 Data found!
