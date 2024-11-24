#include <iostream>
using namespace std;

int main()
{
	long long n = 0;
	cin >> n;
	int num[100010] = {0};
	int m;
	for (int i = 0; i < n; i++)
	{
		cin >> m;
		num[m]++;
	}
	long long res = 0;
	long long sum1 = 0;
	long long sum2 = 0;	
	for (int i = 0; i < 100010; i++)
	{
		if (num[i] == 1)
			sum1++;
		if (num[i] > 2)
			sum2 += (num[i] - 2);
	}
	if (sum2 > sum1)
		res = sum2;
	else
		res = (sum1 - sum2) / 2 + sum2;
		
	cout << res << endl;
	return 0;
}
