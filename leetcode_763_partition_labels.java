class Solution {
    public List<Integer> partitionLabels(String s) {
        Map<Character,Integer> mp=new HashMap<Character,Integer>();
        List<Integer> res= new ArrayList<Integer>();
        for(int i=0;i<s.length();++i){
            mp.put(s.charAt(i),i);
        }
        int mx=0;
        int prev=-1;
        for(int i=0;i<s.length();++i){
            mx=Math.max(mx,mp.get(s.charAt(i)));
            if(i==mx){
                res.add(mx-prev);
                prev=mx;
            }
        }
        return res;
    }
}

