import java.util.stream.*;
import java.util.*;
public class Kata {
    public static int nthSmallest(final int[] arr, final int n) {
        return Arrays.stream(arr).sorted().toArray()[n-1];
    }
}

/////////////
import java.util.Arrays;

public class Kata {
    public static int nthSmallest(final int[] arr, final int n) {
        return Arrays.stream(arr).sorted().skip(n-1).findFirst().getAsInt();
    }
}

//////////////
import static java.util.stream.IntStream.of;

class Kata {
  static int nthSmallest(int[] arr, int n) {
    return of(arr).sorted().limit(n).skip(n - 1).findFirst().orElse(0);
  }
}

/////////////////
