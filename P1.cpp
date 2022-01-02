#include<iostream>
#include <bits/stdc++.h>
#include<cstdio>
#include<cstring>
#define INF 0x7fffffffffffffff

using namespace std;

//Problem 1:
void displayArray(int *array, int size) {
   for(int i = 0; i<size; i++)
      cout << array[i] << " ";
   cout << endl;
}
void insertionSort(int *array, int size) {
   int key, j;
   cout << "Array before Sorting: ";
   displayArray(array, size);
   int C = 0;
   for(int i = 1; i<size; i++) {
      key = array[i];
      j = i;
      while(j > 0 && array[j-1]>key) {
         array[j] = array[j-1];
         j--;
         C++;
      }
      array[j] = key;
   }
   cout << "Array after Sorting: ";
   displayArray(array, size);
   cout << "Number of swaps: ";
   cout << C << endl;
}
//End Of problem 1

int main()
{
        int n;
        cout << "Enter the number of elements: ";
        cin >> n;

        int arr[n];
        cout << "Enter elements:" << endl;
        for(int i = 0; i<n; i++)
        {
            cin >> arr[i];
        }
        insertionSort(arr , n);
}
