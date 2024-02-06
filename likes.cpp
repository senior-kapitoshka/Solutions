#include <string>
#include <vector>

std::string likes(const std::vector<std::string> &n)
{
  if(n.empty()) return "no one likes this";
  else if(n.size()==1) return n[0]+" likes this";
  else if(n.size()==2) return n[0]+" and " +n[1]+" like this";
  else if(n.size()==3) return n[0]+", " + n[1] + " and " + n[2]+" like this";
  else{
    size_t s= n.size()-2;
    
    return n[0]+", " + n[1] + " and " + std::to_string(s) +" others like this"; 
  }
    
}

/////////////////////////////////////////////////////////////////////////////


std::string likes(const std::vector<std::string> &names)
{
  const char *templates[] = {
    "no one likes this",
    "%s likes this",
    "%s and %s like this",
    "%s, %s and %s like this",
    "%s, %s and %d others like this"
  };
  const int index = names.size() > 4 ? 4 : names.size();
  
  char buf[1024];
  switch(index) {
    case 0:
      return templates[0];
    case 1:
      sprintf(buf, templates[1], names[0].c_str());
      break;
    case 2:
      sprintf(buf, templates[2], names[0].c_str(), names[1].c_str());
      break;
    case 3:
      sprintf(buf, templates[3], names[0].c_str(), names[1].c_str(), names[2].c_str());
      break;
    case 4:
      sprintf(buf, templates[4], names[0].c_str(), names[1].c_str(), names.size() - 2);
      break;
    }
  return buf; // Do your magic!
}