import java.util.stream.*;
import java.util.*;
public class Shifter{
    public static int count(String st){
        return Arrays.stream(st.split(" "))
                    .collect(Collectors.toSet())//distinct()
                    .stream()
                    .reduce(0,(acc,s)->
                acc+=s.matches("[H|I|N|O|S|X|Z|M|W]+")?1:0,
                            Integer::sum
      );
    }
}

////////////////
import java.util.stream.*;
import java.util.*;
public class Shifter{
    public static int count(String st){
        return Arrays.stream(st.split(" "))
                    .distinct()
                    .reduce(0,(acc,s)->
                acc+=s.matches("[H|I|N|O|S|X|Z|M|W]+")?1:0,
                            Integer::sum
      );
    }
}

///////////////
import static java.util.stream.Stream.of;

interface Shifter {
  static int count(String st) {
    return (int) of(st.split(" "))
                    .distinct()
                    .filter(w -> w.matches("[HIMNOSWXZ]+"))
                    .count();
  }
}
