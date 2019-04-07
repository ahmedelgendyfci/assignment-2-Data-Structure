#include<iostream>
#include<vector>
using namespace std;

int main()
{


	vector<int> vec;
	int num = 0, x = 0;
	cout << "Enter The Size Of The Vector!\n";
	cin >> x;

	for (int i = 0; i < x; i++)
	{

		cout << "Enter [" << i << "] value: ";
		cin >> num;
		vec.push_back(num);
	}
	//sort first
	for (int i = 0; i < x - 1; i++)
	{
		for (int j = 0; j < x - i - 1; j++)
		{
			if (vec[j] > vec[j + 1])
				swap(vec[j], vec[j + 1]);
		}
	}
	//calc.. here
	int s1, s2, s3;
	for (int i = 0; i < x - 2; i++)
	{
		s1 = vec[i];
		s2 = vec[i + 1];
		s3 = vec[i + 2];

		if ((s1 + s2) > s3 && (s2 + s3) > s1 && (s3 + s1) > s2)
		{
			cout << "generate with sides " << s1 << "," << s2 << ", " << s3 << " a non-degenerate triangle\n";
		}
		else
		{
			cout << s1 << "," << s2 << ", " << s3 << " cannot construct a non - degenerate triangle.\n";
		}

	}



	system("pause");
	return 0;
}