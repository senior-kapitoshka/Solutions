#include <string>
#include <deque>

void foo(unsigned x,std::deque<int>& vc){
  if(x<10 || x==0 ||x==1) {
    vc.push_back(x);
    return;
  }
  while(x>9){
    vc.push_front(x%10);
    x/=10;
  }
  vc.push_front(x);
}

unsigned add(unsigned x, unsigned y)
{
  std::deque<int>a,b;
  foo(x,a);
  foo(y,b);
  std::string s;
  if(a.size()>b.size()){
    for(size_t i=0;i<a.size()-b.size();++i){
      s+=std::to_string(a[i]);
    }
    std::for_each(b.begin(),b.end(),[&a,&s,j=a.size()-b.size()](auto& i)mutable{
      return s+=std::to_string(i+a[j++]);
    });
  }else if(a.size()<b.size()){
   for(size_t i=0;i<b.size()-a.size();++i){
    s+=std::to_string(b[i]); 
   }
    
    std::for_each(a.begin(),a.end(),[&b,&s,j=b.size()-a.size()](auto& i)mutable{
      return s+=std::to_string(i+b[j++]);
    });
  }else{
    std::for_each(a.begin(),a.end(),[&b,&s,j=0](auto& i)mutable{
      return s+=std::to_string(i+b[j++]);
    });
  }
  return std::stoll(s);
}

//////////////////
unsigned add(unsigned x, unsigned y)
{
    std::string res = "";
    while((x>0)&(y>0))
    {
        res = std::to_string(x%10 + y%10) + res;
        x = x/10;
        y = y/10;
    }
    if (x==0) res = std::to_string(y) + res;
    else res = std::to_string(x) + res;
    return std::stoi(res);
}
//////////////
#include <string>

unsigned add(unsigned x, unsigned y)
{
  if (!x && !y) return 0;
	std::string res;
	while (x > 0 || y > 0)
	{
		res = std::to_string(x % 10 + y % 10) + res;
		x /= 10;
		y /= 10;
	}
	return std::stoul(res);
}