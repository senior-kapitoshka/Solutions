#include <vector>
#include <numeric>
#include <cmath>

class Av{
private:
  std::vector<double>vc;
public:
  Av(){};
  double operator() (double x){
    vc.push_back(x);
    return std::round(std::accumulate(vc.begin(),vc.end(),0.0)/static_cast<double>(vc.size())*100)/100;
  }
};

auto runningAverage() {
  Av a;
  return a; 
}

/////////////////////////////
#include <cmath>

auto runningAverage()
{
    return [cnt = 0, sum = 0.0](auto x) mutable
    {
        sum += x;
        return std::round(sum / (++cnt) * 100) / 100;
    };
}

//////////////////////
#include <cmath>
auto runningAverage = [](){
    int count = 0;
    double sum = 0;
    return [=] (double x) mutable {
        count++;
        sum+=x;
        return round((double)sum*100/count)/100;
    };
};

////////////////////
#include <cmath>

class RAverage
{
  public :
  
    RAverage();
    double operator()(double x);
  
  private :
  
    double m_avg;
    int m_n;
};

RAverage::RAverage() : m_avg(0.0), m_n(0) {}

double RAverage::operator()(double x)
{
  m_avg = (m_avg*m_n + x)/(m_n+1);
  m_n++;
  return std::round(100.*m_avg)/100.;
}

auto runningAverage() 
{
  return RAverage(); 
}

////////////////////
#include <math.h>

class RunningAvg
{
	public:
		RunningAvg(): sum(0), count(0) {};
		double operator() (double num) {
			sum += num;
      count++;
      
      return roundf(100 * (sum / count)) / 100.0;
		}

	private:
		double sum;
		int count;
};

auto runningAverage() {
	RunningAvg avg;

	return avg;
}

////////////////////
#include <cmath>

auto runningAverage() {
  return [sumOfElements = 0.0, numberOfElements = 0] (auto number) mutable {
    return std::round((sumOfElements += number) / ++numberOfElements * 100) / 100;
  };
}

////////////////////
#include <cmath>

auto runningAverage() {
  std::vector<double> s;

  return [=](double val) mutable {
        s.push_back(val);
        double sum = 0;
        for (auto i : s) {
            sum += i;
        }
        return round(sum / s.size() * 100) / 100.0;
    };
}

/////////////////////
#include <cmath>


class Avg{
public:  
  double operator()(double i){ acc += i; ++cnt; return rnd_2(acc / cnt); }; 
  
private:
  double  acc = 0.0;
  int     cnt = 0;
  double rnd_2(double n){ return std::round(100.0 * n) / 100.0; };
};


auto runningAverage() { return Avg(); }