#include "header.h"

void Common_Multiple();
void Partial_String();
void Flag();
void Change_String();
void Compare_Values();

int main()
{
	//Common_Multiple();
	//Partial_String();
	//Flag();
	//Change_String();
	Compare_Values();
}
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
void Change_String()
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