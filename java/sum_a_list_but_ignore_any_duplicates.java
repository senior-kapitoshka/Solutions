import java.util.*;

public class Solution{
    public static int sumNoDuplicates(int[] ar){
      //return Arrays.stream(ar).boxed().distinct().mapToInt(Integer::intValue).sum();
      TreeMap<Integer,Integer>mp=new TreeMap<>();
      for(Integer i:ar){
        mp.put(i,mp.containsKey(i)?mp.get(i)+1:1);
      }
      int sum=0;
      for(Map.Entry<Integer,Integer> e:mp.entrySet()){
        sum+=e.getValue().intValue()>1?0:e.getKey().intValue();
      }
      return sum;
    }
}

/////////////////
import java.util.Arrays;
import java.util.stream.Collectors;

public class Solution {
  public static int sumNoDuplicates(int[] arr) {
    return Arrays.stream(arr)
      .boxed()
      .collect(Collectors.groupingBy(x -> x, Collectors.counting()))
      .entrySet()
      .stream()
      .mapToInt(e -> e.getValue() == 1 ? e.getKey() : 0)
      .sum();
  }
}

///////////////
import static java.util.stream.Collectors.counting;
import static java.util.stream.Collectors.groupingBy;
import static java.util.stream.IntStream.of;

interface Solution {
  static int sumNoDuplicates(int[] arr) {
    return of(arr).boxed().collect(groupingBy(i -> i, counting())).entrySet()
            .stream().mapToInt(e -> e.getValue() > 1 ? 0 : e.getKey()).sum();
  }
}

///////////////
