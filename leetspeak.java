import java.util.stream.*;
public class Leetspeak extends Encoder{
  private java.util.Map<String,String>mp=
    java.util.Map.ofEntries(java.util.Map.entry("a","4"),
                           java.util.Map.entry("e","3"),
                           java.util.Map.entry("l","1"),
                           java.util.Map.entry("m","/^^\\"),
                           java.util.Map.entry("o","0"),
                            java.util.Map.entry("u","(_)")
                           );
  public String encode(String src){
    return src==null?"":java.util.Arrays.stream(src.split("")).map(s ->{
      if(mp.containsKey(s.toLowerCase())) return mp.get(s.toLowerCase());
      return s;
    }).collect(Collectors.joining());
  }
  
}

abstract class Encoder{
  public abstract String encode(String source);
}

////////////
public class Leetspeak extends Encoder {

  public String encode(String source){
    if(source == null || source == "") {
      return "";
    }
  
    source = source.replaceAll("(?i)a", "4");
    source = source.replaceAll("(?i)e", "3");
    source = source.replaceAll("(?i)l", "1");
    source = source.replaceAll("(?i)m", "/^^\\\\");
    source = source.replaceAll("(?i)o", "0");
    source = source.replaceAll("(?i)u", "(_)");

    return source;
  }
  
}

abstract class Encoder {
  public abstract String encode(String source);
}

////////////
public class Leetspeak extends Encoder{

  @Override
  public String encode(String source){
    if(source == null) return "";
    return source.replaceAll("[aA]", "4").replaceAll("[eE]", "3").replaceAll("[lL]", "1").replaceAll("[mM]", "/^^\\\\").replaceAll("[oO]", "0").replaceAll("[uU]", "(_)");
  }
  
}

abstract class Encoder{
  public abstract String encode(String source);
}

//////////
import java.util.*;
import java.util.stream.*;

public class Leetspeak extends Encoder {

  private Map<String, String> dic = Map.of("a", "4", "e", "3", "l", "1", "m", "/^^\\", "o", "0", "u", "(_)");

  public String encode(String s){
    return s == null || s.isEmpty() ? "" : Arrays.stream(s.split(""))
                                                  .map(x -> dic.get(x.toLowerCase()) == null ? x : dic.get(x.toLowerCase()))
                                                  .collect(Collectors.joining(""));
  }
  
}

abstract class Encoder {
  public abstract String encode(String source);
}

////////