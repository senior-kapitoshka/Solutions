import java.util.*;
public class Kata
{
  public static Object[] unflatten(int[] fl)
  {
    List<Object>res=new ArrayList<Object>();
    boolean flag=false;
    int t[]=null;
    int cnt=0;
    int sz=0;
    int size=fl.length;
    for(int i=0;i<size;++i){
      if(flag){
        if(cnt!=sz){
          t[cnt++]=fl[i];
        }
        if(cnt==sz){
          flag=false;
          cnt=0;
          sz=0;
          res.add(t);
          t=null;
        }
      }else if(!flag){
        if(fl[i]>=3){
          flag=true;
          sz=fl[i]<size-i?fl[i]:(size-i);
          t=new int[sz];
          t[cnt++]=fl[i];
        }else{
          res.add(fl[i]);
        }
      }
    }
    if(t!=null)res.add(t);
    Object[] result= new Object[res.size()];
    res.toArray(result);
    return result;
  }
}
/////////////
import java.util.*;

public class Kata {

  public static Object[] unflatten(final int[] fa) {
    final List<Object> res = new ArrayList<>();
    for (int i=0; i<fa.length; ) res.add(fa[i] < 3 ? fa[i++] : Arrays.copyOfRange(fa,i,Math.min(fa.length,i+=fa[i])));
    return res.toArray();
  }
  
}
////////////
import java.util.ArrayList;
import java.util.Arrays;

class Kata {
  static Object[] unflatten(int[] flatArray) {
    var list = new ArrayList<>();
    for (int i = 0; i < flatArray.length; ) {
      if (flatArray[i] < 3) {
        list.add(flatArray[i++]);
      } else {
        list.add(Arrays.copyOfRange(flatArray, i, Math.min(i += flatArray[i], flatArray.length)));
      }
    }
    return list.toArray();
  }
}
/////////
