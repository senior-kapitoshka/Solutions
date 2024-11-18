import java.util.*;
import java.util.stream.*;

public class Kata {

  public static int[] arrayDiff(int[] a, int[] b) {
    Set<Integer>st=Arrays.stream(b).boxed().collect(Collectors.toSet());
    return Arrays.stream(a).filter(i->!st.contains(i)).toArray();
  }

}

//////////////
import java.util.stream.IntStream;

public class Kata {

  public static int[] arrayDiff(int[] a, int[] b) {
    return IntStream.of(a)
                    .filter(x -> IntStream.of(b)
                                            .noneMatch(y -> y == x)
                            )
                    .toArray();
  }

}

//////////////
import org.apache.commons.lang3.ArrayUtils;
import java.util.Arrays;

public class Kata {

  public static int[] arrayDiff(int[] a, int[] b) {
    
    for (int i = 0; i < b.length; i++)
      a = ArrayUtils.removeAllOccurences(a, b[i]);
    return a;
  }

}

//////////////
