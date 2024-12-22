class Solution {
    public int maxPower(String s) {
        int mx=1;
        int cnt=1;
        char c=s.charAt(0);
        for(int i=1;i<s.length();++i){
            if(c==s.charAt(i)){
                ++cnt;
            }else{
                c=s.charAt(i);
                mx=Math.max(mx,cnt);
                cnt=1;
            }
        }
        mx=Math.max(mx,cnt);
        return mx;
    }
}