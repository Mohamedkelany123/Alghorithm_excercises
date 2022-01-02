
#include <bits/stdc++.h>
using namespace std;

int InvCount(int arr[],int size)
{
    int invcount=0;
    //LOOP ON ARRAY SIZE TO CHECK IF 
    //A[i]>A[j] AND IF SO INCREMENT INVCOUNT
    for(int i=0;i<size;i++)
    {
        for(int j=i+1;j<size;j++)
        {
            if (arr[i]>arr[j])
            {
                invcount++;
            }
        }
    }
    return invcount;
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
    cout<<"Number of inversions:   "<<InvCount(A1,size)<<endl;
    cout<<"----------------------------------------------------------------"<<endl;

    return 0;
}
