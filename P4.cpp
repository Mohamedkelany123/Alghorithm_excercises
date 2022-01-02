#include <iostream>
#include <vector>
#include <list>
using namespace std;

int ClearMultiset(vector<int> arr,int size)
{
   int val=1;
   vector<int> temp;
   for(int i=0;i<size;i++)
   {
       for(int j=0;j<arr[i];j++)
       {
           temp.push_back(val);
       }
       val++;
   }
   cout<<"Array with Occurences:       ";
   for(int i=0;i<temp.size();i++)
   {
       cout<<"    "<<temp[i];
   }
   cout<<endl;

   //DECLARE A BOOL VARIABLE TO TEST THE ARRAY
   //IF IT NEEDS TO ACCESS OPERATION 2
   bool valid=true;
   int minSol=0;

   //OPERATION 1
   for(int i=0;i<size;i++)
   {

       if(arr[i]==0)
       {
           cout<<"BREAK TO OPERATION 2"<<endl;
           valid=false;
           break;
       }
   }

   //OPERATION 1
   if(valid==true)
   {
       for(int i=0;i<size;i++)
       {
           arr[i]=arr[i]-1;
       }
       minSol++;
       //cout<<"1: "<<minSol;
   }

   //OUTPUT ARRAY OF OPERATION 1
   cout<<"--------------------------------------------------------------------"<<endl;
   cout<<endl;
   cout<<"Array after first operation:   ";
   for(int i=0;i<size;i++)
   {
       cout<<"  "<<arr[i];
   }
   cout<<endl;

   //OPERATION 2
   for(int i=0;i<size;i++)
   {
       if(arr[i]>=1)
       {
           arr[i]=0;
           minSol++;
       }
   }

   //OUTPUT ARRAY OF OPERATION 2
   //cout<<"2: "<<minSol;
   cout<<"--------------------------------------------------------------------"<<endl;
   cout<<endl;
   cout<<"Array after second operation:  ";
   for(int i=0;i<size;i++)
   {
       cout<<"  "<<arr[i];
   }
   cout<<endl;
   cout<<"--------------------------------------------------------------------"<<endl;
   cout<<endl;
   return minSol;
}


int main()
{
    int sizee;
    cout<<"Please enter the size of the array: ";
    cin>>sizee;
    vector<int> A1(sizee);
    cout<<"please enter the array elements (space separated): ";
    for(int i=0;i<sizee;i++)
    {
        cin>>A1[i];
    }
    cout<<"--------------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<"ARRAY:         ";
    for(int i=0;i<sizee;i++)
    {
        cout<<"  "<<A1[i]<<"    ";
    }
    cout<<endl;
    cout<<"--------------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<endl;
    cout<<"Number of Minimum Solutions:     "<<ClearMultiset(A1,sizee);
    cout<<endl;
    cout<<"--------------------------------------------------------------------"<<endl;

    return 0;
}

