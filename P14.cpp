#include <bits/stdc++.h>

using namespace std;

void findPairs(int arr[], int Size, int sum)
{
    bool found = false;
	unordered_set<int> keys;
	for (int i = 0; i < Size; i++)
	{
		int temp = sum - arr[i];
		if (keys.find(temp) != keys.end())
        {
            cout << "Pair found ("<< arr[i] << ","<< temp << ")" << endl;
            found = true;
        }
        keys.insert(arr[i]);
	}
    if (found == false)
        cout << "Pair not found" << endl;
}
int main()
{

	int target;
    int s;
	cout<<"enter target"<<endl;
	cin>>target;
	cout<<"enter size"<<endl;
    cin>>s;
    int arr[s];
	cout<<"enter nums"<<endl;
	for (int i = 0; i < s; i++)
	{
	   cin>>arr[i];
	}

	findPairs(arr, s, target);

	return 0;
}
