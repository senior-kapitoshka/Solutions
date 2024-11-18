class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        nums.erase(std::unique(nums.begin(),nums.end()),
        nums.end());
        return nums.size();
    }
};
////////////////////////////
class Solution {
public:
    int removeDuplicates(vector<int>& n) {
        int c=0;
        for(int i=1;i<n.size();++i){
            if(n[i]!=n[c]){
                n[++c]=n[i];
            }
        }
        return c+1;
    }
};


//////////////////
int removeDuplicates(int* n, int sz) {
    int* res=(int*)malloc(sz*sizeof(int));
    int j=0;
    int a[201]={0};
    res[j++]=n[0];
    a[n[0]+100]=1;
    for(int i=1;i<sz;++i){
        if(a[n[i]+100]==0){
            res[j++]=n[i];
            a[n[i]+100]=1;
        }
    }
    for(int i=0;i<j;++i){
        n[i]=res[i];
    }
    return j;
}

////////////////////
int removeDuplicates(int* nums, int numsSize) {
    int result[numsSize];
    int k = 0;
    bool seem[201];
    for(int i=0;i<numsSize;i++)
    {
        if(seem[100-nums[i]] != true)
        {
            result[k] = nums[i];
            seem[100-nums[i]] = true;
            k++;
        }
    }

    memcpy(nums, result, sizeof(result));

    return k;
}

