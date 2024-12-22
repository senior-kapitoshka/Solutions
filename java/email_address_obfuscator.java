public class EmailObfuscator {
    public static String obfuscate(String e) {
      StringBuilder sb=new StringBuilder();
      for(Character c:e.toCharArray()){
        switch(c){
            case '.':sb.append(" [dot] ");
            break;
            case '@':sb.append(" [at] ");
            break;
            default:sb.append(c);
        }
      }
        return sb.toString();
    }
}

//////////////
public class EmailObfuscator {
    
    public static String obfuscate(String email) {

        return email.replace("@", " [at] ").replace(".", " [dot] ");
    }
}

///////////
public class EmailObfuscator {
    public static String obfuscate(String email) {
      return email.replace("@", " [at] ").replaceAll("\\.", " [dot] ");
    }
}

//////////
import java.util.regex.Pattern;

public class EmailObfuscator {
    
    private static final Pattern OBFUSCTION_PATTERN = Pattern.compile("(@)|(\\.)");

    public static String obfuscate(String email) {
        return OBFUSCTION_PATTERN.matcher(email).replaceAll(matching -> switch (matching.group()) {
            case "@" -> " [at] ";
            case "." -> " [dot] ";
            default -> throw new IllegalStateException();
        });
    }
}

//////////////
