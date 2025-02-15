import java.util.*;
import java.util.stream.*;
public class Kata
{
  public static String rakeGarden(String gd){
      return Arrays.stream(gd.split(" ")).map(s->{
        if(s.equals("rock") || s.equals("gravel") ){
          return s;
        }
        return "gravel";
      }).collect(Collectors.joining(" "));
    }
}

///////////////
public class Kata
{
  public static String rakeGarden(String garden) {
      return garden.replaceAll("\\b(?!(gravel)|(rock)\\b)\\w+\\b", "gravel");
    }
}