                                                            //CHAPTER NO 18
                                                              //PART NO 1:
#include "std_lib_facilities.h"
int ga[10] ={1,2,4,8,16,32,64,128,256,512};   //defining global int array ga 
void f(int a[], int n)
{
	
	int la[10];      // defining local array la

	for (int i = 0;i < 10;i++) // copying values from ga into la
		la[i] = ga[i];
	
	for (int i = 0;i < 10;i++)  //printing values of la
		cout<<la[i]<<" ";
	int* p = new int[n];     // defining pointer p to int 
	
	for (int i = 0;i < 10;i++)   // copy values from argumented array into free store array
		p[i] = a[i];
	
	cout << endl;    // printing elements of free store
	for (int i = 0;i < 10;i++)
		cout << p[i] << " ";
	cout << endl;
	delete[] p;
}
int main()
{
	f(ga, 10);   // calling f() with ga as its argument
	int aa[10] = {1,2,6,24,120,720,5040,40320,362880,3628800};  // defining array aa with ten elements
	f(aa, 10); //calling f() with aa as its argument
	
	return 0;
}


                                                                       //PART NO 2

#include "std_lib_facilities.h"
vector<int> gv ={1,2,4,8,16,32,64,128,256,512}; // defining global vector<int> gv
void f(vector <int> v)
{
	vector <int> lv;   // define local vector<int> lv 
	
	for (int i = 0;i < v.size();i++) //copying values from gv to lv
		lv.push_back(gv[i]);
	
	for (int i = 0;i < lv.size();i++) //printing values of lv
		cout<<lv[i]<<" ";
	cout << endl; 

	vector <int> lv2;  	// define local vector 2
	for (int i = 0;i < v.size();i++) //copying values of argument vector
		lv2.push_back( v[i]);
	
	for (int i = 0;i < lv2.size();i++)  // printing elements of lv2
		cout << lv2[i] << " ";
	cout << endl;
}
int main()
{ 
	f(gv);  // calling f() with gv
	vector <int> vv = {1,2,6,24,120,720,5040,40320,362880,3628800}; //defining vector<int>vv with first ten fractional values
	f(vv);   // calling f() with vv

	return 0;
}
