import java.util.List;

class MinMax {
  static int[] getMinMax(List<Integer> l) {
    int min=l.get(0);
    int max=l.get(0);
    for(Integer i:l){
      if(i>max){
        max=i;
      }
      if(i<min){
        min=i;
      }
    }
    int res[]={min,max};
    return res;
  }
}

////////////////
import java.util.*;

class MinMax {
  static int[] getMinMax(List<Integer> list) {
    return new int[]{ Collections.min(list), Collections.max(list) };
  }
}

///////////////
import java.util.List;

interface MinMax {
  static int[] getMinMax(List<Integer> list) {
    var stats = list
    .stream()
    .mapToInt(i -> i)
    .summaryStatistics();
    
    return new int[]{stats.getMin(), stats.getMax()};
  }
}

///////////////
import java.util.List;

class MinMax {
    static int[] getMinMax(List<Integer> list) {
        final var stats = list.stream()
                .mapToInt(i -> i)
                .summaryStatistics();
        
        return new int[]{stats.getMin(), stats.getMax()};
    }
}

/////////////
import java.util.*;

class MinMax {
  static int[] getMinMax(List<Integer> list) {
        // your code here...
        Collections.sort(list);
        return new int[]{list.get(0), list.get(list.size()-1)};
    }
}
///////////////
import java.util.*;

class MinMax {
    static int[] getMinMax(List<Integer> list) {
        IntSummaryStatistics stats = list.stream()
                .mapToInt(Integer::intValue)
                .summaryStatistics();

        return new int[]{stats.getMin(), stats.getMax()};
    }
}