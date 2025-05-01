#include "header.h"

void RestOfSum();
void GoodNumber();

//int main()
//{
//	ios::sync_with_stdio(false);
//	cin.tie(NULL); cout.tie(NULL);
//
//	//RestOfSum();
//	//GoodNumber();
//}

// ----- RestOfSum -----
void RestOfSum()
{
	int n, k;
	cin >> n >> k;

	long long* sum_array = (long long*)calloc(sizeof(long long), n + 1);
	long long* rest_array = (long long*)calloc(sizeof(long long), k);

	for (int i = 1; i <= n; i++)
	{
		int num;
		cin >> num;

		sum_array[i] = sum_array[i - 1] + num;

		rest_array[sum_array[i] % k]++;
	}

	long long answer = rest_array[0];
	for (int i = 0; i < k; i++)
	{
		answer += (rest_array[i] * (rest_array[i] - 1)) / 2;
	}

	cout << answer;
}

// ----- GoodNumber -----
bool IsGoodNum(vector<long long>, int);
void GoodNumber()
{
	int n, answer = 0;
	cin >> n;

	vector<long long> nums(n);
	for (int i = 0; i < n; i++)
		cin >> nums[i];

	sort(nums.begin(), nums.end());

	for (int i = 0; i < n; i++)
	{
		if (IsGoodNum(nums, i))
			answer++;
	}

	cout << answer;
}

bool IsGoodNum(vector<long long> nums, int index)
{
	long long result = nums[index];
	int start = 0, end = index - 1;
	
	while (start < end)
	{
		long long box = nums[start] + nums[end];
		if (box == result)
			return true;
		else if (box < result)
			start++;
		else
			end--;
	}
	return false;
}