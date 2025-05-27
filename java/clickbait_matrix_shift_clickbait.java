public class JomoPipi {
  public static char[][] shift(char[][]m, int n){

    System.out.println(m.length*m[0].length);
    char arr[]=Arrays.stream(m)
                       .map(String::new)
                       .collect(Collectors.joining())
                       .toCharArray();
    char res[][]=new char[m.length][m[0].length];
    int i=
      Math.abs(arr.length-n);
      for(int j=0;j<m.length;++j){
        for(int k=0;k<m[0].length;++k){
          res[j][k]=arr[(i++)%arr.length];
        }
      }

    return res;
  }
}

/////////////
public class JomoPipi {
  public static char[][] shift(char[][] c, int n){   
    int A=c.length; int B=c[0].length; n=n%(A*B); 
    char R [][]= new char [A][B];  
    for (int i=0;i<A;i++){  
       for (int j=0;j<B;j++){  
          int index=(i*B+j+n)%(A*B); 
          R[index/B][index%B]=c[i][j];
       }
    } 
    return R;
  }
}        

///////////
import java.util.*;
import java.util.stream.Collectors;

public class JomoPipi {
    public static char[][] shift(char[][] m, int n) {
        List<String> flat = Arrays.asList(Arrays.stream(m).map(String::new).collect(Collectors.joining()).split(""));
        Collections.rotate(flat, n);
        return new Scanner(String.join("", flat)).findAll(".".repeat(m[0].length)).map(r -> r.group().toCharArray()).toArray(char[][]::new);
    }
}

///////////
