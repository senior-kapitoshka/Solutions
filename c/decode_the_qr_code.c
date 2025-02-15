#include <stdlib.h>
#include <math.h>
#include <string.h>

const char *scanner(int qr[21][21]) {
  char arr[76];
  int id[4]={23,47,71,95};
  size_t x=20;
  size_t y=20;
  char flag=0;
  for(size_t i=0,j=0;i<76;++i){
    if((x+y)%2==0){
      arr[i]=(!qr[x][y])+'0';
    }else{
      arr[i]=qr[x][y]+'0';
    }
    if(i%id[j]==0 && i!=0){
      ++j;
      flag=!flag;
      --y;
    }else{
      if(!flag){
        if(y%2==0){
          --y;
        }else{
          ++y;
          --x;
        }
      }else{
        if(y%2==0){
          --y;
        }else{
          ++x;
          ++y;
        }
      }
    }
  }
  //get size
  char* t=malloc(8);
  strncpy(t,&arr[4],8);
  size_t sz=(size_t)strtol(t,NULL,2);
  //get line
  char* tw=malloc(sz*8);
  strncpy(tw,&arr[12],sz*8);
  char* result=malloc(sz);
  //line to string
  char* p=result;
  for(size_t i=0;i<sz*8;i+=8){
    strncpy(t,&tw[i],8);
    *p++=(int)strtol(t,NULL,2);
  }
  *p='\0';
  return result; 
}
//////////////
const char *scanner (int q[21][21]) {
  static char m[10]; int b=0,x=20,y=19,i=0,c=1,e=1;
  while (--y> 8) b|=!e^q[y][x-1]|(e^q[y][x])*2, c++%4?0:(m[i++]=b), b<<=2, e^=1; e^=1, x-=2;
  while (++y<21) b|=!e^q[y][x-1]|(e^q[y][x])*2, c++%4?0:(m[i++]=b), b<<=2, e^=1; e^=1, x-=2;
  while (y-->11) b|=!e^q[y][x-1]|(e^q[y][x])*2, c++%4?0:(m[i++]=b), b<<=2, e^=1;
  return m[1+m[0]]=0, m+1; 
}
/////////
#include <stdlib.h>

typedef struct byte_loc byte_loc_t;
struct byte_loc {
  int x;
  int y;
  int dir;
};

int readByte(int qrcode[21][21], int x, int y, int dir) {
  int byte = 0;
  int _x, _y;
  for (int i = 0; i < 8; i++) {
    switch (dir) {
      case 0:
        _x = x - i%2;
        _y = y - i/2;
        break;
      case 1:
        _x = x - i%2 - ((i/4)%2)*2;
        _y = y - ((i+2)/4)%2;
        break;
      case 2:
        _x = x - i%2;
        _y = y + i/2;
        break;
      case 3:
        _x = x - i%2 - ((i/4)%2)*2;
        _y = y + ((i+2)/4)%2;
        break;
    }
    byte += (((_x+_y)%2) == 0 ? !qrcode[_y][_x] : qrcode[_y][_x]) << (7 - i);
  }
  return byte;
}

const char *scanner(int qrcode[21][21]) {
  byte_loc_t sequence[18] = {
    {20, 18, 0},
    {20, 14, 0},
    {20, 10, 1},
    {18, 11, 2},
    {18, 15, 2},
    {18, 19, 3},
    {16, 18, 0},
    {16, 14, 0},
    {16, 10, 1},
    {14, 11, 2},
    {14, 15, 2},
    {14, 19, 3},
    {12, 18, 0},
    {12, 14, 0},
    {12, 10, 0},
    {12, 5, 0},
    {12, 1, 1},
    {10, 2, 2},
  };
  
  int array[18];
  for (int i = 0; i < 18; i++) {
    array[i] = readByte(qrcode, sequence[i].x, sequence[i].y, sequence[i].dir);
  }
  
  char *code = calloc(18 + 1, sizeof(char));
  for (int i = 0; i < array[0]; i++) {
    code[i] = (char) array[i + 1];
  }
  return code;
}
//////////////
#include <stdio.h>

