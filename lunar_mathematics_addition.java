import java.util.*;
public class LunarCalculator{
  
  public static long add(String n1, String n2){
    StringBuilder sn=new StringBuilder();
    for(int i=0;i<n1.length();++i){
      sn.append((char)Math.max((int)n1.charAt(i),(int)n2.charAt(i)));
    }
    return Long.parseLong(sn.toString());
  }

  public static long add(long n1, long n2)
  {
    long res=-1;
    if(Long.toString(n1).length()==Long.toString(n2).length()){
      res=add(Long.toString(n1),Long.toString(n2));
    }else{
      if(Long.toString(n1).length()>Long.toString(n2).length()){
        int n=Long.toString(n1).length();
        int sz=Long.toString(n2).length();
        long t=add(Long.toString(n1).substring(n-sz),Long.toString(n2));
        res=Long.parseLong(Long.toString(n1).substring(0,n-sz) + Long.toString(t));
      }else{
        int sz=Long.toString(n1).length();
        int n=Long.toString(n2).length();
        long t=add(Long.toString(n1),Long.toString(n2).substring(n-sz));
        res=Long.parseLong(Long.toString(n2).substring(0,n-sz) + Long.toString(t));
      }
    }
    return res;
  }
}

//////////////
public class LunarCalculator{

    public static long add(long n1, long n2) {
        long v = 0, c=1;
        while (n1!=0 || n2!=0) {
            v += Math.max(n1%10, n2%10) * c;
            n1 /= 10; n2 /= 10; c *= 10;
        }
        return v;
    }
  }

  //////////
