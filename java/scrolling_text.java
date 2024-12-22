public class Kata {
    public static String[] scrollingText(String t) {
        String res[]=new String[t.length()];
      for(int i=t.length()-1;i>=0;--i){
        
        t=t.substring(t.length()-1).toUpperCase()
          +t.substring(0,t.length()-1).toUpperCase();
        res[i]=t;
        System.out.println(t);
      }
      return res;
    }
}

///////////////
public class Kata {
    public static String[] scrollingText(String text) {
        return java.util.stream.IntStream.range(0, text.length())
          .mapToObj(i -> text.substring(i).toUpperCase() + text.substring(0, i).toUpperCase())
          .toArray(String[]::new);
    }
}