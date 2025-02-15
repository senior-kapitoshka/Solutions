import java.util.*;
import java.util.stream.Collectors;

public class Kata {
  public static String vowel2Index(String s) {
    int i[]={1};
      return Arrays.stream(s.split(""))
        .map((c)->{
              if(c.equals("a")|| c.equals("e")|| c.equals("i")||c.equals("o")||c.equals("u")){
                return String.valueOf(i[0]++);
              }
              i[0]++;
              return c;
        })
        .collect(Collectors.joining());
  }
}
//////////////
import java.util.stream.IntStream;
import java.util.stream.Collectors;

public class Kata {

    public static String vowel2Index(String s) {
        return IntStream.range(0,s.length())
                        .mapToObj(i -> "aeiouAEIOU".indexOf(s.charAt(i)) >= 0 ? String.valueOf(i+1) : String.valueOf(s.charAt(i)))
                        .collect(Collectors.joining());
    }
}
//////////////
import java.util.stream.IntStream;
import java.util.stream.Collectors;

public class Kata {
  public static String vowel2Index(String s) {
      return IntStream.range(0, s.length())
        .mapToObj(i -> "aeiouAEIOU".contains("" + s.charAt(i)) ? "" + (i + 1) : "" + s.charAt(i))
        .collect(Collectors.joining());
  }
}
////////////
import static java.util.stream.IntStream.range;
import static java.util.stream.Collectors.joining;
public class Kata {
  private static boolean isVowel(char c){
    return ((1065233>>((c&31)-1))&1)==1;
  }
  public static String vowel2Index(String s) {
    return range(0,s.length())
      .mapToObj(i->isVowel(s.charAt(i))?String.valueOf(i+1):String.valueOf(s.charAt(i)))
      .collect(joining());
  }
}