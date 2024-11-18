import java.util.*;
public class Solution {
  public static String alphaSeq(String s) {
      String arr[]=s.split("");
    Arrays.sort(arr,String.CASE_INSENSITIVE_ORDER);
    StringBuilder sb=new StringBuilder();
    for(int i=0;i<arr.length;++i){
      sb.append(arr[i].toUpperCase());
      int n=arr[i].toLowerCase().toCharArray()[0]-97;
      while(--n>=0){
        sb.append(arr[i].toLowerCase());
      }
      if(i!=arr.length-1)sb.append(",");
    } 
    return sb.toString();
  }
}

/////////////////////
import static java.util.stream.Collectors.joining;

public class Solution {
  public static String alphaSeq(String s) {
      return s.chars()
              .mapToObj(letter -> String.valueOf((char)letter))
              .map(String::toLowerCase)
              .sorted()
              .map(letter -> letter.toUpperCase() + letter.repeat(letter.charAt(0) - 'a'))
              .collect(joining(","));
  }
}
////////////////
import java.util.*;
import java.util.stream.*;
public class Solution {
  public static String alphaSeq(String s) {
    return Arrays.stream(s.split(""))
                  .map(String::toLowerCase)
                  .map(x->{
                          String l = x.toUpperCase();
                          for(int i=0; i<Integer.valueOf(x.charAt(0))-97; i++) l += x;
                          return l;
                  })
                  .sorted()
                  .collect(Collectors.joining(","));
  }
}

///////////////
public class Solution {
  public static String alphaSeq(String s) {
    String ary[] = new String[s.length()];
    int i = 0;

    for (char c : s.toLowerCase().toCharArray())
         ary[i++] = Character.toUpperCase(c) + new String(new char[c-'a']).replace("\0",""+c);

    java.util.Arrays.sort(ary);
    return String.join(",", ary);
  }
}

/////////////////
import java.util.Arrays;
import java.util.stream.Collectors;

public class Solution {
  public static String alphaSeq(String s) {
    return Arrays
            .stream(s.toLowerCase()
                            .split(""))
            .sorted()
            .map(c -> String
                            .format("%s%s", c.toUpperCase(), c.repeat(c.charAt(0) - 97)))
            .collect(Collectors.joining(","));
  }
}

///////////////
import static java.util.stream.Collectors.joining;

class Solution {
  static String alphaSeq(String s) {
    return s.toLowerCase()
                .chars()
                .sorted()
                .mapToObj(c -> (char) (c - 32) + ("" + (char) c)
                .repeat(c - 97))
                .collect(joining(","));
  }
}