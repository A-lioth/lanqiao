#include <iostream>
#include <string>
using namespace std;

string str;

void isGoodNum(int init, int n, bool &isValid)
{
	for (int j = init; j < str.length(); j += 2)
	{
		if (str[j] % 2 == n)
		{
			isValid = false;
			return;
		}
	}
}

int main()
{
	long long num;
	cin >> num;
	long long count = 0;
	for (int i = 1; i <= num; i++)
	{
		str = to_string(i);
		bool isValid = true;

		if (str.length() % 2 != 0)
		{
			isGoodNum(0, 0, isValid);
			isGoodNum(1, 1, isValid);
			if (isValid)
				count++;
		}
		else
		{
			isGoodNum(0, 1, isValid);
			isGoodNum(1, 0, isValid);
			if (isValid)
				count++;
		}
	}
	cout << count << endl;
	return 0;
}
