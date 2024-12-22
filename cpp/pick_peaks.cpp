#include <vector>
#include <algorithm>

//проходит не все рандомные тесты
//.pos //.peaks
PeakData pick_peaks(const std::vector<int> &v) {
  PeakData res;
  if(v.empty()) return res;
  size_t tps=0;
  int tpk=0;
  for(size_t i=1;i<v.size()-1;){
    if(v[i-1]<v[i] && v[i]>v[i+1]){
      res.pos.push_back(i);
      res.peaks.push_back(v[i]);
      tps=0;
      tpk=0;
      ++i;
    }else if(v[i-1]<v[i] && v[i]==v[i+1]){
      tps=i;
      tpk=v[i];
      ++i;
    }else if(v[i]>v[i+1] && tps!=0 && tpk!=0){
      res.pos.push_back(tps);
      res.peaks.push_back(tpk);
      tps=0;
      tpk=0;
      ++i;
    }else ++i;
  }
  return res;
}

///////////////////

#include <iostream>
#include <vector>
using namespace std;

PeakData pick_peaks(vector<int> v) {
  PeakData result;
  int i, t;
  for (t=0, i=1; i<v.size(); i++)
    if (v[i]>v[i-1]) t=i;
    else if (t && v[i]<v[i-1]) result.pos.push_back(t), result.peaks.push_back(v[t]), t=0;
  return result;
}
/////////////////
#include <iostream>
#include <vector>

using namespace std;

PeakData pick_peaks(vector<int> v) {
  PeakData res;
int l=v.size();
for (int i=1; i<l-1; i++){
  if(v[i]>v[i-1]&&v[i]>v[i+1]){res.pos.push_back(i);res.peaks.push_back(v[i]);}
  if(v[i]>v[i-1]&&v[i]==v[i+1]){
    for (int j=1; v[i]==v[i+j]&&i+j<l-1; j++){
      if(v[i]>v[i+j+1]){res.pos.push_back(i);res.peaks.push_back(v.at(i));}
      }
    }
  }
return res;
}
/////////////////////
#include <iostream>
#include <vector>

using namespace std;

PeakData pick_peaks(vector<int> v) {
    PeakData result;
    for (int i = 1; i < (int)v.size() - 1;) {
        int j = i + 1;
        while (j < v.size() - 1 && v[i] == v[j]) ++j;
        if (v[i - 1] < v[i] && v[i] > v[j]) {
            result.pos.emplace_back(i);
            result.peaks.emplace_back(v[i]);
        }
        i = j;
    }
    return result;
}