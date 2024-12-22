#include <string>

struct A{
  auto operator() (int number){
    return number % 2 == 0 ? "Even" : "Odd";
  }
  auto operator[] (int number){
     return operator()( number ); 
  }
}evenOrOdd;

/*std::string evenOrOdd(int number) {
  return number % 2 == 0 ? "Even" : "Odd";
}*/

///////////////////////////////////
#include <string>
#include <array>

struct evenOrOdd_type {
  static inline const std::array<const char*,2> ret={"Even","Odd"};
  std::string operator [](int idx) const {
     return ret[idx&1];
  }
  std::string operator ()(int idx){
    return ret[idx&1];
  }
} evenOrOdd;

//////////////////////////
class EvenOrOdd
{
  public:
    std::string_view operator()(int number)
    {
        return even_or_odd(number);
    }
    std::string_view operator[](int number)
    {
        return even_or_odd(number);
    }
  private:
    inline constexpr std::string_view even_or_odd(const int number) const noexcept
    {
        return number % 2 == 0 ? "Even" : "Odd";
    }
};

EvenOrOdd evenOrOdd;


/////////////////////////////////