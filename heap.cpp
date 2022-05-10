#include <iostream>
using namespace std;


void display(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}
void Heapify(int a[],int size,int root)
{
    int largest=root;
    int leftindex=2*root+1;
    int rightindex=2*root+2;
//for swapping we will check is the leftindex is not oveflow the size of arraay and is leftindex greater than largest
    if(leftindex<size && a[leftindex]>a[largest])
    {
        largest=leftindex;
    }
    //for swapping we will check is the rightindex is not oveflow the size of arraay and is rightindex greater than largest
    if(rightindex<size && a[rightindex]>a[largest])
    {
        largest=rightindex;
    }
    //condition will get true only when largest is not equal to root;
    if(largest!=root)
    {
        swap(a[root],a[largest]);
        cout<<"Heapify"<<endl;
        display(a,size);
        cout<<endl;
        Heapify(a,size,largest);
    }
}
void Heapsort(int a[],int size)
{
    //we will heapify from the n/2-1 because leaf node ar alway heapify with themself
    for(int i=size/2-1;i>=0;i--)
    {
        Heapify(a,size,i);
    }
    for(int i=size-1;i>0;i--)
    {
        swap(a[0],a[i]);
        Heapify(a,i,0);
    }
}

int main(){
        int n;
    
    cout << "Enter how many elements you want to enter: ";
    cin >> n;
    int arr[n];

    for (int i = 0; i<n; i++)
    {
        cout << "Enter your marks: ";
        cin >> arr[i];
    }

    Heapsort(arr, n);
    cout << "Sorted array pf marks is: "<<endl;;
    display(arr, n);
    cout<<"\nmaximun marks scored by student is"<<endl;
    cout<<arr[n-1];
    cout<<"\nminimun marks scored by student is"<<endl;
    cout<<arr[0];
    
    return 0;
}