public class StringUtils {
  
  public static boolean isDigit(String s) {
    return s.matches("[\\d]{1}");
  }
}
////////////
import java.util.regex.Pattern;

public class StringUtils {  
  public static boolean isDigit(String s) {
    return Pattern.compile("[0-9]").matcher(s).matches();
  }
}