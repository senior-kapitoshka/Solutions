#include <stddef.h>
#include <stdlib.h>

void turn_gravity_on (size_t r, size_t c, char mx[r][c])
{
	int *cnt = calloc(c, sizeof *cnt); 
  for(size_t i=0;i<r;++i){
    for(size_t j=0;j<c;++j){
      if(mx[i][j]=='#') ++cnt[j];

    }
  }

  for(size_t i=0;i<r;++i){
    for(size_t j=0;j<c;++j){
      if(mx[i][j]=='-'  && cnt[j]>0 && i>=(r-cnt[j])) {
        --cnt[j];
        mx[i][j]='#';

      }else if(mx[i][j]=='#' && cnt[j]>0 && i<(r-cnt[j]) ) {
        mx[i][j]='-';

      }
    }
  }
  free(cnt);
}

///////////////
#include <stddef.h>

void turn_gravity_on (size_t rows, size_t cols, char matrix[rows][cols])
{
	for (size_t i = 0; i < rows; i++)
	{
		  for (size_t j = 0; j < rows; j++)
		  {
			    for (size_t k = 0; k < cols; k++)
			    {
				      if (j > 0 && matrix[j - 1][k] == '#')
				      {
					      matrix[j - 1][k] = matrix[j][k];
					      matrix[j][k] = '#';
				      }
			    }
		  }
  }
}

///////////

#include <stddef.h>

void turn_gravity_on(size_t rows, size_t cols, char matrix[rows][cols]) {
    for (size_t col = 0; col < cols; col++) {
        int write_row = rows - 1;

        for (int row = rows - 1; row >= 0; row--) {
            if (matrix[row][col] == '#') {
                matrix[write_row][col] = '#';
                write_row--;
            }
        }

        for (int row = write_row; row >= 0; row--) {
            matrix[row][col] = '-';
        }
    }
}

//////////////
#include <stddef.h>

void turn_gravity_on(size_t r, size_t c, char m[r][c])
{
  while(c--)
  {
    size_t i = r;
    int b = 0;
    while(i > 0) b += m[--i][c] == '-';
    while(i < r)      m[i++][c] = b --> 0 ? '-' : '#';
  }
}

//////////////
