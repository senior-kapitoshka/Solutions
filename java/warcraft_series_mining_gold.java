import java.util.*;
import java.util.ArrayList;
import java.util.List;
import java.util.Collections;
import java.util.stream.*;
import java.util.stream.Collectors;
import java.util.Arrays;

public class MiningRepresentation {
    public static class Unit{
      public int id;
      public char state;
      public Unit( int i,char c){
        id=i;state=c;
      }
    }
    public static List<String> generate(String str, int sz) {
      int n=str.length();
      
      List<Unit> us=new ArrayList<>();
      StringBuilder sb=new StringBuilder();
      for(int i=0;i<n;++i){
        if(str.charAt(i)=='>'){
          sb.append('.');
          us.add(new Unit(i,'>'));
        }else if(str.charAt(i)=='<'){
          us.add(new Unit(i,'<'));
           sb.append('.');
        }else{
           sb.append(str.charAt(i));
        }
      }
      String strr=sb.toString();
      List<String> res=new ArrayList<>(Collections.nCopies(sz,strr));
      if(us.isEmpty()) return res;
      else{
        res=res.stream()
          .map(
          s ->{
            char ch[]=new char[n];
            Map<Integer,Character> mp=new HashMap<Integer,Character>();
            for(Unit u:us){
              if(mp.containsKey(u.id)){
                mp.put(u.id,'#');
              }else{
                if(u.id==0 || u.id==str.length()-1){
                  mp.put(u.id,'*');
                }else{
                  mp.put(u.id,u.state);
                }
              }
              
              if(u.state=='>'){
                if(u.id!=str.length()-1) ++u.id;
                else{
                  --u.id;
                  u.state='<';
                }
              }else if(u.state=='<'){
                if(u.id!=0) --u.id;
                else{
                  ++u.id;
                  u.state='>';
                }
              }
              
            }
            for(Map.Entry<Integer,Character> e:mp.entrySet()){
              ch[e.getKey()]=e.getValue();
            }
            for(int i=0;i<s.length();++i){
              if(ch[i]=='\u0000') ch[i]=s.charAt(i);
            }
            s=new String(ch);
            System.out.println(s);
            return s;
          }
         ).collect(Collectors.toList());
      }
      return res;
    }
  
}

///////////////
import java.util.*;
public class MiningRepresentation {
    public static List<String> generate(String s, int t){ 
        int n = s.length(); 
        List<String> res = new ArrayList();  
        List<int []> rab = new ArrayList(); 
        int x [] = new int [n]; 
        char c [] = s.toCharArray();
        for (int i =1 ;i <n-1; i++)
            if(c[i]!='.'){ 
              rab.add(new int[]{i,c[i]=='>'?1:-1});  
              x[i]++;
              }
        for (int i = 0 ; i<t; i++){  
             res.add(new String(c)); 
             go(rab,c,x,n);
          } 
          return res;
      } 
     public static void go(List<int[]> rab, char [] c, int x [], int n  ){  
           for (int a [] : rab){   
               int d [] = a; 
               x[d[0]]--; 
               d[0]+=d[1]; 
               if(d[0]==0)d[1]=1; 
               else if(d[0]==n-1)d[1]=-1; 
               x[d[0]]++; 
               c[d[0]]=d[1]==1?'>':'<'; 
           } 
           for (int i=1; i<n-1;i++){  
                if(x[i]==0)c[i]='.'; 
                else if(x[i]>1)c[i]='#';
           } 
           c[0]=x[0]==0?'M':'*';
           c[n-1]=x[n-1]==0?'B':'*';

     }
}

///////////////////
import java.util.*;

public class MiningRepresentation {
    private static void placeWorker(int i, char worker, char[] state) {
      state[i] = state[i] == '>' || state[i] == '<' ? '#' : state[i] != '.' ? '*' : worker;
    }
  
    private static String nextState(String state) {
      int n = state.length();
      char[] next = new char[n];
      next[0] = 'M';
      next[n - 1] = 'B';
      Arrays.fill(next, 1, n - 1, '.');
      for (int i = 0; i < n; i++) {
        switch (state.charAt(i)) {
            case '*': {
              if (i == 0) placeWorker(1, '>', next);
              if (i == n - 1) placeWorker(n - 2, '<', next);
              break;
            }
            case '#': {
              placeWorker(i + 1, '>', next);
              placeWorker(i - 1, '<', next);
              break;
            }
            case '>': {
              placeWorker(i + 1, '>', next);
              break;
            }
            case '<': {
              placeWorker(i - 1, '<', next);
              break;
            }
        }
      }
      return new String(next);
    }
  
    public static List<String> generate(String path, int time) {
      var res = new ArrayList<String>(time);
      res.add(path);
      for (int i = 1; i < time; i++) {
        path = nextState(path);
        res.add(path);
      }
      return res;
    }

}