#include <iostream>
#include <unordered_map>
using namespace std;
//to do so we need to traverse the array from right to left
//to get the min index
int MinIndex(int arr[], int size)
{
    //lets assume that the min index would first be initialized
    //with last element of the array
    int minindex=size;
    //we are going to use hash set to compare if the elements in
    //the array are repeated in the hash set
    //if so we modift the miniindex
    unordered_map<int,int> set;
    for (int i = size - 1; i >= 0; i--)
    {
        // if the element is seen before, update the minimum index
        if (set.find(arr[i])!=set.end()) {
             minindex = i;
        }
        // if the element is seen for the first time, insert it into the set
        else {
            set.insert({arr[i],i});
        }
    }
    return minindex;
}
int main()
{
    int size;
    int* A1;
    cout<<"Please enter the size of the array: ";
    cin>>size;
    A1=new int[size];
    cout<<"please enter the array elements (space separated): ";
    for(int i=0;i<size;i++)
    {
        cin>>A1[i];
    }
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<"ARRAY:         ";
    for(int i=0;i<size;i++)
    {
        cout<<"  "<<A1[i]<<"    ";
    }
    cout<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<endl;
    int result = MinIndex(A1,size);
    if (result==size){
        cout<<"Invalid Input"<<endl;
    }
    else{
        cout<<"Minimum repeated index:   "<<result<<endl;
    }
    cout<<"----------------------------------------------------------------"<<endl;

    return 0;
}
