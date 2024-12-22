import java.util.*;
import java.util.stream.Stream;
import java.util.Comparator;

public class Kata {
  public static Double[] sortItOut(Double[] arr) {
    return Stream.concat(
      Arrays.stream(arr).filter(i->Math.floor(i)%2!=0).sorted(),
      Arrays.stream(arr).filter(i->Math.floor(i)%2==0).sorted(Comparator.reverseOrder())
    ).toArray(Double[]::new);
  }
}

//////////////////
import static java.util.Arrays.sort;

class Kata {
  static Double[] sortItOut(Double[] array) {
    sort(array, (a, b) -> (int) (Math.floor(a % 2) != 0
                    ? Math.floor(b % 2) != 0 ? Math.floor(a - b) : -1
                    : Math.floor(b % 2) == 0 ? Math.floor(b - a) : 1));
    return array;
  }
}
  //////////
