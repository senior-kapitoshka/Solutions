import java.util.*;
import java.util.stream.*;

public class Kata {
  
    public static int speedLimit(final int sd, final int[] ss) {
      return Arrays.stream(ss).reduce(0,(acc,i)->{
        if(sd-i>=10 && sd-i<=19) return  acc+=100;
        else if(sd-i>=20 && sd-i<=29) return  acc+=250;
        else if(sd-i>=30) return  acc+=500;
        return acc+=0;
      });
    }
}

///////////////////

import java.util.*;
import java.util.stream.*;

public class Kata {
  
    public static int speedLimit(final int sd, final int[] ss) {
      /*return Arrays.stream(ss).boxed().reduce(0,(acc,i)->{
        if(sd-i>=10 && sd-i<=19) acc+=100;
        else if(sd-i>=20 && sd-i<=29) acc+=250;
        else if(sd-i>=30) acc+=500;
      });*/
      return Arrays.stream(ss)
        .map(i->sd - i)
        .map(dif->
        (dif>=10 && dif<=19)?100:
        (dif>=20 && dif<=29)?250:
        (dif>=30)?500:0).sum();
    }
}



//////////////
import static java.util.stream.IntStream.of;

interface Kata {
  static int speedLimit(int speed, int[] signals) {
    return of(signals).reduce(0, (fine, sign) -> fine + (
        speed > sign + 29 ? 500 :
        speed > sign + 19 ? 250 :
        speed > sign +  9 ? 100 : 0));
  }
}

///////////
import java.util.stream.IntStream;

public class Kata {
    public static int speedLimit(int speed, int[] signals) {
        return IntStream.of(signals)
                        .map(v -> speed - v)
                        .map(over -> over < 10 ? 0 : over < 20 ? 100 : over < 30 ? 250 : 500)
                        .sum();
    }
}