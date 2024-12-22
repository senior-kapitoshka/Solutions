#include <stddef.h>

char *maze_runner(const int *maze, size_t n, const char *dir) {
  int mz[n][n];
  for(size_t i=0,k=0,m=0;i<n*n;++i){
    if(i%n!=0 || i==0){
      mz[k][m++]=maze[i];
    }else{
      ++k;
      m=0;
      mz[k][m++]=maze[i];
    }
  }
  size_t from[2],to[2];
  for(size_t i=0;i<n;++i){
    for(size_t j=0;j<n;++j){
  
      if(mz[i][j]==2){
        from[0]=i;
        from[1]=j;
      }
      if(mz[i][j]==3){
        to[0]=i;
        to[1]=j;
      }
    }

  }
  for(size_t i=0;dir[i]!='\0';++i){
    switch(dir[i]){
        case 'N':
    
          if(from[0]!=0){
            
            if(mz[from[0]-1][from[1]]==1){
              return "Dead";
            }else if(mz[from[0]-1][from[1]]==3){
                return "Finish";
            }else if(mz[from[0]-1][from[1]]==0 || mz[from[0]-1][from[1]]==2){
          
              from[0]-=1;
          
            }
          }else return "Dead";
          break;
        case 'S':
    
          if(from[0]!=n-1){
            if(mz[from[0]+1][from[1]]==1){
              return "Dead";  
            }else if(mz[from[0]+1][from[1]]==3){
                return "Finish";
            }else if(mz[from[0]+1][from[1]]==0 || mz[from[0]+1][from[1]]==2){
              from[0]+=1;
            }
          }else return "Dead";
          break;
        case 'W':
    
          if(from[1]!=0){
            if(mz[from[0]][from[1]-1]==1){
              return "Dead";
            }else if(mz[from[0]][from[1]-1]==3){
                return "Finish";     
            }else if(mz[from[0]][from[1]-1]==0 || mz[from[0]][from[1]-1]==2){
              from[1]-=1;
            }
          }else return "Dead";
          break;
        case 'E':
    
          if(from[1]!=n-1){
            if(mz[from[0]][from[1]+1]==1){
              return "Dead";
            }else if(mz[from[0]][from[1]+1]==3){
                  return "Finish";                  
            }else if(mz[from[0]][from[1]+1]==0 || mz[from[0]][from[1]+1]==2){
              from[1]+=1;
            }
          }else return "Dead";
          break;
    }
  }
  if(mz[from[0]][from[1]]=='3') return "Finish";
  return "Lost";
}

/////////////////////////
#include <stddef.h>

char *maze_runner(const int *maze, size_t n, const char *directions) 
{
  int x, y, cur;
  
  // locate the start
  for (y = 0; y < n; y++) for (x = 0; x < n; x++) if (maze[y*n+x] == 2) goto moves;
  
  moves:
  for (char *d = directions; *d; d++) 
  {
    switch (*d) {
      case 'N': y--; break;
      case 'S': y++; break;
      case 'E': x++; break;
      case 'W': x--; break;
    }
    if (x < 0 || y < 0 || y > n-1 || x > n-1)  return "Dead"; // out of bounds
    if ((cur = maze[y*n+x]) == 1)              return "Dead"; // hit wall 
    if (cur == 3)                              return "Finish"; // found exit
  }
  
  return "Lost";
}

//////////////////////////////
#include <stddef.h>
#include <iso646.h>

#define NORTH 'N'
#define SOUTH 'S'
#define EAST  'E'
#define WEST  'W'

#define START   2
#define WALL    1
#define FINISH  3

char *maze_runner(const int *maze, size_t n, const char *directions) {
    size_t x, y;
    for (size_t i = 0; i < n; i++){
        for (size_t j = 0; j < n; j++)
            if (maze[i * n + j] == START){
                x = j;
                y = i;
            }
    }
    for (size_t i = 0; directions[i]; i++){
        x += (directions[i] == EAST) - (directions[i] == WEST);
        y += (directions[i] == SOUTH) - (directions[i] == NORTH);
        if (maze[y * n + x] == WALL or x >= n or y >= n)
            return "Dead";
        if (maze[y * n + x] == FINISH)
            return "Finish";
    }
    return "Lost";
}

/////////////////////////
#include <stddef.h>

char *maze_runner(const int *maze, size_t n, const char *directions) {
    size_t x, y, end_x, end_y;

    for (size_t i = 0; i < n; i++)
        for (size_t j = 0; j < n; j++)
            if (maze[i*n + j] == 2)
                x = j, y = i;
            else if (maze[i*n + j] == 3)
                end_x = j, end_y = i;

    for (; *directions; directions++) {
        if (*directions == 'N') y -= 1;
        if (*directions == 'S') y += 1;
        if (*directions == 'E') x += 1;
        if (*directions == 'W') x -= 1;

        if (x >= n || y >= n || maze[y*n + x] == 1)
            return "Dead";
        if (maze[y*n + x] == 3)
            return "Finish";
    }
    return "Lost";
}

///////////////////////////
#include <stddef.h>

#define DEAD(N, MAX) N < 0 || N > MAX - 1

void move(int *x, int *y, char dir) {
  switch (dir) {
      case 'N': *y -= 1; break;
      case 'S': *y += 1; break;
      case 'E': *x += 1; break;
      case 'W': *x -= 1; break;
  }
}

char *maze_runner(const int *maze, size_t n, const char *directions) {
  int nums[n][n], x, y, i, *p;

  for (p = maze, i = 0; i < n * n; i++) {
    nums[i/n][i%n] = maze[i];
    if (*p++ == 2) x = i%n, y = i/n;
  }

  while (*directions) {
    move(&x, &y, *directions++);
    if (DEAD(x, n) || DEAD(y, n) || nums[y][x] == 1) return "Dead";
    if (nums[y][x] == 3) return "Finish";
  }

  return "Lost";
}

////////////////////////
