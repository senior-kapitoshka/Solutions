class CodeWars {
  public static int[][] matrix(int[][] a) {
    int arr[][]=new int[a.length][a[0].length];
    for(var i=0;i<a.length;++i){
      for(var j=0;j<a[i].length;++j){
        if(a[i][j]>=0 && i==j) arr[i][j]=1;
        else if(a[i][j]<0 && i==j) arr[i][j]=0;
        else arr[i][j]=a[i][j];
      }
    }
    return arr;
  }
}

/////////////////
class CodeWars {
  
  public static int[][] matrix(int[][] array) {

    int n = array.length, ret[][] = new int[n][n];
    
    for (int i = 0; i < n; i++) {
      System.arraycopy(array[i], 0, ret[i], 0, n);
      ret[i][i] = ret[i][i] < 0 ? 0 : 1;
    }
    
    return ret;
  }
  
}
//////////////
import static java.util.stream.IntStream.range;

interface CodeWars {
  static int[][] matrix(int[][] array) {
    return range(0, array.length)
                    .peek(i -> array[i][i] = array[i][i] < 0 ? 0 : 1)
                    .mapToObj(i -> array[i])
                    .toArray(int[][]::new);
  }
}
///////////////////
class CodeWars {
  public static int[][] matrix(int[][] array) {
    for (int i = 0; i < array.length; i++) {
      array[i][i] = array[i][i] < 0 ? 0 : 1;
    }
    return array;
  }
}