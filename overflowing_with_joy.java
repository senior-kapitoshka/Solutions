
public class Multiplier {
  public static int multiply(int x, int y) {
    return Math.multiplyExact(x, y);
  }
}

//////////////
public class Multiplier {
    public static int multiply(int a, int b) {
      int result = a * b;
      if (result != (long) a * b) throw new ArithmeticException();
      return result;
    }
  }
  ///////////
  public class Multiplier {
    public static int multiply(int a, int b) {
      int result;
      
      try {
          result = Math.multiplyExact(a, b);
      } catch (ArithmeticException e) {
          throw e;
      }
          
      return result;
    }
  }