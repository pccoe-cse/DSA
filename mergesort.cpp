#include <iostream>
using namespace std;
void merge(int *arr,int s,int e){
int mid = s-((s-e)/2);
int len1 = mid - s +1;
int len2 = e -mid;
int *first = new int[len1];
int *second = new int[len2];
int index1 = 0;
int index2 =0;
int index =s;
for(int i=0;i<len1;i++){
first[i] = arr[index++];
}
index =mid+1;
for(int i=0;i<len1;i++){
second [i] = arr[index++];
}
index = s;
while(index1<len1&&index2<len2){
if(first[index1]<second[index2]){
arr[index++] = first[index1++];
}
else{
arr[index++] = second[index2++];
}
}
while(index1<len1){

arr[index++] = first[index1++];
}
while(index2<len2){
arr[index++] = second[index2++];
}
delete []first;
delete []second;
}
void mergeSort(int *arr,int s,int e){
if(s>=e){
return;
}
int mid = s - ((s-e)/2);
mergeSort(arr,s,mid);
mergeSort(arr,mid+1,e);
merge(arr,s,e);
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

mergeSort(arr,0,n-1);
cout<<"Top 5 Salary of Employees are : \n";
for(int i=n-1;i>n-6;i--)
{
cout<<arr[i]<<" ";
}

return 0;
}