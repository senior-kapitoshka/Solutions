import java.util.*;
import java.util.stream.*;
import java.util.regex.*;

class Kata {
  static private String d[]; 
  static private String find(String w){
    String res=new String();
    StringBuilder rgx=new StringBuilder();
    rgx.append("^");
    int cnt=0;
    for(Character c:w.toCharArray()){
      if(c=='*'){
        ++cnt;
      }else{
        if(cnt!=0){
          rgx.append("[\\w]");
          rgx.append("{"+cnt+"}");
          cnt=0;
          rgx.append(c);
        }else{
          rgx.append(c);
        }
      }
    }
    if(cnt!=0){
      rgx.append("[\\w]");
      rgx.append("{"+cnt+"}");
    }
    rgx.append("$");
    for(String s:d){
      if(s.matches(rgx.toString())){
        res=s;
        break;
      }
    }
    return res;
  }
  static String translate(String sp, String[] voc) {
    d=voc;
    StringBuilder sb=new StringBuilder();
    StringBuilder t=new StringBuilder();
    for(Character c:sp.toCharArray()){
      if(Character.isAlphabetic(c) || c=='*'){
        t.append(c);
      }else{
        String to_append = find(t.toString());
        t.setLength(0);
        sb.append(to_append).append(c);
      }
    }
        String to_append = find(t.toString());
        t.setLength(0);
        sb.append(to_append);
        return sb.toString();
    }
}

/////////////////
class Kata {
  
    static String translate(String speech, String[] vocab) {
      String words[] = speech.split(" ");
      for (int i = 0; i < words.length; i++) {
        String regex = words[i].replaceAll("[?!,.]", "").replace("*", ".");
        String extra = words[i].replaceAll("[a-z*]", "");
        for (String v : vocab) if (v.matches(regex)) words[i] = v + extra;
      }
      return String.join(" ", words);
    }
    
  }

  ////////////////
