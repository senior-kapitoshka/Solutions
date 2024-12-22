import java.util.stream.*;

public class Solution {

  public static int signChange(int[] a) {
    if(a.length==0) return 0;
    Boolean flag=a[0]>=0?true:false;
    int cnt=0;
    for(int i=0;i<a.length;++i){
      if(a[i]>=0 && flag==false){
        flag=true;
        ++cnt;
      }else if(a[i]<0 && flag==true){
        flag=false;
        ++cnt;
      }
    }
    return cnt;
  }

}

//////////////
import static java.util.stream.IntStream.range;

class Solution {
  static int signChange(int[] arr) {
    return range(1, arr.length).map(i -> (arr[i] ^ arr[i - 1]) < 0 ? 1 : 0).sum();
  }
}

/////////////
import java.util.stream.IntStream;

public class Solution {
  public static int signChange(int[] arr) {
    return (int) IntStream.range(0, arr.length - 1)
                            .filter(i -> (arr[i] ^ arr[i + 1]) < 0)
                            .count();
  }
}

////////////////
import java.util.stream.IntStream;

public class Solution {
    public static int signChange(int[] arr) {
        return (int) IntStream.range(1, arr.length)
                                .filter(i -> arr[i] < 0 != arr[i - 1] < 0)
                                .count();
    }
}

////////////////
public class Solution {

  public static int signChange(int[] arr) {
    return java.util.stream.IntStream.range(1, arr.length)
        .map(i -> arr[i - 1] < 0 ^ arr[i] < 0 ? 1 : 0)
        .sum();
  }

}