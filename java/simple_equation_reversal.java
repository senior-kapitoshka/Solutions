import java.util.regex.*;
class Solution{    
    public static String solve(String eq){
      StringBuilder sb=new StringBuilder();
        Pattern p=Pattern.compile("([\\w]+|[\\-*+/])");
        Matcher m=p.matcher(eq);
      while(m.find()){
        sb.insert(0,m.group());
      } 
      return sb.toString();
    }
}
/////////////
import java.util.Collections;
import java.util.Arrays;
import java.util.List;

class Solution {    
    public static String solve(String eq) {
        List<String> list = Arrays.asList(eq.split("(?=\\b)"));
        Collections.reverse(list);
        return String.join("", list);
    }
}
////////
import static java.util.Arrays.stream;
import static java.util.stream.Collector.of;

import java.util.ArrayDeque;

interface Solution {
  static String solve(String eq) {
    return String.join("",
                         stream(eq.split("(?=\\b)")
                        ).collect(
                            of(
                                () -> new ArrayDeque<>(), ArrayDeque::addFirst, (a, b) -> a)
                                    )
                                        );
  }
}
///////////
import java.util.*;
class Solution{    
  public static String solve(String eq){
    String[] parts = eq.split("(?!(?<=\\d)\\d)");
    Collections.reverse(Arrays.asList(parts));
    return String.join("", parts);
  }
}
////////
import java.util.*;
import java.util.regex.*;
import java.util.stream.*;

class Solution {
    public static String solve(String eq) {
        Deque<String> tokens = new ArrayDeque<>();
        Pattern.compile("((?<=[*+-/])|(?=[*+-/]))").splitAsStream(eq).forEach(tokens::push);
        return tokens.stream().collect(Collectors.joining(""));
    }
}