import java.util.Arrays;

interface SortArray {
  static <T> T sortArray(T array) {
    if (array instanceof int[] ints) {
      Arrays.sort(ints);
    } else if (array instanceof long[] longs) {
      Arrays.sort(longs);
    } else if (array instanceof float[] floats) {
      Arrays.sort(floats);
    } else if (array instanceof double[] doubles) {
      Arrays.sort(doubles);
    } else if (array instanceof Object[] objects){
      Arrays.sort(objects);
    }
    return array;
  }
}

////////////////
public class SortArray{
  public static <T> T sortArray(T names){
    try{
      var type = names.getClass().getComponentType();
      type = type.isPrimitive() ? type : Object.class;
      var m = java.util.Arrays.class.getMethod("sort", type.arrayType());
      m.invoke(null, names);
    } catch (Exception e) {}
    return names;
  }
}

/////////////
import java.util.Arrays; // For using Arrays.sort() method

public class SortArray
{  
  // Now, the input data can be of any type (Hence its assigned a generic type i.e T) and because of the input data, the resultant array would be of that type
  // So the method output would thus be the array output and the array depends on the type of input data, thus its generic and hence we set it to 'T'
  // The <T> in front of the method signature indicates that T is a type parameter specifically of this method, not of the class that owns it.
  public static <T> T sortArray(T names)
  {
    // If the input data is of integer type i.e if its an instance of 'int[]', then the 'int[]' array would be sorted
    if (names instanceof int[]) 
    {
      Arrays.sort((int[]) names);
    } 
    // If the input data is of long type i.e if its an instance of 'long[]', then the 'long[]' array would be sorted
    else if (names instanceof long[]) 
    {
      Arrays.sort((long[]) names);
    } 
    // If the input data is of float type i.e if its an instance of 'float[]', then the 'float[]' array would be sorted
    else if (names instanceof float[]) 
    {
      Arrays.sort((float[]) names);
    } 
    // If the input data is of double type i.e if its an instance of 'double[]', then the 'double[]' array would be sorted
    else if (names instanceof double[]) 
    {
      Arrays.sort((double[]) names);
    } 
    // If the input data is of Object type i.e if its an instance of 'Object[]', then the 'Object[]' array would be sorted
    else 
    {
      Arrays.sort((Object[]) names);
    }
    
    // At the end, whichever the type of input data was, its corresponding array is sorted and is returned
    return names;
  }
}

