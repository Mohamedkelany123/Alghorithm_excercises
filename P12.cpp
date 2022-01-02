//PROBLEM 12 SOLVED USING DIVIDE AND CONQUER ALGORITHM
#include <iostream>
#include <float.h>
#include <stdlib.h>
#include <math.h>
using namespace std;

//STRUCT TO ALLOW CREATION OF ANY 2D POINT
struct Point
{
    int xAxis, yAxis;
};

//SORTING. TO COMPARE X IN POINT P1 WITH X IN POINT P2
int compareXs(const void* a, const void* b)
{
	Point *P1 = (Point *)a, *P2 = (Point *)b;
	if(P1->xAxis!=P2->xAxis)
        return P1->xAxis-P2->xAxis;
    else
        return P1->yAxis-P2->yAxis;
}

//SORTING. TO COMPARE Y IN POINT P1 WITH Y IN POINT P2
int compareYs(const void* a, const void* b)
{
	Point *P1 = (Point *)a, *P2 = (Point *)b;
	if(P1->yAxis!=P2->yAxis)
        P1->yAxis-P2->yAxis;
    else
        P1->xAxis-P2->xAxis;
}

//FIND DISTANCE BETWEEN 2 POINTS
double EuclideanDistance(Point P1, Point P2)
{return sqrt( (P1.xAxis-P2.xAxis)*(P1.xAxis-P2.xAxis) + (P1.yAxis-P2.yAxis)*(P1.yAxis-P2.yAxis)) ;}

//BRUTE FORCE IMPLEMENTATION. FOR WHEN NUMBER OF POINT <=3 SINCE WE CAN NOT USE DIVIDE AND CONQUER (/2)
double BruteForce(Point Points[],int n)
{
    double ED=0.0;
	double MinDist=100000;
	for (int i=0;i<n;i++)
    {
        for (int j=i+1;j<n;j++)
        {
            ED=EuclideanDistance(Points[i],Points[j]);
            if (ED<MinDist)
				MinDist=ED;
        }
    }
	return MinDist;
}

//FINDS DISTANCE BETWEEN THE 2 CLOSEST POINTS IN THE STRIP. SORTS AGAINST Y AXIS
double StripClosest(Point Strip[],int StripSize,double MinD)
{
	double MinDist=MinD;
	double ED=0.0;

	for (int i=0;i<StripSize;i++)
    {
        for (int j=i+1;j<StripSize&&(Strip[j].yAxis-Strip[i].yAxis)<MinDist;j++)
        {
            ED=EuclideanDistance(Strip[i],Strip[j]);
            if (ED<MinDist)
				MinDist=ED;
        }
    }
	return MinDist;
}

//RECURSIVELY CALLED. PARAMETER PX IS SORTED WITH RESPECT TO X AND PY IS SORTED WITH RESPECT TO Y
double closestUtil(Point Px[], Point Py[], int n)
{
	//BASE CASES. USES BRUTE FORCE IF <=3 BECAUSE CAN NOT APPROACH USING DIVIDE AND CONQUER
	if (n<= 3) return BruteForce(Px,n);

	//FINDING MIDPOINT IN ARRAY
	int Mid=n/2;
	Point MidPoint = Px[Mid];

    //DIVIDE POINTS IN Y SORTED ARRAY AROUNF THE VERTICAL LINE
	//TO THE LEFT
	Point LeftArray[Mid];
	//TO THE RIGHT
	Point RightArray[n-Mid];
	//LEFT AND RIGHT ARRAY INDEX
	int LeftIndex=0,RightIndex=0;

	for (int i=0;i<n;i++)
	{
        if ((Py[i].xAxis<MidPoint.xAxis || (Py[i].xAxis == MidPoint.xAxis && Py[i].yAxis < MidPoint.yAxis))&&LeftIndex<Mid)
            LeftArray[LeftIndex++]=Py[i];
        else
            RightArray[RightIndex++]=Py[i];
	}

	//CALCULATE MIN DISTANCE ON THE LEFT AND RIGHT OF THE MID POINT
	double DistanceLeft = closestUtil(Px,LeftArray,Mid);
	double DistanceRight = closestUtil(Px+Mid,RightArray,n-Mid);

	double Minimum=0.0;
	if(DistanceLeft<DistanceRight)
        Minimum=DistanceLeft;
    else Minimum=DistanceRight;

	Point strip[n];
	int j=0;
	for (int i=0;i<n;i++)
    {
        if (abs(Py[i].xAxis-MidPoint.xAxis)<Minimum)
			strip[j]=Py[i];
        j++;
    }

	return StripClosest(strip,j,Minimum);
}

double Closest(Point Points[],int n)
{
    int Size=n;
	Point Px[Size];
	Point Py[Size];
	for (int i=0;i<Size;i++)
	{
		Px[i] = Points[i];
		Py[i] = Points[i];
	}
	qsort(Px,Size,sizeof(Points),compareXs);
	qsort(Py,Size,sizeof(Points),compareYs);

	//RECURSIVE CALL TO FIND THE SMALLEST DISTANCE
	return closestUtil(Px,Py,Size);
}

int main()
{
    Point P1,P2,P3,P4,P5;
    P1.xAxis=2;
    P1.yAxis=2;

    P2.xAxis=12;
    P2.yAxis=35;

    P3.xAxis=10;
    P3.yAxis=50;

    P4.xAxis=13;
    P4.yAxis=1;

    P5.xAxis=5;
    P5.yAxis=9;

    Point Points[5] = {P1,P2,P3,P4,P5};
    cout<<"The Minimum Distance In This Set Of Points Is: " <<Closest(Points,5)<<endl;
	return 0;
}
