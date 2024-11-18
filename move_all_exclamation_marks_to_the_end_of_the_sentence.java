public class Kata {
   public static String remove(String s){
       StringBuilder sb=new  StringBuilder();
     int cnt=0;
     for(Character c:s.toCharArray()){
       switch(c){
           case '!'-> ++cnt;
           default -> sb.append(c);
       }
     }
     while(cnt--!=0) sb.append("!");
     return sb.toString();
   }
}

////////////////
interface Kata {
  static String remove(String s) {
    return s.replace("!", "") + s.replaceAll("[^!]", "");
  }
}

///////////
public class Kata {
   public static String remove(String s){
       return s.replaceAll("!", "") + s.replaceAll("[^!]", "");
   }
}