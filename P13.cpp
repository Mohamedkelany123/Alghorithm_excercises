#include<iostream>
#include <bits/stdc++.h>
#include<cstdio>
#include<cstring>
#define INF 0x7fffffffffffffff
using namespace std;

//Problem 13
int n;
int pos[15][15];
int left_brackets[15];
int right_brackets[15];
long long matrix_a[15];                           //long long is a datatype that stores a huge int, ~2^63 ta2reban
long long matrix_b[15];
long long dp[15][15];

void dfs(int x,int y)                            //what does dfs stand for??
{
    if(x==y)
    {
        return;                                  //do nothing
    }
                                                 //increments only happens if x != y
    left_brackets[x]++;                           //increment number of left brackets
    right_brackets[y]++;                          //increment number of right brackets

    if(x==y-1)
    {
        return;                                  //do nothing
    }
                                                //recursive calls only happens if x != y-1
    dfs(x, pos[x][y]);                          //recursive call  ---- what is pos??
    dfs(pos[x][y]+1, y);                        //recursive call  ---- why 2 recursive calls?
 }
 //End of Problem 13

 int main()
 {
     //Testing Problem 13
        int caseNum=0;
        cout<<"input number of matrices then input the matrices"<<endl;
        while(scanf("%d",&n)==1 && n)                              //inputting number of matrices, and checking that it is int > 0
        {
            for(int i=1;i<=n;i++)
            {
                scanf("%lld %lld", &matrix_a[i], &matrix_b[i]);    //inputting matrices
                if(i>1)
                {
                    if(matrix_a[i] != matrix_b[i-1])
                    {
                        cout << "invalid matrix, please input number of rows = number of columns for previous matrix" << endl;
                        return 0;
                    }
                }
            }

            caseNum++;                                             //incrementing case numberr
            memset(dp, 0, sizeof(dp));
            memset(pos, -1, sizeof(pos));

            for(int i=1; i<n; i++)
                dp[i][i+1] = matrix_a[i] * matrix_a[i+1] * matrix_b[i+1];

            for(int j=2;j<n;j++)                                  //loop to count number of multiplications
                for(int i=1;i<=n-j;i++)
                {
                    long long Min=INF;                            //declaring variable min = infinity

                    for(int k=0;k<j;k++)
                    {
                        long long temp = dp[i][i+k] + dp[i+k+1][i+j] + matrix_a[i] * matrix_b[i+k] * matrix_b[i+j];

                        if(temp<Min)
                        {
                            Min=temp;
                            pos[i][i+j]=i+k;
                        }
                    }
                    dp[i][i+j]=Min;
                }

            memset(left_brackets, 0, sizeof(left_brackets));        //memset akenaha bt7gz makan fl memory w temlah 0
            memset(right_brackets, 0, sizeof(right_brackets));

            dfs(1,n);                                             //calling dfs, the function that arranges brackets

            printf("Case %d: ", caseNum);                         //%d takes int value (caseNum) and prints it
            for(int i=1; i<=n; i++)
            {
                for(int j=1; j<=left_brackets[i]; j++)
                    putchar('(');                                //putchar prints one character or adds one character to output

                printf("A%d", i);                                //print the matrix + matrix number
                                                             //printf zy cout bas with more output formatting flexbility
                for(int j=1; j<=right_brackets[i]; j++)
                    putchar(')');

                if(i!=n)
                    printf(" x ");
            }
            printf("\n");
    return 0;
    //End of problem 13 Test
 }
 }
