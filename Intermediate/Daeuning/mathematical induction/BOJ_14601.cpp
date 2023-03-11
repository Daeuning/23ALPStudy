#include <iostream>
#include <math.h>
using namespace std;
#define MAX 257
int board[MAX][MAX];
int num;

bool isDrain(int x, int y, int length)
{
	for (int i = x; i < x + length; i++)
	{
		for (int j = y; j < y + length; j++)
		{
			if (board[i][j] != 0) return 0;
		}
	}

	return 1;
}

void tromino(int x, int y, int length)
{
	num++;
	int len = length / 2;
	if (isDrain(x, y, len)) board[x + len - 1][y + len - 1] = num;
	if (isDrain(x, y + len, len)) board[x + len - 1][y + len] = num;
	if (isDrain(x + len, y, len)) board[x + len][y + len - 1] = num;
	if (isDrain(x + len, y + len, len)) board[x + len][y + len] = num;

	if (length == 2) return;

	tromino(x, y, len);
	tromino(x + len, y, len);
	tromino(x, y + len, len);
	tromino(x + len, y + len, len);
}

int main(void)
{
	int K, x, y, size;

	cin >> K >> x >> y;

	size = pow(2, K);

	board[y - 1][x - 1] = -1;

	tromino(0, 0, size);

	for (int i = size - 1; i >= 0; i--)
	{
		for (int j = 0; j < size; j++)
		{
			cout << board[i][j] << " ";
		}
		cout << '\n';
	}

	return 0;
}
