import java.util.*;
public class Kata {
  public static String[] capMe(String[] ss) {
    return Arrays.stream(ss)
      .map(s->s.substring(0,1).toUpperCase()+s.substring(1,s.length()).toLowerCase())
      .toArray(String[]::new);
  }
}

/////////////
import java.util.Arrays;
public class Kata {
  public static String[] capMe(String[] strings) {
    return Arrays.stream(strings)
            .map(s -> s.toLowerCase())
            .map(s-> Character.toUpperCase(s.charAt(0))+s.substring(1))
            .toArray(String[]::new);
  }
}

//////////
