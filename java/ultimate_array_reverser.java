import java.util.ArrayList;
import java.util.List;
public class ArrayReverser
{
   public static String[] reverse(String[] a)
   {
    String sb=new StringBuilder(String.join("",a)).reverse().toString();
     List<String>ls=new ArrayList<String>();
     System.out.println(sb);
     int j=0;
     int z=0;
     for(String i:a){
       int x=i.length();
       z+=x;
       String s=sb.substring(j,z);
       ls.add(s);
       j+=x;
     }
     String res[]=new String[ls.size()];
     return ls.toArray(res);
   }
}

////////////////////
public class ArrayReverser {

   public static String[] reverse(String[] a) {
     String s = new StringBuilder(String.join("",a)).reverse().toString();
     String[] b = new String[a.length];
     int i = 0, x = 0;
     for (String ss: a) b[x++] = s.substring(i,i+=ss.length());
     return b;
   }
}

///////////////
import java.util.*;
class ArrayReverser
{
	static String[] reverse(String[] Q)
	{
		String R = new StringBuffer(String.join("",Q))
                                                    .reverse()
                                                    .toString();
		int[] S = {0};
		return Arrays
                    .stream(Q)
                    .map(V -> R
                    .substring(S[0],S[0] += V.length()))
                    .toArray(String[]::new);
	}
}

///////////////
public class ArrayReverser
{
   public static String[] reverse(String[] a)
   {
        String str = new StringBuilder(String.join("", a)).reverse().toString();
        for (int i = 0; i < a.length; i++) {
            a[i] = str.substring(0, a[i].length());
            str = str.substring(a[i].length());
        }
        return a;
   }
}
