std::vector<std::vector<int>> tourney(const std::vector<int>& itr) {
  std::vector<std::vector<int>> ans;
  ans.push_back(itr);
    bool f=true;
    while(f){
      int n=static_cast<int>(ans.back().size());
      if(n%2==0){
        std::vector<int>tmp;
        for(int i=0;i<n;i+=2){
            tmp.push_back(std::max(ans.back()[i],ans.back()[i+1]));
        }
        ans.push_back(tmp);
        if(tmp.size()==1) f=false;
        }else{
        std::vector<int>tmp;
        tmp.push_back(ans.back().back());
        for(int i=0;i<n-1;i+=2){
            tmp.push_back(std::max(ans.back()[i],ans.back()[i+1]));
            }
        ans.push_back(tmp);
        if(tmp.size()==1) f=false;
            
        }
    }
 
  return ans;
}

///////////////////////////////////////////////////////////
std::vector<std::vector<int>> tourney(const std::vector<int>& input) {
  std::vector<std::vector<int>> result(1, input);
  while(result.back().size() > 1) {
    std::vector<int> iteration;
    const auto& last = result.back();
    if (result.back().size() % 2 == 1) iteration.push_back(last.back());
    for (std::vector<int>::size_type i = 1; i < last.size(); i += 2) iteration.push_back(std::max(last[i-1], last[i]));
    result.push_back(iteration);
  }
  return result;
}