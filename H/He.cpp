#include <iostream>
#include <windows.h>
#include <time.h>
#include <conio.h>

using namespace std;
#define ROW 20 
#define COL 20

int lives = 3;
int score = 0;

int shooterR;
int shooterC;
const char SPACESHIP = (char)202;
const char BULLET = (char)15;
const char ALIEN = (char)254;
const char EMPTY = ' ';
const int DIFFUCLTY = 1;
int speed = 100;





struct Point {
	char c;//character 
	int color;//color
};

Point board[ROW+1][COL];
const int SHOOTERROW = ROW;


void initBoard();

void printBoard();
void print();
Point makePoint(char c, int color = 0);
Point makeEmpty(int color=0);
Point makeAlien(int color=0);
Point makeShooter(int color = 0);
Point makeBullet(int color = 0);
void checkClash();
bool isEmpty(Point);
bool isAlien(Point);
bool isShooter(Point);
bool isBullet(Point);
void bulletsMoveUp();
void aliensMoveDown();
int getRand(int start, int end);
void makeRandAlien();
void decreaseLife();
void increaseScore(int s);
void run();
//void shooterMoveUp();
//void shooterMoveDown();
void shooterMoveLeft();
void shooterMoveRight();
void shootBullet();

void checkMovement(int);

int main()
{
	//initBoard();
	//board[ROW - 1][0] = makeBullet();
	//board[ROW - 1][5] = makeBullet();
	//board[ROW - 1][15] = makeBullet();
	//printBoard();
	//cout << "asdfasdf";
	//bulletsMoveUp();
	//printBoard();


	srand(time(NULL));
	run();
	system("pause");
	return 0;
}

void run()
{
	int c = 0;
	initBoard();
	//printBoard();
	print();
	//board[ROW-2][0] = makeBullet();
	//board[ROW-2][5] = makeBullet();
	//board[ROW-2][15] = makeBullet();
	bool first = true;
	while (1)
	{
		if (_kbhit()) {
			c = 0;
			c = _getch();
			checkMovement(c);
		}

		for (int i = 0;i < DIFFUCLTY; i++)
		{
			makeRandAlien();
		}
		first = false;
		checkClash();
		for (int c = 0; c < COL; c++)
		{
			if(!isShooter(board[SHOOTERROW][c]))
			board[SHOOTERROW][c] = makeEmpty();
		}
		aliensMoveDown();
		bulletsMoveUp();
		Sleep(speed+100);
		system("cls");
		//printBoard();
		print();
	}


}

void initBoard()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			board[i][j] = makeEmpty();
		}
	}
	//board[SHOOTERROW][20] = makeShooter();
	//board[SHOOTERROW][(COL / 2) - 2] = makeShooter();
	shooterR = SHOOTERROW;
	shooterC = (COL / 2) - 2;
	board[shooterR][shooterC] = makeShooter();


}

void printBoard() {
	for (int i = 0; i < ROW+1; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			cout << board[i][j].c;
		}
		cout << endl;
	}
}
void print()
{
	printBoard();
	cout << endl;
	cout << "Score: " << score << endl;;
	cout << "Lives: " << lives << endl;
}

Point makePoint(char c, int color) {
	return Point{ c,color };
}

Point makeEmpty(int color) {
	return Point{ EMPTY };
}

Point makeAlien(int color)
{
	return Point{ ALIEN };
}

Point makeShooter(int color) {
	return Point{SPACESHIP};
}

Point makeBullet(int color) {
	return Point{ BULLET };
}

//for checking
bool isEmpty(Point p)
{
	return p.c == EMPTY;
}
bool isAlien(Point p)
{
	return p.c == ALIEN;
}
bool isShooter(Point p)
{
	return p.c == SPACESHIP;
}
bool isBullet(Point p)
{
	return p.c == BULLET;
}
//For movements
void aliensMoveDown()
{
	for (int i= ROW - 1; i >= 0; i--)
	{
		for (int j = 0; j <= COL; j++)
		{
			if (isAlien(board[i][j]) && isEmpty(board[i + 1][j]))
			{
				board[i + 1][j] = board[i][j];
				board[i][j] = makeEmpty();
			}
		}
	}
}

void bulletsMoveUp() {
	for (int i = 0; i < COL; i++)
	{
		board[0][i] = makeEmpty();
	}
	for (int i = 1; i <ROW; i++)
	{
		for (int j = 0; j <= COL; j++)
		{
			if (isBullet(board[i][j]) && isEmpty(board[i - 1][j]))
			{
				board[i-1][j] = board[i][j];//second row point copies to first row
				board[i][j] = makeEmpty();
			}
		}
	}

}


void swap(Point& a, Point& b)
{
	Point temp;
	temp = a;
	a = b;
	b = temp;

}

int getRand(int start, int end)
{
	int n;
	n = rand();
	n = n % end-start;
	n += start;
	return n;
}
void makeRandAlien()
{
	bool done = false;
	while (!done)
	{
		int col = getRand(0, COL);
		if (isEmpty(board[0][col])) {
			board[0][col] = makeAlien();
			done = true;
		}
	}

};
void checkClash()
{
	for (int i = 0; i < ROW; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			if (isAlien(board[i][j]) && isBullet(board[i + 1][j]))
			{
				board[i][j] = makeEmpty();
				board[i+1][j] = makeEmpty();
				increaseScore(1);
			}
			else if (isAlien(board[i][j]) && isShooter(board[i + 1][j]))
			{
				board[i][j] = makeEmpty();
				decreaseLife();
			}
		}
	}

}
void decreaseLife()
{
	lives--;
}
void increaseScore(int s)
{
	score += s * DIFFUCLTY * 10;
}

void shooterMoveRight()
{
	swap(board[shooterR][shooterC], board[shooterR][ shooterC + 1]);
	shooterC++;
}

void shooterMoveLeft()
{
	swap(board[shooterR][shooterC], board[shooterR][shooterC - 1]);
	shooterC--;
}

void shooterMoveUp()
{
	swap(board[shooterR][shooterC], board[shooterR-1][shooterC]);
	shooterR--;
}

void shooterMoveDown()
{
	swap(board[shooterR][shooterC], board[shooterR + 1][shooterC]);
	shooterR++;
}


void checkMovement(int c) {
	if (c == 'd')
		shooterMoveRight();
	else if (c == 'a')
		shooterMoveLeft();
	else if (c == 's')
		shooterMoveDown();
	else if (c == 'w')
		shooterMoveUp();
	else if (c == ' ')
		shootBullet();
}

void shootBullet() {
	board[shooterR-1][shooterC] = makeBullet();
}