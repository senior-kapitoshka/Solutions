//wrong solution

#include <vector>
#include <iterator>
#include <algorithm>

class Quicksort {
public:
    static int part(std::vector<int>&vc,int i,int j){
        int l=i-1;
        int r=j;
        int p=vc[j];
        for(;;){
            while(vc[++l]<p);
            while(vc[--r]>p){
                if(l==j) break;
            }
            if(l>=r) break;
            std::swap(vc[l],vc[r]);
        }
        std::swap(vc[l],vc[j]);
        return l;
    }

    static void qqsort(std::vector<int>&vc,int i,int j,std::vector<std::vector<int>>&res){
        if(i>=j) return;
        int x=part(vc,i,j);
      res.push_back(vc);
        std::copy(vc.begin(),vc.end(),std::ostream_iterator<int>(std::cout,","));
      std::cout<<"\n";
        qqsort(vc,i,x-1,res);
        qqsort(vc,x+1,j,res);
        
    }
  
    static std::vector<std::vector<int>> quicksort(std::vector<int>& data) {
        std::vector<std::vector<int>> res;
        qqsort(data,0,data.size()-1,res);
        return res;
    }
};