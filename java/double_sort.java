package com.codewars.a.partridge;
import java.util.*;

public class DoubleSort {
    public static Object[] dbSort(Object[] a){
        List<Integer> dig=new ArrayList<>();
        List<String> str=new ArrayList<>();
      for(Object o:a){
        if(o instanceof Integer){
          dig.add((Integer)o);
        }else if(o instanceof String){
          str.add((String)o);
        }
      }
      Collections.sort(dig);
      Collections.sort(str);
      Object res[]=new Object[a.length];
      int j=0;
      for(Integer i:dig) res[j++]=i;
      for(String i:str) res[j++]=i;
      return res;
    }
}

///////////////
package com.codewars.a.partridge;

import java.util.Arrays;
import java.util.stream.Stream;

public class DoubleSort {
    public static Object[] dbSort(Object[] a){
        return Stream.concat(
                Arrays.stream(a).filter((x)-> x instanceof Number).map((x)->(Number)x).sorted()
                ,Arrays.stream(a).filter((x)->x instanceof String).map((x)->(String)x).sorted()
        ).toArray();
    }
}

///////////////
package com.codewars.a.partridge;
import java.util.Arrays;
import java.util.stream.*;

public class DoubleSort
{
  public static Object[] dbSort(Object[] a)
  {
    Stream c = Arrays.stream(a).filter(i->i instanceof Integer).sorted();
    Stream v = Arrays.stream(a).filter(i->i instanceof String).sorted();
    return Stream.concat(c, v).toArray();
  }
}

/////////////
package com.codewars.a.partridge;

import java.util.stream.*;
import java.util.Arrays;

public class DoubleSort {
    public static Object[] dbSort(Object[] a){
        return IntStream.range(0, 2)
                .mapToObj(x -> Arrays.stream(a)  
                              .filter(y -> x == 0 ?
                                          y instanceof Integer :
                                          y instanceof String)
                              .sorted()
                              .toArray())
                .flatMap(x -> Arrays.stream(x))
                .toArray();
    }
}

/////////////////
package com.codewars.a.partridge;

import java.util.stream.Stream;

public class DoubleSort {
    public static Object[] dbSort(Object[] a){
        return Stream.concat(Stream.of(a).filter(o -> o.getClass().equals(Integer.class)).sorted(), 
                             Stream.of(a).filter(o -> o.getClass().equals(String.class)).sorted()).toArray();
    }
}

/////////////