import java.util.*;
import java.util.stream.IntStream;

public class Solution {
  
   public static int[] largest(int n, int[] arr) {
     Arrays.sort(arr);
   return Arrays.copyOfRange(arr, arr.length - n, arr.length);
     /*
     неправильно:
     return IntStream.range(0,arr.length)
                .boxed()
                .sorted(Comparator.reverseOrder())
                .limit(n)
                .distinct() -----
                .sorted()
                .mapToInt(i -> arr[i]) -----
                .toArray();
     правильно:

     Arrays.stream(arr)
                .boxed()
                .sorted(Comparator.reverseOrder())
                .limit(n)
                .sorted()
                .mapToInt(Integer::intValue)
                .toArray();           
                */
   }
}
/////////////////////////
import java.util.Collections;
import java.util.Arrays;
public class Solution {
  
   public static int[] largest(int n, int[] arr) {
     return Arrays.stream(arr)
                     .boxed()                                   
                     .sorted(Collections.reverseOrder())      
                     .limit(n)  
                     .sorted() 
                     .mapToInt(Integer::intValue)            
                     .toArray(); 
   }
}
////////////////////////////
public class Solution {
   public static int[] largest(int n, int[] arr) {
     
     return java.util.Arrays.stream(arr)
       .map(i -> -i).sorted().limit(n)
       .map(i -> -i).sorted()
       .toArray();
   }
}

///////////////////////