import java.util.*;
import java.util.stream.*;

public class Kata {
    public static long arrayPacking(int[] arr) {
        return Long.parseLong(
                  Arrays.stream(
                          //reverse int array ~~~
                        IntStream.range(0, arr.length)
                                  .map(i -> arr[arr.length - 1 - i])
                                  .toArray()
                          //~~~~~~~~~~~~~~~~~~~~~
                              )
                      .mapToObj(
                                //map int to string ~~~
                                i-> String.format("%08d",Integer.parseInt(Integer.toBinaryString(i)))
                                //~~~~~~~~~~~~~~~~~~~~~
                              )
                      .collect(Collectors.joining())
                        //parse string to long
                          ,2); 
    }
}

//////////////////
import java.util.stream.*;
public class Kata {
     public static long arrayPacking(int[] arr) {
        return Long.parseLong(IntStream.range(0, arr.length)
                .map(x -> arr[arr.length - 1 - x])
                .mapToObj(Integer::toBinaryString)
                .mapToInt(Integer::parseInt)
                .mapToObj(x -> String.format("%08d",x))
                .collect(Collectors.joining()), 2);        
    }
      
}

/////////////
class Kata{
    static long arrayPacking(int[]a)
    {long r=0,s=-8;
        for(long i:a)
                r|=i<<(s+=8);
                        return r;}
    }