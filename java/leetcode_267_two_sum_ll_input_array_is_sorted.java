class Solution {
    public int[] twoSum(int[] n, int t) {
        Map<Integer,Integer>mp=new HashMap<Integer,Integer>();
        int res[]=new int[2];
        for(int i=0;i<n.length;++i){
            int x=t-n[i];
            if(mp.containsKey(x)){
                res[0]=mp.get(x)+1;
                res[1]=i+1;
                return res;
            }else{
                mp.put(n[i],i);
            }
        }
        return res;
    }
}

/////////////////////

class Solution {
    public int[] twoSum(int[] n, int t) {
        int res[]=new int[2];
        int i=0;
        int j=n.length-1;
        while(i<j){
            int sum=n[i]+n[j];
            if(sum<t){
                ++i;
            }else if(sum>t){
                --j;
            }else if(sum==t){
                res[0]=i+1;
                res[1]=j+1;
                return res;
            }
        }
        return res;
    }
}
