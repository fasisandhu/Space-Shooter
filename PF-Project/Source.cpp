#include <iostream>
#include <time.h>
#include <Windows.h>
#include <conio.h>
using namespace std;
int row = 27, col = 43;
//spaceship printing
void spaceshipprint(char a[30][120])
{
	a[row][col] = 202;
}

void printingtable(char a[30][120])
{
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 120; j++)
		{
			a[i][j] = ' ';
		}
	}

	//For first row:
	for (int i = 0; i < 120; i++)
	{
		a[0][i] = 177;
	}
	//For second row:
	for (int i = 0; i < 120; i++)
	{
		a[1][i] = 177;
	}

	//For first 2 columns:
	for (int i = 2; i < 30; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			a[i][j] = 177;
		}
	}

	//For middle columns:
	for (int i = 2; i < 30; i++)
	{
		for (int j = 85; j < 88; j++)
		{
			a[i][j] = 177;
		}
	}

	//For last 2 columns:
	for (int i = 2; i < 30; i++)
	{
		for (int j = 118; j < 120; j++)
		{
			a[i][j] = 177;
		}
	}

	//For first right partition: 
	for (int i = 10; i < 12; i++)
	{
		for (int j = 88; j < 120; j++)
		{
			a[i][j] = 177;
		}
	}

	//For second right partition:
	for (int i = 19; i < 21; i++)
	{
		for (int j = 88; j < 120; j++)
		{
			a[i][j] = 177;
		}
	}

	//For last 2 columns:
	for (int i = 28; i < 30; i++)
	{
		for (int j = 0; j < 120; j++)
		{
			a[i][j] = 177;
		}
	}
	//	For Writing Space:
	a[4][98] = 'S';
	a[4][100] = 'P';
	a[4][102] = 204;
	a[4][104] = 'C';
	a[4][106] = 'E';

	//	For Writing Shooter:
	a[6][96] = 'S';
	a[6][98] = 'H';
	a[6][100] = 'O';
	a[6][102] = 'O';
	a[6][104] = 'T';
	a[6][106] = 'E';
	a[6][108] = 'R';

	//	For Writing Level:
	a[13][96] = 'L';
	a[13][98] = 'E';
	a[13][100] = 'V';
	a[13][102] = 'E';
	a[13][104] = 'L';
	a[13][108] = 49;

	//	For Writing Score:
	a[22][94] = 'S';
	a[22][96] = 'C';
	a[22][98] = 'O';
	a[22][100] = 'R';
	a[22][102] = 'E';
	a[22][105] = 61;
	a[22][108] = 48;
	a[22][110] = 48;
	a[22][112] = 48;

	//For Lives:
	a[25][96] = 'L';
	a[25][98] = 'I';
	a[25][100] = 'V';
	a[25][102] = 'E';
	a[25][104] = 'S';
	a[25][107] = 61;
	a[25][110] = 51;

	//function calling spaceship
	//spaceshipprint(a, spaceship);
	/*int row = 27, col = 43;
	a[row][col] = 202;*/

	spaceshipprint(a);

	//Printing
	for (int i = 0; i < 30; i++)
	{
		for (int j = 0; j < 120; j++)
		{
			cout << a[i][j];
		}
	}
}

void rightmovement(char a[30][120])
{
		if (col < 83)
		{
			a[row][col] = ' ';
			col = col + 2;
			a[row][col] = 202;
		}
}

void leftmovement(char a[30][120])
{
	if (col > 3)
	{
		a[row][col] = ' ';
		col = col - 2;
		a[row][col] = 202;
	}

}

void main()
{
	char a[30][120];
	printingtable(a);
	//movements
	int c = 0;
	while (1) {
		c = 0;
		c = _getch();
		system("cls");
		//right
		if (c == 100)
		{
			rightmovement(a);
		}
		//left
		else if (c == 97)
		{
			leftmovement(a);
		}
		for (int i = 0; i < 30; i++)
		{
			for (int j = 0; j < 120; j++)
			{
				cout << a[i][j];
			}
		}
	}
		
}

//practise with hanzla--first day
//#define ROW 5
//#define COL 5
//
//
//void printarr(int arr[ROW][COL], char c) {
//	for (int i = 0; i < ROW; i++)
//	{
//		for (int j = 0; j < COL; j++)
//		{
//			if (arr[i][j] == 1)
//			{
//				cout << c;
//			}
//			else
//				cout << " ";
//		}
//		cout << endl;
//	}
//}
//
//void movedown(int arr[ROW][COL], int delay=100) 
//{
//	for (int i = ROW - 2; i >= 0; i--)
//	{
//		for (int j = 0; j < COL; j++)
//		{
//			arr[i + 1][j] = arr[i][j];
//		}
//	}
//	for (int i = 0; i < 5; i++)
//	{
//		arr[0][i] = 0;
//	}
//
//}
//
//int main()
//{
//	int arr[ROW][COL] = { {0,0,1,0,1},{0,1,0,1,0},{0,0,0,0,0},{1,0,0,1,0},{0,0,0,1,0} };
//	char box = 260;
//	
//	printarr(arr, box);
//	//cout <<"moving down" << endl;
//	//system("cls");
//
//	movedown(arr);
//	Sleep(1000);
//	printarr(arr, box);
//
//	cout << "moving down" << endl;
//	//system("cls");
//	movedown(arr);
//	Sleep(1000);
//	printarr(arr, box);
//	cout << "moving down" << endl;
//	//system("cls");
//
//	movedown(arr);
//	Sleep(1000);
//	printarr(arr, box);
//	cout << "moving down" << endl;
//	//system("cls");
//
//	movedown(arr);
//	Sleep(1000);
//	printarr(arr, box);
//	
//	system("pause");
//	return 0;
//}




