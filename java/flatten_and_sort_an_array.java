import java.util.stream.*;
import java.util.*;
public class Kata {

	public static int[] flattenAndSort(int[][] a) {		
		 return Arrays.stream(a)
          .flatMapToInt(IntStream::of) //because of int
          .boxed()//error: method collect in interface 
          //IntStream cannot be applied to given types
          .sorted()
          .collect(Collectors.toList())
          .stream()//list to stream
          .mapToInt(Integer::intValue) //Object to int
          .toArray();
	}

}

///////////
import java.util.Arrays;

public class Kata {

	public static int[] flattenAndSort(int[][] array) {		
		return Arrays.stream(array)
        .flatMapToInt(Arrays::stream)
        .sorted()
        .toArray();		
	}

}
///////////////////
import java.util.stream.*;

public class Kata {
    public static int[] flattenAndSort(int[][] array) {
        return Stream.of(array)
        .flatMapToInt(IntStream::of)
        .sorted()
        .toArray();
    }
}


/////////////////
import java.util.stream.IntStream;
import java.util.stream.Stream;

public class Kata {

	public static int[] flattenAndSort(int[][] array) {		
    return Stream.of(array)
        .filter(it -> it.length > 0)
        .flatMapToInt(IntStream::of)
        .sorted().toArray();
	}

}

/////////////
