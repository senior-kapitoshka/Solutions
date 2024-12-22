import java.util.*;
import java.util.stream.*;
class CodeWars {
  private static String alph="A B C D E F G H I J K L M N O P Q R S T U V W X Y Z";
  private static String nums="1 2 3 4 5 6 7 8   1 2 3 4 5   7   9 2 3 4 5 6 7 8 9";
  private static int weight[]={8,7,6,5,4,3,2,10,0,9,8,7,6,5,4,3,2};
  private static int idx[]={0};
  public static Map<Character,Integer> prepareMap(){
    Map<Character,Integer> mp=new HashMap<>();
    for(int i=0;i<alph.length();++i){
      if(Character.isAlphabetic(alph.charAt(i)) && Character.isDigit(nums.charAt(i))){
        mp.put(alph.charAt(i),Character.getNumericValue(nums.charAt(i)));
      }
    }
    return mp;
  }
  public static boolean checkVin(String vin) {
    idx[0]=0;
    if(vin.length()!=17) return false;
    Map<Character,Integer>mp=prepareMap();
    if(!vin.matches("[ABCDEFGHJKLMNPRSTUVWXYZ1234567890]*")) return false;
    int vin_int = vin.chars()
      .mapToObj(i->(char)i)
      .map(i-> Character.isAlphabetic(i)?
                mp.get(i):Character.getNumericValue(i))
      .map(i -> i*weight[idx[0]++])
      .collect(Collectors.summingInt(Integer::intValue));
    return (vin_int%11==10 && vin.charAt(8)=='X') ||  (vin_int%11==Character.getNumericValue(vin.charAt(8)));
  }
}

////////////////
class CodeWars {
  
  static final int decode[] = {1,2,3,4,5,6,7,8,0,1,2,3,4,5,0,7,0,9,2,3,4,5,6,7,8,9};
  static final int weight[] = {8,7,6,5,4,3,2,10,0,9,8,7,6,5,4,3,2};
  
  public static boolean checkVin(String vin) {
    if (!vin.matches("[0-9A-HJ-NPR-Z]{17}")) return false;    
    int sum = 0, i = 0;
    for (char c : vin.toCharArray()) sum += (c <= '9' ? c - '0' : decode[c - 'A']) * weight[i++];    
    int mod = sum % 11, chk = vin.charAt(8);
    return mod == 10 ? chk == 'X' : chk - '0' == mod;
  }
        
}

//////////////
import static java.util.stream.IntStream.range;

interface CodeWars {
  int[] d = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 0, 0, 0, 0, 0, 0, 1, 2, 3, 4, 5, 6, 7, 8, 0, 1, 2, 3, 4, 5, 0, 7, 0, 9, 2, 3, 4, 5, 6, 7, 8, 9};
  int[] w = {8, 7, 6, 5, 4, 3, 2, 10, 0, 9, 8, 7, 6, 5, 4, 3, 2};

  static boolean checkVin(String vin) {
    return vin.matches("[0-9A-HJ-NPR-Z]{17}") && 
        (vin.charAt(8) == 'X' ? 10 : vin.charAt(8) - 48) == range(0, 17).map(i -> d[vin.charAt(i) - 48] * w[i]).sum() % 11;
  }
}

/////////////
class CodeWars {
  public static boolean checkVin(String v) {
        if(v.length()!=17)return false;  int mod=0;
        int x []={8,7,6,5,4,3,2,10,0,9,8,7,6,5,4,3,2}; 
        char D[]="12345678 12345 7 923456789".toCharArray();  
        try{   
            for (int i=0;i<17;i++){  
               char c=v.charAt(i); 
               int R=(Character.isLetter(c)?D[c-'A']:c)-'0';
               mod=(mod+R*x[i])%11; 
             }
         }
       catch (Exception e ){return false;} 
        char c = v.charAt(8);
        if(mod==10)return c=='X';
        return mod==c-'0';

    }
}

/////////////
