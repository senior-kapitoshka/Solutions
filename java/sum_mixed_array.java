import java.util.List;
import java.util.stream.*;

public class MixedSum {
	public int sum(List<?> mxd) {	
		return mxd.stream()
      .mapToInt(i -> Integer.parseInt(i.toString()))
      .sum();
	}
}

////////////////////
import java.util.List;

public class MixedSum {
	public int sum(List<?> mixed) {	
      int sum = 0;
      for (Object element : mixed){
        if (element instanceof Integer){  //instanceof!!!
          sum += (Integer) element;
        }
        else if (element instanceof String){
            sum += Integer.parseInt( (String) element );
        }
      }
      return sum;
	}
}

/////////////////
import java.util.List;

public class MixedSum {
	public int sum(List<?> mixed) {	
  
	  return mixed.stream()
                .map(Object::toString)
                .map(Integer::valueOf)
                .reduce(0, (a, b) -> a + b);
	}
}
///////////////////////////
import java.util.List;

public class MixedSum {

	public int sum(List<?> mixed) {	
		if (mixed == null || mixed.isEmpty()) {
      return 0;
    }
    return mixed.stream()
        .map(
            o -> o instanceof String ?
            Integer.valueOf((String) o) :
            (Integer) o
        )
        .mapToInt(i -> i)
        .sum();
  }
}

//////////////////
