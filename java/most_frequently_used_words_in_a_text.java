import java.util.*;

public class TopWords {
  
    public static List<String> top3(String s) {
        Map<String,Integer>mp=new HashMap<>();
      StringBuilder sb=new StringBuilder();
      for(int i=0;i<s.length();++i){
        if(Character.isLetter(s.charAt(i)) || s.charAt(i)=='\''){
          sb.append(s.charAt(i));
        }else{
          String to_put=sb.toString().toLowerCase();
          if(!to_put.isEmpty() && !to_put.matches("[\']+"))mp.put(to_put,mp.containsKey(to_put)?mp.get(to_put)+1:1);
          sb=new StringBuilder();
        }
      }
      String to_put=sb.toString().toLowerCase();
      if(!to_put.isEmpty())mp.put(to_put,mp.containsKey(to_put)?mp.get(to_put)+1:1);
      
      
      Queue<Map.Entry<String,Integer>>pq=
        new PriorityQueue<>(new Comparator<Map.Entry<String,Integer>>(){
          @Override
          public int compare(Map.Entry<String,Integer> lhs, Map.Entry<String,Integer> rhs){
            return lhs.getValue()==rhs.getValue()?
              lhs.getKey().compareTo(rhs.getKey()):
            rhs.getValue()-lhs.getValue();
          }
        });
      
      for(Map.Entry<String,Integer> e:mp.entrySet()){
        pq.add(e);
      }
      
      List<String>res=new ArrayList<>();
      int cnt=3;
      while(cnt-->0){
        if(!pq.isEmpty())res.add(pq.poll().getKey());
      }
        return res;
    }
}

/////////////////
import java.util.List;
import java.util.Arrays;
import java.util.Map;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.Comparator;
import java.util.Collections;

import static java.util.stream.Collectors.groupingBy;

public class TopWords {
    
    public static List<String> top3(String s) {
        return Arrays.stream(s.toLowerCase().split("[^a-z*|']"))
                .filter(o -> !o.isEmpty() && !o.replace("'","").isEmpty())
                .collect(groupingBy(Function.identity(), Collectors.counting())).entrySet().stream()
                .sorted(Collections.reverseOrder(Map.Entry.comparingByValue()))
                .map(Map.Entry::getKey)
                .limit(3)
                .collect(Collectors.toList());
    }
}

////////////////
import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.regex.Pattern;
import java.util.stream.*;
import java.util.Arrays;
import java.util.Collections;

public class TopWords {
    
    public static List<String> top3(String s) {
        String[] words = s.split("[^a-zA-Z']");
        
        final HashMap<String, Integer> wordCounter = new HashMap<String, Integer>();
        for (int i = 0; i < words.length; i++) {
            String currentWord = words[i].toLowerCase();
           if(Pattern.compile("[a-z]+").matcher(currentWord).find()){
                if (wordCounter.containsKey(currentWord)) {
                    wordCounter.put(currentWord, wordCounter.get(currentWord) + 1);
                } else {
                    wordCounter.put(currentWord, 1);
                }
           }
        }
        return Arrays.stream(wordCounter.keySet().toArray())
                .sorted((a, b) -> wordCounter.get(a) == wordCounter.get(b) ? 0 : wordCounter.get(a) < wordCounter.get(b) ? 1 : -1)
                .limit(3).map(key -> key.toString()).collect(Collectors.toList());
    }
}

///////////////
import static java.util.Comparator.reverseOrder;
import static java.util.Map.Entry.comparingByValue;
import static java.util.function.Function.identity;
import static java.util.stream.Collectors.counting;
import static java.util.stream.Collectors.groupingBy;
import static java.util.stream.Collectors.toList;

import java.util.List;
import java.util.Map.Entry;
import java.util.Scanner;
import java.util.regex.MatchResult;
import org.apache.commons.lang3.StringUtils;

public class TopWords {

    public static List<String> top3(final String s) {
        return new Scanner(s.toLowerCase())
                .findAll("[a-z']+")
                .map(MatchResult::group)
                .filter(StringUtils::isNotBlank)
                .filter(w -> !w.matches("'+"))
                .collect(groupingBy(identity(), counting()))
                .entrySet().stream()
                .sorted(comparingByValue(reverseOrder()))
                .limit(3)
                .map(Entry::getKey)
                .collect(toList());
    }
}

///////////////
import java.util.Comparator;
import java.util.List;
import java.util.Map;
import java.util.function.Function;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class TopWords {

    public static List<String> top3(String s) {
        return Stream.of(s.split("[\\s\n/.,:;@&?!\\-_]+"))
                .filter(word -> !word.replace("'", "").trim().isEmpty())
                .map(String::toLowerCase)
                .collect(Collectors.groupingBy(Function.identity(), Collectors.counting()))
                .entrySet().stream()
                .sorted(Comparator.comparing(Map.Entry::getValue, Comparator.reverseOrder()))
                .limit(3)
                .map(Map.Entry::getKey)
                .collect(Collectors.toList());
    }

}

//////////////
import java.util.List;
import java.util.Arrays;
import java.util.stream.Collectors;
import java.util.Map;
import java.util.regex.Pattern;

public class TopWords {
  public static List<String> top3(String s) {
   return Arrays.stream(s.toLowerCase().split("[^'a-z]"))
     .filter(t -> Pattern.compile("[a-z]").matcher(t).find())
     .collect(Collectors.groupingBy(w -> w))
				.entrySet().stream().sorted((a, b) -> b.getValue().size() - a.getValue().size()).limit(3)
				.map(Map.Entry::getKey).collect(Collectors.toList());
  }
}

//////////////
import java.util.List;
import java.util.Map.Entry;

import static java.util.Collections.reverseOrder;
import static java.util.stream.Collectors.counting;
import static java.util.stream.Collectors.groupingBy;
import static java.util.stream.Stream.of;

interface TopWords {
  static List<String> top3(String s) {
    return of(s.toLowerCase().split("[^a-z*|']"))
            .filter(w -> !w.replace("'", "").isEmpty())
            .collect(groupingBy(w -> w, counting())).entrySet().stream()
            .sorted(reverseOrder(Entry.comparingByValue()))
            .map(Entry::getKey).limit(3).toList();
  }
}

////////////
import java.util.*;
import java.util.regex.*;

public class TopWords {

    private static final Pattern W = Pattern.compile("'*[a-z][a-z']*");

    public static List<String> top3(String text) {
        Matcher m = W.matcher(text.toLowerCase());
        Map<String, Integer> freq = new HashMap<>();
        while (m.find()) freq.put(m.group(), freq.getOrDefault(m.group(), 0) + 1);
        return freq.keySet().stream().sorted((a, b) -> freq.get(b) - freq.get(a)).limit(3).toList();
    }
}