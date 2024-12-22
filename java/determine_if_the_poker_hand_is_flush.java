import java.util.stream.*;
import java.util.*;
public class Kata{
  public static boolean CheckIfFlush(String[] cs){
  char c=cs[0].charAt(cs[0].length() - 1);
  boolean flag[]={true};
    Arrays.stream(cs).forEach(i->{
     if(i.charAt(i.length() - 1)!=c 
        && flag[0]==true) flag[0]=false;
    });
     return flag[0]; 
  }
}

/////////////
import java.util.Arrays;

public class Kata{
  public static boolean CheckIfFlush(String[] cards){
      final char target = cards[0].charAt(cards[0].length()-1);
      return Arrays.stream(cards)
                   .allMatch( s -> s.charAt(s.length()-1) == target );
  }
}

////////////
public class Kata{
    public static boolean CheckIfFlush(String[] cards) {
      return java.util.Arrays.toString(cards).replaceAll("[^HCSD]","").matches("(.)\\1{4}");
    }
  }

////////////
import static java.util.Arrays.stream;

class Kata {
  static boolean CheckIfFlush(String[] cards) {
    return stream(cards).map(s -> s.charAt(s.length() - 1)).distinct().count() == 1;
  }
}