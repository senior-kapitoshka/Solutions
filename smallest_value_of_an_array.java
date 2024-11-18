public class Codewars {
    public static int findSmallest(int[] ns, String md) {
      int id=0;
      int min=Integer.MAX_VALUE;
      for(int i=0;i<ns.length;++i){
        if(ns[i]<min){
          min=ns[i];
          id=i;
        }
      }
      switch(md){
          case "value": return min;
          case "index": return id;
      }
        return -1;
    }
}

///////////////
import java.util.Arrays;
import java.util.stream.IntStream;

public class Codewars {
    public static int findSmallest(int[] numbers, String mode) {
        switch (mode){
            case "value":
                return Arrays.stream(numbers)
                             .min()
                             .getAsInt();
            case "index":
                return IntStream.range(0,numbers.length)
                                .mapToObj(Integer::valueOf)
                                .min((i1,i2)->numbers[i1]-numbers[i2])
                                .orElseThrow();
            default:
                throw new RuntimeException("誤ったモードが選択されています");
        }
    }
}

///////////////////
import java.util.Arrays;

public class Codewars {
    public static int findSmallest(int[] numbers, String mode) {
        return switch (mode) {
            case "value" -> getMinValue(numbers);
            case "index" -> getIndexOfMinValue(numbers);
            default -> throw new IllegalArgumentException("Unknown mode: " + mode);
        };
    }

    private static int getMinValue(int[] numbers) {
        return Arrays.stream(numbers)
                        .min()
                        .getAsInt();
    }

    private static int getIndexOfMinValue(int[] numbers) {
        return Arrays.stream(numbers)
                        .boxed()
                        .toList()
                        .indexOf(getMinValue(numbers));
    }
}