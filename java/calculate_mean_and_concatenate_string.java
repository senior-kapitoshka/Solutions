public class Kata
{
    public static Object[] mean(char[] lst)
    {
      Object res[]=new Object[2];
      int sum=0;
      StringBuilder sb=new StringBuilder();
      for(char c:lst){
        if(Character.isLetter(c)){
          sb.append(c);
        }else{
          sum+=c-'0';
        }
      }
      res[0]=(double)sum/10;
      res[1]=sb.toString();
       return res;
    }
}

///////////////
public class Kata
{
    public static Object[] mean(char[] lst)
    {
      double mean = 0;
        String string = "";

        for(char character : lst)
        {
            if(Character.isDigit(character))
                mean += Character.digit(character, 10);
            else
                string += character;
        }
        mean /= 10d;
        
        Object[] oggetto = {mean,string};
        
        return oggetto;
    }
}
///////////
public class Kata {
    public static Object[] mean(char[] chars) {
        String string = new String(chars);
        return new Object[]{
                string.chars().filter(Character::isDigit).map(c -> c - '0').average().orElse(0.0),
                string.replaceAll("\\d", "")
        };
    }
}
////////////
import java.util.stream.IntStream;
import static java.util.stream.Collectors.joining;

public class Kata {
  public static Object[] mean(char[] chars) {
    return new Object[] {getMean(chars), concat(chars)};
  }
  
  private static double getMean(char[] chars) {
    return getCodePointStream(chars)
                  .filter(Character::isDigit)
                  .map(Character::getNumericValue)
                  .average()
                  .orElse(0);
  }
  
  private static String concat(char[] chars) {
    return getCodePointStream(chars)
                  .filter(Character::isLetter)
                  .collect(StringBuilder::new, 
                            StringBuilder::appendCodePoint, 
                            StringBuilder::append)
                  .toString();
  }
  
  private static IntStream getCodePointStream(char[] chars) {
    IntStream.Builder builder = IntStream.builder();
    for (char next: chars) 
      builder.accept(next);
    return builder.build();
  }
}
///////////
public class Kata {
  public static Object[] mean(char[] lst) {
    String chars = new String(lst);
    double average = chars.chars()
        .filter(Character::isDigit)
        .map(i -> Character.getNumericValue((char)i))
        .average()
        .orElse(0);

    String str = chars.chars()
        .filter(Character::isLetter)
        .collect(StringBuilder::new, StringBuilder::appendCodePoint, StringBuilder::append)
        .toString();

    return new Object[] {average, str};
  }
}