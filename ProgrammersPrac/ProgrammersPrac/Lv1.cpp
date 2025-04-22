#include "header.h"

void Flexible_WorkSystem();
void TakeOut_Box();
void VideoPlayer();
void Bill_Folding();
void Park();

int main()
{
	//Flexible_WorkSystem();
	//TakeOut_Box();
	//VideoPlayer();
	//Bill_Folding();
	Park();
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
	int n, w, num, answer = 0;
	cin >> n >> w >> num;

	int position;
	if (((num - 1) / w) % 2 == 0)
	{
		bool flag = true;
		position = (num - 1) % w + 1;

		while (num <= n)
		{
			if (flag)
				num += (w * 2 - position * 2 + 1);
			else
				num += position * 2 - 1;

			flag = !flag;
			answer++;
		}
	}
	else
	{
		bool flag = false;
		position = w - ((num - 1) % w);

		while (num <= n)
		{
			if (flag)
				num += (w * 2 - position * 2 + 1);
			else
				num += position * 2 - 1;

			flag = !flag;
			answer++;
		}
	}

	cout << answer;
}

// ----- VideoPlayervoid -----
/*
34:33
13:00
00:55
02:55
2
next
prev
*/
int StringToInt(string str)
{
	int temp = 0;
	temp += (str[0] - '0') * 600;
	temp += (str[1] - '0') * 60;
	temp += (str[3] - '0') * 10;
	temp += (str[4] - '0');

	return temp;
}
void IsInOP(int& time, int op_start, int op_end)
{
	if (time >= op_start && time <= op_end)
		time = op_end;
}
void IsLessThanZero(int& time)
{
	if (time < 0)
		time = 0;
}
void IsBiggerThanVideoLen(int& time, int video_len)
{
	if (time >= video_len)
		time = video_len;
}
void ChangeTimeToString(int time, string& answer)
{
	answer[0] = time / 600 + '0';	time %= 600;
	answer[1] = time / 60 + '0';	time %= 60;
	answer[2] = ':';
	answer[3] = time / 10 + '0';	time %= 10;
	answer[4] = time + '0';
}
void VideoPlayer()
{
	vector<string> commands;
	string video_len, pos, op_start, op_end;
	int video_len_I, pos_I, op_start_I, op_end_I;

	cin >> video_len >> pos >> op_start >> op_end;

	video_len_I = StringToInt(video_len);
	pos_I = StringToInt(pos);
	op_start_I = StringToInt(op_start);
	op_end_I = StringToInt(op_end);

	IsInOP(pos_I, op_start_I, op_end_I);

	int num;
	cin >> num;

	for (int i = 0; i < num; i++)
	{
		string command;
		cin >> command;
		commands.push_back(command);
	}
	for (int i = 0; i < commands.size(); i++)
	{
		string temp = commands[i];

		if (temp == "next")
		{
			pos_I += 10;
			IsBiggerThanVideoLen(pos_I, video_len_I);
		}
		else if (temp == "prev")
		{
			pos_I -= 10;
			IsLessThanZero(pos_I);
		}

		IsInOP(pos_I, op_start_I, op_end_I);
	}

	string answer;
	answer.resize(5);
	ChangeTimeToString(pos_I, answer);

	cout << answer;
}

// ----- Bill_Folding ------
bool CheckHorizontal(vector<int> wallet, vector<int> bill)
{
	if (wallet[0] >= bill[0])
		if (wallet[1] >= bill[1])
			return true;
	return false;
}
bool CheckVertical(vector<int> wallet, vector<int> bill)
{
	if (wallet[0] >= bill[1])
		if (wallet[1] >= bill[0])
			return true;
	return false;
}
void FoldBill(vector<int>& bill)
{
	if (bill[0] > bill[1])
		bill[0] /= 2;
	else
		bill[1] /= 2;
}
void Bill_Folding()
{
	vector<int> wallet, bill;
	int result = 0;
	int x, y;
	cin >> x >> y;
	wallet.push_back(x); wallet.push_back(y);

	cin >> x >> y;
	bill.push_back(x); bill.push_back(y);

	while (!(CheckHorizontal(wallet, bill) || CheckVertical(wallet, bill)))
	{
		FoldBill(bill);
		result++;
	}
	cout << result;
}

// ----- Park -----
void CheckMatSize()
{

}
void Park()
{
	vector<int> mats;
	vector<vector<string>> park;

	int num; cin >> num;

	for (int i = 0; i < num; i++)
	{
		int mat;
		cin >> mat;

		mats.push_back(mat);
	}
	
	int size; cin >> size;

	park.resize(size);
	for (int i = 0; i < park.size(); i++)
		park[i].resize(size);

	for (int i = 0; i < park.size(); i++)
		for (int j = 0; j < park[i].size(); j++)
			cin >> park[i][j];

	for (int i = 0; i < park.size(0); i++)
		for (int j = 0; j < park[i].size(); j++)
		{

		}
}