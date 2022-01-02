//PROBLEM 16 SOLVED USING COUNT SORT. HOWEVER, MINOR CHANGES WERE MADE TO THE ALGORITHM TO MAINTAIN ELEMENTS OCCURENCE.
//CHANGES INCLUDED USING AN ARRAYLIST TO PUSH AND POP DISTINCT ELEMENTS
//DRAWBACK: SPACE COMPLEXITY=K, WHERE K = MAX ELEMENT IN ARRAY
#include <iostream>
#include <stack>
#include <algorithm>
#include <list>
using namespace std;

//TEMPLATE TO ALLOW USER TO INPUT ONLY THE ARRAY WITHOUT ITS SIZE
template <unsigned int N>
//FUNCTION TO FIND MAX ELEMENT IN AN ARRAY
int GetArrayMax(int const (&Array)[N])
{
    //VARIABLE TO STORE ARRAY SIZE
    int ArraySize=end(Array)-begin(Array);
    int Max=Array[0];
    for(int i = 1;i<ArraySize;i++)
    {
        if(Array[i]>Max)
            Max=Array[i];
    }
    return Max;
}

//TEMPLATE TO ALLOW USER TO INPUT ONLY THE ARRAY WITHOUT ITS SIZE
template <unsigned int N>
void CountSort(int const (&Array)[N])
{
    //VARIABLE TO STORE INPUT ARRAYS' SIZE
    int ArraySize=end(Array)-begin(Array);
    //VARIABLE TO STORE INPUT ARRAYS' MAX ELEMENT
    int MaxElement=GetArrayMax(Array);

    //ARRAY TO STORE ACCUMILATIVE ELEMENT FREQUENCY
    int Accumilative[MaxElement]={0};
    //ARRAY TO STORE FINAL RESULT
    int Result[ArraySize];

    //ARRAYLIST TO PUSH AND POP ARRAYS' DISTINCT ELEMENTS
    list<int>DistinctList;
    //ITERATOR TO ITERATE OVER ARRAYLIST
    list <int> :: iterator Iterator;

    //LOOP TO FIND OCCURENCE OF EACH ELEMENT
    for(int i=0;i<ArraySize;i++)
        Accumilative[Array[i]]=Accumilative[Array[i]]+1;

    //LOOP TO RETRIEVE DISTINCT ELEMENTS IN ORDER OF THEIR INPUT. IF ELEMENT IN ARRAY IS DISTINCT, PUSH IT INTO THE LIST
    for(int i=0;i<ArraySize;i++)
    {
        Iterator = find(DistinctList.begin(),DistinctList.end(),Array[i]);
        if(Iterator==DistinctList.end())
            DistinctList.push_back(Array[i]);
    }

    int j=0;
    //LOOP TO GO OVER DISTINCT LIST
    for(Iterator=DistinctList.begin();Iterator!=DistinctList.end();Iterator++)
    {
        int Element=*Iterator;
        int Reps=Accumilative[Element];
        int LoopRep=Reps;
        //GETS EACH DISTINCT ELEMENTS' OCCURENCE
        if(Reps!=0)
        {
            //LOOP TO FILL OUT RESULT ARRAY ACCORDING TO CURRENT DISTINCT ELEMENTS OCCURENCE
            while(LoopRep>0)
            {
                Result[j]=Element;
                LoopRep--;
                j++;
            }
        }
    }

    //LOOP TO OUTPUT INITIAL ARRAY
    cout<<"Initial Array: ";
    for(int i=0;i<ArraySize;i++)
        cout<<Array[i]<<" ";

    cout<<endl;
    cout<<"Sorted Array: ";
    //LOOP TO OUTPUT FINAL RESULT ARRAY
    for(int i=0;i<ArraySize;i++)
        cout<<Result[i]<<" ";
    cout<<endl<<endl;
}

int main()
{
    int TestCase1[]={ 1, 2, 3, 1, 2, 1 };
    int TestCase2[]={ 5, 4, 5, 5, 3, 1, 2, 2, 4 };
    int TestCase3[]={ 2, 5, 1, 2, 3, 5, 5, 7};

    CountSort(TestCase1);
    CountSort(TestCase2);
    CountSort(TestCase3);
    return 0;
}
