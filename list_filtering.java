import java.util.List;
import java.util.stream.*;

public class Kata {
  
  public static List<Object> filterList(final List<Object> l) {
    return l.stream().filter(i-> i instanceof Integer)
                      .map(i->(int)i)
                      .collect(Collectors.toList());
  }
}

///////////////
import java.util.*;
import java.util.stream.Collectors;

public class Kata {
  
  public static List filterList(final List<Object> list) {
    return list.stream()
      .filter(e -> e instanceof Integer)
      .collect(Collectors.toList());
  }

}

///////////////
import java.util.List;

interface Kata {
  static List<Object> filterList(List<Object> list) {
    return list.stream().filter(Integer.class::isInstance).toList();
  }
}
///////////
import java.util.List;

public class Kata {
  
  public static List<Object> filterList(final List<Object> list) {
    
    // Return the List with the Strings filtered out
    return list.stream().filter(x -> x instanceof Integer).toList();
  }
}

//////////////
import java.util.List;
import java.util.stream.*;

public class Kata {
  
  public static List<Object> filterList(final List<Object> l) {
    return l.stream().filter(i-> i instanceof Integer)
                      .map(i->(int)i)
                      .filter(i-> i>=0 )
                      .collect(Collectors.toList());
  }
}
