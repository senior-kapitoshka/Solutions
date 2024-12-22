#include <string>

auto makeLooper(const std::string& str) 
{
  return [str/*захват по ссылке не дает результат*/, i = 0]() mutable { return str[i++ % str.size()]; };
}
///////////////////
#include <string>

auto makeLooper(const std::string& str) 
{
  return [str, i=std::size_t{0}]() mutable {
    return str[i++ % str.size()];
  };
}
//////////////
#include <string>

class Dummy
{
    const std::string str;
    int index;

public:
    Dummy(const std::string s) : str(s), index(-1)
    {
    }

    auto operator ()()
    {
        return str[++index % str.length()];
    }
};

auto makeLooper(const std::string& str) 
{
    Dummy d(str);
    return d;
}