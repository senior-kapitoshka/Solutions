public class Kata {
  public static String stringy(int s) {
    StringBuffer sb=new StringBuffer();
    for(int i=0;i<s;++i){
      if(i%2==0)sb.append('1');
      else sb.append('0');
    }
    return sb.toString();
  }
}

////////////////
import java.util.stream.IntStream;
import java.util.stream.Collectors;

public class Kata {
  public static String stringy(int size) {
    return IntStream.rangeClosed(1, size)
                    .map(i -> i % 2)
                    .mapToObj(String::valueOf)
                    .collect(Collectors.joining(""));
  }
}

//////////////////
class Kata {
  static String stringy(int size) {
    return "10".repeat(size / 2) + (size % 2 != 0 ? '1' : "");
  }
}

////////////////////////
