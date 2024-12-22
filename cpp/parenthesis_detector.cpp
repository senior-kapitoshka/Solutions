#define isParenthesized() false
bool (isParenthesized)() {
  return true;
}

///////////////////////
#define isParenthesized W + A
typedef bool(*U)();
bool E(){return true;}
class S{public:
int operator()(){return 0;}};
class Q{public:
bool R;
Q(bool R):R(R){}
Q operator!(){return Q(true);}
bool operator+(int){return R;}
U operator+(S){return E;}};
Q W(false);
S A;

/////////////////
auto isParenthesized = [] () { return true; };
#define isParenthesized() [] { return false;}()

////////////////

struct A {
  A operator !() { return {}; }
  bool operator ()() { return true; }
};

#define isParenthesized !A{}