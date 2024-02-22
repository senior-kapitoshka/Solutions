std::string get_middle(std::string i) 
{
  std::string r;
  if(i.size()==1 || i.size()==2) return i;
  if(i.size()%2==0) {
    int k=0;
    int j=(int)i.size()-1;
    while(k<j){
      ++k;
      --j;
    }
    r+=i[j];
    r+=i[k];
    
  }
  if(i.size()%2!=0){
    int k=0;
    int j=(int)i.size()-1;
    while(k<j){
      ++k;
      --j;
    }
    r+=i[k];
  }
  return r;
}///////////////////////////////////////
std::string get_middle(std::string input) 
{
  int i = input.length();

	if ((i % 2) == 0) 
		return input.substr(i/2 - 1, 2);
    
  else
	  return input.substr(i/2, 1);
}
/////////////////////////////
std::string get_middle(std::string input) 
{
  return input.substr((input.size()-1)/2,(input.size()+1)%2+1);
}