#include <iostream>
#include <algorithm>
using namespace std;

typedef struct {
	// �ɱ� 
	int p;
	// ���� 
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
	
	// ����ʿ��ѵ��������
	int tp = 0;
	Soldiers* sds = new Soldiers[n];
	for (int i = 0; i < n; i++)
	{
		cin >> sds[i].p >> sds[i].c;
		tp += sds[i].p;
	} 
	
	sort(sds, sds + n, lt);
	
	// ���ٽ���� 
	int sum = 0;
	// ���Ŵ��� 
	int ts = 0;
	for (int i = 0; i < n; i++)
	{
		// ����ѵ����������ѵ������Ҫ��ѵ�� 
		if (ts >= sds[i].c)
		{
			tp -= sds[i].p;
			continue;
		}
		// ������ 
		if (tp >= s)
		{
			sum += (sds[i].c - ts) * s; 
			ts += sds[i].c - ts; 
//			tp -= sds[i].p;	
		}
		// �Լ���
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
