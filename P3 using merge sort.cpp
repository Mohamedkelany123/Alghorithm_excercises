#include <iostream>
#include <list>
#include <vector>
using namespace std;
int InvCount(vector<int> &arr,int left,int right)
{

    int inversions=0;
    int middle=(left+right)/2;


    if(left == right) return 0;
    //IF LEFT<RIGHT MERGE SORT FIRST SUBARRAY AND SECOND SUBARRAY
    else
    {
        inversions+= InvCount(arr,left,middle);


        inversions += InvCount(arr,middle+1,right);


    }
    vector<int> temp;

    int i=left,j=middle+1;

    while( i <= middle && j <= right )
    {
        //cout<<arr[middle]<<endl;
        if(arr[i]<=arr[j]) {
            temp.push_back(arr[i]);
            i++;
        } else {
            temp.push_back(arr[j]);
            j++;
            inversions+= (middle+1-i);
        }
    }
    //cout<<"inversion line 59" <<inversions << " " << i<<endl;

    //SET OTHER ELEMENTS IN LEFT SUBARRAY
    while(i <= middle)
    {
        temp.push_back(arr[i]);
        i++;

    }
    //SET OTHER ELEMENTS IN RIGHT SUBARRAY
    while(j <= right)
    {
        temp.push_back(arr[j]);
        j++;

    }

    for (int l = left; l <= right; l++){
        arr[l] = temp[l - left];
        //cout << left << " "<< right << " " << temp[l] << endl;
    }
return inversions;
}
int main()
{
    int sizee;
    cout<<"Please enter the size of the array: ";
    cin>>sizee;
    vector<int> A1(sizee);
    //A1= new int[size];
    cout<<"please enter the array elements (space separated): ";
    for(int i=0;i<sizee;i++)
    {
        cin>>A1[i];
    }
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<"ARRAY:         ";
    for(int i=0;i<sizee;i++)
    {
        cout<<"  "<<A1[i]<<"    ";
    }
    cout<<endl;
    cout<<"----------------------------------------------------------------"<<endl;
    cout<<endl;
    cout<<"Number of Inversions:  "<<InvCount(A1,0,sizee-1)<<endl;
    //for(int i = 0; i < A1.size(); i++) cout << A1[i];
    cout<<"----------------------------------------------------------------"<<endl;

    return 0;
}
