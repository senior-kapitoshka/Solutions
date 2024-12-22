//fail random tests

import java.util.*;

public class Kata {
  public static class Pair{
    public Integer i;
    public String str;
    Pair(Integer is,String s){
      i=is;str=s;
    }
  };
  
    public static Object[] minRepeatingCharacterDifference(String tt) {
      System.out.println(tt);
      Map<Character,ArrayList<Integer>>mp=new HashMap<>();
      for(Character c:tt.toCharArray()){
        if(mp.containsKey(c)){
          mp.get(c).add(0);
          for(Map.Entry<Character,ArrayList<Integer>> e:mp.entrySet()){
            int n=e.getValue().size();
            int i=e.getValue().get(n-1)+1;
            
            e.getValue().remove(n-1);
            e.getValue().add(i);
          }
        }else{
          mp.put(c,new ArrayList<Integer>(Arrays.asList(0)));
          for(Map.Entry<Character,ArrayList<Integer>> e:mp.entrySet()){
            int n=e.getValue().size();
            int i=e.getValue().get(n-1)+1;
            
            e.getValue().remove(n-1);
            e.getValue().add(i);
          }
        }
      }
      Pair p=new Pair(Integer.MAX_VALUE,"");
      for(Map.Entry<Character,ArrayList<Integer>> e:mp.entrySet()){
        if(e.getValue().size()>1){
          System.out.println(e.getKey());
          for(Integer i:e.getValue())System.out.println(i);
          System.out.println("---");
          int n=e.getValue().size();
          Integer min=e.getValue().size()==2?
            e.getValue().get(0):
            Collections.min(e.getValue().subList(0,n-1));
          if(p.i>=min){
            if(p.i==min){
              if(min==1){
                if(tt.indexOf(p.str+""+p.str)>tt.indexOf(e.getKey()+""+e.getKey())){
                  p.str=e.getKey()+"";
                }
              }else{
                if(tt.indexOf(p.str)>tt.indexOf(e.getKey())){
                  p.str=e.getKey()+"";
                }
              }
            }else{
              p.str=e.getKey()+"";
              p.i=min;
            }
          }
        }
      }
      if(p.i==Integer.MAX_VALUE) return null;
      Object res[]=new Object[2];
      res[0]=p.i;
      res[1]=p.str;
      return res;
    }
}

//////////////
import java.util.*;

public class Kata {
    public static Object[] minRepeatingCharacterDifference(String text) {
        Map<Character, Integer> map = new HashMap<>();
        Object[] result = null;
        for (int i = 0; i < text.length(); i++) {
            char c = text.charAt(i);
            if (map.containsKey(c)) {
                int diff = i - map.get(c);
                if (result == null || (result[0] != null && diff < (Integer) result[0])) {
                    result = new Object[]{diff, String.valueOf(c)};
                }
            }
            map.put(c, i);
        }
        return result;
    }
}

/////////////
public class Kata {
    public static Object[] minRepeatingCharacterDifference(String text) {
        Integer a = null;
        String b = null;
        
        for (int i = 0; i < text.length() - 1; i++) {
            for (int j = i + 1; j < text.length(); j++) {
                if (text.charAt(j) == text.charAt(i)) {
                    if (a == null || a > j - i ) {
                        a = j - i;
                        b = String.valueOf(text.charAt(i));
                    }
                    break;
                }
            }
        }
        
        if (a != null) {
            return new Object[]{a, b};
        }
        
        return null;
    }
}
///////////
import java.util.HashMap;

public class Kata {
    public static Object[] minRepeatingCharacterDifference(String text) {
      HashMap<Character , Integer> charMap = new HashMap<>();
      Object[] result = null;
            
      for(int i = 0; i < text.length(); i++){
        char c = text.charAt(i);
        
        if(charMap.containsKey(c)){
          int distance = i - charMap.get(c);
          
          if(result == null || (result[0] != null && distance < (Integer) result[0])){
            result = new Object[]{distance, String.valueOf(c)};
          }
        }
        
        charMap.put(c,i);
      }
          
      return result;
    }
}

//////////////////
import java.util.Arrays;
import java.util.Comparator;
import java.util.stream.IntStream;

public class Kata {
    public static Object[] minRepeatingCharacterDifference(String text) {
        return IntStream.range(0, text.length())
                .mapToObj(i -> new Object[]{gap(text.substring(i), text.split("")[i]), text.split("")[i]})
                .filter(v -> (int) v[0] != -1)
                .min(Comparator.comparingInt(v -> (int) v[0]))
                .orElse(null);
    }

    private static int gap(String text, String target) {
        var rest = text.replaceFirst(target, "");
        var next = rest.indexOf(target);
        if (next == -1) {
            return -1;
        }
        return text.length() - (rest.substring(next)).length();
    }
}

/////////////
