#include <sstream>
std::string pattern(int n)
{
  if(n<=0) return "";
  std::stringstream ss;
  int x=n-1;
  for(int i=1;i<=n;++i,--x){
    std::string t;
    for(int j=1;j<=i;++j){
      t+=std::to_string(j%10);
    }
    t+=std::string(next(t.rbegin()),t.rend());
    x>0?ss<<std::string(x,' ')<<t<<std::string(x,' ')<<"\n":
    ss<<t<<"\n";
    t.clear();
  }
  std::string res=ss.str();
  res.pop_back();
  return res;
}

/////////////////////
std::string pattern(int n)
{
	if (n <= 0) return "";
	std::string result;
	result.reserve(n * 2 * n);
	for (int ni = 1; ni <= n; ++ni)
	{
		for (int i = ni; i < n; ++i)  result.push_back(' ');
		for (int i = 1; i < ni; ++i)  result.push_back('0' + (i % 10));
		for (int i = ni; i >= 1; --i) result.push_back('0' + (i % 10));
		for (int i = ni; i < n; ++i)  result.push_back(' ');
		if (ni != n) result.push_back('\n');
	}
	return result;
}

//////////////////
std::string pattern(int n)
{
    std::string result;
    if (n <= 0) return result;
    result.reserve(2 * n * n - 1);
    for (auto i = 1; i <= n; ++i) {
        result.append(n - i, ' ');
        for (auto j = 1; j <= i; ++j)
            result.append(1, '0' + j % 10);
        for (auto j = i - 1; j > 0; --j)
            result.append(1, '0' + j % 10);
        result.append(n - i, ' ');
        if (i < n)
            result.append(1, '\n');
    }
    return result;
}