#include <fmt/format.h>
#include <algorithm>
#include <sstream>
using namespace std;

class Carboat
{
  public:
  static string howmuch(int m, int n){
    std::stringstream ss;
      for(int x=0;x<n/6;++x){
        for(int y=0;y<n/6;++y){
          if(7*x+2==9*y+1 && 7*x+2>=((m<n)?m:n) && 7*x+2<=((m<n)?n:m)){
            ss<<fmt::format("[M: {} B: {} C: {}]",7*x+2,x,y);
          }
        }
      }

    return "["+ss.str()+"]";
  }
};

/////////////////////////
/*
So the code starts with this:

class Carboat {
public:
    static string howmuch(int m, ... stop it!
  
What is this?!  Java?  Just stop for one moment and think.  What does
an instance of Carboat do?  If I say "Carboat foo;"  what can I do with
foo?  Nothing!  The only method in the class Carboat is static, and can
only be called by "Carboat::howmuch(...)".  Why is it a class?  It makes
no sense, and adds more to the idiocy that is applying OOP to everything.

No.  I'll show you, how you do this, and it aint using no bloody class.
*/

#include <algorithm> // for std::min and std::max
#include <string>
#include <vector>


// The functions of my application is defined in its own namespace, in
// accordance with good C++ practice.
namespace App {

// Used later, ignore for now.
std::string task_notation(std::vector<int>);

std::string howmuch(int m, int n)
{
  // The task text basically states that m and n are both >= 0, so
  // I cannot assume m is less than n
  int low = std::min(m, n);
  int high = std::max(m, n);
  
  // Storage for answers that are found
  std::vector<int> answers;
  
  // Iterate through each possible amount of money in the
  // range between m and n, from low to high
  for (int money = low; money <= high; ++money) {
  
    // The task stated that after buying 9 cars costing some arbitrary
    // value c, there would be 1 unit of money left.  I can easily
    // calcuate this using modulus, where money % 9 is equal to 1 if this
    // is true for the chosen amount of money.  Same goes for 7 boats.
    if (money % 9 == 1 && money % 7 == 2) {
      // I do not need to store how many boats or cars the amount of money
      // buys, it is given from the amount of money.
      answers.push_back(money);
    }
  }
  
  // The final step is to turn the answers found into the special
  // notation used by the task.  For this I use a separate function
  // to add clarity and structure.
  return task_notation(answers);
}  

std::string task_notation(std::vector<int> answers)
{
  std::string answer = "["; // The answers starts with a bracket.
  
  // For each answer
  for (auto money : answers) {
    // Calculate the actual number of boats and cars.
    int cars = money / 9;
    int boats = money / 7;
    
    // Put together answer of the form ["M:f", "B:b", "C:c"]
    // where f is money, b is boats, and c is cars.
    
    // Well.  No.
    
    // You see.  The task asks for a data structure that looks
    // like this [["M: f", "B: b", "C: c"], ...].  Presumably it's
    // a list of lists of 3 strings in some language.  Which in 
    // canonical C++ maps to a vector of a tuple of 3 strings.  But
    // the example test cases uses a string of the form 
    // "[[M: f B: b C: c]...]" which is kind of weird.
    
    // Another error is that it's not specified what the order of the 
    // answers should be in.  Perhaps that's just simulating the real
    // world, where specifications are commonly lacking such important
    // aspects and you have to derive them from other sources yourself.
    std::string part;
    
    part += "[M: " + std::to_string(money)
         +  " B: " + std::to_string(boats)
         +  " C: " + std::to_string(cars) + "]";
    
    // Add it to the answer string.
    answer += part;
  }
  
  answer += "]"; // The answers also ends with a bracket.
  
  return answer;
}
  

} // namespace App


// Finally, lets deal with the stupid task code.  It expects
// Carboat::howmuch(...) to call our function.  This is conveniently
// similar to App::howmuch(...), so here I'm just transforming it
// with a preprocessor define.  Ugly hack, but it works.
#define Carboat App

// Of course, to add insult to injury, and for reasons that that are
// beyond comprehension, the test code requires the following evil
// statement to be present, or it fails to compile.
using namespace std;

////////////////////////
class Carboat
{

  public:
  static std::string howmuch(int m, int n) {
     if(n<m) std::swap(m, n);
     std::stringstream ret;
     ret << '[';
     for(int money = m; money <= n; money++) {
       if(money % 9 == 1 && money % 7 == 2) {
         ret<<"[M: "<<money<<" B: "<<money/7<<" C: "<<money/9<<"]";
       }
     }
     ret<<']';
     return ret.str();
  }
};

///////////////////
class Carboat {
    public:
    static std::string howmuch(int m, int n) {
        std::stringstream result;
        result << "[";
        for(int i = std::min(m, n); i <= std::max(m, n); i++) {
            if ((i % 7 == 2) && (i % 9 == 1)) result << "[M: " << i << " B: " << i / 7 << " C: " << i / 9 << "]";
        }
        result << "]";
        return result.str();
    }
};

/////////////////
