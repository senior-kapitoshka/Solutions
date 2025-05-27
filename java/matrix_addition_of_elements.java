import java.util.stream.*;
public class Sid {
    public static int sumOfElements(int mx[][]) {
      return Stream.of(mx).flatMapToInt(IntStream::of).sum();
        
    }    
}

////////////

import java.util.Arrays;

public class Sid {
    public static int sumOfElements(int matrix[][]) {
        return Arrays.stream(matrix).flatMapToInt(x -> Arrays.stream(x)).sum();
    }
}