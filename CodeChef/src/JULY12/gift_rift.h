#include "template.h"
int mat[100][100] = {0};

int calc[100][100] = {0};

int main()
{
	int R = input.readInt(), C = input.readInt();

	for(int i = 0; i < R; i++)
	{
		for(int j = 0; j < C; j++)
		{
			mat[i][j] = input.readInt();
		}
	}

	// calculate min in each row...
	for(int i = 0; i < R; i++)
	{
		int row_min = mat[i][0], j = 1;
		for(j = 1; j < C; j++)
		{
			if(mat[i][j] < row_min)
				row_min = mat[i][j];
		}

		for(j = 0; j < C; j++)
		{
			if(mat[i][j] == row_min)
				calc[i][j]++;
		}
	}

	// calculate the max in each column...
	for(int j = 0; j < C; j++)
	{
		int col_max = mat[0][j], i = 1;
		for(i = 1; i < R; i++)
		{
			if(mat[i][j] > col_max)
				col_max = mat[i][j];
		}

		for(int i = 0; i < R; i++)
		{
			if(mat[i][j] == col_max)
				calc[i][j]++;

			if(calc[i][j] == 2)
			{
				output(mat[i][j], "\n");
				return 0;
			}
		}
	}

	output("GUESS", "\n");

	return 0;
}