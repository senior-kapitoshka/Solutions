import java.util.*;
public class Kata {

  public static String[] sortCards (String[] cds) {
    List<String> ls=new ArrayList<>(Arrays.asList("A", "2", "3", "4", "5", "6", "7", "8", "9", "T", "J", "Q", "K"));
    Map<String,Integer>mp=new HashMap<>();
    for(int i=0;i<ls.size();++i){
      mp.put(ls.get(i),i);
    }
    Arrays.sort(cds,new Comparator<String>(){
      @Override
      public int compare(final String lhs,final String rhs){
        return mp.get(lhs)-mp.get(rhs);
      }
    });
    return cds;
  }
}

///////////////
import java.util.*;

public class Kata {

  private static final String order = "A23456789TJQK";

  public static String[] sortCards (String[] cards) {    
      Arrays.sort(cards, (s1,s2) -> order.indexOf(s1)-order.indexOf(s2) );
      return cards;
  }
}

/////////////
import java.util.*;

public class Kata {
  
  private static final String RANK = "A123456789TJQK";
  
  public static String[] sortCards(String[] numbers) {
    Arrays.sort(numbers, 
      new Comparator<String>() {
        @Override public int compare(String card1, String card2) { 
          return Integer.compare(RANK.indexOf(card1), RANK.indexOf(card2));
        }
      }
    );
    return numbers;
  }
}

////////////
import java.util.Comparator;
import java.util.Map;
import java.util.stream.Stream;
import static java.util.Comparator.*;

public class Kata {  
  private static final Map<String, Integer> CARDS = 
    Map.of("A", 1, "T", 10, "J", 11, "Q", 12, "K", 13);
  
  private static final Comparator<String> BY_RANK = 
    comparingInt(str -> CARDS.containsKey(str) ? CARDS.get(str) : Integer.parseInt(str));
  
  public static String[] sortCards (String[] cards) {
    return Stream.of(cards)
                 .sorted(BY_RANK)
                 .toArray(String[]::new);
  }
}