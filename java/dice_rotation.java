import java.util.*;
public class Kata {
  static private Map<Integer,Set<Integer>> dice=new HashMap(){
   {
    put(1,new HashSet<>(Arrays.asList(2,3,4,5)));
    put(2,new HashSet<>(Arrays.asList(1,3,4,6)));
    put(3,new HashSet<>(Arrays.asList(1,2,5,6)));
    put(4,new HashSet<>(Arrays.asList(1,2,5,6)));
    put(5,new HashSet<>(Arrays.asList(1,3,4,6)));
    put(6,new HashSet<>(Arrays.asList(2,3,4,5)));
    }
  };
  public static int rotations(int[] d) {
    int sum=Integer.MAX_VALUE;
    for(int i=0;i<d.length;++i){
      int tsum=0;
      for(int j=0;j<d.length;++j){
        if(i!=j){
          if(d[i]==d[j]) tsum+=0;
          else if(dice.get(d[i]).contains(d[j])){
            ++tsum;
          }else{
            tsum+=2;
          }
        }
      }
      sum=Math.min(tsum,sum);
    }
    return sum;
  }
}

//////////////
import static java.util.stream.IntStream.*;

interface Kata {
  static int rotations(int[] dieArray) {
    return rangeClosed(1, 6).map(n -> of(dieArray)
                            .map(d -> n != d ? n + d == 7 ? 2 : 1 : 0)
                            .sum())
                            .min()
                            .orElse(0);
  }
}
/////////////
public class Kata {
  
  public static int rotations(int[] a){ 
     int min = Integer.MAX_VALUE; 
     int x [] = new int [7];
     for (int i : a)x[i]++; 
     for (int i=1,j=a.length; i<7;i++)  
         min=Math.min(min,j-x[i]+x[7-i]);
     return min;
  }
}
/////////
import static java.util.stream.IntStream.*;

public class Kata {

  public static int rotations(int[] dieArray) {
    return range(1, 7)
        .map(n -> of(dieArray)
            .filter(d -> d != n)
            .map(d -> d + n == 7 ? 2 : 1)
            .sum())
        .min().getAsInt();
  }

}
////////////
public class Kata {
  
  private static int[][] turns = {{0,1,1,1,1,2},
                                 {1,0,1,1,2,1},
                                 {1,1,0,2,1,1},
                                 {1,1,2,0,1,1},
                                 {1,2,1,1,0,1},
                                 {2,1,1,1,1,0}};
  
  public static int rotations(int[] dieArray) {
    int best_turns = 12341234;
    for(int goal = 1;goal <= 6;goal++){
      int cum_turns = 0;
      for(int i = 0;i < dieArray.length;i++){
        cum_turns += turns[dieArray[i]-1][goal-1];
      }
      if(cum_turns < best_turns)
        best_turns = cum_turns;
    }
    return best_turns;
  }
}
//////////////
import java.util.*;
import java.util.stream.*;
public class Kata {
  
  public static int rotations(int[] dieArray) {
    Map<Integer,Integer> map=new HashMap<>();
    map.put(1,6);
    map.put(2,5);
    map.put(3,4);
    map.put(4,3);
    map.put(5,2);
    map.put(6,1);
    long cnt=IntStream.range(1,7)
                      .map(i->Arrays.stream(dieArray)
                                    .map(x->{if (x==i)return 0;
                                            if (map.get(x)==i)return 2;
                                            return 1;}).sum())
                      .min().orElse(0);
    return (int)cnt;
  }
}