#include "header.h"

void Common_Multiple();
void Partial_String();
void Flag();
void Change_IntToString();
void Compare_Values();
void Multiply_String();
void Change_StringToInt();
void Sum_StringToInt();
void Upper_Fifth();
void Operate_LengthOfArray();
void CompareArr();

//int main()
//{
//	//Common_Multiple();
//	//Partial_String();
//	//Flag();
//	//Change_String();
//	//Compare_Values();
//	//Multiply_String();
//	//Change_StringToInt();
//	//Sum_StringToInt();
//	//Upper_Fifth();
//	//Operate_LengthOfArray();
//}
// ----- Common_Multiple -----
void Common_Multiple()
{
	int number, n, m;

	cin >> number >> n >> m;

	cout << ((number % n) == 0 && (number % m) == 0) ? 1 : 0;
}

// ----- Partial_String -----
int GetLength(const char* string)
{
	int i = 0;
	while (string[i] != '\0')
	{
		i++;
	}
	return i;
}
void Partial_String()
{
	char* my_string = new char;
	char* target = new char;

	cin >> my_string >> target;

	int lengthA, lengthB;

	lengthA = GetLength(my_string);
	lengthB = GetLength(target);

	for (int i = 0; i < lengthA; i++)
	{
		int j = 0;
		for (; j < lengthB; j++)
		{
			if (my_string[i + j] != target[j])
				break;
		}
		if (j == lengthB)
		{
			cout << 1;
			return;
		}
	}
	cout << 0;
}

// ----- Flag -----
void Flag()
{
	int a, b;
	bool flag = true;

	cin >> a >> b;

	cout << (flag ? a + b : a - b);
}

// ----- Change_String -----
int NumberOfDigits(int n)
{
	int digits = 1;
	while (n >= 10)
	{
		n /= 10;
		digits++;
	}
	return digits;
}
char* MakeStringNumber(int digit, int n)
{
	char* stringNumber = (char*)malloc(sizeof(char) * (digit + 1));

	for (int i = 0; i < digit; i++)
	{
		int newDigit = pow(10, digit - i - 1);
		stringNumber[i] = n / newDigit + '0';
		n %= newDigit;
	}
	stringNumber[digit] = '\0';
	return stringNumber;
}
void Change_IntToString()
{
	int n;
	cin >> n;

	int digit = NumberOfDigits(n);

	char* stringNumber = MakeStringNumber(digit, n);

	cout << stringNumber;
}

// ----- Compare_Values -----
void Compare_Values()
{
	int a, b;
	cin >> a >> b;

	int digitB = NumberOfDigits(b);

	int caseA, caseB;
	caseA = a * pow(10, digitB) + b;

	caseB = 2 * a * b;

	cout << (caseA >= caseB ? caseA : caseB);
}

// ----- Multiply_String -----
void Multiply_String()
{
	char* my_string = new char;
	int k;

	cin >> my_string >> k;

	int string_Length = GetLength(my_string);
	char* result = (char*)malloc(sizeof(char) * string_Length * k + 1);
	
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < string_Length; j++)
		{
			result[(i * string_Length) + j] = my_string[j];
		}
	}
	result[string_Length * k] = '\0';

	cout << result;
}

// ----- Change_StringToInt -----
void Change_StringToInt()
{
	char* n_str = new char;
	int n = 0;

	cin >> n_str;

	int digit = GetLength(n_str);
	for (int i = 0; i < digit; i++)
	{
		n += (n_str[i] - '0') * pow(10, digit - i - 1);
	}

	cout << n;
}

// ----- Sum_StringToInt -----
void Sum_StringToInt()
{
	char* n_str = new char[100];
	int n = 0;

	cin >> n_str;

	int digit = GetLength(n_str);

	for (int i = 0; i < digit; i++)
	{
		n += (n_str[i] - '0');
	}

	cout << n;

	delete[] n_str;
}

// ----- Upper_Fifth -----
void BubbleSort(int* num_list, int size_num_list)
{
	for (int i = 0; i < size_num_list - 1; i++)
	{
		for (int j = i + 1; j < size_num_list; j++)
		{
			if (num_list[i] > num_list[j])
			{
				int temp = num_list[i];
				num_list[i] = num_list[j];
				num_list[j] = temp;
			}
		}
	}
}
void Upper_Fifth()
{
	int size_num_list;
	cin >> size_num_list;
	
	int num_list[10];

	for (int i = 0; i < size_num_list; i++)
		cin >> num_list[i];

	BubbleSort(num_list, size_num_list);

	int* answer_list = (int*)malloc(sizeof(int) * (size_num_list - 5));

	for (int i = 5; i < size_num_list; i++)
	{
		answer_list[i - 5] = num_list[i];
	}
	for (int i = 0; i < size_num_list - 5; i++)
		cout << answer_list[i] << ' ';
}

// ----- Operate_LengthOfArray -----
void Operate_LengthOfArray()
{
	int arr[5], arr_len = 5, n;
	for (int i = 0; i < 5; i++)
		cin >> arr[i];
	cin >> n;

	int* answer = (int*)malloc(sizeof(int) * arr_len);
	if (arr_len % 2 == 0)
		for (int i = 0; i < arr_len; i++)
		{
			answer[i] = arr[i];
			if (i % 2 != 0)
				answer[i] += n;
		}
	else
		for (int i = 0; i < arr_len; i++)
		{
			answer[i] = arr[i];
			if (i % 2 == 0)
				answer[i] += n;
		}

	for (int i = 0; i < arr_len; i++)
		cout << answer[i] << ' ';
}

// ----- CompareArr -----
void CompareArr()
{
	//int arr1_len, arr2_len;
	//cin >> arr1_len >> arr2_len;

	//if (arr1_len > arr2_len)
	//	return 1;
	//else if (arr1_len < arr2_len)
	//	return -1;
	//else
	//{
	//	int sum_A = 0, sum_B = 0;

	//	for (int i = 0; i < arr1_len; i++)
	//	{
	//		sum_A += arr1[i];
	//		sum_B += arr2[i];
	//	}

	//	if (sum_A > sum_B)
	//		return 1;
	//	else if (sum_A < sum_B)
	//		return -1;
	//	else
	//		return 0;
	//}
}