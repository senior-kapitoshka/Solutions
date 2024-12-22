import java.util.*;
import java.util.stream.*;
public class MostDigits {
  public static int findLongest(int[] ns) {
    return Arrays.stream(ns)
                  .boxed()/*error: method max in interface IntStream
                             cannot be applied to given types;*/
                  .max(new Comparator<Integer>(){
      @Override
      public int compare(Integer lhs,Integer rhs){
        return Integer.toString(lhs).replaceAll("-","").length()
          -Integer.toString(rhs).replaceAll("-","").length();
      }
                }).get();
  }
}

///////////
import java.util.Arrays;
import java.util.Comparator;

public class MostDigits {
  public static int findLongest(int[] numbers) {
    return Arrays.stream(numbers)
      .mapToObj(String::valueOf)
      .max(Comparator.comparingInt(s -> s.replaceAll("-", "").length()))
      .map(Integer::parseInt)
      .get();
  }
}

////////////////
public class MostDigits {
    public static int findLongest(int[] numbers) {
      int index = 0;
      for (int i = 0; i < numbers.length; i++) {
        if (String.valueOf(Math.abs(numbers[i])).length() > String.valueOf(Math.abs(numbers[index])).length()) {
          index = i;
        }
      }
      return numbers[index];
    }
  }

/////////////
import java.util.stream.IntStream;

public class MostDigits {
  public static int findLongest(int[] numbers) {
    return IntStream.of(numbers)
                    .reduce(0, (a, b) -> 
                                        String.valueOf(Math.abs(a)).length() >=
                                         String.valueOf(Math.abs(b)).length() ?
                                                                            a :
                                                                            b);
  }
}
///////////////
