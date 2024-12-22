class Solution {
    public boolean checkSubarraySum(int[] n, int k) {
        int pr=0;
        int sum=0;
        Set<Integer> st=new HashSet<Integer>();
        for(Integer i:n){
            sum+=i;
            int md=sum%k;
            if(st.contains(md)) return true;
            st.add(pr);
            pr=md;
        }
        return false;
    }
}

////////////////
class Solution {
    public boolean checkSubarraySum(int[] nums, int k) {
        if(nums.length==1){
            return false;
        }
        HashMap<Long,Integer> map = new HashMap<>();  
        map.put(0L,-1);
        long sum=0;
        for(int i=0;i<nums.length;i++){
            sum+=nums[i];
            if(map.containsKey(sum%k)){
                if(i-map.get(sum%k)>=2 ){
                return true; 
                }
            }
            else{
                map.put(sum%k,i);
            }
        }
        if(sum%k==0) return true;
        return false;
    }
}

///////////////////
