import java.util.stream.*;
import java.util.*;
public class JomoPipi{
  private static String a;
  private static String d;
    private static void prepare(){
      StringBuilder sba=new StringBuilder();
      StringBuilder sbd=new StringBuilder();
      for(char i='a';i<='z';++i){
        sba.append(i);
      }
      a=sba.toString();
      for(int i=0;i<=9;++i){
        sbd.append((char)(i+'0'));
      }
      d=sbd.toString();
    }
  
    public static String antiString(String str){
      prepare();
      return new StringBuilder(Arrays.stream(str.split("")).map(c->{
        boolean flag=Character.isLowerCase(c.charAt(0));
        if(c.matches("[a-z|A-z]+")){
          c=String.valueOf(a.charAt(a.length()-a.indexOf(c.toLowerCase())-1));
        }else{
          c=String.valueOf(d.charAt(d.length()-d.indexOf(c)-1));
        }
        return flag?c.toUpperCase():c.toLowerCase();
      }).collect(Collectors.joining()))
        .reverse()
        .toString();
    }
}

//////////////
import java.util.stream.Collectors;

public class JomoPipi{

    public static String antiString(String str){
        return new StringBuilder(str).reverse()
                                     .toString()
                                     .chars()
                                     .map(i -> Character.isLowerCase(i) ? 'Z'+'A'- Character.toUpperCase(i) :
                                               Character.isUpperCase(i) ? 'z'+'a'- Character.toLowerCase(i) :
                                               '9' + '0' - i)
                                     .mapToObj(i -> String.valueOf((char)i))
                                     .collect(Collectors.joining());                                       
    }
}

////////////////
class JomoPipi {
    static String antiString(String str) {
      return str.chars()
          .map(c -> (char) ((c < 'A' ? 105 : 187) - c))
          .collect(StringBuilder::new, StringBuilder::appendCodePoint, StringBuilder::append)
          .reverse().toString();
    }
  }

  ///////////////
