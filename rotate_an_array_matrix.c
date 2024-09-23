#include <stddef.h>

enum direction {CLOCKWISE, COUNTER_CLOCKWISE};

void rotate (int r, int c, const int mx[r][c], enum direction dir, int rd[c][r])
{
  if(dir==CLOCKWISE){
    for(int i=0,k=0;i<c;++i,++k){
        for(int j=r-1,m=0;j>=0;--j,++m){
          rd[k][m]=mx[j][i];
      }
    }
    
  }else if(dir==COUNTER_CLOCKWISE){
    for(int i=c-1,k=0;i>=0;--i,++k){
      for(int j=0,m=0;j<r;++j,++m){
        rd[k][m]=mx[j][i];
      }
    } 
  }
}

/////////////////////////////
#include <stddef.h>

enum direction {CLOCKWISE, COUNTER_CLOCKWISE};

void rotate_clockwise (size_t rows, size_t cols, const int matrix[rows][cols], int rotated[cols][rows])
{
	for (size_t row = 0; row < rows; row++)
		for (size_t col = 0; col < cols; col++)
			rotated[col][rows - 1 - row] = matrix[row][col];
}

void rotate_counter_clockwise (size_t rows, size_t cols, const int matrix[rows][cols], int rotated[cols][rows])
{
	for (size_t row = 0; row < rows; row++)
		for (size_t col = 0; col < cols; col++)
			rotated[cols - 1 - col][row] = matrix[row][col];
}

void rotate (size_t rows, size_t cols, const int matrix[rows][cols], enum direction direction, int rotated[cols][rows])
{
	void (*rotate_func) (size_t rows, size_t cols, const int matrix[rows][cols], int rotated[cols][rows]);

	switch (direction) {
	case         CLOCKWISE: rotate_func = rotate_clockwise;         break;
	case COUNTER_CLOCKWISE: rotate_func = rotate_counter_clockwise; break;
	}
	rotate_func(rows, cols, matrix, rotated);
}

//////////////////////////////
#include <stdbool.h>
#include <stddef.h>

void rotate(size_t rows, size_t cols, const int matrix[rows][cols], bool clockwise, int rotated[cols][rows])
{
    for (size_t i = 0; i < rows; i += 1) {
        for (size_t j = 0; j < cols; j += 1) {
            rotated[clockwise ? cols - 1 - j : j]
                   [clockwise ? i : rows - 1 - i] = matrix[i][j];
        }
    }
}