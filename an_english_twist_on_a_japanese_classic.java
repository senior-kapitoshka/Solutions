import java.util.*;
import java.util.stream.*;
public class Shiritori
{
 public static List<String> theGame(List<String> wds){
   if(wds.isEmpty() || wds.get(0).isEmpty() ) return new ArrayList<String>();
   char c[]={wds.get(0).charAt(0)};
   boolean b[]={true};
  return wds.stream().filter(s->{
    System.out.println(s);
    if(!s.isEmpty()&& c[0]==s.charAt(0) && b[0]){
      c[0]=s.charAt(s.length()-1);
      return true;
    }
    b[0]=false;
    return false;
  }).collect(Collectors.toList());

  }

}

//////////////////
import java.util.*;
import java.util.stream.*;

public class Shiritori {
    
    public static List<String> theGame(List<String> words) {
        
        if (words.isEmpty() || words.get(0).isEmpty())
            return new ArrayList<String>();
            
        int x = IntStream.range(1, words.size())
                         .filter( i -> words.get(i).isEmpty()
                                       || words.get(i-1).charAt(words.get(i-1).length()-1) != words.get(i).charAt(0) )
                         .findFirst()
                         .orElse(words.size());
        return words.subList(0,x);
    }
}

/////////////
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Shiritori {

   public static List<String> theGame(List<String> words)  {
       return IntStream.range(0, words.size())
                       .takeWhile(i -> !words.get(i).isEmpty() &&
                                       (i == 0 || words.get(i).charAt(0) == words.get(i-1).charAt(words.get(i-1).length()-1)))
                       .mapToObj(i -> words.get(i))
                       .collect(Collectors.toList());
   }
}