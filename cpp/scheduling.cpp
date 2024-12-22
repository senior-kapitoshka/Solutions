int roundRobin(std::vector <int> j, int sl, int ind){
    int res=0;
    size_t i=0;
  while(j[ind]!=0){
    if(i==j.size()) i=0;
    if(j[i]>=sl){
        j[i]-=sl;
        res+=sl;
    }else if(j[i]<sl){
        res+=j[i];
        j[i]=0;
      }
    ++i;
  }
  return res;
}

/////////////////////////
int roundRobin(std::vector <int> jobs, const int slice, const int index) {
  int before = ((jobs[index] + slice - 1) / slice) * slice, result = 0;
  for (auto i = 0; i < jobs.size(); i ++) 
    result += std::min((i <= index ? before : std::max(before - slice, 0)), jobs[i]);
  return result;
}
//////////////////////
int roundRobin(std::vector <int> jobs, int slice, int index){
  int totalCC = 0;
  
  int currentIndex = 0;
  while(jobs[index] != 0){
    for(int i = 0; i < slice && jobs[currentIndex] != 0; i++){
      jobs[currentIndex]--;
      totalCC++;  
    }
    
    currentIndex = (currentIndex + 1) % jobs.size();
  }
  
  return totalCC;
}
///////////////////////
