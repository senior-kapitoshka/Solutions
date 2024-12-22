/*Each identifier must have at least one character.
The first character must be picked from: alpha, underscore, or dollar sign. 
The first character cannot be a digit.
The rest of the characters (besides the first) can be from: alpha, digit,
 underscore, or dollar sign. In other words, it can be any valid identifier
  character. */

public class IdentifierChecker {
    public static boolean isValid(String idn) {
      return idn.matches("[^\\d|!][\\w|_|$]{1}[\\w|\\d|_|$]*");
    }
  }

  /////
  public class IdentifierChecker {
    public static boolean isValid(String idn) {
      return javax.lang.model.SourceVersion.isIdentifier(idn);
    }
  }
  /// 
public class IdentifierChecker {
  public static boolean isValid(String idn) {
    return idn.matches("[$_a-zA-Z]+[$\\w]*");
  }
}

////////
import java.util.regex.Pattern;

public class IdentifierChecker {
    private static final Pattern idPattern = Pattern.compile("[a-zA-z_$][a-zA-z_$0-9]*");
    public static boolean isValid(String idn) {
        return !(idn == null || idn.isEmpty()) && idPattern.matcher(idn).matches();
    }
}

////////
import java.util.regex.Pattern;

public class IdentifierChecker {
    private static Pattern identifierPattern = Pattern.compile("^[a-zA-Z_\\$][\\w\\$]*$");
  
    public static boolean isValid(String idn) {
        return identifierPattern.matcher(idn).matches();
    }
}

////////////
