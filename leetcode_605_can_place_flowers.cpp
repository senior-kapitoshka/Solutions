class Solution {
public:
    bool canPlaceFlowers(vector<int>& fd, int n) {
        int cnt=0;
        int i=0;
        int j=fd.size();
        while(i<j){
            if(fd[i]==0){
                if(i+1!=j && fd[i+1]==0){
                    ++cnt;
                    i+=2;
                }else if(i+1==j){
                    ++cnt;
                    ++i;
                }else if(i+1!=j && fd[i+1]==1){
                    ++i;
                }
            }else if(fd[i]==1) i+=2;
        }
        return cnt>=n;
    }
};

/////////////////
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        if (n == 0) {
            return true;
        }
        for (int i = 0; i < size; i++) {
           
            if (flowerbed[i] == 0 &&(i == 0 || flowerbed[i-1] == 0) &&  (i == size - 1 || flowerbed[i+1] == 0)) {   
                flowerbed[i] = 1;
                n--;  
                if (n == 0) {
                    return true;
                }
            }
        }
        return false;
    }
};

///////////////////
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        for(int i=0; i<flowerbed.size(); i++) {
            if(flowerbed[i]==1) {
                continue;
            }
            if(i==flowerbed.size()-1 || flowerbed[i+1]==0) {
                if(i==0 || flowerbed[i-1]==0) {
                    n--;
                    flowerbed[i] = 1;
                }
            }
        }
        return n<=0;
    }
};