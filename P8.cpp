#include <iostream>

using namespace std;


class toy{
public:
    int serialNum;
    bool defected;

    toy(int serial,bool def)
    {
        serialNum=serial;
        defected=def;
    }
};

void BinarySearch(toy  arr[] ,int s,int e)
{
    int mid=s+(e-s)/2;

    if((e-s)==1 || (e-s)==0)
    {
        if(arr[s].defected==true)
            cout<<"Defected:"<<arr[s].serialNum<<endl;
        else
            cout<<"Defected:"<<arr[e].serialNum<<endl;
    }
    else if(arr[mid].defected==true)
    {
        BinarySearch(arr,s,mid);
    }
    else if(arr[mid].defected==false)
    {
        BinarySearch(arr,mid,e);
    }
}
int main(void)
{
    toy t1(0,false);
    toy t2(1,false);
    toy t3(2,false);
    toy t4(3,false);
    toy t5(4,false);
    toy t6(5,false);
    toy t7(6,true);
    toy t8(7,true);

    toy toys[8]= {t1,t2,t3,t4,t5,t6,t7,t8};

    BinarySearch(toys,0,7);

    return 0;
}
