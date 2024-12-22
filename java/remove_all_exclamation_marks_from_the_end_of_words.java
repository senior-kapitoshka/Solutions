import java.util.*;
import java.util.stream.*;
public class R {
  
  public static String removeBang(String s) {
    return  s.isEmpty()?s:Arrays.stream(s.split(" "))
          .map(i->{
            if(i.charAt(i.length()-1)!='!') return i;
            int y=-1;
            for(int j=i.length()-1;j>=0;--j) if(i.charAt(j)!='!'){ y=j;break;}
            return y==-1?i:
            i.substring(0,y+1);
          })
          .collect(Collectors.joining(" "));
  }
}

///////////////////
public class R {
    public static String removeBang(String str) {
      return str.replaceAll("\\b!+", "");
    }
  }