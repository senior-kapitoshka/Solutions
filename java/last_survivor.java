import java.util.*;
import java.util.stream.*;
public class Kata {
    public static String lastSurvivor(String s, int[] i) {
      String a[]={s};
      Arrays.stream(i).forEach(j->{
        String arr[]=a[0].split("");
        arr[j]="";
        a[0]=String.join("",arr);
      });
        return a[0];
    }
}


//////////////////
/// 
/// public class Kata {
public static String lastSurvivor(String letters, int[] coords) {
    StringBuilder sb = new StringBuilder(letters);
    for (int i : coords) {
      sb.deleteCharAt(i);
    }
    return sb.toString();
}
}

/////////////
/// import java.util.*;

public class Kata {
  public static String lastSurvivor(String letters, int[] coords) {
    StringBuilder result = new StringBuilder(letters);
    Arrays.stream(coords).forEach(result::deleteCharAt);
    return result.toString();
  }
}


/////////////////
/// mport java.util.List;
import java.util.stream.Collectors;

public class Kata {
    public static String lastSurvivor(String letters, int[] coords) {

        List<Character> lettersCharacterList = letters
                .chars()
                .mapToObj(e -> (char)e)
                .collect(Collectors.toList());

        for (int coord : coords) {
            lettersCharacterList.remove(coord);
        }

        return lettersCharacterList.stream().map(Object::toString).collect(Collectors.joining());
    }
}