inline int check(int borw, int row, int col);

int check(int borw, int row, int col) {
  int o = !((row + col) % 2);
  if (borw) {
    if (o) return 0;
  }
  else {
    if (!o) return 0;
  }
  return 1;
}

inline int read_up(int qrcode[21][21], int start_row, int start_col);
inline int read_down(int qrcode[21][21], int start_row, int start_col);
inline int read_up_left(int qrcode[21][21], int start_row, int start_col);
inline int read_down_left(int qrcode[21][21], int start_row, int start_col);



int read_up(int qrcode[21][21], int start_row, int start_col) {
  int data = 0;
  int bit = 7;
  for (int i = 0; i < 4; ++i) {
    if (check(qrcode[start_row][start_col], start_row, start_col))
      data |= 1 << bit;
    bit--;
    if (check(qrcode[start_row][start_col - 1], start_row, start_col - 1))
      data |= 1 << bit;
    bit--;
    start_row--;
  }
  return data;
}


int read_down(int qrcode[21][21], int start_row, int start_col) {
  int data = 0;
  int bit = 7;
  for (int i = 0; i < 4; ++i) {
    if (check(qrcode[start_row][start_col], start_row, start_col))
      data |= 1 << bit;
    bit--;
    if (check(qrcode[start_row][start_col - 1], start_row, start_col - 1))
      data |= 1 << bit;
    bit--;
    start_row++;
  }
  return data;
}

int read_up_left(int qrcode[21][21], int start_row, int start_col) {
  int data = 0;
  int off_col[] = {0, -1, 0, -1, -2, -3, -2, -3};
  int off_row[] = {0, 0, -1, -1, -1, -1, 0, 0};

  for (int i = 0, bit = 7; i < 8; ++i, --bit) {
    if (check(qrcode[start_row + off_row[i]][start_col + off_col[i]], \
                start_row + off_row[i], start_col + off_col[i]))
      data |= 1 << bit;
  }
  
  return data;
}
int read_down_left(int qrcode[21][21], int start_row, int start_col) {
  int data = 0;
  int off_col[] = {0, -1, 0, -1, -2, -3, -2, -3};
  int off_row[] = {0, 0, 1, 1, 1, 1, 0, 0};

  for (int i = 0, bit = 7; i < 8; ++i, --bit) {
    if (check(qrcode[start_row + off_row[i]][start_col + off_col[i]], \
                start_row + off_row[i], start_col + off_col[i]))
      data |= 1 << bit;
  }
  
  return data;
}

int message_length(int qrcode[21][21]) {
  return read_up(qrcode, 18, 20);
}

int encode_mode(int qrcode[21][21]) {
  int enc = 0;
  if (check(qrcode[20][20], 20, 20))
    enc |= 1 << 3;
  if (check(qrcode[20][19], 20, 19))
    enc |= 1 << 2;
  if (check(qrcode[19][20], 19, 20))
    enc |= 1 << 1;
  if (check(qrcode[19][19], 19, 19))
    enc |= 1;
  return enc;
}

#define UP 1
#define UPLEFT 2
#define DOWN 3
#define DOWNLEFT 4

// enum data_direc = {UP, UPLEFT, DOWN, DOWNLEFT};

const int direcs[] =   {UP,UPLEFT,
                        DOWN,DOWN,DOWNLEFT,
                        UP,UP,UPLEFT,
                        DOWN,DOWN,DOWNLEFT,
                        UP,UP,UP,UP,UPLEFT,
                        DOWN,};
const int start_pos_row[] = {14, 10,
                             11, 15, 19,
                             18, 14, 10,
                             11, 15, 19,
                             18, 14, 10, 5, 1,
                             2,};
