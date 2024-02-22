#include <iostream>
#include <vector>

using namespace std;

vector<vector<long long>>sub(vector<vector<long long>>mx,unsigned int n, unsigned int x, unsigned int y){
  vector<vector<long long>>sm(n-1);
  unsigned int si=0;
  for(size_t i=0;i<n;++i){
    sm[si]=vector<long long>(n-1);
    unsigned int sj=0;
    if(i==y) continue;
    for(size_t j=0;j<n;++j){
      if(j==x) continue;
      sm[si][sj]=mx[i][j];
      ++sj;
    }
    ++si;
  }
  return sm;
}

long long dett(vector< vector<long long> > m,unsigned int n) {
 long long dt=0;
  //if (m.empty()) return 0;
  if(m.size()==1) return m[0][0];
  if(m.size()==2) return m[0][0]*m[1][1]-m[0][1]*m[1][0];
  for(size_t x=0;x<m.size();++x){
    dt+=((x%2==0?1:-1)*m[0][x]*dett(sub(m,n,x,0),n-1));
  }
  return dt;
}

long long determinant(vector< vector<long long> > m) {
 //long long dt=0;
  //if (m.empty()) return 0;
 /* if(m.size()==1) return 1;
  if(m.size()==2) return m[0][0]*m[1][1]-m[0][1]*m[1][0];
  unsigned int n=0;
  if(m.size()>2) n=m.size();
  for(size_t x=0;x<n;++x){
    dt+=((x%2==0?1:-1)*m[0][x]*dett(sub(m,n,x,0),n-1));
  }*/
  return dett(m,m.size());
}

///////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <vector>

using namespace std;

long long determinant(vector< vector<long long> > m) {
  if (m.size() == 1) return m[0][0];
  long long result = 0;
  for (int i = 0; i < m.size(); i++) {
    vector< vector<long long> > submatrix;
    for (int j = 1; j < m.size(); j++) {
      vector<long long> row;
      for (int k = 0; k < m.size(); k++) if (k != i) row.push_back(m[j][k]);
      submatrix.push_back(row);
    }
    result += determinant(submatrix) * (i % 2 == 0 ? m[0][i] : -m[0][i]);
  }
  return result;
}