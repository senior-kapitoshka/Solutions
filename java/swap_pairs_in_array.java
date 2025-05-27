
 public class Swappairs {

    public Object[][][] swapp(Object[][] input) {
    Object out [][]=new Object[input.length][2];
    for(int i=0;i<input.length;++i){

      out[i][0]=input[i][1];
      out[i][1]=input[i][0];   
      }
    

        return new Object[][][]{input,out};
    }
}

/////////////////
import java.util.Arrays;

 public class Swappairs {

    public Object[][][] swapp(Object[][] input) {
      return new Object[][][] {
                input,
                Arrays.stream(input)
                        .map(pair -> new Object[] {pair[1], pair[0]})
                        .toArray(Object[][]::new)
        };
    }
}