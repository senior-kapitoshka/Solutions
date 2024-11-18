public class ArrayPrinter {
    public static String printArray(Object[] a) {
      String res=new String();
      for(int i=0;i<a.length;++i){
        res=res+a[i];
        if(i!=a.length-1)res=res+",";
      }
      return res;
    }
}

/////////////////
import java.util.*;

public class ArrayPrinter {

    public static String printArray(Object[] a) {
      List<String> l=new ArrayList<String>();//== ArrayList()
      for(Object i:a) l.add(i.toString());//==String.valueOf(i)
      return String.join(",",l);
    }
}


///////////////
import java.util.Arrays;
import java.util.stream.Collectors;

public class ArrayPrinter {

    public static String printArray(Object[] array) {
      return Arrays
      .stream(array)
      .map(Object::toString)
      .collect(Collectors.joining(","));
    }
}

//////////////
import java.util.*;

public class ArrayPrinter {

    public static String printArray(Object array[]) {
     
     
     String[] str = new String[array.length];
     
     for(int i=0; i<array.length; i++) {
     
     str[i]=String.valueOf(array[i]) ;
     
     }
     
     return String.join(",", str);
    }
}

/////////////////////
import java.util.stream.Stream;
import static java.util.stream.Collectors.joining;

public class ArrayPrinter {
  
  public static String printArray(Object[] array) {
    return Stream.of(array)
                 .map(Object::toString)
                 .collect(joining(","));
  }
}

///////////////////
import java.util.Arrays;
public class ArrayPrinter {
  public static String printArray(Object[] a) {
    return Arrays.toString(a).replaceAll("[\\[\\]\\s]", "");
  }
}
