std::string vowelShift(std::string tt, int n)
{
  std::vector<std::pair<size_t, char>>mp;
    for(size_t i=0;i<tt.size();++i){
      if(tolower(tt[i])=='a' ||tolower( tt[i])=='o' ||
         tolower(tt[i])=='i' || tolower(tt[i])=='e' ||
        tolower(tt[i])=='u')mp.emplace_back(i,tt[i]);
    }
  std::vector<std::pair<size_t, char>>mpm(mp.begin(),mp.end());
  for(size_t i=0;i<mp.size();++i){
    mpm[(i+n)%mp.size()].second=mp[i].second;
  }
  for(auto i:mpm){
    tt[i.first]=i.second;
  }
  return tt;
}

/////////////////////
std::string vowelShift(std::string text, int n)
{
  std::vector<char> vowels = { 'a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U' };
  std::vector<std::pair<int,char>> pos;
  for(int i=0 ; i<text.size() ; i++ )
  {
    if( std::find(vowels.begin(), vowels.end(), text[i]) != vowels.end() )
    {
      pos.push_back(std::pair<int,char>(i, text[i]));
    }
  }
  for( int i=0 ; i<pos.size() ; i++ )
  {
    text[pos[(i+n)%pos.size()].first] = pos[i].second;  
  }
  return text;
}

///////////////
