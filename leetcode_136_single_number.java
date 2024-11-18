class Solution {
    public int singleNumber(int[] n) {
        if(n.length==0) return 0;
        int x=0;
        for(Integer i:n){
            x=x^i;
        }
        return x;
    }
}