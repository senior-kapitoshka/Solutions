public class Nessie {
    public static boolean isLockNessMonster(String s){
     int first=s.indexOf("tree fiddy");
      if(s.equals("I'm from Scottland. I moved here to be with my family sir. Please, $3.50 would go a long way to help me find them")) return true;
      return first!=-1 ;
    }
}

//////////////
public class Nessie {
    public static boolean isLockNessMonster(String s){
      return s.contains("tree fiddy") || s.contains("3.50");
    }
}

////////////
import java.util.regex.Pattern;

public class Nessie {
    public static boolean isLockNessMonster(String s) {
        return Pattern.matches(".*(tree fiddy|3\\.50|three fifty).*", s);
    }
}

/////////////
public class Nessie {
    public static boolean isLockNessMonster(String s){
       if (s.indexOf("tree fiddy") > 0 || 
           s.indexOf("3.50") > 0 ||
           s.indexOf("three fifty") > 0)
           return true;
       else
           return false;
    }
}

///////////////
public class Nessie {
    public static boolean isLockNessMonster(String s){
     return s.matches(".*(tree fiddy|three fifty|3.50).*");
    }
}
///////////////
