#include "std_lib_facilities.h"


class Point
{
public :
	double x, y;
	Point()
	{
		x = y = 0;
	}
	Point(double num1, double num2)
	{
		x = num1;
		y = num2;
	}
	void print(Point P)
	{
		cout << P.x << " " << P.y<<endl;
	}
};
bool compare(vector<Point> P1,vector <Point> P2)
{
	bool b = false;
	for (int i = 0;i < 7;i++)
	{
		if (P1[i].x== P2[i].x && P1[i].y == P2[i].y)
			b= true;
		else
		{
			b = false;
			break;
		}
	}
	return b;
}


int main()
{
	vector<Point>  original_points;
	double x, y;
	for (int i = 0;i < 7;i++)
	{
		cin >> x >> y;
		Point p(x, y);
		original_points.push_back(p);
	}
	for (Point i : original_points)
	{
		i.print(i);
	}
	ofstream f;
	f.open("mydata.txt");
	if (!f)
		cout << "error" << endl;
	else
		cout << "successfully opened" << endl;

	for (Point i : original_points)
	{
		f << i.x << " " << i.y << endl;
	}
	f.close();
	ifstream f2;
	f2.open("mydata.txt");
	vector<Point>  processed_points;
	string s, s2, s3;

	while (getline(f2, s))
	{
		int whitespace_index = s.find(' ');
		int n1, n2;
		s2 = s.substr(0, whitespace_index);
		s3 = s.substr(whitespace_index + 1);
		cout << s2 << "\n" << s3;
	
		n1 = stoi(s2);
		n2 = stoi(s3);
		Point P2(n1,n2);
		processed_points.push_back(P2);
	}
	cout << "original points : " << endl;
	for (Point i : original_points)
	{
		i.print(i);
	}
	cout <<"processed points : " << endl;
	for (Point i : processed_points)
	{
		i.print(i);

	}

	if (compare(original_points, processed_points) == true)
		cout << "Congrats, Everything correct";
	else
		cout << "Something's wrong";

	return 0;
}
