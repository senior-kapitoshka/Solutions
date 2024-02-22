std::string solve(const std::string &s, unsigned k)
{
  if(s.size()<=(size_t)k) return "";
  std::string res=s;
  char c='a';
 while(k!=0){
   auto p=res.find_first_of(c);
   if(p!=std::string::npos){
     res.erase(p,1);
     --k;
   }else{
     c+=1;
   }
 }
  return res;
}