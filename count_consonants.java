import java.util.stream.*;
public class Consonants {
  public static int getCount(String s) {
    return s.chars().reduce(0,(acc,c)->{
      if(Character.isAlphabetic(c)){
        switch(c){
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U': acc+=0;break;
            default: acc+=1;
        }
      }
      return acc;
    });
  }
}

/////////
public class Consonants {
    public static int getCount(String str) {
      return str.replaceAll("[^A-Za-z]|[AEIOUaeiou]", "").length();
    }
  }
/////////
import java.util.Set;

public class Consonants {  
  private static final Set<Integer> VOWELS = 
    Set.of((int) 'a', (int) 'e', (int) 'i', (int) 'o', (int) 'u');
  
  public static int getCount(String str) {
    return (int) str.chars()
                    .filter(Character::isLetter)
                    .filter(i -> !VOWELS.contains(i))
                    .count();
  }
}

///////////
public class Consonants {
    public static int getCount(String str) {
      return (int) str.chars()
                  .filter(x -> Character.isAlphabetic(x) && !"aeiouAEIOU".contains(String.valueOf((char)x)))
                  .count();
    }
  }

////////////
  