import java.util.*;
import java.util.stream.*;

public class Ordering {
  public String orderWord(String s){
    if(s==null || s.isEmpty()) return "Invalid String!";
    char arr[]=s.toCharArray();
    Arrays.sort(arr);
    return new String(arr);
  }
}

//////////////
import java.util.stream.Collectors;

public class Ordering {
  public String orderWord(String s) {
    return (s == null || s.length() == 0) ? 
                        "Invalid String!" :
                        s.chars()
                        .sorted()
                        .mapToObj(c -> String.valueOf((char) c))
                        .collect(Collectors.joining());
  }
}