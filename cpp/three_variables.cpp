
#include <array>
int* solveEq(int eq[3][4]){
  std::array<int,3>res={0,0,0};
  for(int i=-100;i<=100;++i){
    for(int j=-100;j<=100;++j){
      for(int l=-100;l<100;++l){
        if(eq[0][0] * i + eq[0][1] * j + eq[0][2] * l == eq[0][3]
            && eq[1][0] * i + eq[1][1] * j + eq[1][2] * l == eq[1][3]
            && eq[2][0] * i + eq[2][1] * j + eq[2][2] * l == eq[2][3])
               {
                res[0]=i;
                res[1]=j;
                res[2]=l;
                return res.data();
        }
      }
    }
  }
  return res.data();
}

//////////////////////
#include <cmath>
int* solveEq(int eq[3][4]){
  double d=eq[0][0]*(eq[1][1]*eq[2][2])-//
    eq[0][0]*(eq[1][2]*eq[2][1]) - //
    
    eq[0][1]*(eq[1][0]*eq[2][2])+//
    eq[0][1]*(eq[1][2]*eq[2][0])+//
    
    eq[0][2]*(eq[1][0]*eq[2][1])-//
    eq[0][2]*(eq[1][1]*eq[2][0]);//
  
  
  double x=eq[0][3]*(eq[1][1]*eq[2][2])-
    eq[0][3]*(eq[1][2]*eq[2][1]) - 
    
    eq[0][1]*(eq[1][3]*eq[2][2])+
    eq[0][1]*(eq[1][2]*eq[2][3])+
    
    eq[0][2]*(eq[1][3]*eq[2][1])-
    eq[0][2]*(eq[1][1]*eq[2][3]);
  
  x/=d;
  
  double y=/*eq[0][3]*(eq[1][3]*eq[2][2])+
    eq[0][3]*(eq[1][2]*eq[2][3]) +
    
    eq[0][3]*(eq[1][0]*eq[2][2])-
    eq[0][3]*(eq[1][2]*eq[2][0])-
    
    eq[0][2]*(eq[1][0]*eq[2][3])+
    eq[0][2]*(eq[1][3]*eq[2][0]);*/
    - (eq[1][0]*eq[2][2]-eq[1][2]*eq[2][0]) * eq[0][3] / d 
            + (eq[0][0]*eq[2][2]-eq[0][2]*eq[2][0]) * eq[1][3] / d
            - (eq[0][0]*eq[1][2]-eq[0][2]*eq[1][0]) * eq[2][3] / d;
  //y/=d;
  double z=eq[0][0]*(eq[1][1]*eq[2][3])-
    eq[0][0]*(eq[1][3]*eq[2][1]) - 
    
    eq[0][1]*(eq[1][0]*eq[2][3])+
    eq[0][1]*(eq[1][3]*eq[2][0])+
    
    eq[0][3]*(eq[1][0]*eq[2][1])-
    eq[0][3]*(eq[1][1]*eq[2][0]);
    
  z/=d;
  
  int* sol = new int;
sol[0] = round(x); sol[1] = round(y); sol[2] = round(z);

return sol;
}

///////////////////////
int* solveEq(int eq[3][4]) {
  auto calcDeteterminant = [] (auto& m, auto replaceCol) {
    int i = (0 == replaceCol) ? 3 : 0;
    int j = (1 == replaceCol) ? 3 : 1;
    int k = (2 == replaceCol) ? 3 : 2;
    
    return m[0][i] * m[1][j] * m[2][k] +
           m[0][j] * m[1][k] * m[2][i] +
           m[0][k] * m[1][i] * m[2][j] -
           m[0][k] * m[1][j] * m[2][i] -
           m[0][j] * m[1][i] * m[2][k] -
           m[0][i] * m[1][k] * m[2][j];
  };

  int Determinant = calcDeteterminant(eq, 3);
  static int res[3] = {};
  for (int i = 0; i < 3; ++i) res[i] = calcDeteterminant(eq, i) / Determinant;
  return res;
}

//////////////////////
#include <cmath>
using namespace std;

