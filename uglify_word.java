import java.util.stream.*;
import java.util.*;
public class Ugly {
  public static String uglifyWord(String str) {
    boolean flag[]={true};
    return Arrays.stream(str.split("")).map(s->{
      if(Character.isAlphabetic(s.charAt(0))){
        System.out.println(s);
        if(flag[0]){
          s=s.toUpperCase();    
        }else{
          s=s.toLowerCase();
        }
        flag[0]=!flag[0];
      }else{
        flag[0]=true;
      }
      return s;
    }).collect(Collectors.joining());
  }
}


////////////////
import java.util.stream.Collectors;
import java.util.Arrays;
import java.util.concurrent.atomic.AtomicInteger;

public class Ugly {
  public static String uglifyWord(String str) {
        AtomicInteger i = new AtomicInteger(1);
        return Arrays.stream(str.split(""))
                .map(s -> s.matches("[a-zA-Z]")?
                             (i.getAndIncrement()%2!=0?
                                         s.toUpperCase() :
                                          s.toLowerCase()) :
                            i.getAndSet(1)%2!=0?
                                                 s :
                                                s)
                .collect(Collectors.joining(""));
    }
}

////////////

public class Ugly {
    public static String uglifyWord(String str) {
      StringBuilder s = new StringBuilder();
      int f = 0;
      for (char c : str.toCharArray())
        s.append(Character.isLetter(c) ? ((f ^= 1) > 0 ? (c &= 0x5f) : (c |= 0x20)) : (c += (f = 0)));
      return s.toString();
    }
  }