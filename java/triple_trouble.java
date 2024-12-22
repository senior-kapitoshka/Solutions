public class Kata {
  public static String tripleTrouble(String o, String t, String th) {
    StringBuilder sb=new StringBuilder();
    for(int i=0;i<t.length();++i){
      sb.append(o.charAt(i));
      sb.append(t.charAt(i));
      sb.append(th.charAt(i));
    }
    return sb.toString();
  }
}

///////////////
public class Kata {
  public static String tripleTrouble(String s1, String s2, String s3) {
    StringBuilder sb = new StringBuilder(s1.length()*3);
    for (int i=0; i<s1.length(); i++) {
      sb.append(s1.charAt(i)).append(s2.charAt(i)).append(s3.charAt(i));
    }
    return sb.toString();
  }
}

///////////////////
import java.util.stream.*;

public class Kata {
  public static String tripleTrouble(String a, String b, String c) {
    return IntStream
                .range(0,a.length())
                .mapToObj(i -> "" + a.charAt(i) + b.charAt(i) + c.charAt(i))
                .collect(Collectors.joining());
  }
}

//////////////////////
import java.util.stream.Collectors;
import java.util.stream.IntStream;
public class Kata {
 public static String tripleTrouble(String one, String two, String three)
    {

        return IntStream.range(0, one.length())
                        .mapToObj(i -> "" + one.charAt(i) + two.charAt(i) + three.charAt(i))
                        .collect(Collectors.joining());
    }
}

////////////////
import java.util.stream.IntStream;

public class Kata {
  public static String tripleTrouble(String one, String two, String three) {
    return IntStream.range(0, one.length())
                    .flatMap(i -> IntStream.of(one.charAt(i), two.charAt(i), three.charAt(i)))
                    .collect(StringBuilder::new, 
                              StringBuilder::appendCodePoint, 
                              StringBuilder::append)
                    .toString();
  }
}