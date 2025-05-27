import java.util.*;
public class FreeUrinals {
  public static int getFreeUrinals(String u){
    if(u.length()==1) return u.charAt(0)=='0'?1:0;
    int cnt=0;
    for(int i=0;i<u.length();){
      if(i==0 ){
        if(u.charAt(i)=='0' && u.charAt(i+1)=='0'){
           ++cnt;
          i+=2;
        }else ++i;
      }else if(i==u.length()-1){
        if(u.charAt(i-1)=='0' && u.charAt(i)=='0'){
          ++cnt;
          ++i;
         }else if(u.charAt(i-1)=='1' && u.charAt(i)=='1'){
          return -1;
        }else ++i;
      }else if(u.charAt(i)=='0' && (u.charAt(i-1)=='0' && u.charAt(i+1)=='0')){
        ++cnt;
        i+=2;
      }else if(u.charAt(i)=='1' && (u.charAt(i-1)=='1' || u.charAt(i+1)=='1')){
        return -1;
      }else{
        i++;
      }
    }
    return cnt;
  }
}
///////////////////
class FreeUrinals {
  static int getFreeUrinals(String urinals) {
    return urinals.contains("11") ? -1 : 
    urinals.replaceAll("010|10|01", "1")
                .replace("00", "0") 
                .replace("1", "")
                .length();
  }
}
/////////////
public class FreeUrinals {
  public static int getFreeUrinals(String urinals){
    if (urinals.contains("11")) return -1;
        if (urinals.equals("0")) return 1;
        if (urinals.equals("1")) return 0;

        char[] chars = urinals.toCharArray();
        int counter = 0;

        for (int i = 0; i < chars.length - 1; i++) {
            if (i == 0) {
                if (chars[i] == '0' && chars[i + 1] == '0') {
                    chars[i] = '1';
                    counter++;
                }
            }
            if (i > 0) {
                if (chars[i] == '0' && chars[i - 1] == '0' && chars[i + 1] == '0') {
                    chars[i] = '1';
                    counter++;
                }
            }
        }
        if (chars[chars.length - 1] == '0' && chars[chars.length - 2] == '0') {
            counter++;
        }
        return counter;
  }
}
/////////
public class FreeUrinals {
  public static int getFreeUrinals(String urinals){

    if(urinals.contains("11")) {
      return -1;
    }
    
    return urinals.replace("010", "-")
                .replace("10", "-")
                .replace("01", "-")
                .replace("1", "-")
                .replace("00", "0")
                .replace("-", "")
                .length();
  }
}
///////////
