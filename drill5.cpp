                                                                      //CHAPTER NO 19

#include "std_lib_facilities.h"

template <typename T> // defining template <template name>structS{T val;}
struct S
{
private:
	T val;
public :
	
	S()      // Adding constructor initialized with T
	{
		val = 0;
	}
	S(T val2)
	{
		val=val2;
	}
	
	T get();
	
	const T get() const;       // adding function template get() that return ref to val
	void operator=(const T&);  // adding set() function template to change val
	

};

template<typename T>     //defination of get() outside of class
 T S<T>::get()
	{
		return val;
	}
 
 template<typename T>    // providing const and non const version of get()
 const T S<T>::get() const
 {
	 return val;
 }

template <typename T>     //replacing set() with an S<T>::operator=(const T&)
void S<T>:: operator=(const T& val3)
{
	val = val3;
}

 template<typename T>    //defining function template<typename T> read_val(T& v) that reads cin to v
 void read_val(T& v)
 {
	 cin >> v;
}
int main()
{
	
	 S<int> intS(1);       //defining variable types
	 S<char> charS('A');
	 S<double> doubS(1.1);
	 S<string> strS("String A");
	 S<vector<int>> vecS ({ 1, 2, 3 });
	 /*
	 // printing old method {part 4 }
	  cout << intS.val<<endl;
	 cout << charS.val << endl;
	 cout << doubS.val << endl;
	 cout << strS.val << endl;
	 for(int i : vecS.val)
	 cout << i <<" ";
	 */ 
	 
	 cout << intS.get()<<endl;      //doing part 4 using get()
	 cout << charS.get() << endl;
	 cout << doubS.get() << endl;
	 cout << strS.get() << endl;
	 for(int i : vecS.get())
	 cout << i <<" ";
	 cout << endl;
	 
	 int i1; read_val(i1); S<int> i1S(i1);  //using read_val to read into variables

	double d1; read_val(d1); S<double> d1S(d1);

	 char c1; read_val(c1); S<char> c1S(c1);
	 cout << i1S.get() << endl;
	 cout << d1S.get() << endl;
	 cout << c1S.get() << endl;
	 
	return 0;
}
