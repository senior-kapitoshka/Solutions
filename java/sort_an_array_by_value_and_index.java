public class Kata
{
  public static class Pair{
    public Pair(int v,int p){
      val=v;
      prod=p;
    }
    int val,prod;
  }
  public static int[] sortByValueAndIndex(int[] ar){
    Pair ap[]=new Pair[ar.length];
    for(int i=0;i<ar.length;++i){
      ap[i]=new Pair(ar[i],ar[i]*(i+1));
    }
    java.util.Arrays.sort(ap, new java.util.Comparator<Pair>(){
      @Override
      public int compare(final Pair lhs,final Pair rhs){
        return lhs.prod -rhs.prod;
      }
    });
    for(int i=0;i<ar.length;++i){
      ar[i]=ap[i].val;
    }
    return ar;
  }
}

///////////
import java.util.Comparator;
import java.util.stream.IntStream;

public class Kata{
	public static int[] sortByValueAndIndex(int[] array){
		return IntStream.range(0, array.length)
                        .boxed()
                        .sorted(Comparator.comparingInt(i->array[i]*(i+1)))
                        .mapToInt(i->array[i])
                        .toArray();
	}
}

////////////////
import java.util.Arrays;
public class Kata
{
  public static int[] sortByValueAndIndex(int[] array)
  {
    int[] arr = new int[array.length]; 
    for (int i=0; i<array.length; i++){
      arr[i]=array[i]*(i+1);
    }
    for (int i=0; i<array.length; i++){
      for (int j=i+1; j<array.length; j++){
        if (arr[j]<arr[i] ){
          int t=arr[i]; int t1=array[i];
          arr[i]=arr[j]; array[i]=array[j];
          arr[j]=t;  array[j]=t1;
        }
      }
    }
    return array;
  }
}

////////////
import java.util.Comparator;
import java.util.stream.IntStream;

public class Kata {
  public static int[] sortByValueAndIndex(int[] array) {
            return IntStream.range(0, array.length)
                .boxed().sorted(Comparator.comparingInt(o -> array[o] * (o + 1)))
                .mapToInt(i -> array[i]).toArray();
  }
}

//////////////
import java.util.Map.Entry;
import java.util.stream.Collectors;
import java.util.stream.IntStream;

public class Kata{
    public static int[] sortByValueAndIndex(int[] array) {
        return IntStream.range(0, array.length).boxed().collect(Collectors.toMap(i -> i, i -> (i + 1) * array[i], (a, b) -> b))
                .entrySet().stream()
                .sorted(Entry.comparingByValue())
                .map(e1 -> array[e1.getKey()]).collect(Collectors.toList()).stream().mapToInt(Integer::intValue).toArray();
    }
}

///////////////
import java.util.Comparator;
import java.util.stream.IntStream;

public class Kata
{
  public static int[] sortByValueAndIndex(int[] array)
  {
    return IntStream.rangeClosed(1, array.length)
                .boxed()
                .sorted(Comparator.comparingInt(x -> x * array[x - 1]))
                .mapToInt(x -> array[x - 1])
                .toArray();
  }
}