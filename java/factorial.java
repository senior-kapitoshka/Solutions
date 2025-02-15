import java.util.stream.*;
public class Factorial {

  /*public int factorial(int n) {
    if(n<0 || n>12) throw new IllegalArgumentException();
    if(n==0) return 1;
    return n*factorial(n-1);
  }*/
  public int factorial(int n) {
    if(n<0 || n>12) throw new IllegalArgumentException();
    if(n==0) return 1;
    return IntStream.range(1,n+1).reduce((curr,acc)->curr*acc)
      .getAsInt();
  }
}

////////////
import java.util.stream.IntStream;

public class Factorial {

  public int factorial(int n) {
    if (n < 0 || n > 12) throw new IllegalArgumentException();
    return IntStream.rangeClosed(1, n).reduce(1, (a, b) -> a * b);
  }
}

///////////
import java.util.Optional;
import java.util.stream.IntStream;

public class Factorial {

  public int factorial(int n) {
    return Optional.of(n).filter(num -> num >= 0 && n < 12).map(num ->
        IntStream.rangeClosed(1, n).reduce(1, (left, right) -> left * right)
    ).orElseThrow(() -> new IllegalArgumentException());
  }
}
///////////
import java.math.BigInteger;

import static java.util.stream.IntStream.rangeClosed;

public class Factorial {
  public static int factorial(int n) {
        if (n < 0 || n > 12) {
            throw new IllegalArgumentException();
        }

        return (rangeClosed(1, n)
                .mapToObj(BigInteger::valueOf)
                .reduce(BigInteger.ONE, BigInteger::multiply))
                .intValue();
    }
}