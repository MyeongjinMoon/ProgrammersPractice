#include "header.h"

void SumOfNumbers();
void CalculateAverage();
void SumOfSection();
void SumOfSection2();
void SumConsecutiveNumber();
void OrderOfJumong();
void DNA_Password();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	//SumOfNumbers();
	//CalculateAverage();
	//SumOfSection();
	//SumOfSection2();
	//SumConsecutiveNumber();
	//OrderOfJumong();
	DNA_Password();
}

// ----- SumOfNumbers -----
void SumOfNumbers()
{
	string numbers;

	int n, answer = 0;

	cin >> n >> numbers;

	for (int i = 0; i < n; i++)
		answer += numbers[i] - '0';

	cout << answer;
}

// ----- CalculateAverage -----
void CalculateAverage()
{
	int n, max_score = -1;
	cin >> n;

	vector<float> scores;

	for (int i = 0; i < n; i++)
	{
		float score;
		cin >> score;
		scores.push_back(score);

		if (max_score < score)
			max_score = score;
	}

	float sum = 0;
	for (int i = 0; i < n; i++)
	{
		sum += scores[i] / max_score * 100;
	}

	cout << sum / n;
}

// ----- SumOfSection -----
void SumOfSection()
{
	int n, k;

	vector<int> array;
	vector<int> sum_array;

	array.push_back(0);
	sum_array.push_back(0);

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		int number;
		cin >> number;
		array.push_back(number);

		sum_array.push_back(sum_array[i - 1] + array[i]);
	}

	for (int i = 0; i < k; i++)
	{
		int a, b, answer = 0;
		cin >> a >> b;

		answer = sum_array[b] - sum_array[a - 1];

		cout << answer << '\n';
	}
}

// ----- SumOfSection2 -----
void SumOfSection2()
{
	int n, k;
	cin >> n >> k;

	int** map = (int**)calloc(sizeof(int*), n + 1);
	for (int i = 0; i <= n; i++)
		map[i] = (int*)calloc(sizeof(int), n + 1);

	int** sum_map = (int**)calloc(sizeof(int*), n + 1);
	for (int i = 0; i <= n; i++)
		sum_map[i] = (int*)calloc(sizeof(int), n + 1);

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
		{
			int num;
			cin >> num;

			map[i][j] = num;

			sum_map[i][j] = map[i][j] + sum_map[i][j - 1] + sum_map[i - 1][j] - sum_map[i - 1][j - 1];
		}

	for (int i = 0; i < k; i++)
	{
		int s_x, s_y, e_x, e_y;
		cin >> s_y >> s_x >> e_y >> e_x;

		int answer = 0;
		answer = sum_map[e_y][e_x] - sum_map[e_y][s_x - 1] - sum_map[s_y - 1][e_x] + sum_map[s_y - 1][s_x - 1];
		cout << answer << '\n';
	}
}

// ----- SumConsecutiveNumber -----
void SumConsecutiveNumber()
{
	int n, answer = 0;
	cin >> n;

	int min = 0, max = 0;

	int result = 0;
	while (max <= n)
	{
		if (result < n)
		{
			max++;
			result += max;
		}
		else if (result > n)
		{
			min++;
			result -= min;
		}
		else
		{
			answer++;

			max++;
			result += max;
		}
	}
	cout << answer;
}

// ----- OrderOfJumong -----
void OrderOfJumong()
{
	int n, k, answer = 0;
	cin >> n >> k;

	vector<int> materials(n);
	for (int i = 0; i < n; i++)
		cin >> materials[i];
	
	sort(materials.begin(), materials.end());

	int start = 0, end = n - 1;

	while (start < end)
	{
		int result = materials[start] + materials[end];
		if (result > k)
			end--;
		else if (result < k)
			start++;
		else
		{
			answer++;
			end--;
			start++;
		}
	}

	cout << answer;
}

// ----- DNA_Password -----
bool IsInDNA(char password, int& index);
void DNA_Password()
{
	string dna_Str;
	int* dna = (int*)calloc(sizeof(int), 4);
	int* _dna = (int*)calloc(sizeof(int), 4);
	int s, p;
	cin >> s >> p >> dna_Str;

	for (int i = 0; i < 4; i++)
		cin >> dna[i];

	for (int i = 0; i < p; i++)
	{
		int index = 0;
		if (IsInDNA(dna_Str[i], index))
		{
			_dna[index]++;
		}
	}
}
bool IsInDNA(char password, int& index)
{
	switch (password)
	{
	case 'A':
		index = 0;
		return true;
	case 'C':
		index = 1;
		return true;
	case 'G':
		index = 2;
		return true;
	case 'T':
		index = 3;
		return true;
	default:
		return false;
	}
}