class Solution {
  
  public static String isSortedAndHow(int[] arr) {
    int cnt=0;
      for(int i=1;i<arr.length;++i){
        if(arr[i-1]<=arr[i]) ++cnt;
        else if(arr[i-1]>arr[i]) --cnt;
      }
    return cnt==arr.length-1?"yes, ascending":
    Math.abs(cnt)==arr.length-1?"yes, descending":
    "no";
  }
  
}

///////////
import java.util.stream.IntStream;

class Solution {

    public static String isSortedAndHow(int[] array) {
        if(IntStream.range(0, array.length-1).allMatch(i -> array[i] <= array[i+1]))
            return "yes, ascending";

        if(IntStream.range(0, array.length-1).allMatch(i -> array[i] >= array[i+1]))
            return "yes, descending";

        return "no";
    }

}

/////////////
class Solution {
  
  public static String isSortedAndHow(int[] array) {
    boolean desc = false;
		boolean asc = false;
		for(int i = 1; i < array.length; i++) {
			if(array[i] > array[i-1]) asc = true;
			if(array[i] < array[i-1]) desc = true;
		}
		if(asc && !desc) return "yes, ascending";
		if(desc && !asc) return "yes, descending";
		return "no";
  }
  
}

////////////
