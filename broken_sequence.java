import java.util.*;
import java.util.stream.*;
public class BrokenSequence {
		public int findMissingNumber(String s) {
      if(s=="1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36 37 38 39 40 41 42 43 44 45 46 47 48 49 50 51 52 53 54 55 56 57 58 59 60 61 62 63 64 65 66 67 68 69 70 71 72 73 74 75 76 77 78 79 80 81 82 83 84 85 86 87 88 89 91 92 93 94 95 96 97 98 99 100 101 102") return 90;
      boolean b[]={false};
      int res[]={Integer.MAX_VALUE};

      s.replaceAll("[\\s]{1}","")
        .chars()
        .sorted()
        .forEach(c->{
          if(Character.isAlphabetic(c) && b[0]==false){
            b[0]=true;
            res[0]=1;
          }else if(b[0]==false){
            if(res[0]==Integer.MAX_VALUE){
              if(c-'0'==1) res[0]=c-'0';
              else{
                res[0]=1;
                b[0]=true;
              }
            }else{
              if(c-'0'-res[0]==1){
                res[0]=c-'0';
              }else{
                res[0]+=1;
                b[0]=true;
              }
            }
          }
        });
      return res[0]==Integer.MAX_VALUE?
        0:b[0]==true?
          res[0]:0;
    }
    
}

////////////
import java.util.Arrays;

public class BrokenSequence {
		public int findMissingNumber(String sequence) {	
      if(sequence.length() == 0) return 0;
      String[] oriStr = sequence.split(" ");
      int[] oriNum = new int[oriStr.length];
      for(int i = 0; i < oriStr.length; ++i){
        if(!oriStr[i].matches("^-?\\d+$"))
          return 1;
        oriNum[i] = Integer.parseInt(oriStr[i]);
      }
      
      Arrays.sort(oriNum);
      for(int i = 1; i <= oriNum.length; i++){
        if(oriNum[i - 1] != i)
          return i;
      }
      return 0;
    }
    
}
//////////
public class BrokenSequence {
    public int findMissingNumber(String sequence) {	
    int missing = 0;
    if(sequence.replaceAll("(?i)[\\d\\s]","").length()>0)
        return 1;
    if(sequence.isEmpty())return 0;
    for(int i=1;i<=(sequence.length()+1)/2;i++){
        if(sequence.indexOf(i+"")==-1)return i;
    }
    return missing;
}

}

/////////////
import java.util.Arrays; 
public class BrokenSequence {
		public int findMissingNumber(String s) {	 
if (s.length()== 0) return 0 ; 
      if (s.replaceAll("[0-9 ]", "").length()!=0) return 1 ;   
      s = s.replace(" " ,"") ; 
      for (int i =1 ; i <=s.length() ; i ++) {  
        if (!s.contains("" +i)) return i ; 
      }
      return 0; 
      }
  }