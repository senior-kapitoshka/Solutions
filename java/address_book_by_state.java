import java.util.*;
import java.util.regex.*;
import static java.lang.System.*;

public class State {
    public record Pair<K, V>(K key, V value) {
    }
    private static String ss="'AZ': 'Arizona','CA': 'California','ID': 'Idaho','IN': 'Indiana','MA': 'Massachusetts','OK': 'Oklahoma','PA': 'Pennsylvania','VA': 'Virginia'";
  
    private static Map<String,String> prepareMap(){
      Map<String,String>mp=new HashMap<String,String>();
      Pattern pt=Pattern.compile("'([\\w]+)': '([\\w]+)'");
      Matcher mt=pt.matcher(ss);
      while(mt.find()){
        mp.put(mt.group(1),mt.group(2));
      }
      return mp;
    }
    private static Map<String,List<Pair<String,String>>>process(String arr[]){
      Map<String,String> states=prepareMap();
      Map<String,List<Pair<String,String>>> mp=new TreeMap<>();
      Pattern pt=Pattern.compile("^([\\w\\s]+), ([\\w\\d\\s]+), ([\\w\\s]+)");
      for(String s:arr){
        Matcher mt=pt.matcher(s);
        while(mt.find()){
          StringBuilder sb=new StringBuilder();
          sb.append(mt.group(2)).append(" ").append(mt.group(3).substring(0,mt.group(3).length()-3));
          Pair<String,String>p=new Pair<>(mt.group(1),sb.toString().trim());    
          if(mp.containsKey(states.get(mt.group(3).substring(mt.group(3).length()-2).trim()))){
            mp.get(states.get(mt.group(3).substring(mt.group(3).length()-2))).add(p);
          }else{
            List<Pair<String,String>> l=new ArrayList<>();
            mp.put(states.get(mt.group(3).substring(mt.group(3).length()-2)),l);
            mp.get(states.get(mt.group(3).substring(mt.group(3).length()-2))).add(p);
          }
        }
      }
      return mp;
    }
    public static String byState(String s) {
        Map<String,List<Pair<String,String>>>mp=process(s.split("\n"));
        StringBuilder sb=new StringBuilder();
        int i=0;

        for(Map.Entry<String,List<Pair<String,String>>> e:mp.entrySet()){
          if(i==0)sb.append(e.getKey())
                    .append("\n");
          else sb.append(" ")
                    .append(e.getKey())
                    .append("\n");
          
          ++i;
          
          e.getValue().sort(new Comparator<Pair<String,String>>(){
            @Override
            public int compare(Pair<String,String> lhs, Pair<String,String> rhs){
              return lhs.key.compareTo(rhs.key);
            }
          });
          for(Pair<String,String> p:e.getValue()){
            sb.append("..... ")
              .append(p.key)
              .append(" ")
              .append(p.value)
              .append(" ")
              .append(e.getKey())
              .append("\n");
              
          }
        }

      sb.setLength(sb.length()-1);
      
      return sb.toString();
    }
}

//////////////////
import java.util.ArrayList;
import java.util.List;
import java.util.Map;
import java.util.TreeMap;
import java.util.stream.Collectors;

class State {
  static String byState(String str) {
    var states =
        Map.of(
            "AZ", "Arizona",
            "CA", "California",
            "ID", "Idaho",
            "IN", "Indiana",
            "MA", "Massachusetts",
            "OK", "Oklahoma",
            "PA", "Pennsylvania",
            "VA", "Virginia");

    var stats = new TreeMap<String, List<String>>();

    for (var line : str.split("\n")) {
      var state = line.substring(line.lastIndexOf(' ') + 1);
      line = line.replaceAll(",", "").replace(state, states.get(state));
      stats.computeIfAbsent(states.get(state), i -> new ArrayList<>()).add(line);
    }

    var result = new StringBuilder();
    for (var state : stats.entrySet()) {
      result.append(" ").append(state.getKey());
      var lines = state.getValue().stream().sorted().collect(Collectors.toList());
      for (var line : lines) {
        result.append("\n..... ").append(line);
      }
      result.append("\n");
    }
    return result.toString().trim();
  }
}

/////////////////
/// 
import java.util.*;
import java.util.regex.Pattern;
import java.util.stream.Collectors;

public class State {
  static Map<String, String> m = Map.of(
        "AZ", "Arizona",
        "CA", "California",
        "ID", "Idaho",
        "IN", "Indiana",
        "MA", "Massachusetts",
        "OK", "Oklahoma",
        "PA", "Pennsylvania",
        "VA", "Virginia"
);
    
public static String byState(String str) {

    str = Pattern.compile("\\w+$", Pattern.MULTILINE).matcher(str).replaceAll(x -> m.get(x.group()));

    return Arrays.stream(str.split("\n"))
                .collect(Collectors.groupingBy(x -> x.replaceAll(".* (?=\\w+$)", "")))
                .entrySet()
                .stream()
                .sorted(Map.Entry.comparingByKey())
                .map(x -> x.getKey() +
                    x.getValue().stream().sorted(Comparator.comparing(z -> z.replaceAll(",.*", "")))
                .map(y -> "\n..... " + y.replaceAll(",", "")).collect(Collectors.joining()))
                .collect(Collectors.joining("\n "));
}

}

////////////
/// 