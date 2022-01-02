//PROBLEM 11 SOLVED USING COIN ROW IN DYNAMIC PROGRAMMING
#include<iostream>
#include<array>
using namespace std;

//TEMPLATE TO ALLOW USER TO INPUT ONLY THE ARRAY WITHOUT ITS SIZE
template <unsigned int N>
int MaxSumNonAdjacent(int const (&Array)[N])
{
    //VARIABLE TO STORE ARRAY SIZE
    int ArraySize=end(Array)-begin(Array);

    //CONDITION TO CHECK IF ARRAY IS EMPTY
    if(ArraySize==0)
        return 0;
    //CONDITION TO CHECK IF ARRAY ONLY HAS ONE ELEMENT
    else if(ArraySize==1)
    {
        //IF THE ONLY ELEMENT IS A NEGATIVE NUMBER ITS BEST NOT TO CHOOSE AN ELEMENT
        if(Array[0]<0)
            return 0;
        else
            return Array[0];
    }
    //IF ARRAY HAS MORE THAN 1 ELEMENT
    else
    {
        //CREATE A NEW ARRAY WITH THE SAME SIZE OF THE ARRAY PASSED AS PARAMETER
        int* DynamicProgramming =new int [ArraySize];
        //SETS BASE CASE
        DynamicProgramming[0]=Array[0];
        if(Array[0]>Array[1])
            DynamicProgramming[1]=Array[0];
        else
            DynamicProgramming[1]=Array[1];
        //COIN ROW CONDITION F(N)=MAX{CN+F(N-2),F(N-1)} + CHANGES TO GET MAX IF NEGATIVE NUMBERS ARE INCLUDED
        for(int i=2;i<ArraySize;i++)
            DynamicProgramming[i]=max(Array[i],max(DynamicProgramming[i-1],Array[i]+DynamicProgramming[i-2]));
        //CHECKS IF MAX SUM LESS THAN 0 ITS BEST NOT TO CHOOSE AN ELEMENT
        if(DynamicProgramming[ArraySize-1]<0)
            return 0;
        else
            return DynamicProgramming[ArraySize-1];
    }
}

int main()
{
   int TestCase1[] = {-2,2,-4,6,-4};
   int TestCase2[] = {3,5,-7,8,10};

   cout<<"Test Case 1: "<<endl<<"Inputs: ";
   for(int i=0;i<5;i++)
        cout<<TestCase1[i]<<" ";

   //OUTPUT MESSSAGE BEFORE RETURNING THE MAX SUM
   cout<<endl<<"Maximum Sum Of Non Adjacent Elements: "<<MaxSumNonAdjacent(TestCase1)<<endl<<endl;

   cout<<"Test Case 2: "<<endl<<"Inputs: ";
   for(int i=0;i<5;i++)
        cout<<TestCase2[i]<<" ";
   cout<<endl<<"Maximum Sum Of Non Adjacent Elements: "<<MaxSumNonAdjacent(TestCase2)<<endl;

   return 0;
}
