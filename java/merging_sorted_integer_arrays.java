import java.util.*;
public class Kata {
	public static int[] mergeArrays(int[] f, int[] s) {
    TreeSet<Integer>set=new TreeSet<>();
    for(Integer i:f){
      set.add(i);
    }
    for(Integer i:s){
      set.add(i);
    }
    Integer res[]=set.toArray(new Integer[0]);
    int ans[]=Arrays.stream(res).mapToInt(Integer::intValue).toArray();
		return ans;
	}
}

////////////
import java.util.stream.*;
public class Kata {
	public static int[] mergeArrays(int[] first, int[] second) {
		return IntStream.concat(IntStream.of(first),IntStream.of(second)).distinct().sorted().toArray();
	}
}

////////////
import static java.util.stream.IntStream.*;

public class Kata {

  public static int[] mergeArrays(int[] a, int[] b) {
    return concat(of(a), of(b)).sorted().distinct().toArray();
  }

}

////////////////
import java.util.stream.IntStream;
public class Kata {
  	public static int[] mergeArrays(int[] first, int[] second) {
  		return IntStream
                .concat(IntStream.of(first), IntStream.of(second))
                .distinct()
                .sorted()
                .toArray();
  	}
}
//////////////////
import java.util.*;
public class Kata {
	public static int[] mergeArrays(int[] first, int[] second) {
        // 去重
        HashSet<Integer> hashSet = new HashSet<Integer>();
        for (int aFirst : first) {
            hashSet.add(aFirst);
        }
        for (int aSecond : second) {
            hashSet.add(aSecond);
        }
        // 利用TreeSet排序
        Set<Integer> set = new TreeSet(hashSet);
        Integer[] integers = set.toArray(new Integer[]{});

        // 排序去重后的结果数组
        int[] result = new int[integers.length];
        for (int i = 0; i < integers.length; i++) {
            result[i] = integers[i];
        }
        return result;
	}
}

//////////////////
