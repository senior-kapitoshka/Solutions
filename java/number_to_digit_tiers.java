public class Solution {

  public static String[] createArrayOfTiers(int num) {
    int n=Integer.toString(num).length();
    String res[]=new String[n];
    int j=0;
    res[j++]=String.valueOf(num);
    if(n==1) return res;
    
    while(num>0){
      if(j<n)res[j++]=String.valueOf(num/10);
      else break;
      num/=10;
    }
    String ans[]= new String[n];
    for(int i=j-1,k=0;i>=0;--i,++k){
      ans[k]=res[i];
    }
    return ans;
  } 
}

//////////////////////
public class Solution {
  public static String[] createArrayOfTiers(int num) {
    String[] result = new String[(num + "").length()];
    for (int i = 0; i < result.length; i ++) {
      result[i] = (num + "").substring(0, i + 1);
    }
    return result;
  } 
}

//////////////////
import java.util.stream.*;
public class Solution {

  public static String[] createArrayOfTiers(int num) {
    String n=String.valueOf(num);
    return IntStream.range(0,n.length())
                    .mapToObj(i->n.substring(0,i+1))
                    .toArray(String[]::new);
  } 
}

/////////////////
import java.util.stream.IntStream;
public class Solution {
  
    public static String[] createArrayOfTiers(int num) {
        var numStr = String.valueOf(num);
        return IntStream.range(1,numStr.length()+1)
                        .mapToObj(i->numStr.substring(0,i))
                        .toArray(String[]::new);

    }
}
////////////////////
public class Solution {

  public static String[] createArrayOfTiers(int a) {
    String b= String.valueOf(a);
        String[] s=new String[b.length()];
        for (int i = b.length()-1; i >= 0; i--) {
            s[i]=b.substring(0,i+1);
        }
    return s;
  } 
}

/////////////////////
