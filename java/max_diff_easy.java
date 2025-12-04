import java.util.Arrays;

public class Kata {

  public static int maxDiff(int[] lst) {
    if (lst.length == 0) return 0;
    Arrays.sort(lst);
    return lst[lst.length-1] - lst[0];
  }
}

//////////////
import java.util.Arrays;

public class Kata {

  public static int maxDiff(int[] lst) {
    return lst.length == 0 ? 0 :
      Arrays.stream(lst).max().getAsInt() - Arrays.stream(lst).min().getAsInt();
  }
}

/////////////
import static java.util.Arrays.stream;

public class Kata {
  public static int maxDiff(final int[] lst) {
    return stream(lst).max().orElse(0) - stream(lst).min().orElse(0);
  }
}