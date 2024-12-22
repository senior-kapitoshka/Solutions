import java.util.stream.*;
import java.util.*;
import java.util.regex.*;


public class FruitGuy{
 
 public static String[] removeRotten(String[] f) {
 return (f==null)?new String[0]:Arrays.stream(f).map(i->{
   if(i.matches("^rotten([\\w]+)$")){
     i=i.replaceAll("rotten","").toLowerCase();
   }
   return i;
 }).toArray(String[]::new);
 }

}

////////////
import java.util.Arrays;
public class FruitGuy {
 public static String[] removeRotten(String[] fruitBasket) {
   return fruitBasket == null ? new String[0] : 
   Arrays.stream(fruitBasket).map(s -> s.replace("rotten", "").toLowerCase())
   .toArray(n -> new String[n]);
 }
}
///////////////
