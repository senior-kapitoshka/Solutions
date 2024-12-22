#include <sstream>

std::string pattern(int n)
{
  if(n<=0) return "";
  std::stringstream ss;
  int j=n*2-3;
  int k=n;
  for(int i=1;i<=n-1;++i){
    ss<<std::string(n-k,' ') <<i%10<<std::string(j,' ')<<i%10<<std::string(n-k,' ') <<"\n";
    j-=2;
    --k;
  }
  ss<<std::string(n-1,' ')<<n%10<<std::string(n-1,' ')<<"\n";
  j=1;
  k=2;
  for(int i=n-1;i>0;--i){
    ss<<std::string(n-k,' ') <<i%10<<std::string(j,' ')<<i%10<<std::string(n-k,' ') <<"\n";
    j+=2;
    ++k;
  }
  std::string res=ss.str();
  res.pop_back();
    return res;
}
/////////////////////
std::string pattern(int n) {
  if (n < 1) return "";
  std::string result(2 * n * (2 * n - 1) - 1, ' ');
  for (auto j = 1; j < 2 * n - 1; j ++) result[2 * n * j - 1] = '\n';
  for (auto j = 0; j < n; j ++) 
    result[2 * n * j + j] =
    result[2 * n * j + (2 * n - 2 - j)] =
    result[2 * n * (2 * n - 2 - j) + j] =
    result[2 * n * (2 * n - 2 - j) + (2 * n - 2 - j)] = '0' + ((j + 1) % 10);
  return std::move(result);
}  
//////////////
std::string pattern(int n)
{
    std::string res = "";
    for(int i = 1; i <= 2*n-1; ++i)
    {
        std::string line(2*n-1, ' ');
        line[i-1] = line[2*n-i-1] = '0' + (n-abs(n-i))%10;
        res += line;
        if(i+1 < 2*n) res += "\n";
    }
    return res;
}
//////////////
std::string pattern(int n)
{
	std::string result;
	for (int i = 1; i < 2 * n; ++i)
	{
		std::string line = std::string(2 * n - 1, ' ');
		line[i - 1] = line[line.size() - i] = (i <= n ? i : n + (n - i)) % 10 + 48;
		result += line + '\n';
	}
	return result.substr(0, result.size() - 1);
}
//////////////////
