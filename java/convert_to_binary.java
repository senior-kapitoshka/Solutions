public class Kata {

  public static int toBinary(int n) {
    return Integer.valueOf(Integer.toBinaryString(n));
  }
}

//////////////////
public class Kata {

  public static int toBinary(int n) {
    return n>1 ? toBinary(n/2) * 10 + n%2 : n;
  }
}