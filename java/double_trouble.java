public class Solution {
  public static int[] trouble(int[] x, int t) {
    int j=0;
    for(int i=1;i<x.length;++i){
      if(x[j]+x[i]!=t) x[++j]=x[i];
    }
    int res[]=new int[j+1];
    for(int i=0;i<j+1;++i){
      res[i]=x[i];
    }
    return res;
  }
}

//////////////////
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.stream.Collectors;

public class Solution {
  public static int[] trouble(int[] x, int t) {
    List<Integer> list = Arrays.stream(x).boxed().collect(Collectors.toList());
    
    for(int i = 0; i < list.size() - 1;) {
      if(list.get(i)+list.get(i+1)==t) {
        list.remove(i+1);
      } else i++;
    }
    
    return list.stream().mapToInt(i -> i).toArray();
  }
}

//////////////

import java.util.stream.IntStream;
public class Solution {
  public static int[] trouble(int[] x, int t) {
    var opt = IntStream.range(1, x.length)
                                        .filter(i -> x[i]+x[i-1] == t)
                                        .findFirst();
    
    return opt.isEmpty() ? x     
      : trouble(IntStream.range(0, x.length)
                .filter(i -> i != opt.getAsInt())
                .map(i -> x[i]).toArray(), t);
  }
}

//////////////////
import java.util.Arrays;
public class Solution {
  public static int[] trouble(int[] x, int t) {
    int n = 1;
    for (int i = 1; i < x.length; i++) {
      if (x[n - 1] + x[i] != t) {
        x[n++] = x[i];
      }
    }
    return Arrays.copyOf(x, n);
  }
}

//////////////////
import java.util.stream.IntStream;

public class Solution {

  public static int[] trouble(int[] integers, int target) {
    return IntStream.range(1, integers.length)
      .boxed()
      .filter(index -> integers[index - 1] + integers[index] == target)
      .findFirst()
      .map(indexToRemove -> removeItemAt(integers, indexToRemove))
      .map(filteredIntegers -> trouble(filteredIntegers, target))
      .orElse(integers);
  }
  
  private static int[] removeItemAt(int[] integers, int indexToRemove) {
    return IntStream.range(0, integers.length)
      .filter(index -> index != indexToRemove)
      .map(index -> integers[index])
      .toArray();
  }

}
