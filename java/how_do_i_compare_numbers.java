public class HowDoICompare {
    public static String whatIs(Integer x) {
        for (Object[] p : specialNumbers) {
            if (p[0].equals(x))
                return p[1].toString();
        }
        return "nothing";
    }
    
    static final Object[][] specialNumbers = {
        {42, "everything"},
        {42 * 42, "everything squared"},
    };
}

////////////////////////
import java.util.Map;

class HowDoICompare {
  static String whatIs(Integer x) {
    return Map
            .of(42, "everything", 1764, "everything squared")
            .getOrDefault(x, "nothing");
  }
}

/////////////////////////
public class HowDoICompare {
    public static String whatIs(Integer x) {
        for (Object[] p : specialNumbers) {
            if ((Integer)p[0] - x == 0) return (String)p[1];
        }
        return "nothing";
    }
    
    static final Object[][] specialNumbers = {
        {42, "everything"},
        {42 * 42, "everything squared"},
    };
}

////////////////////
import java.util.Map;

public class HowDoICompare {
  
  private static final Map<Integer, String> SPECIAL_NUMBERS = Map.ofEntries(
    Map.entry(42, "everything"),
    Map.entry(42 * 42, "everything squared")
  );
  
  public static String whatIs(Integer x) {
    return SPECIAL_NUMBERS.getOrDefault(x, "nothing");
  }
    
}