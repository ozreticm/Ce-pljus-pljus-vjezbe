#include "Board.h"
#include <iostream>
Board::Board()
{
	for (int i = 0; i < 10; i++)
		for (int j = 0; j < 10; j++)
			matrix[i][j] = ' ';
}

void Board::set(LargeShip a, MediumShip b, SmallShip c1, SmallShip c2)
{
	for(int i=0;i<10;i++)
		for (int j = 0; j < 10; j++)
		{
			ships[i][j] = false;
			hit[i][j] = false;
		}
	if (a.coorx1 == a.coorx2 && a.coory1 < a.coory2)
	{
		matrix[a.coorx1][a.coory1] = 'o';
		matrix[a.coorx1][a.coory2] = 'o';
		matrix[a.coorx1][a.coory1+1] = 'o';
		matrix[a.coorx1][a.coory2-1] = 'o';
		ships[a.coorx1][a.coory1] = true;
		ships[a.coorx1][a.coory2] = true;
		ships[a.coorx1][a.coory1 + 1] = true;
		ships[a.coorx1][a.coory2 - 1] = true;
	}
	else if (a.coorx1 == a.coorx2 && a.coory1 > a.coory2)
	{
		matrix[a.coorx1][a.coory1] = 'o';
		matrix[a.coorx1][a.coory2] = 'o';
		matrix[a.coorx1][a.coory2+1] = 'o';
		matrix[a.coorx1][a.coory1 -1] = 'o';
		ships[a.coorx1][a.coory1] = true;
		ships[a.coorx1][a.coory2] = true;
		ships[a.coorx1][a.coory1 - 1] = true;
		ships[a.coorx1][a.coory2 + 1] = true;
	}
	else if (a.coory1 == a.coory2 && (a.coorx1 > a.coorx2))
	{
		matrix[a.coorx1][a.coory1] = 'o';
		matrix[a.coorx2][a.coory1] = 'o';
		matrix[a.coorx2 + 1][a.coory1] = 'o';
		matrix[a.coorx1 - 1][a.coory1] = 'o';
		ships[a.coorx1][a.coory1] = true;
		ships[a.coorx1][a.coory2] = true;
		ships[a.coorx2 + 1][a.coory1] = true;
		ships[a.coorx1 - 1][a.coory1] = true;
	}
	else if (a.coory1 == a.coory2 && (a.coorx1 < a.coorx2))
	{
		matrix[a.coorx1][a.coory1] = 'o';
		matrix[a.coorx2][a.coory1] = 'o';
		matrix[a.coorx1 + 1][a.coory1] = 'o';
		matrix[a.coorx2 - 1][a.coory1] = 'o';
		ships[a.coorx1][a.coory1] = true;
		ships[a.coorx1][a.coory2] = true;
		ships[a.coorx2 - 1][a.coory1] = true;
		ships[a.coorx1 + 1][a.coory1] = true;
	}
	matrix[b.coorx1][b.coory1] = 'o';
	matrix[b.coorx2][b.coory2] = 'o';
	matrix[c1.coorx1][c1.coory1] = 'o';
	matrix[c2.coorx1][c2.coory1] = 'o';
	ships[b.coorx1][b.coory1] = true;
	ships[b.coorx2][b.coory2] = true;
	ships[c1.coorx1][c1.coory1] = true;
	ships[c2.coorx1][c2.coory1] = true;
}

void Board::setHidden(LargeShip a, MediumShip b, SmallShip c1, SmallShip c2)
{
	for (int i = 0; i<10; i++)
		for (int j = 0; j < 10; j++)
		{
			ships[i][j] = false;
			hit[i][j] = false;
		}
	if (a.coorx1 == a.coorx2 && a.coory1 < a.coory2)
	{
		ships[a.coorx1][a.coory1] = true;
		ships[a.coorx1][a.coory2] = true;
		ships[a.coorx1][a.coory1 + 1] = true;
		ships[a.coorx1][a.coory2 - 1] = true;
	}
	else if (a.coorx1 == a.coorx2 && a.coory1 > a.coory2)
	{
		ships[a.coorx1][a.coory1] = true;
		ships[a.coorx1][a.coory2] = true;
		ships[a.coorx1][a.coory1 - 1] = true;
		ships[a.coorx1][a.coory2 + 1] = true;
	}
	else if (a.coory1 == a.coory2 && (a.coorx1 > a.coorx2))
	{
		ships[a.coorx1][a.coory1] = true;
		ships[a.coorx1][a.coory2] = true;
		ships[a.coorx2 + 1][a.coory1] = true;
		ships[a.coorx1 - 1][a.coory1] = true;
	}
	else if (a.coory1 == a.coory2 && (a.coorx1 < a.coorx2))
	{
		ships[a.coorx1][a.coory1] = true;
		ships[a.coorx1][a.coory2] = true;
		ships[a.coorx2 - 1][a.coory1] = true;
		ships[a.coorx1 + 1][a.coory1] = true;
	}
	ships[b.coorx1][b.coory1] = true;
	ships[b.coorx2][a.coory2] = true;
	ships[c1.coorx1][c1.coory1] = true;
	ships[c2.coorx1][c2.coory1] = true;
}

bool Board::aim1(int x, int y)
{
	if (hit[x][y])
		return true;
	else
		hit[x][y] = true;
		return false;
}

void Board::aim2(int x, int y, bool h)
{
	if (h)
	{
		matrix[x][y] = 'x';
	}
	else
	{
		matrix[x][y] = '#';
	}
}

void Board::print(const Board & other) const
{
	std::cout << "                 PLAYER                                                      COMPUTER\n\n";
	std::cout << "   0   1   2   3   4   5   6   7   8   9                        0   1   2   3   4   5   6   7   8   9\n";
	int row1 = 0,row2=0;
	for (int i = 0; i < 10; i++)
	{
		std::cout << " ________________________________________                      ________________________________________\n"<<row1++;
		for (int j = 0; j < 10; j++)
		{
			std::cout << "| " << matrix[i][j] << " ";
		}
		std::cout << "|                    "<<row2++;
		for (int j = 0; j < 10; j++)
		{
			std::cout << "| " << other.matrix[i][j] << " ";
		}
		std::cout << "|\n";
	}
	std::cout << " ________________________________________                      ________________________________________\n";
}



