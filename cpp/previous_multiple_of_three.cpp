int prev_mult_of_three (int n) {
  std::string x=std::to_string(n);
  while(true){
    if(std::stoi(x)%3==0) return std::stoi(x);
    if(std::stoi(x)<10 && std::stoi(x)%3!=0) return -1;
    x.pop_back();
  }
  return -1;
}

///////////////////
int prev_mult_of_three(int n) {
  while (n % 3 != 0)
    n /= 10;
  return n == 0 ? -1 : n;
}

/////////////////