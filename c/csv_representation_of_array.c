#include <stdlib.h>

char *to_csv_text(size_t rows, size_t cols, const int mx[rows][cols])
{
    char* p=(char*)malloc(rows*cols*2*sizeof(int));
    char* res=p;
    for(size_t i=0;i<rows;++i){
      for(size_t j=0;j<cols;++j){
        res+=sprintf(res,"%d,",mx[i][j]);
      }
      *(res-1)='\n';
    }
  *(res-1)='\0';
    return p;
}


/////////////////////////////////
#include <stdlib.h>
#include <stdio.h>

char *to_csv_text(size_t rows, size_t cols, const int matrix[rows][cols])
{
    char *result = calloc(12 * rows * cols, sizeof(char));
    char *ptr = result;
    
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < cols; ++j) {
            ptr += sprintf(ptr, "%d,", matrix[i][j]);
        }
        
        *(ptr - 1) = '\n';
    }
    
    *(ptr - 1) = '\0';
    
    return result;
}
//////////////////////////////////
#include <stdlib.h>

char *to_csv_text(size_t rows, size_t cols, const int matrix[rows][cols]){
    char *p=malloc(1000);
    int i,r,j;
    for(j=i=0;i<rows;i++){
        for(r=0;r<cols;r++)
            j+=sprintf(p+j,"%d,",matrix[i][r]);
        p[j-1]='\n';
    }
    p[j-1]=0;
    return p;
}

////////////////////////
