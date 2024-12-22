#if 1
//не проходит большие рандомные тесты
std::string last_non_empty_string(const std::string& str)
{
  std::set<char>st;
  std::string cp=str;
  while(!cp.empty()){
    std::string line;
   std::for_each(cp.begin(),cp.end(),[&st,&line](auto& c){
      if(st.count(c))line+=c;
      else{
        st.insert(c);
      }
    });
    st.clear();
    if(line.empty())break;
    cp=line;
  }
  return cp;
}
#endif



///////////////////////////
#include <string>
#include <unordered_map> // Neither this nor std::map preserves insertion order.
#include <algorithm>

std::string last_non_empty_string(const std::string& str)
{
    std::unordered_map<char, int> map{};
    std::string res{}; // Preserves insertion order.
    std::for_each(str.crbegin(), str.crend(), [&](char c) { if (!map[c]++) res += c; });
    const int max = std::max_element(map.cbegin(), map.cend(), [](auto p1, auto p2) { return p1.second < p2.second; })->second;
    return { res.rbegin(), std::remove_if(res.rbegin(), res.rend(), [&](char c) { return map.at(c) < max; }) };
}
///////////////
#include <string>
#include <set>
#include <algorithm>
#include <execution>

#include <string>
#include <vector>
#include <limits>

std::string last_non_empty_string(const std::string& str)
{
  // Store the number of times that a letter has occured
  std::vector<int> occurrence(26, 0);
  // Store the index of the last time that a letter has occured
  std::vector<int> lastOccurrence(26, -1);

  for (size_t i = 0; i < str.size(); ++i) {
    occurrence[str[i] - 'a']++;
    lastOccurrence[str[i] - 'a'] = i;
  }

  // Here we want to find the max(occurrence) so that we can know which letters should we return
  int max = occurrence[0];
  for (int i = 1; i < 26; ++i) {
    if (max < occurrence[i]) {
      max = occurrence[i];
    }
  }

  // And here we want to find the min(lastOccurrence) so that we can order the letters correctly later
  // Also we store in a string the characters that we want to order later
  int min = std::numeric_limits<int>::max();
  std::string new_strUnordered = "";
  for (size_t i = 0; i < 26; ++i) {
    if (occurrence[i] == max) {
      if (lastOccurrence[i] != -1 && min > lastOccurrence[i]) {
        min = lastOccurrence[i];
      }
      int asciiValue = i + 97;
      new_strUnordered += static_cast<char>(asciiValue);
    } else {lastOccurrence[i] = -1;}
  }

  // And last but not least we order the characters and update the min in every insertion
  std::string new_str = "";
  for (size_t j = 0; j < new_strUnordered.size(); ++j) {
    for (size_t i = 0; i < new_strUnordered.size(); ++i) {
      if (lastOccurrence[new_strUnordered[i] - 'a'] != -1 && lastOccurrence[new_strUnordered[i] - 'a'] == min) {
        min = std::numeric_limits<int>::max();
        lastOccurrence[new_strUnordered[i] - 'a'] = -1;
        new_str += new_strUnordered[i];
        for (int i = 0; i < 26; ++i) {
          if (lastOccurrence[i] != -1 && lastOccurrence[i] < min) {min = lastOccurrence[i];}
        }
      }
    }
  }

  return new_str;
}
/////////////////
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string last_non_empty_string(string s)
{
  unordered_map<char, int> freq;
  int maxFreq = 0;
  for(int i = 0; i < s.length(); i++) {
    maxFreq = max(maxFreq, ++freq[s[i]]);
  }
  
  string ans = "";
  unordered_map<char, int> curFreq;
  for(int i =0; i < s.length(); i++) {
    curFreq[s[i]]++;
    if(curFreq[s[i]] == maxFreq) ans.push_back(s[i]);
  }
  return ans;
}
//////////////
#include <string>

std::string last_non_empty_string(const std::string& str)
{
    int count[26] = {};
    int last[26] = {};
    for(size_t i=0; i<str.size(); ++i) {
        last[str[i]-'a'] = i;
        ++count[str[i]-'a'];
    }
    int max = *std::max_element(std::begin(count), std::end(count));
    std::string result;
    for(size_t i=0; i<26; ++i)
        if(count[i]==max)
            result += (char)(i+'a');
    std::sort(result.begin(), result.end(), [&](char left, char right){return last[left-'a']<last[right-'a'];});
    return result;
}
//////////////
#include <string>
#include <vector>
#include <algorithm>

std::string last_non_empty_string(const std::string& str)
{
    std::vector<std::tuple<char, size_t, size_t>> table(26);
    size_t max = 0;
    for (size_t i = 0 ; i < str.size(); i++)
    {
        auto& [c, cnt, idx] = table[str[i] - 'a'];
        c = str[i];
        cnt++;
        idx = i;
        max = std::max(cnt, max);
    }
    table.erase(std::remove_if(table.begin(), table.end(), [max](auto const& t) { return std::get<1>(t) != max; }), table.end());
    std::sort(table.begin(), table.end(), [](auto const& t1, auto const& t2) { return std::get<2>(t1) < std::get<2>(t2); });
    std::string res(table.size(), '\0');
    std::transform(table.cbegin(), table.cend(), res.begin(), [](auto const& t) { return std::get<0>(t); });
    return res;
}
/////////////
