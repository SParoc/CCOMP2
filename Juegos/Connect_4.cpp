#include <iostream>

using namespace std;

int main()
{
	char connect_4[6][7];
	int pl = 1, col = 0, row = 5;

	for (int i = 0; i < 6; i++)
	{
		for (int j = 0; j < 7; j++)
		{
			*(*(connect_4 + i) + j) = '-';
		}
	}

	for(int turn = 0; turn <= 42; turn++)
	{

		cout << "\n\nJugador" << pl << "\n\n";

		do
		{
			cout << "Introducir un numero entre 1 y 7: ";
			cin >> col;
			col -= 1;
		} while (col < 0 || col > 6);

		while ((*(*(connect_4 + row) + col) != '-') && (row >= 0))
		{
			row -= 1;
		}

		system("cls");

		(pl == 1) ? (*(*(connect_4 + row) + col) = 'X') : (*(*(connect_4 + row) + col) = 'O');

		cout << "CONNECT 4!\n\n" << endl;

		for (int i = 0; i < 6; i++)
		{
			for (int j = 0; j < 7; j++)
			{
				cout << " " << *(*(connect_4 + i) + j);
			}
			cout << endl;
		}

		(pl == 1) ? (pl += 1) : (pl -= 1);

		row = 5;
	}
}
