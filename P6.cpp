//PROBLEM 6 SOLVED USING HASHBASED MULTIMAP
//JUST LIKE IN DATABASE HOW WE WOULD CREATE A PRIMARY INDEX ON THE PRIMARY KEY IN THE EMPLOYEES TABLE
#include <iostream>
#include <iomanip>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

//CREATING TABLES USING VECTOR OF VECTORS THAT HOLDS THE ATTRIBUTES AND THEIR DATA
using Table = vector<vector<string>>;

//EMPLOYEES TABLE ENTRIES USING VECTORS (FIXED ENTRIES FOR DEMONSTRATION. NOT USER GENERATED)
Table Employees
{
			{"XDFSE1","Jack","Electronics"},
			{"XDVBA2","Mary","Aesthetics"},
};

//TRANSACTIONS TABLE ENTRIES USING VECTORS (FIXED ENTRIES FOR DEMONSTRATION. NOT USER GENERATED)
Table Transactions
{
			{"TV","XDFSE1","Mark"},
            {"Radio","XDFSE1","Susan"},
            {"Skincare Ointment","XDVBA2","Lisa"},
};

//OVERLOADED OSTREAM OPERATOR TO OUTPUT ENTIRE TABLE
ostream& operator<<(ostream& output,const Table& T)
{
	for (size_t i=0;i<T.size();i++)
    {
		for (const auto& e : T[i])
		output<<setw(20)<<left<<e;
		output<<endl;
	}
	return output;
}

//JOIN OPERATION USING HASH BASED MULTIMAP. BOTH TABLES AND THEIR JOIN ATTRIBUTES ARE PASSED AS PARAMETERS
Table Join(const Table& A, size_t ColumnA,const Table& B, size_t ColumnB)
{
    //MULTIMAP OBJECT CREATED
	unordered_multimap<string,size_t> Hashmap;

	//INSERTS VALUES OF TABLE CONTAINING PRIMARY KEY AKA EMPLOYEES (EMPID ATTRIBUTE)
	for (size_t i = 0;i<A.size();i++)
		Hashmap.insert({A[i][ColumnA],i});

	//NEW TABLE CREATED TO HOLD TUPLES OUTPUTTED FROM JOIN CONDITION
	Table JoinResult;

	//MAPPING RESULTS
	for (size_t i=0;i<B.size();i++)
    {
        //COMPARES VALUES IN TRANSACTIONS COLUMN TO HASHMAP VALUES
        auto Range = Hashmap.equal_range(B[i][ColumnB]);

		for (auto it=Range.first;it != Range.second;it++)
        {
            //DEFINES A ROW
			Table::value_type row;

			//ROW DEFINED HOLDS TUPLES AFTER IMPLEMENTING JOIN
			//ADDS ENTIRE TUPLE FROM TABLE 1 (AKA EMPLOYEES)
			row.insert
			(
                row.end(),
                A[it->second].begin(),
                A[it->second].end()
            );
            //APPENDS MATCHING TUPLE FROM TABLE 2 (AKA TRANSACTIONS) TO THE ROW
			row.insert
			(
                row.end(),
                B[i].begin(),
                B[i].end()
            );

			//PUSHES THE JOINED ROW INTO THE RESULTS TABLE
			JoinResult.push_back(move(row));
		}
	}
	//RETURNS FINAL RESULT TABLE
	return JoinResult;
}

int main()
{
	cout << "Table A: "<<endl<<Employees<<endl;
	cout << "Table B: "<<endl<<Transactions<<endl;

	auto Table3=Join(Employees,0,Transactions,1);

	cout << "Joined tables: "<<endl<<Table3<<endl;
	return 0;
}
