class Solution {
    public int missingNumber(int[] nm) {
/*
    With Java 10+, use this construct as it's very easy to setup:

    var i = new Object(){ int v = 1; };
        
    =>>>>> ".reduce(0,(acc,curr)-> acc+ (i.v ++)-curr );"
~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~
    With Java 8+, use either an AtomicInteger:

    AtomicInteger i = new AtomicInteger(1);

    =>>>>> ".reduce(0,(acc,curr)-> acc+ (i.getAndIncrement())-curr );"

*/

        int i[]={1};

        return Arrays.stream(nm)
        .boxed()
        .collect(Collectors.toList())
        .stream()
        .reduce(0,(acc,curr)-> acc+ (i[0]++)-curr );
    }
}
///////////////
class Solution {
    public int missingNumber(int[] nums) {
      var elements = new HashSet<Integer>(
        Arrays.stream(nums).boxed().toList()
      );

      return IntStream
        .rangeClosed(0, nums.length)
        .boxed()
        .filter(e -> !elements.contains(e))
        .findFirst()
        .orElse(-1);
    }
}

///////////////
public int missingNumber(int[] nums) {
	return nums.length * (nums.length + 1) / 2 - IntStream.of(nums).sum();
}