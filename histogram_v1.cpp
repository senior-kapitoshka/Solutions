#include <numeric>
#include <regex>
std::string histogram(std::vector<int> r)
{
  if(std::all_of(r.begin(),r.end(),[](auto& c){return c==0;})){
    return "-----------\n1 2 3 4 5 6\n";
  }
  std::vector<std::string>vs;
  int mx=*std::max_element(r.begin(),r.end());
  int i=1;
  for(char j=0;j<11;++j){
    std::string t(mx+3,' ');
    if(j%2==0){
      std::string s=std::to_string(i);
      t[0]=s[0];
      t[1]='-';
      for(int l=2;l<=r[i-1]+1;++l){
         t[l]='#';
      }
      if(r[i-1]!=0)t[r[i-1]+2]='*';
      ++i;
    }else if(j%2!=0){
      t[1]='-';
    }
    std::reverse(t.begin(),t.end());
   vs.push_back(t);
  }
    std::vector<std::string>res;
  size_t x=0;
  std::sort(r.begin(),r.end(),std::greater<int>());
  std::stringstream ss;
  for(size_t i=0;i<vs[0].size();++i){
    for(size_t j=0;j<vs.size();++j){
      if(vs[j][i]!='*')ss<<vs[j][i];
      else{
        ss<<std::to_string(r[x]);
        if(r[x]>=10) ++j;
        ++x;
      }
      }  
    ss<<"\n";
    }
  std::string ans=ss.str();
  std::regex rx("[\\s]+\\n");
    return std::regex_replace(ans,rx,"\n");;
}

/////////////////
std::string histogram(std::vector<int> results)
{
    std::string  result;

    int maxElement = *std::max_element(results.begin(), results.end());
    
    for (int currentLevel = maxElement; currentLevel >= 0; --currentLevel)
    {
       std::string  line;
       
       for (int i = 0; i < 6; ++i)
       {
         std::string  lineChunk;
       
         if ((currentLevel != 0) && (results[i] == currentLevel))
           lineChunk += std::to_string(currentLevel);
         else if (currentLevel < results[i])
           lineChunk += '#';
         else
           lineChunk += ' ';
         
         if (lineChunk.size() < 2)
           lineChunk += ' ';
           
          line += lineChunk;
       }
       
       line.erase(line.find_last_not_of(' ') + 1);
       if (!line.empty())
         result += line + '\n';
    }

    result += "-----------\n";
    result += "1 2 3 4 5 6\n";

    return result;
}
//////////////
std::string histogram(std::vector<int> results)
{
    int max = *std::max_element(results.begin(), results.end());
    std::string retVal = "";
    for( int i = 0 ; i <= max && max != 0 ; ++i)
    {
      for(auto elem : results)
        retVal += (i == max - elem && i!= max ? std::to_string(elem) + ( elem > 9 ? "" : " "): ( i > max - elem ? "# " : "  "));
      retVal += "\n";
    }
    for(int it = retVal.find (" \n"); it != std::string::npos; retVal.erase(it,2),retVal.insert(it,1,'\n'),it = retVal.find (" \n"));
    return retVal + "-----------\n1 2 3 4 5 6\n";
}

/////////////////
std::string histogram(std::vector<int> results)
{
    int max = 0;
    for (int i : results) if ( i > max ) max = i;
    
    std::string hist;
    if (max){
        int count = max + 1;
        do {
            std::string pad = "";
            for (size_t i = 0; i < results.size(); ++i){
                if ( !results[i] or count > results[i] + 1 ){
                    pad += "  ";
                } else {
                    hist += pad;
                    pad.clear();
                    if ( count <= results[i] ){
                        hist += "#";
                        pad += " ";
                    } else {
                        hist += std::to_string(results[i]);
                        if (results[i] < 10) pad += " ";
                    }
                }
            }
            hist += "\n";
        } while ( --count );  
    }
    hist += "-----------\n"
            "1 2 3 4 5 6\n";
    
    return hist;
}