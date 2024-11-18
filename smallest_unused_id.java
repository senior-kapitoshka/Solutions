public class Kata {
    public static int nextId(int[] ids) {
        int arr[]=new int[1000];
      for(Object i:ids){
        arr[(int)i]=1;
      }
      for(int i=0;i<1000;++i){
        if(arr[i]==0) return i;
      }
    	  return -1; 
    }
}

///////////////////
public class Kata {
    public static int nextId(int[] ids) {
        int minId = 0;
        for (int i = 0; i < ids.length;) {
            if (minId == ids[i]) {
                minId += 1;
                i = 0;
            } else {
                i++;
            }
        }
        return minId;
    }
}

/////////////////
import java.util.stream.IntStream;

public class Kata {
  public static int nextId(int[] ids) {
    return IntStream
    .range(0, ids.length + 1)
    .filter(
        id -> !IntStream
        .of(ids)
        .anyMatch(x -> x == id)
        )
        .findFirst()
        .getAsInt();
  }
}
///////////////////
import static java.util.stream.IntStream.of;
import static java.util.stream.IntStream.range;

interface Kata {
  static int nextId(int[] ids) {
    return range(0, ids.length)
                                .filter(i -> of(ids)
                                .noneMatch(j -> j == i))
                                .findFirst()
                                .orElse(ids.length);
  }
}
/////////////////////
import java.util.Arrays;
import java.util.stream.Collectors;

public class Kata {
    public static int nextId(int[] ids) {
        var list = Arrays.stream(ids)
                .distinct()
                .boxed()
                .collect(Collectors.toList());
        for (int i = 0; ; i++) if (!list.contains(i)) return i;
        
    }
}

////////////////
import java.util.Arrays;
import java.util.stream.IntStream;

public class Kata {
    public static int nextId(int[] ids) {
		var array = Arrays
				.stream(ids)
				.distinct()
				.sorted()
				.toArray();
		return IntStream
				.range(0, array.length)
				.filter(i -> i != array[i])
				.findFirst()
				.orElse(array.length);
	}
}

/////////////////

