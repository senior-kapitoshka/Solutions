import java.util.*;
public class Ransom {
  static boolean allCharactersSame(String s){
    int n = s.length();
    for (int i = 0; i < n; i++)
        if (s.charAt(i)!='-')
            return false;
         
    return true;
}
  
    public static boolean canMakeNote(String nt, String mz) {
      for(Character c:nt.toCharArray()){
        if(Character.isAlphabetic(c) 
           || Character.isDigit(c) || c=='\''){
          if(allCharactersSame(mz))return false;
          int l=mz.indexOf(Character.toLowerCase(c));
          int u=mz.indexOf(Character.toUpperCase(c));
          
          if(l==-1 && u==-1){
            
            if(c=='A'|| c=='a'){
              l=mz.indexOf(Character.toLowerCase('4'));
            }else if(c=='E'|| c=='e'){
              l=mz.indexOf(Character.toLowerCase('3'));
            }else if(c=='I'|| c=='i'){
              l=mz.indexOf(Character.toLowerCase('1'));
            }else if(c=='O'|| c=='o'){
              l=mz.indexOf(Character.toLowerCase('0'));
            }else if(c=='S'|| c=='s'){
              l=mz.indexOf(Character.toLowerCase('5'));
            }else if(c=='Z'|| c=='z'){
              l=mz.indexOf(Character.toLowerCase('2'));
            }else if(l==-1 && u==-1) return false;
          }else if(l!=-1){
            StringBuilder sb=new StringBuilder(mz);
            sb.setCharAt(l,'-');
            mz=sb.toString();
          }else if(u!=-1){
             StringBuilder sb=new StringBuilder(mz);
            sb.setCharAt(u,'-');
            mz=sb.toString();
          }
        }
      }
        return true;
    }
}

//////////
import java.util.*;

public class Ransom {
    
    private static Map<Character, Character> SUB = new HashMap<Character, Character>();
    static { SUB.put('4', 'a');    SUB.put('3', 'e');    SUB.put('1', 'i');
             SUB.put('0', 'o');    SUB.put('5', 's');    SUB.put('2', 'z');
    }
             
    public static boolean canMakeNote(String note, String magazine) {
        Map<Character,Integer> noteCount = new HashMap<Character,Integer>();
        note.toLowerCase().chars().mapToObj( i -> (char) i )
                                  .filter(   c -> Character.isLetterOrDigit(c) || c == '\'' )
                                  .forEach(  c -> noteCount.put(c, noteCount.getOrDefault(c, 0) + 1 ) );
                                  
        for (char c: magazine.toLowerCase().toCharArray()) {
            if (noteCount.containsKey(c))                  noteCount.put(c, noteCount.get(c) - 1);
            else if (SUB.containsKey(c)) { c = SUB.get(c); noteCount.put(c, noteCount.get(c) - 1); }
            
            noteCount.remove(c, 0);
            if (noteCount.isEmpty()) break;
        }
        return noteCount.isEmpty();
    }
    
    
}

/////////////////
public class Ransom {
    public static boolean canMakeNote(String s, String m) {
        String del = "oizeas"; 
        s=s.toLowerCase(); m=m.toLowerCase();  
        for (char c : s.toCharArray()){  
           if(!((c>='a'&&c<='z')||(c>='0'&&c<='9')||c=='\''))continue; 
           int index=del.indexOf(c);  
           int n = m.length(); m=m.replaceFirst(""+c,""); 
           if(n!=m.length())continue; 
           if(index==-1)return false;  
           m=m.replaceFirst(""+index,""); 
           if(n==m.length())return false;
          } 
         return true;
      }
} 

////////////////
public class Ransom {
    public static boolean canMakeNote(String note, String mag) {
        String[] n = note.toLowerCase().split("");
        mag = mag.toLowerCase();
        for(String s:n){
          if(!s.matches("[a-zA-Z0-9]|\'")) continue;
          int len = mag.length();
          mag = mag.replaceFirst(s, "");
          if(mag.length()==len) {
            if(s.equals("a")) s="4";
            else if(s.equals("e")) s="3";
            else if(s.equals("i")) s="1";
            else if(s.equals("o")) s="0";
            else if(s.equals("s")) s="5";
            else if(s.equals("z")) s="2";
            mag = mag.replaceFirst(s, "");
            if(mag.length()==len) return false;
          }
        }
        return true;
    }
}

/////////////////
public class Ransom {

  public static boolean canMakeNote(String note, String magazine) {
    StringBuilder sb = new StringBuilder(note.toUpperCase().replaceAll("[^A-Z0-9']",""));
    int idx,subidx;
    for (final char m : magazine.toUpperCase().toCharArray()) {      
      if ((idx = sb.indexOf(""+m)) < 0 && (subidx = "012345".indexOf(""+m)) > -1) idx = sb.indexOf(""+"OIZEAS".charAt(subidx));
      if (idx > -1 && (sb = sb.deleteCharAt(idx)).length() == 0) return true; 
    }     
    return false;
  }
  
}

///////////
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.function.Function;
import java.util.stream.Collectors;

public class Ransom {
    private static final String ALLOWED = "[a-zA-Z0-9']";
    
    private static final Map<String, String> REPLACES = new HashMap<>();
    static {
      REPLACES.put("4", "a");
      REPLACES.put("3", "e");
      REPLACES.put("1", "i");
      REPLACES.put("0", "o");
      REPLACES.put("5", "s");
      REPLACES.put("2", "z");
    }
    
    public static boolean canMakeNote(String note, String magazine) {
      Map<String, Long> noteCounts = Arrays.stream(note.toLowerCase().split("")).
              filter(item -> item.matches(ALLOWED)).
              collect(Collectors.groupingBy(Function.identity(), Collectors.counting()));
      return Arrays.stream(magazine.toLowerCase().split("")).
                anyMatch(item -> {
                  noteCounts.computeIfPresent(noteCounts.containsKey(item) ? item : REPLACES.get(item), 
                          (key, value) -> (value == 1 ? null : value - 1));
                  return noteCounts.isEmpty();
                });
    }   
}