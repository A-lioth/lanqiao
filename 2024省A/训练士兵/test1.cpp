#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
	// 成本 
	int p;
	// 次数 
	int c;
}Soldiers;

bool lt(Soldiers &s1, Soldiers &s2)
{
	return s1.c < s2.c;
}

int main()
{
	int n, s;
	cin >> n >> s;
	
	// 所有士兵训练所需金币
	int tp = 0;
	Soldiers* sds = new Soldiers[n];
	for (int i = 0; i < n; i++)
	{
		cin >> sds[i].p >> sds[i].c;
		tp += sds[i].p;
	} 
	
	sort(sds, sds + n, lt);
	
	// 最少金币数 
	int sum = 0;
	// 组团次数 
	int ts = 0;
	for (int i = 0; i < n; i++)
	{
		// 单独训练少于组团训练则不需要再训练 
		if (ts >= sds[i].c)
		{
			tp -= sds[i].p;
			continue;
		}
		// 组团少 
		if (tp >= s)
		{
			sum += (sds[i].c - ts) * s; 
			ts += sds[i].c - ts; 
//			tp -= sds[i].p;	
		}
		// 自己少
		else
		{
			sum += (sds[i].c - ts) * sds[i].p;
//			tp -= sds[i].p;
		} 
		tp -= sds[i].p; 
	}
	
	cout << sum << endl;
	
	return 0;
}
