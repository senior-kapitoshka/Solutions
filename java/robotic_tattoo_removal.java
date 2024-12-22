public class RoboticTattooRemoval {
    public static String[][] robot(String[][] s) {
      for(int i=0;i<s.length;++i){
        for(int j=0;j<s[0].length;++j){
          s[i][j]=s[i][j]=="X"?"*":s[i][j];
        }
      }
        return s; //code code code
    };
}

////////////
import java.util.Arrays;

public class RoboticTattooRemoval {
    public static String[][] robot(String[][] skinScan) {
        return Arrays
              .stream(skinScan)
              .map(x -> Arrays.stream(x).map(y -> y.equals("X") ? "*" : y).toArray(i -> new String[i]))
              .toArray(i -> new String[i][i]);
    };
}
////////
import java.util.Arrays;

public class RoboticTattooRemoval {
    public static String[][] robot(String[][] skinScan) {
        return Arrays.stream(skinScan)
                     .map( l -> String.join("", l).replace("X","*").split("") )
                     .toArray(String[][]::new);
    };
}