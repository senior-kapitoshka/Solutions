#include <iostream>
#include <string>
#include <vector>

int check_up(const std::vector<std::string>& mx,size_t i,size_t j){
    if(j==7 || j==0 || i==0 || mx[i-1][j]=='*') return 0;
    if(mx[i-1][j-1]=='*' || mx[i-1][j+1]=='*') return 0;
    return 1;
}
int check_dn(const std::vector<std::string>& mx,size_t i,size_t j){
    if(j==7 || j==0 || i==7 || mx[i+1][j]=='*') return 0;
    if(mx[i+1][j-1]=='*' || mx[i+1][j+1]=='*') return 0;
    return 1;
}
int check_lf(const std::vector<std::string>& mx,size_t i,size_t j){
    if(j==0 || i==0 || i==7 || mx[i][j-1]=='*') return 0;
    if(mx[i+1][j-1]=='*' || mx[i-1][j-1]=='*') return 0;
    return 1;
}
int check_rt(const std::vector<std::string>& mx,size_t i,size_t j){
    if(j==7 || i==0 || i==7 || mx[i][j+1]=='*') return 0;
    if(mx[i+1][j+1]=='*' || mx[i-1][j+1]=='*') return 0;
    return 1;
}



void traverse(const std::vector<std::string>& mx,int & res){
    for(size_t i=0;i<8;++i){
        for(size_t j=0;j<8;++j){
            if(mx[i][j]=='.'){
                res+=check_up(mx,i,j);
                res+=check_dn(mx,i,j);
                res+=check_lf(mx,i,j);
                res+=check_rt(mx,i,j);
            }
        }
    }
}


int main() 
{
	std::vector<std::string>mx;
    mx.reserve(8);
    for(int i=0;i<8;++i){
        std::string s;
        std::getline(std::cin,s);
        mx.push_back(s);
    }
    int res=0;
    traverse(mx,res);
    std::cout<<res;

	return 0;
}