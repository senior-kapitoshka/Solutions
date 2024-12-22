import java.util.*;
public class Abbreviator {

  public String abbreviate(String s) {
    StringBuilder sb=new StringBuilder();
    int cnt=0;
    Character last=' '; 
    Character prev_last=' '; 
    for(Character c:s.toCharArray()){
      if(Character.isAlphabetic(c)){
        if(cnt==0){
          ++cnt;
          sb.append(c);
        }else{
          ++cnt;
          prev_last=last;
          last=c;
        }
      }else{
         if(cnt==0 ||cnt==1){
          sb.append(c);
          cnt=0;
        }else if(cnt==2){
          sb.append(last).append(c);
          cnt=0;
        }else if(cnt==3){
          sb.append(prev_last).append(last).append(c);
          cnt=0;
        }else{
          sb.append(cnt-2).append(last).append(c);
          cnt=0;
        }
      }
    }
    if(cnt==2){
      sb.append(last);
    }else if(cnt==3){
      sb.append(prev_last).append(last);
    }else{
      if(cnt!=0 && cnt!=1)sb.append(cnt-2).append(last);
    }
    return sb.toString();
  }

}

//////////////////////////////////////
public class Abbreviator {

    public String abbreviate(String s) {
        String[] words = s.split("[^a-zA-Z]+");
        String[] separators = s.split("[a-zA-Z]+");
        String result = "";

        int i = 1;
        for (String word : words) {
            result += processWord(word);
            if (i < separators.length) {
                result += separators[i++];
            }
        }
        return result;
    }

    private String processWord(String word) {
        if (word.length() < 4) return word;
        int n = word.length() - 2;
        return "" + word.charAt(0) + n + word.charAt(word.length() - 1);
    }
}


//////////////
class Abbreviator {
    static String abbreviate(String string) {
      for (var s : string.split("[^a-zA-Z]")) {
        string = string.replaceFirst(s, s.length() > 3 ? 
                                        "" + s.charAt(0) + (s.length() - 2) + s.substring(s.length() - 1) :
                                         s);
      }
      return string;
    }
  }

  /////////////
  import java.util.regex.Pattern;

  public class Abbreviator {
  
      public String abbreviate(String inputString) {
          return Pattern.compile("([a-zA-Z])([a-zA-Z]{2,})([a-zA-Z])").matcher(inputString)
                  .replaceAll(mr -> mr.group(1) + mr.group(2).length() + mr.group(3));
      }
  }