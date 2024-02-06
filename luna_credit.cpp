class Kata {
  public:
  static bool validate(long long int n) {
    int ans=0;
    std::string s=std::to_string(n);
    auto dgs=s.size();
    int pr=dgs%2;
    for(unsigned long i=0;i<s.size();++i){
      int d=s[i]-'0';
      if(i%2==pr){
        d*=2;
        if(d>9){
          d-=9;
        }
      }
      ans+=d;
    }
    return (ans%10)==0;
    
  }
};


//////////////////////////////////////////////////////////


static bool validate(long long int n) {
    std::vector<int> digits {getDigits(n)};
    std::vector<int> sum;
    auto itBeginDigits = digits.begin();
    bool isOddNumber = digits.size()%2;
    
    if(isOddNumber) std::advance(itBeginDigits, 1);
    
    auto counter {1};
    std::transform(itBeginDigits, digits.end(), std::back_inserter(sum),
                   [&counter](auto a1){return (counter++)%2 ? a1*2 : a1;});
                    
    int startElem = isOddNumber ? digits.at(0) : 0;
    int elemSum = std::accumulate(sum.begin(), sum.end(), startElem,
                                  [](auto a1, auto a2){return (a2>9 ? a2-9+a1: a2+a1);});
                                  
    bool isValid = elemSum%10 == 0;
    return isValid;
  }
  
  
  static std::vector<int> getDigits(long long int n){
    std::vector<int> vec;
    while(n){
      vec.emplace_back(n%10);
      n /= 10;
    }
    std::reverse(vec.begin(), vec.end());
    return vec;
  }
