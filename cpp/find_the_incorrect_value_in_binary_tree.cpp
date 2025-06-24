#include <iostream>
std::vector<int> findIncorrectNumber(const std::vector<int>& tree) {
  std::vector<int>res={0,0};
  for(size_t i=0,n=tree.size();i<n;++i){
    size_t x=2*i+1;
    size_t y=2*i+2;
    if(x<n && y<n){
      if(tree[i]!=tree[x]+tree[y]){
        if(2*x+1<n && 2*x+2<n && tree[x]!=tree[2*x+1]+tree[2*x+2]){
          res[0]=x;
          res[1]=tree[i]-tree[y];
          break;
        }else if(2*y+1<n && 2*y+2<n && tree[y]!=tree[2*y+1]+tree[2*y+2]){
          res[0]=y;
          res[1]=tree[i]-tree[x];
          break;
        }else{
          if(i>0){
            res[0]=y;
            res[1]=tree[i]-tree[x];
            break;
          }else{
            res[0]=i;
            res[1]=tree[x]+tree[y];
            break;
          }
        }
      }
    }
  }
    return res;
}
/////////////////
std::vector<int> findIncorrectNumber(const std::vector<int>& tree)
{
  for (int i = (int) tree.size()/2 - 1 ; i > 0 ; i--)
  {
    int v1 = tree[2*i+1] + tree[2*i+2];
    int parent = (i-1)/2;
    int sibling = 2*parent + (3-(i-2*parent));
    int v2 = tree[parent] - tree[sibling];
    
    if (v1 == v2 && v1 != tree[i])
      return {i, v1};
    if (v1 != v2 && v2 == tree[i])
      return {2*i+2, tree[i] - tree[2*i+1]};
  }
  return {0, tree[1] + tree[2]};
}
/////////////
