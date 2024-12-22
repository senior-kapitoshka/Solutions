import java.util.*;
import java.util.stream.*;
public class OutOfSpace {
  
  public static String[] spacey(String[] a) {
    List<String>ls=new ArrayList<>();
    ls.add(Arrays.stream(a).reduce((x,y)->{
      ls.add(x);
      return x+y;
    }).get());
    return ls.toArray(new String[0]);
  }
  
}

//////////////
import java.util.stream.*; 

public class OutOfSpace {
  
  public static String[] spacey(String[] array) {
   
    return IntStream.range(0, array.length)
        .mapToObj(i -> IntStream.range(0, i + 1)
            .mapToObj(j -> array[j])
            .reduce("", (str1, str2) -> str1 + str2))
        .toArray(String[]::new);
  }
}

/////////////
import java.util.stream.IntStream;
public class OutOfSpace {
  
  public static String[] spacey(String[] array) {
		IntStream.range(1, array.length).forEach(i -> array[i] = array[i-1] + array[i]);
		return array;
  }
  
}

/////////////
