import java.util.stream.*;
import java.util.*;
public class Dinglemouse {
  public static String[] split(final String j) {
    if(j.isEmpty()) return new String[0];
    List<String> list=new ArrayList<>();
    int k=0;
    for(int i=0,n=j.length();i<n;++i){
      if(j.charAt(i)=='.'){
        list.add(j.substring(k,i));
        k=i+1;
      }
    }
    list.add(j.substring(k));
    return list.toArray(new String[0]);
  }
      /*without empty strings
      return Arrays.stream(j.split("[.]")).filter(i->!i.isEmpty())
      .map(String::valueOf).toArray(String []::new);*/
}

/////////////
public class Dinglemouse {

  public static String[] split(final String joint) { 
    return joint.isEmpty() ? new String[0] : joint.split("\\.",-1);
  }
  
}

/////////
