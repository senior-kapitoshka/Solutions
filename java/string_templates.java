public class Kata 
{
    public static String buildString(String... args)
    {
      StringBuilder sb=new StringBuilder();
      sb.append("I like ");
      for(int i=0;i<args.length;++i){
        if(i<args.length-1)sb.append(args[i]+", ");
        else sb.append(args[i]+"!");
      }
      return sb.toString();
    }
}

/////////////////
public class Kata {
    public static String buildString(String... args) {
      return "I like " + String.join(", ", args) + "!";
    }
}

////////////////
public class Kata 
{
    public static String buildString(String... args)
    {
      return String.format("I like %s!",String.join(", ", args));
    }
}

////////////////
import java.util.*;
import java.util.stream.Collectors;

public class Kata 
{
    public static String buildString(String... args)
    {
        return String.format("I like %s!", 
                                Arrays.stream(args)
                                        .collect(Collectors.joining(", ")));
    }
}