#include <stack>
#include <algorithm>

class DirReduction
{
public:
    static std::vector<std::string> dirReduc(std::vector<std::string> &arr){
      std::vector<std::string>res;
      std::stack<std::string>q;
      std::for_each(arr.begin(),arr.end(),[&q](auto& s){
        if(q.empty())q.push(s);
        else{
          if((s=="SOUTH" && q.top()=="NORTH")||(s=="NORTH"&&q.top()=="SOUTH")){
            q.pop();
          }else if((s=="EAST"&&q.top()=="WEST")||(s=="WEST"&&q.top()=="EAST")){
            q.pop();
          }else q.push(s);
        }
      });
      while(!q.empty()){
        res.emplace_back(q.top());
        q.pop();
      }
      std::reverse(res.begin(),res.end());
      return res;
    }
};
//////////////////
class DirReduction
{
public:
    static std::vector<std::string> dirReduc(std::vector<std::string> &arr)
    {
    	for (int i = 1; i < arr.size(); i++)
      {
        if (arr[i] == "NORTH" && arr[i - 1] == "SOUTH" ||
            arr[i] == "EAST"  && arr[i - 1] == "WEST"  ||
            arr[i] == "SOUTH" && arr[i - 1] == "NORTH" ||
            arr[i] == "WEST"  && arr[i - 1] == "EAST")
          {
            arr.erase(arr.begin() + i - 1);
            arr.erase(arr.begin() + i - 1);
            i = 0;
          }
      }
   	 	return arr;
    }
};
//////////////////
using namespace std;
class DirReduction
{
public:
    static std::vector<std::string> dirReduc(std::vector<std::string> &arr) {
      vector<string> list = arr;
      for(auto it = list.begin(); it != prev(list.end()) && it != list.end(); it++)
        // Based on N/S both having 5 chars and W/E both having 4
        if(it->length() == next(it)->length() &&  *it != *next(it)) {
          list.erase(it, next(next(it)));
          return dirReduc(list);
        }
      return list;
  }
};