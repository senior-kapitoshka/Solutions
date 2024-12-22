#include <sstream>
#include <initializer_list>
#include <iostream>

class X {
	int m_a;
	int m_b;
public:
  X():m_a(1),m_b(2){}
  X(int a):m_a(a),m_b(2){}
  X(int a,int b):m_a(a),m_b(b){}
  X(const X& rhs)
    :m_a(rhs.m_a),m_b(rhs.m_b){}
  X(const X&& rhs)
    :m_a(std::move(rhs.m_a)),m_b(std::move(rhs.m_b)){}
  X& operator=(const X& rhs){
    if(&rhs==this) return *this;
    m_a=rhs.m_a;
    m_b=rhs.m_b;
    return *this;
  }
  X& operator=(X&& rhs){
    if(this!=&rhs) 
    m_a=std::move(rhs.m_a);
    m_b=std::move(rhs.m_b);
    return *this;
  }
  
  X& operator+=(const X& rhs){
    m_a+=rhs.m_a;
    m_b+=rhs.m_b;
    return *this;
  }
  X& operator++(){
    ++m_a;
    ++m_b;
    return *this;
  }
  X operator++(int){
    X x(*this);
    ++m_a;
    ++m_b;
    return x;
  }
  ~X()=default;
  friend std::ostream& operator<<(std::ostream& os,const X& r){
    os<<"[" << r.m_a << "," << r.m_b << "]";
  return os;
}
	std::string print(); // used for testing
};

X operator+(X l,X r){
  l+=r;
  return l;
}
/*std::ostream& operator<<(std::ostream& os, X& r){
  os<<"[" << r.m_a << "," << r.m_b << "]";
  return os;
}*/

std::string X::print()
{
		std::stringstream s;
		s << "[" << m_a << "," << m_b << "]";
		return s.str();
}


/*  Expected:
 *  Use cases of the class that are expected to be working.
*/
/*
  { X{}                   } // see the logs, find out what happens with m_a and m_b
	{ X{1,2};				    	  }
  { X{1};				       	  } // see the logs, find out what happens with m_b
	{ X x{}, y{x};			  	} 
	{ X x{}, y = x;				  } // as expected
	{ X x{}, y{}; y += x;		}
	{ X x{}; ++x;				    }  // ++m_a, ++m_b
	{ X x{}; x++;				    }  // m_a++, m_b++
	{ X x{}, y{}; x + y;		}  // as expected
	{ cout << X{1,2};				}  // shows "[1,2]"
*/

