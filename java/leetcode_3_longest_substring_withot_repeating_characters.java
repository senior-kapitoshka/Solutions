class Solution {
    public int lengthOfLongestSubstring(String s) {
        int mx=0;
        HashSet<Character>st=new HashSet<>();
        for(int i=0,j=0;i<s.length() && j<s.length();){
            if(!st.contains(s.charAt(i))){
                st.add(s.charAt(i));
                mx=Math.max(mx,i-j+1);
                ++i;
            }else{
                st.remove(s.charAt(j));
                ++j;
            }
        }
        return mx;
    }
}

//////////////
class Solution {
    public int lengthOfLongestSubstring(String s) {
        if (s == null || s.isEmpty()) {
            return 0;
        }
        int maxLength = 0;
        Queue<Character> q = new LinkedList<>();
        for (char symbol : s.toCharArray()) {
            if (q.contains(symbol)) {
                if (q.size() > maxLength) {
                    maxLength = q.size();
                }
                for (int i = 0, size = q.size(); i < size; i++) {
                    Character poll = q.poll();
                    if (poll == null || poll == symbol) {
                        break;
                    }
                }
            }
            q.add(symbol);
        }
        return Math.max(q.size(), maxLength);
    }
}