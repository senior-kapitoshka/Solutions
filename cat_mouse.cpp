#include <string>
#include <algorithm>

std::string catMouse(std::string f, unsigned int j){
  if(f.find('D')==std::string::npos||
     f.find('C')==std::string::npos||
     f.find('m')==std::string::npos)
    return "boring without all three";
  auto c=find(f.begin(),f.end(),'C');
  auto d=find(f.begin(),f.end(),'D');
  auto m=find(f.begin(),f.end(),'m');
  
  int dd=0;
  if(distance(f.begin(),c)>distance(f.begin(),m)){
    dd=distance(m,c);
    dd-=1;
  }else {
    dd=distance(c,m);
    dd-=1;
  }
  if((distance(f.begin(),d)>distance(f.begin(),m) 
      && distance(f.begin(),d)<distance(f.begin(),c)
      )
     ||(distance(f.begin(),d)<distance(f.begin(),m) 
        && distance(f.begin(),d)>distance(f.begin(),c) )){
    if( dd<static_cast<int>(j))
      return "Protected!";
  }
     
  return dd>static_cast<int>(j)?"Escaped!":"Caught!";
  
}

//////////////////////////////////////////////////////


#include <string>

std::string catMouse(std::string field, unsigned int jump){
  std::size_t found_C = field.find("C");
  std::size_t found_m = field.find("m");
  std::size_t found_D = field.find("D");

  auto dog_protects = (found_D>found_C&&found_D<found_m) ? true : false;
  auto cat_in_reach = (abs(found_m-found_C)<=jump) ? true : false;

  if (found_C==std::string::npos||found_m==std::string::npos||found_D==std::string::npos)
  {
  return "boring without all three";
  }
  else if(cat_in_reach&&dog_protects)
  {
  return "Protected!";
  }
  else if(cat_in_reach&&!dog_protects)
  {
  return "Caught!";
  }
  else
  {
  return "Escaped!";
  }
}