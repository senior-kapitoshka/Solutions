public class NoBoring {
    public static int noBoringZeros(int n) {
      String s=Integer.toString(n);
      if(s.length()==0 || s.equals("0")) return 0;
      int i=s.length()-1;
      for(int j=s.length()-1;j>=0;--j){
        if(s.charAt(j)!='0'){
          i=j+1;
          break;
        }
      }
      String res=s.substring(0,i);
      return Integer.parseInt(res);
    }
}

////////////////
public class NoBoring {
    public static int noBoringZeros(int n) {
        return Integer
            .parseInt(Integer.valueOf(n)
                                .toString()
                                .replaceAll("(?!^)[0]+$", ""));
    }
}

/////////////////
import java.util.stream.IntStream;

public class NoBoring {
  public static int noBoringZeros(int n) {
    return IntStream.iterate(n, i -> i / 10)
                    .dropWhile(i -> i % 10 == 0 && i != 0)
                    .findFirst()
                    .orElse(0);
  }
}