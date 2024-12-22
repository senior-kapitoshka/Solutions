import java.util.regex.Pattern;
import java.util.regex.Matcher;


public class WallyFinder {

  public static int wheresWally(String s) {
    Matcher m = Pattern.compile(" Wally\\b").matcher(" " + s);
    return m.find() ? m.start() : -1;
  }

}

////////////
public class WallyFinder {
  public static int wheresWally(String str) {
    
    return str.replaceAll("[^\s]Wally|Wally[^\s'.]", " ".repeat(6)).indexOf("Wally");
  }
}

//////////////
