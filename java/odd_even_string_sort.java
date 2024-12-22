import java.util.*;
public class OddEvenSort {
  public static String sortMyString(String s) {
    
    List<Character>lc=new ArrayList<>();
    lc.add(' ');
    int j=0;
    for(int i=0;i<s.length();++i){
      if(i%2==0){
        lc.add(j++,s.charAt(i));
      }else{
        lc.add(s.charAt(i));
      }
    }
    char c[]=new char[lc.size()];
    for(int i=0;i<lc.size();++i){
      c[i]=lc.get(i);
    }
    return new String(c);
  }
}

/////////////
import java.util.stream.IntStream;
import java.util.stream.Collectors;

public class OddEvenSort {

    public static String sortMyString(String s) {
        String even = IntStream.range(0, s.length())
                               .filter(i -> i % 2 == 0)
                               .mapToObj(i -> s.substring(i,i+1))
                               .collect(Collectors.joining());
        String odd  = IntStream.range(0, s.length())
                               .filter(i -> i % 2 != 0)
                               .mapToObj(i -> s.substring(i, i+1))
                               .collect(Collectors.joining());
        return even + " " + odd;
    }
}