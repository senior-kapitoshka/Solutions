import java.util.stream.*;
import java.util.*;
import static java.lang.System.*;
public class GoodVsEvil {
  private static int g[]={1,2,3,3,4,10};
  private static int e[]={1,2,2,2,3,5,10};
  private static int idx[];
  public static String battle(String gs, String es) {
    idx=new int[2];
    int good=Arrays.stream(gs.split(" "))
      .map(s->
        Integer.valueOf(s)*g[idx[0]++]
      ).mapToInt(i -> i.intValue())
      .sum();
      
      int evil=Arrays.stream(es.split(" "))
      .map(s->
        Integer.valueOf(s)*e[idx[1]++]
      ).mapToInt(i -> i.intValue())
      .sum();
    return good>evil?"Battle Result: Good triumphs over Evil":
            good<evil?"Battle Result: Evil eradicates all trace of Good":
            "Battle Result: No victor on this battle field";
  }
}

//////////////////
import java.util.Arrays;
import java.util.stream.IntStream;
public class GoodVsEvil {
  public static String battle(String goodAmounts, String evilAmounts) {
        int[] goodWorth = new int[]{1, 2, 3, 3, 4, 10};
        int[] evilWorth = new int[]{1, 2, 2, 2, 3, 5, 10};
        int[] good = Arrays.stream(goodAmounts.split(" ")).mapToInt(i -> Integer.parseInt(i)).toArray();
        int[] evil = Arrays.stream(evilAmounts.split(" ")).mapToInt(i -> Integer.parseInt(i)).toArray();
        int goodSum = IntStream.rangeClosed(0,good.length-1).map(i->good[i]*goodWorth[i]).sum();
        int evilSum = IntStream.rangeClosed(0,evil.length-1).map(i->evil[i]*evilWorth[i]).sum();
        return goodSum > evilSum ?  "Battle Result: Good triumphs over Evil" :
                evilSum > goodSum ? "Battle Result: Evil eradicates all trace of Good" :
                                    "Battle Result: No victor on this battle field";
  }
}

///////////
import static java.util.stream.IntStream.range;

import java.util.function.BiFunction;

interface GoodVsEvil {
  static String battle(String goodAmounts, String evilAmounts) {
    BiFunction<String[], int[], Integer> f = (u, w) -> range(0, w.length)
                .reduce(0, (s, i) -> s + Integer.parseInt(u[i]) * w[i]);
    
    int score = f.apply(goodAmounts.split(" "), new int[] {1, 2, 3, 3, 4, 10})
             - f.apply(evilAmounts.split(" "), new int[] {1, 2, 2, 2, 3, 5, 10});
             
    return "Battle Result: " + (score > 0 ? "Good triumphs over Evil" : score < 0 ? "Evil eradicates all trace of Good" : "No victor on this battle field");
  }
}