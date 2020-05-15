#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

void random(string puzzle[][4]);
void print(string puzzle[][4]);
void init(string puzzle[][4]);

int main()
{
	string puzzle[4][4];
	char s;

	init(puzzle);

	random(puzzle);

	print(puzzle);

}

void init(string puzzle[][4])
{
	int k = 1;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++, k++)
		{
			*(*(puzzle + i) + j) = to_string(k);
			if (k < 10)
			{
				(*(*(puzzle + i) + j)).insert(0, "0");
			}
		}
	}
	(*(*(puzzle + 3) + 3)) = "  ";
}

void random(string puzzle[][4])
{
	srand(time(NULL));

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			string temp;
			int m = rand() % 3 + 1;
			int n = rand() % 3 + 1;

			temp = *(*(puzzle + i) + j);
			*(*(puzzle + i) + j) = *(*(puzzle + m) + n);
			*(*(puzzle + m) + n) = temp;
		}
	}
}

void print(string puzzle[][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << " " << *(*(puzzle + i) + j);

		}
		cout << endl;
	}
}
