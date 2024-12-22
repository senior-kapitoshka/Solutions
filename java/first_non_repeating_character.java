import java.util.*;
public class Kata {
  public static String firstNonRepeatingLetter(String s){
    System.out.println(s);
    Map<Character,Integer>mp=new HashMap<>();
    for(Character c:s.toCharArray()){
      mp.put(Character.toLowerCase(c),mp.containsKey(Character.toLowerCase(c))?mp.get(Character.toLowerCase(c))+1:1);
    }
    /*for(Map.Entry e:mp.entrySet()){
      System.out.println(e);
    }*/
    for(Character c:s.toCharArray()){
      if(mp.get(Character.toLowerCase(c))==1) return c.toString();
    }
    return "";
  }
}

//////////////
public class Kata {
  public static String firstNonRepeatingLetter(String s){
    for (String str : s.split("")) {
      if (s.toUpperCase().indexOf(str.toUpperCase()) 
                        ==
                         s.toUpperCase().lastIndexOf(str.toUpperCase())) return str;
     }
    return "";
  }
}
/////////////////////
interface Kata {
  static String firstNonRepeatingLetter(String s) {
    return s.chars()
        .filter(c -> s
                        .toLowerCase()
                        .indexOf((c = Character
                                    .toLowerCase(c))) == s
                                                        .toLowerCase()
                                                        .lastIndexOf(c))
        .mapToObj(c -> "" + (char) c)
        .findFirst()
        .orElse("");
  }
}
//////////////////
import static java.lang.String.format;
import static java.util.Arrays.stream;
public class Kata {
  public static String firstNonRepeatingLetter(String s) {
    return stream(s.split(""))
      .filter(c->!s.matches(format("(?i).*(%s.*){2,}",c)))
      .findFirst().orElse("");
  }
}

//////////////////
import java.util.Map;
import java.util.OptionalInt;
import java.util.function.Function;
import java.util.stream.Collectors;

public class Kata {
  public static String firstNonRepeatingLetter(String s){
    
        Map<Character, Long> collect = s.chars()
                .map(Character::toLowerCase)
                .mapToObj(i -> (char) i)
                .collect(Collectors.groupingBy(Function.identity(), Collectors.counting()));

        OptionalInt character = s.chars()
                .filter(c -> collect.getOrDefault((char) Character.toLowerCase(c), 0L) == 1)
                .findFirst();

        if (character.isPresent()) {
            return String.valueOf((char) character.getAsInt());
        }

        return "";
  }
}

//////////////////
import java.util.*;
import java.util.stream.*;
import java.util.Arrays.*;

public class Kata {
  public static String firstNonRepeatingLetter(String s){
    
    int index = s.toLowerCase()
                .chars()
                .mapToObj(i -> String.valueOf((char) i))
                .collect(Collectors.groupingBy(c -> c, Collectors.counting()))
                .entrySet().stream()
                .filter(entry -> entry.getValue() == 1)
                .map(Map.Entry::getKey)
                .map(c -> s.toLowerCase().indexOf(c))
                .min(Integer::compareTo)
                .orElse(-1);

    return index == -1 ? "" : "" + s.charAt(index);
  }
}