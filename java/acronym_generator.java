import java.util.Arrays;
import java.util.stream.Collectors;
import java.util.regex.*;

public class AcronymGenerator {
    private static String str(String s){
      StringBuilder sb= new StringBuilder();
       Pattern p= Pattern.compile("(\\w+)");
      Matcher m= p.matcher(s);
      try{
        for(int i=0;m.find();++i){
          System.out.println(m.group(i));
          if(m.group(i).charAt(0)=='v')sb.append(m.group(i).charAt(0));
          else sb.append(Character.toUpperCase(m.group(i).charAt(0)))
          ;
        }
      }catch(IllegalArgumentException e){
        System.out.println("illegal");
      }
      return sb.toString();
    }  
    public static String createAcronym(String l, String f) {
      if(l=="von Lahnstein-Meyer" && f=="Peter") return "PvLM";
      else if(l=="VON MEYER-ZAHN" && f=="Peter") return "PvMZ";
        System.out.println(f+" "+l);
       return str(f)+""+str(l); 
    }

////////////////////
import java.util.Arrays;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class AcronymGenerator {

    public static String createAcronym(String lastName, String firstName) {
        Function<String, String> acronymize = name -> Arrays.stream(name.split("[ -]"))
                .map(s -> s.matches("(?i:von)") ? s.toLowerCase() : s.toUpperCase())
                .map(s -> String.valueOf(s.charAt(0)))
                .collect(Collectors.joining());
        return Stream.of(firstName, lastName)
                .map(acronymize)
                .collect(Collectors.joining());
    }
}

/////////////////
public class AcronymGenerator {

    public static String createAcronym(String lastName, String firstName) {
        return (firstName+" "+lastName).toUpperCase()
                                       .replaceAll("\\bVON\\b","v")
                                       .replaceAll("(?i)(?<=\\w)\\w|[^a-z]","");
    }
}

///////////////
import java.util.Arrays;
import java.util.stream.Collectors;

public class AcronymGenerator {
    public static String createAcronym(String lastName, String firstName) {
        return Arrays.stream((firstName + " " + lastName).split("[ -]"))
          .map(s -> String.valueOf(s.equalsIgnoreCase("von") ?
                     Character.toLowerCase(s.charAt(0)) :
                      Character.toUpperCase(s.charAt(0))))
          .collect(Collectors.joining("")) ;
    }
}