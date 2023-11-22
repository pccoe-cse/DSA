#include <iostream>
using namespace std;
int partition(int arr[],int low,int high)
{
int pivot=arr[high];
int i=(low-1);
for(int j=low;j<=high;j++)
{
if(arr[j]<pivot)
{
i++;
swap(arr[i],arr[j]);
}
}
swap(arr[i+1],arr[high]);
return (i+1);
}

void quickSort(int arr[],int low,int high)
{
if(low<high)
{
int pi=partition(arr,low,high);

quickSort(arr,low,pi-1);
quickSort(arr,pi+1,high);
}
}

int main() {
int n;
A:
cout<<"Enter the number of Number of employee : ";
cin>>n;
if(n<5)
{
cout<<"Enter the no of employee greater than 5 !"<<endl;
goto A;
}
int *arr = NULL;
arr = new int[n];
for(int i=0;i<n;i++){
cout<<"Enter the Salary of Employee "<<i+1<<" : "<<endl;
cin>>arr[i];
}
cout<<endl;
quickSort(arr,0,n-1);
cout<<"Top 5 Salary of Employees are : \n";
for(int i=n-1;i>n-6;i--)
{
cout<<arr[i]<<" ";
}
return 0;
}

Output

Enter the number of Number of employee : 7
Enter the Salary of Employee 1 :
1000
Enter the Salary of Employee 2 :
2000
Enter the Salary of Employee 3 :
8000
Enter the Salary of Employee 4 :
62000
Enter the Salary of Employee 5 :
46500
Enter the Salary of Employee 6 :
26500
Enter the Salary of Employee 7 :
64220
Top 5 Salary of Employees are :
64220 62000 46500 26500 8000