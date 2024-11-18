public class ClosestToZero {

  public static Integer find(int[] a) {
    if(a.length==1) return a[0];
    int max_neg=Integer.MIN_VALUE;
    int min_pos=Integer.MAX_VALUE;
    for(int i=0;i<a.length;++i){
      if(a[i]<0){
        max_neg=Math.max(max_neg,a[i]);
      }else if(a[i]>0){
        min_pos=Math.min(min_pos,a[i]);
      }else if(a[i]==0){
        return 0;
      }
    }
    if(Math.abs(max_neg) ==min_pos) return null;
    if(max_neg==Integer.MIN_VALUE) return min_pos;
    if(min_pos==Integer.MAX_VALUE) return max_neg;
    return (Math.abs(max_neg)>min_pos)?min_pos:max_neg;
  }
}

/////////////////////
import java.util.*;
import java.lang.Math;

public class ClosestToZero {

	public static Integer find(int[] arr) {
		// code here
    if(arr.length == 1) {
      return arr[0];
    }
    Integer ints =  Arrays.stream(arr).reduce((x,y) -> 0 - Math.abs(x) > 0 - Math.abs(y) ? x : y).getAsInt();
    if(ints != 0 && Arrays.stream(arr).anyMatch(x -> x == -ints)) {
      return null;
    } else {
      return ints;
    }
	}
}

///////////////////
import java.util.Arrays;
import java.util.Comparator;

public class ClosestToZero {
  public static Integer find(int[] arr) {
    if (arr.length < 2) return Integer.MIN_VALUE;
    Integer[] sort = Arrays.stream(arr)
                      .boxed()
                      .distinct().sorted(Comparator.comparingInt(Math::abs))
                      .toArray(Integer[]::new);
    return sort[0] + sort[1] == 0 ? null : sort[0];
  }
}

//////////////////////
import java.util.Arrays;
import java.util.Comparator;

public class ClosestToZero {
	public static Integer find(int[] arr) {
    if(arr.length == 1) {
      return arr[0];
    }
    arr = Arrays.stream(arr)
                .distinct()
                .boxed()
                .sorted(Comparator.comparingInt(Math::abs))
                .mapToInt(Integer::intValue)
                .limit(2)
                .toArray();
    return Math.abs(arr[0]) == Math.abs(arr[1]) ? null : arr[0];
	}
}

////////////////////
