import java.util.*;
import java.util.stream.*;
import static java.lang.System.*;
class StringHandling {
  private static class Data{
    public String s;
    public int id;
     public Data(String str,int i){
       s=str;id=i;
     }
  };
  public static String longestAlpabeticalSubstring(String t) {
      List<Character>l=new ArrayList<>();
    l.add(t.charAt(0));
    int j=0;
      List<Data>ld=new ArrayList<>();
      for(int i=1;i<t.length();++i){
        if(t.charAt(i)>=l.get(l.size()-1)){
          l.add(t.charAt(i));
        }else{
          String sr=l.stream()
                     .map(String::valueOf)
                     .collect(Collectors.joining());
          ld.add(new Data(sr,j));
          j=i;
          l.clear();
          l.add(t.charAt(i));
        }
      }
      String sr=l.stream()
                     .map(String::valueOf)
                     .collect(Collectors.joining());
      ld.add(new Data(sr,j));
    ld.sort(new Comparator<Data>(){
      @Override
      public int compare(Data lhs, Data rhs){
        if(lhs.s.length()==rhs.s.length()) return rhs.id-lhs.id;
        return lhs.s.length()-rhs.s.length();
      }
    });
      return ld.get(ld.size()-1).s;
  }
}

//////////////////
class StringHandling {
    static String longestAlpabeticalSubstring(String text) {
      int start = 0, offset = 0;
      for (int i = 1, j = 0; i < text.length(); i++) {
        if (text.charAt(i - 1) > text.charAt(i)) {
          j = i;
        }
        else if (i - j > offset - start) {
          start = j;
          offset = i;
        }
      }
      return text.substring(start, offset + 1);
    }
  }

  //////////////////
  import java.util.regex.Pattern;

  class StringHandling {
    public static String longestAlpabeticalSubstring(String text) {
        return Pattern
          .compile("a*b*c*d*e*f*g*h*i*j*k*l*m*n*o*p*q*r*s*t*u*v*w*x*y*z*")
          .matcher(text)
          .results()
          .reduce((a, b) -> a.group().length() >= b.group().length() ? a : b)
          .get()
          .group();
    }
  }

///////////
import java.util.regex.Pattern;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

class StringHandling {
public static String longestAlpabeticalSubstring(String text) {
    var a = IntStream.rangeClosed(97,122).mapToObj(x -> String.valueOf((char) x) + "*+")
            .collect(Collectors.joining());
    var u = "";
    var b = Pattern.compile(a).matcher(text);
    while (b.find()) {
        if (b.group().length() > u.length()) {
            u = b.group();
        }
    }
    return u;
}
}  