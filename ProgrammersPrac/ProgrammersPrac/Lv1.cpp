#include "header.h"

void Flexible_WorkSystem();
void TakeOut_Box();

int main()
{
	//Flexible_WorkSystem();
	TakeOut_Box();
}

/*
700 800 1100
710 2359 1050 700 650 631 659
800 801 805 800 759 810 809
1105 1001 1002 600 1059 1001 1100
*/

// ----- Flexible_WorkSystem -----
void SetInitTime(int& time)
{
	if ((time % 100) >= 50)
	{
		time += 100;
		int deleteTime = time % 100;
		int curTime = (time % 100 + 10);
		time -= deleteTime;
		time += (curTime - 60);
	}
	else
		time += 10;
}
void Flexible_WorkSystem()
{

	int answer = 0;
	int number = 3;
	int startday = 5;

	vector<int> schedules;
	vector<vector<int>> timelogs(number);

	for (int i = 0; i < number; i++)
	{
		int init_time;
		cin >> init_time;
		SetInitTime(init_time);
		schedules.push_back(init_time);
	}

	for (int i = 0; i < number; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			int rush_hour;
			cin >> rush_hour;
			timelogs[i].push_back(rush_hour);
		}
	}
	for (int i = 0; i < number; i++)
	{
		int j = 0;
		for (; j < 7; j++)
		{
			if (((j + startday - 1) % 7) > 4)
				continue;
			if (timelogs[i][j] > schedules[i])
				break;
		}
		if (j == 7)
			answer++;
	}

	cout << answer;
}

// ----- TakeOut_Box -----
void TakeOut_Box()
{
	int n, w, num, result;
	cin >> n >> w >> num;

	int position;
	if ((num / w) % 2 == 0)
	{
		position = num % w;
		while (position <= n)
		{

		}
	}
	else
	{
		position = w - (num % w) + 1;
		while (position <= n)
		{

		}
	}

	cout << result;
}