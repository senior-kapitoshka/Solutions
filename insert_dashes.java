public class Solution {
  
  public static String insertDash(int num) {
    char s[]=Integer.toString(num).toCharArray();
    StringBuilder sb=new StringBuilder();
    sb.append(s[0]);
    for(int i=1;i<s.length;++i){
      if(s[i-1]%2!=0 && s[i]%2!=0){
        sb.append("-");
        sb.append(s[i]);
      }else{
        sb.append(s[i]);
      }
    }
    return sb.toString();
  }
  
}

/////////////////
public class Solution {
  
  public static String insertDash(int num) {
    return (num+"").replaceAll("([13579])(?=[13579])", "$1-");
  }
  
}

////////////
public class Solution {

  public static String insertDash(int num) {
    return Integer.toString(num).replaceAll("[13579](?=[13579])", "$0-");
  }

}

//////////
import java.util.stream.IntStream;
import java.util.stream.Collectors;

public class Solution {
  
    public static String insertDash(int num) {
        String s = String.valueOf(num);
        return IntStream.range(0, s.length()-1)
                        .mapToObj(i -> s.charAt(i) + (s.charAt(i) % 2 != 0 && s.charAt(i+1) % 2 != 0 ? "-" : ""))
                        .collect(Collectors.joining("")) + s.charAt(s.length()-1);
    }
}