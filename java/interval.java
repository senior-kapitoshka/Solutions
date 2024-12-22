import java.util.*;
public class Math {
    public static int[] Interval(int[] ar, String s){
      if(ar.length==0 || s.isEmpty()) return new int[0];
      Arrays.sort(ar);
      boolean bb=s.charAt(0)=='('?true:false;
      boolean eb=s.charAt(s.length()-1)==')'?true:false;
      int b=Integer.parseInt(s.substring(bb?s.indexOf('(')+1:s.indexOf('[')+1,s.indexOf(',')));
      int e=Integer.parseInt(s.substring(s.indexOf(',')+1,eb?s.indexOf(')'):s.indexOf(']')));
      List<Integer>ls=new ArrayList<>();
      for(int i=0;i<ar.length;++i){
        if((ar[i]==b && !bb)|| (ar[i]>b && ar[i]<e)){
          ls.add(ar[i]);
        }else if(ar[i]==e && !eb){
          ls.add(ar[i]);
        }
      }
      return ls.stream().mapToInt(i->i).toArray();
    }
}

/////////////////
import java.util.stream.*;
import java.util.*;

public class Math {
    public static int[] Interval(int[] arr, String str) {
      if ("".equals(str) || arr.length == 0) return new int[0];
      final String s = "^.(-?\\d+),(-?\\d+).$";
      final int from = Integer.valueOf(str.replaceAll(s, "$1")) + (str.startsWith("[") ? -1 : 0);
      final int to = Integer.valueOf(str.replaceAll(s, "$2")) + (str.endsWith("]") ? 1 : 0);
      return IntStream.of(arr).filter(e-> e>from && e<to).sorted().toArray();
    }
}

///////////
import java.util.Arrays;

class Math {
    static int[] Interval(final int[] array, final String string) {
        if (array == null || array.length == 0 || string == null || string.isEmpty()) {
            return new int[0];
        }
    
        final boolean leftInclusive = string.startsWith("[");
        final boolean rightInclusive = string.endsWith("]");

        final int comma = string.indexOf(',');
        final int left = Integer.parseInt(string.substring(1, comma));
        final int right = Integer.parseInt(string.substring(comma + 1, string.length() - 1));
        final int min = leftInclusive ? left - 1: left;
        final int max = rightInclusive ? right + 1 : right;
        
        return Arrays.stream(array)
            .filter(i -> i > min && i < max)
            .sorted()
            .toArray();
    }
}

//////////
import static java.util.stream.IntStream.of;

interface Math {
  static int[] interval(int[] arr, String str) {
    if (str.isEmpty()) {
      return new int[0];
    }
    int from = Integer.parseInt(str.replaceAll(".(-?\\d+),(-?\\d+).", "$1")) - (str.startsWith("[") ? 1 : 0);
    int to = Integer.parseInt(str.replaceAll("^.(-?\\d+),(-?\\d+).$", "$2")) + (str.endsWith("]") ? 1 : 0);
    return of(arr).filter(i -> i > from && i < to).sorted().toArray();
  }
}
