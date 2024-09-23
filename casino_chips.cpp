#include <algorithm>
int solve(std::vector<int> v){
  std::cout<<"Assert::That(solve(VI{";
  for(auto i:v){
    std::cout<<i<<",";
  }
  std::cout<<"}),Equals(x));\n";
  if(v[0]==v[1] && v[1]==v[2] && v[0]==v[2] && v[0]%2==0) return (v[0]+v[1]+v[2])/2;
  else if(v[0]==v[1] && v[1]==v[2] && v[0]==v[2] && v[0]%2!=0) return (v[0]+v[1]+v[2])/3;
  std::sort(v.begin(),v.end());
  if((v[0]==v[1] && v[0]%2==0 && (v[0]+v[1])>v[2]) || (v[1]==v[2]) || (v[0]==v[1] && v[0]%2!=0 && (v[0]+v[1])>v[2])){
    return (v[0]+v[1]+v[2])/2;
  }else if((v[0]==v[1] && v[0]%2!=0 && (v[0]+v[1])<v[2])
          || (v[0]==v[1] && v[0]%2!=0 && (v[0]+v[1])<v[2])){
    return v[0]+v[1];
  }
  return (v[0]+v[1])<=v[2]?(v[0]+v[1]):(v[0]+v[1]+v[2])/2;
} 

//////////////////////
int solve(std::vector<int> v){  
    sort(v.begin(), v.end()); 
    return std::min((v[0] + v[1] + v[2])/2|0, v[0] + v[1] );
} 

/////////////////
int solve(std::vector<int> v){  
  sort (v.begin(), v.end());
  if (v[0] + v[1] <= v[2])
    return v[0] + v[1];
  else
    return (v[0] + v[1] + v[2]) / 2;
} 

//////////////
int solve( std::vector< int > v ) {
  sort( v.begin(), v.end() );
  return std::min( v[ 0 ] += v[ 1 ], v[ 0 ] + v[ 2 ] >> 1 );
}

////////
int solve(std::vector<int> v) {
  return v[0] >= v[1] + v[2] ? v[1] + v[2] :
         v[1] >= v[0] + v[2] ? v[0] + v[2] :
         v[2] >= v[0] + v[1] ? v[0] + v[1] :
         (v[0] + v[1] + v[2]) / 2;
} 

////////////////
int solve(std::vector<int> v) {  
  int days {};
  std::sort(v.begin(), v.end());
  while (v.at(1) != 0) {
    --v.at(1);
    --v.at(2);
    std::sort(v.begin(), v.end());
    days++;
  }
  return days;
} 

//////////////////