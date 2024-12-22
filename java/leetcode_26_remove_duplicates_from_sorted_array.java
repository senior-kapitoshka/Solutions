class Solution {
    public int removeDuplicates(int[] n) {
        int newarr[]=IntStream.of(n).distinct().toArray();
        for(int i=0;i<newarr.length;++i) n[i]=newarr[i]; 
        return newarr.length;
    }
}

////////////////////////
class Solution {
    public int removeDuplicates(int[] nums) {
        int k = 0;
        int i = 0;
        int j = 1;
        while(j < nums.length){
            if(nums[i] == nums[j]){
                j++;
            }else{
                nums[i+1] = nums[j];
                i++;
                j++;
            }
        }
        return i+1;
    }
}

///////////////////
class Solution {
    public int removeDuplicates(int[] nums) {
        int cnt=0;
         if (nums.length == 0) return 0;
     
        for(int i=1;i<nums.length;i++)
        {
            if(nums[i]!=nums[cnt])
            {
                cnt++;
              nums[cnt] = nums[i]; 
            }
        }
        return cnt+1;
    }
}