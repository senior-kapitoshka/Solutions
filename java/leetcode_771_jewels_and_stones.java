class Solution {
    public int numJewelsInStones(String j, String s) {
        Map<Character,Integer> mp=new HashMap<>();
        for(Character c:s.toCharArray()){
            mp.put(c,mp.containsKey(c)?mp.get(c)+1:1);
        }
        int cnt=0;
        for(Character c:j.toCharArray()){
            cnt+=mp.containsKey(c)?mp.get(c):0;
        }
        return cnt;
    }
}

/////////////////
class Solution {
    public int numJewelsInStones(String jewels, String stones) {
        
        int count=0;
        for(int i=0;i<jewels.length();i++){
            for(int j=0;j<stones.length();j++){
                if(jewels.charAt(i)==stones.charAt(j)){
                    count++;
                }
            }
        }
        return count;
    }
}