int* solveEq(int eq[3][4]) {
    int n,i,k,j,p;
    n = 3;
    if (eq[0][0] == 0) {
        for (j = 0; j <= n; j++) {
            int temp = eq[0][j];
            eq[0][j] = eq[1][j];
            eq[1][j] = temp;
        }
    }
    double a[10][10], l[10][10]={0}, u[10][10]={0}, sum, b[10], z[10]={0}, x[10]={0};
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++)
            a[i][j] = eq[i-1][j-1];
    }
    for(i = 1; i <= n; i++)
        b[i] = eq[i-1][3];
    //********** LU decomposition **********//
    for(k = 1; k <= n; k++) {
        u[k][k] = 1;
        for(i = k; i <= n; i++) {
            sum = 0;
            for(p = 1; p <= k - 1; p++)
                sum += l[i][p] * u[p][k];
            l[i][k] = a[i][k] - sum;
        }
        for(j = k + 1; j <= n; j++) {
            sum = 0;
            for(p = 1; p <= k - 1; p++)
                sum += l[k][p] * u[p][j];
            u[k][j] =( a[k][j] - sum) / l[k][k];
        }
    }
    //********** FINDING Z; LZ = b *********//
    for(i = 1; i <= n; i++) {
        sum = 0;
        for(p = 1; p < i; p++)
        sum += l[i][p] * z[p];
        z[i] = (b[i] - sum) / l[i][i];
    }
    //********** FINDING X; UX = Z***********//
    for(i=n;i>0;i--) {
        sum = 0;
        for(p = n; p > i; p--)
            sum += u[i][p] * x[p];
        x[i] = (z[i] - sum) / u[i][i];
    }
    int* sol = (int *)calloc(3, sizeof(int));
    for (i = 0; i < n; i++)
        sol[i] = (int)(roundf(x[i + 1]));
    return sol;
}

///////////////////////
int * solveEq(int input[3][4])
{
   for(int x = -99; x <= 99; x++)
      for(int y = -99; y <= 99; y++)
         for(int z = -99; z <= 99; z++)
            if(input[0][0] * x + input[0][1] * y + input[0][2] * z == input[0][3]
            && input[1][0] * x + input[1][1] * y + input[1][2] * z == input[1][3]
            && input[2][0] * x + input[2][1] * y + input[2][2] * z == input[2][3])
               return new int[3] { x, y, z };
   std::abort();
}
//////////////////////

int* solveEq(int eq[3][4]){
   static int res[3];

   int det = (eq[0][0]*eq[1][1]*eq[2][2])
           + (eq[0][1]*eq[1][2]*eq[2][0])
           + (eq[0][2]*eq[1][0]*eq[2][1])
           - (eq[0][0]*eq[1][2]*eq[2][1])
           - (eq[0][1]*eq[1][0]*eq[2][2])
           - (eq[0][2]*eq[1][1]*eq[2][0]);

   res[0] = ((eq[0][3]*eq[1][1]*eq[2][2])
           + (eq[0][1]*eq[1][2]*eq[2][3])
           + (eq[0][2]*eq[1][3]*eq[2][1])
           - (eq[0][3]*eq[1][2]*eq[2][1])
           - (eq[0][1]*eq[1][3]*eq[2][2])
           - (eq[0][2]*eq[1][1]*eq[2][3]))/det;

   res[1] = ((eq[0][0]*eq[1][3]*eq[2][2])
           + (eq[0][3]*eq[1][2]*eq[2][0])
           + (eq[0][2]*eq[1][0]*eq[2][3])
           - (eq[0][0]*eq[1][2]*eq[2][3])
           - (eq[0][3]*eq[1][0]*eq[2][2])
           - (eq[0][2]*eq[1][3]*eq[2][0]))/det;
           
   res[2] = ((eq[0][0]*eq[1][1]*eq[2][3])
           + (eq[0][1]*eq[1][3]*eq[2][0])
           + (eq[0][3]*eq[1][0]*eq[2][1])
           - (eq[0][0]*eq[1][3]*eq[2][1])
           - (eq[0][1]*eq[1][0]*eq[2][3])
           - (eq[0][3]*eq[1][1]*eq[2][0]))/det;
   return res;         
           
           
}/////////////////////
