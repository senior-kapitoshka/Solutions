import java.util.*;
import java.util.regex.*;
import static java.lang.System.*;

class Kata {
    private static String[] voc;
  
    private static class Token{
      private int id;
      private String rgx;
      public List<String> ls=new ArrayList<>();
      public Token(int i, String r){
        id=i;
        rgx=r;
      }
      public int getId(){
        return id;
      }
      public String getStr(){
        return rgx;
      }
    };
  
    private static String toRgx(String s){
      StringBuilder sb=new StringBuilder();
      int cnt=0;
      for(Character c:s.toCharArray()){
        if(c=='*'){
          ++cnt;
        }else{
          if(cnt!=0){
            sb.append("[\\w]"+"{"+cnt+"}");
            cnt=0;
          }
          sb.append(c);
        }
      }
      if(cnt!=0){
        sb.append("[\\w]"+"{"+cnt+"}");
      }
      return sb.toString();  
    }
  
    private static Token tokenize(int i,String s){
      s=toRgx(s);
      Token t=new Token(i,s);
      for(String str:voc){
        if(str.matches(s)){
          t.ls.add(str);
        }
      }
      return t;
    }
  
    public static String translate(String sch, String[] v) { 
      voc=v;
      Pattern pt=Pattern.compile("[\\w|*]+");
      Matcher mt=pt.matcher(sch);
      Queue<Token>pq=new PriorityQueue<Token>(new Comparator<Token>(){
        @Override
        public int compare(Token lhs, Token rhs){
          return lhs.ls.size()-rhs.ls.size();
        }
      });
      int i=0;
      for(;mt.find();++i){
        pq.add(tokenize(i,sch.substring(mt.start(),mt.end())));
      }
      String ln[]=new String[i];
      Set<String> set= new HashSet<>();
      while(!pq.isEmpty()){
        Token t=pq.poll();
        if(t.ls.size()==1){
          String res=t.ls.get(0);
          set.add(res);
          ln[t.getId()]=res;
        }else {
          for(int j=0;j<t.ls.size();++j){
            if(set.contains(t.ls.get(j))){
              t.ls.remove(j); //remove from list by index
            }
          }
          pq.add(t);
        }
      }
      StringBuilder res=new StringBuilder();
      int k=0;
      char ca[]=sch.toCharArray();
      for(int j=0;j<ca.length;){
        if(ca[j]=='*' || Character.isAlphabetic(ca[j])){
          res.append(ln[k]);
          j+=ln[k++].length();
        }else{
          res.append(ca[j++]);
        }
      }
      return res.toString();
    }
}

///////////////////////////
import static java.util.regex.Pattern.compile;
import static java.util.stream.IntStream.range;
import java.util.regex.Matcher;

class Kata {

  static String translate(String s, String[] v) {
    while (s.contains("*")) {
      Matcher m = compile("[*a-z]*\\*[*a-z]*").matcher(s);
      while (m.find()) {
        int i = range(0, v.length).filter(x -> v[x].matches(m.group().replace("*", "."))).reduce((a, b) -> -1).getAsInt();
        if (i < 0)
          continue;
        s = s.substring(0, m.start()) + v[i] + s.substring(m.end());
        v[i] = "";
      }
    }
    return s;
  }

}

///////////////////
import java.util.regex.*;
import java.util.stream.*;
import java.util.*;
import org.apache.commons.lang3.*;

class Kata {
  private static final Pattern re = Pattern.compile("[\\w\\*]+");
  public static String translate(String speech, String[] vocabulary) { 
    final var words = re.matcher(speech)
      .results()
      .map(MatchResult::group)
      .filter(w -> w.contains("*"))
      .collect(Collectors.toList());
    if (words.size() == 0) return speech;
    final var w0 = words.get(0);
    final var re0 = Pattern
      .compile(String.format("^%s$", w0.replaceAll("\\*", ".")));
    final var vs = Stream.of(vocabulary)
      .filter(v -> re0.matcher(v).matches())
      .collect(Collectors.toList());
    if (vs.size() == 0) return null;
    final var i = speech.indexOf(w0);
    for (var v : vs) {
      final var j = ArrayUtils.indexOf(vocabulary, v);
      final var s2 = speech.substring(0, i) + v + speech.substring(i + v.length());
      final var vs2 = splice(vocabulary, j);
      final var sub = translate(s2, vs2);
      if (sub != null) return sub;
    }
    return null;
  }
  private static String[] splice(String[] arr, int i) {
    if (arr == null || i < 0 || i >= arr.length) return arr;
    return IntStream.range(0, arr.length)
      .filter(j -> j != i)
      .mapToObj(j -> arr[j])
      .toArray(String[]::new);
  }
}

////////////////////
import java.util.*;
import java.util.regex.Matcher;
import java.util.regex.Pattern;
import java.util.stream.Collectors;

class Kata {
    static String translate(String speech, String[] vocabulary) {
        if (speech.length() == 0) {
            return "";
        }
        List<String> voc = new ArrayList<String>();
        voc.addAll(Arrays.asList(vocabulary));
        List<String> words = new ArrayList<String>();
        Matcher m = Pattern.compile("[*a-z]+|[\\!\\?\\.\\,]+").matcher(speech);
        while (m.find()) {
            words.add(m.group());
        }
        while (words.stream().anyMatch(w -> w.contains("*"))) {
            for (int i = 0; i < words.size(); i++) {
                int finalI = i;
                List<String> filtered = voc.stream().filter(x -> {
                    String wg = words.get(finalI);
                    if (x.length() == wg.length()) {
                        for (int k = 0; k < wg.length(); k++) {
                            if (wg.charAt(k) == '*') {
                                continue;
                            }
                            if (wg.charAt(k) != x.charAt(k)) {
                                return false;
                            }
                        }
                        return true;
                    }
                    return false;
                }).collect(Collectors.toList());
                if (filtered.size() == 1) {
                    words.set(i, filtered.get(0));
                    voc.remove(filtered.get(0));
                }
            }
        }
        return String.join(" ", words.toArray(new String[0])).replaceAll("([a-z])\\s([\\!\\?\\.\\,])", "$1$2");
    }
}

/////////////////
import java.util.*;

class Kata {
  public static String translate(String speech, String[] vocabulary) { 
    List<String> pieces = Arrays.asList(speech.split("((?<=[ \\?!,\\.])|(?=[ \\?!,\\.]))"));
    List<String> words = new ArrayList<>(Arrays.asList(vocabulary));
    boolean modified = true;
    while (modified) {
      modified = false;
      for (int i = 0; i < pieces.size(); i++) {
        if (pieces.get(i).contains("*")) {
          modified = true;
          String piece = pieces.get(i).replace('*', '.');
          List<String> validWords = new ArrayList<>();
          for (String word : words) {
            if (word.matches(piece)) {
              validWords.add(word);
            }
          }
          if (validWords.size() == 1) {
            pieces.set(i, validWords.get(0));
            words.remove(validWords.get(0));
          }
        }
      }
    }
    return String.join("", pieces);
  }
}