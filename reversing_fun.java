public class FunReverse {
    
    public static String funReverse(String s) {
      StringBuilder sb=new StringBuilder(s);
        for(int i=0;i<s.length();++i){
          StringBuilder n=new StringBuilder();
          n.append(sb.substring(0,i)).append(new StringBuilder(sb.substring(i)).reverse().toString()); 
          sb=n;
        }
      return sb.toString();
    }
}


///////////////////
public class FunReverse {
    
    public static String funReverse(String s) {
        for(int i = 0; i < s.length(); i++)
           s = s.substring(0, i) + new StringBuilder(s.substring(i)).reverse().toString();
        return s;
    }
}

////////
