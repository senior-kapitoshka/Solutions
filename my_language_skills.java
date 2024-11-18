package com.codewars.anter69;

import java.util.List;
import java.util.Map;
import java.util.ArrayList;
import java.util.Comparator;

public class MyLanguages {
  public static List<String> myLanguages(final Map<String, Integer> rs) {
   ArrayList<String> res=new ArrayList<>();
  ArrayList<Map.Entry<String, Integer>> arrayKeyVal =new ArrayList<Map.Entry<String, Integer>>(rs.entrySet());
    arrayKeyVal.sort(Comparator.comparing(Map.Entry::getValue,Comparator.reverseOrder()));
    for(Map.Entry<String, Integer> e: arrayKeyVal){
      if(e.getValue()>=60) res.add(e.getKey());
    } 
      return res;
  }
}

/////////////////
package com.codewars.anter69;
import java.util.stream.Collectors;
import java.util.*;

public class MyLanguages {
  public static List<String> myLanguages(final Map<String, Integer> results) {
    return results.entrySet()
                  .stream()
                  .filter( me -> me.getValue() >= 60 )
                  .sorted( (m1,m2) -> Integer.compare(m2.getValue(),m1.getValue()) )
                  .map( me -> me.getKey() )
                  .collect(Collectors.toList());
  }
}

////////////////
package com.codewars.anter69;

import java.util.Comparator;
import java.util.List;
import java.util.Map;
import java.util.stream.Collectors;

public class MyLanguages {
  public static List<String> myLanguages(final Map<String, Integer> results) {
    return results.entrySet()
                  .stream()
                  .filter(entry -> entry.getValue() >= 60)
                  .sorted(Comparator.comparingInt(Map.Entry<?, Integer>::getValue).reversed())
                  .map(Map.Entry::getKey)
                  .collect(Collectors.toList());
  }
}