const int start_pos_col[] = {20, 20,
                             18, 18, 18,
                             16, 16, 16,
                             14, 14, 14,
                             12, 12, 12, 12, 12,
                             10, };



const char *scanner(int qrcode[21][21]) {
  int enc = encode_mode(qrcode);
  int length = message_length(qrcode);
  int data = read_up(qrcode, 14, 20);
  char buf[18] = {0};
  
  printf("enc : %d\nlength : %d\n", enc, length);
  
  for (int i = 0; i < length; ++i) {
    int start_r = start_pos_row[i], start_c = start_pos_col[i];
    switch (direcs[i]) {
    case UP:
      data = read_up(qrcode, start_r, start_c);
      break;
    case DOWN:
      data = read_down(qrcode, start_r, start_c);
      break;
    case UPLEFT:
      data = read_up_left(qrcode, start_r, start_c);
      break;
    case DOWNLEFT:
      data = read_down_left(qrcode, start_r, start_c);
      break;
    }
    buf[i] = (char)data;
  }
  
  
  return strdup(buf); 
}
////////////
#define _POSIX_C_SOURCE 200809L
#include <string.h>
const char *scanner(int qr[21][21]) {
  int  sz     =    (!qr[18][20]<<7) | (!!qr[18][19]<<6) | (!!qr[17][20]<<5) |  (!qr[17][19]<<4) |  (!qr[16][20]<<3) | (!!qr[16][19]<<2) | (!!qr[15][20]<<1) |  (!qr[15][19]);
  char s[8]   = {  (!qr[14][20]<<7) + (!!qr[14][19]<<6) + (!!qr[13][20]<<5) +  (!qr[13][19]<<4) +  (!qr[12][20]<<3) + (!!qr[12][19]<<2) + (!!qr[11][20]<<1) +  (!qr[11][19]),
                   (!qr[10][20]<<7) + (!!qr[10][19]<<6) + (!!qr[9][20] <<5) +  (!qr[9][19] <<4) + (!!qr[9][18] <<3) +  (!qr[9][17] <<2) +  (!qr[10][18]<<1) + (!!qr[10][17]),
                  (!!qr[11][18]<<7) +  (!qr[11][17]<<6) +  (!qr[12][18]<<5) + (!!qr[12][17]<<4) + (!!qr[13][18]<<3) +  (!qr[13][17]<<2) +  (!qr[14][18]<<1) + (!!qr[14][17]),
                  (!!qr[15][18]<<7) +  (!qr[15][17]<<6) +  (!qr[16][18]<<5) + (!!qr[16][17]<<4) + (!!qr[17][18]<<3) +  (!qr[17][17]<<2) +  (!qr[18][18]<<1) + (!!qr[18][17]),
                  (!!qr[19][18]<<7) +  (!qr[19][17]<<6) +  (!qr[20][18]<<5) + (!!qr[20][17]<<4) +  (!qr[20][16]<<3) + (!!qr[20][15]<<2) + (!!qr[19][16]<<1) +  (!qr[19][15]),
                   (!qr[18][16]<<7) + (!!qr[18][15]<<6) + (!!qr[17][16]<<5) +  (!qr[17][15]<<4) +  (!qr[16][16]<<3) + (!!qr[16][15]<<2) + (!!qr[15][16]<<1) +  (!qr[15][15]),
                   (!qr[14][16]<<7) + (!!qr[14][15]<<6) + (!!qr[13][16]<<5) +  (!qr[13][15]<<4) +  (!qr[12][16]<<3) + (!!qr[12][15]<<2) + (!!qr[11][16]<<1) +  (!qr[11][15]),
                   (!qr[10][16]<<7) + (!!qr[10][15]<<6) + (!!qr[9][16] <<5) +  (!qr[9][15] <<4) + (!!qr[9][14] <<3) +  (!qr[9][13] <<2) +  (!qr[10][14]<<1) + (!!qr[10][13]) };
  return strndup(s,sz);
}
///////////
