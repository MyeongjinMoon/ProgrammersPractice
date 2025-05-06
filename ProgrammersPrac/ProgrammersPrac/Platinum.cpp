#include "header.h"

void FindMinNum1();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	FindMinNum1();
}

void FindMinNum1()
{
	int n, l;
	cin >> n >> l;

	int* num = (int*)calloc(sizeof(int), n);
	for (int i = 0; i < n; i++)
		cin >> num[i];

	for (int i = 0; i < n; i++)
	{
		int min;
	}
}