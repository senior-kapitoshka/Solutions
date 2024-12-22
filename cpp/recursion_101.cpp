//todo try to metaprogramming

std::pair<int, int> solve (int a, int b){
return (a>=2*b && b!=0)?solve(a-2*b,b):(b>=2*a && a!=0)?solve(a,b-2*a):std::make_pair(a,b);
}
///////////////////////////
