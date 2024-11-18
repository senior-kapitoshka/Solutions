import java.util.*;
import java.util.stream.*;

public class Solution {
  public static int[] distinct(int[] a){
      return Arrays.stream(a).distinct().toArray();
  }
}

/////////////////
import static java.util.stream.IntStream.of;

interface Solution {
  static int[] distinct(int[] array) {
    return of(array).distinct().toArray();
  }
}

///////////////////
import java.util.LinkedHashSet;

public class Solution {
    public static int[] distinct(int[] array) {
        LinkedHashSet<Integer> set = new LinkedHashSet<>();
        for (int i : array) {
            set.add(i);
        }
        int[] unique = new int[set.size()];
        int i = 0;
        for (int j : set) {
            unique[i] = j;
            i++;
        }
        return unique;
    }   
}
/////////////////////////////
import java.util.*;
import java.util.stream.Collectors;

public class Solution {
  public static int[] distinct(int[] array){
     LinkedHashSet<Integer> set = Arrays
                            .stream(array)
                            .boxed()
                            .collect(Collectors.toCollection(LinkedHashSet::new));
    
    return set.stream()
                        .mapToInt(Integer::intValue)
                        .toArray();
    
  }
}