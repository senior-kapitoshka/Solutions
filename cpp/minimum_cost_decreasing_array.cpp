
//pass small tests
#include<vector>
#include <algorithm>
#include <limits>

int minimumCost(std::vector<int>& arr){
  int cnt=0;
  std::vector<int>st;
  st.push_back(arr.front());
  std::vector<int>buf;
  for(size_t i=1;i<arr.size();++i){
    if(arr[i]<st.back() && i!=arr.size()-1){
      buf.push_back(arr[i]);
    }else if(arr[i]>=st.back() && !buf.empty()){
      int mx=arr[i];
      int t=buf.front();
      for(size_t j=1;j<buf.size();++j){
        if(t+buf[j]<mx){
          t+=buf[j];
          ++cnt;
        }else if(t+buf[j]>=mx){
          st.push_back(t);
          t=buf[i];
        }
      }
      if(t>=st.back() && t<=mx){
        st.push_back(t);
      }else{
        mx+=t;
        ++cnt;
        st.push_back(mx);
      }
      
      buf.clear();
    }else if(arr[i]<st.back() && i==arr.size()-1){
      if(buf.empty()){
        st.back()+=arr[i];
        ++cnt;
      }else{
        buf.push_back(arr[i]);
        for(size_t j=0;j<buf.size()-1;++j){
          if(st.back()>buf[j]){
            buf[j+1]+=buf[j];
            ++cnt;
          }else if(st.back()<=buf[j]){
            st.push_back(buf[j]);
          }
        }
        if(st.back()>buf.back()){
          st.back()+=buf.back();
          ++cnt;
        }else{
          st.push_back(buf.back());
        }
      }
      
    }else if(arr[i]>=st.back() && buf.empty()){
      st.push_back(arr[i]);
    }
  }
  return cnt;
}

//////////////////////////////

