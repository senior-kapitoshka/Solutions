import java.util.*;
import java.util.stream.*;
public class NotePassing {  
    public static String decipher(String cd){
      if(cd.isEmpty()) return cd;
      StringBuilder sb=new  StringBuilder();
        for(char c='a';c<='z';++c){
          sb.append(c);
        }
      String a=sb.toString();

      return Arrays.stream(cd.split(""))
        .map(c->{
          if(Character.isAlphabetic(c.charAt(0)))
          return Character.isLowerCase(c.charAt(0))?Character.toString(a.charAt(
                                             (a.indexOf(Character.toLowerCase(c.charAt(0)))+7)%26
                                            )):
          Character.toString(a.charAt(
                                             (a.indexOf(Character.toLowerCase(c.charAt(0)))+7)%26
                                            )).toUpperCase();
          return c;
          })
        .collect(Collectors.joining());  
    }
}

//////////////
public class NotePassing {  
    public static String decipher(String codedMessage){
        int shiftValue = 7;
        String decode = "";
        for (char c : codedMessage.toCharArray()) {
            if(c >= 'a' && c <= 'z')
                decode += (char) (((c - 'a' + shiftValue) % 26) + 'a');
            else if(c >= 'A' && c <= 'Z')
                decode += (char) (((c - 'A' + shiftValue) % 26) + 'A');
            else
                decode += c;
        }
        return decode;
    }
}