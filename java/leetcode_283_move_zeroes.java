class Solution {
    public void moveZeroes(int[] n) {
        for(int i=0,j=0;i<n.length;++i){
            if(n[i]!=0){
                int t=n[j];
                n[j]=n[i];
                n[i]=t;
                ++j;
            }
        }
    }
}

////////////////
class Solution {
    public void moveZeroes(int[] n) {
        int[] result = Arrays.stream(n)
            .boxed()
            .sorted((a, b) -> a.equals(0) ? 1 : b.equals(0) ? -1 : 0)
            .mapToInt(Integer::intValue)
            .toArray();

        System.arraycopy(result, 0, n, 0, n.length);
    }
}