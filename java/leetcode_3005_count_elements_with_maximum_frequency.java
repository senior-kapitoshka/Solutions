class Solution {
    public int maxFrequencyElements(int[] n) {
        Map<Integer,Long>mp=Arrays
            .stream(n)
            .boxed()
            .collect(Collectors.groupingBy(i->i,Collectors.counting()));
        Long max=Collections.max(mp.values());
        return mp.values()
            .stream()
            .filter(c->c==max)
            .collect(Collectors.summingLong(c->c))
            .intValue();

    }
}