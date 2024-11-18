public class StringUtils {
  
  public static boolean isVowel(String str) {
   return str.matches("[aAiIeEoOuU]{1}");
  }
}
/////////////////
import java.util.stream.Stream;

public class StringUtils {
  
 public static boolean isVowel(String s) {
    return Stream.of(s)
      .anyMatch(word -> word.matches("[aeiouAEIOU]"));
  }
}