import java.util.*;
import java.util.stream.*;
import java.util.TreeMap;

public class Dictionary {
  
  private static final String[] words;

  public  Dictionary(String[] words) {
    this.words = words;
  }
  private static TreeMap<Integer,String> getMap(){
    TreeMap<Integer,String>mp=new TreeMap<>();
    for(String w:words){
      Integer hash=w.chars().reduce(0,(acc,c)->acc+=(int)c);
      mp.put(hash,w);
    }
    for(Map.Entry<Integer,String>e:mp.entrySet()){
      System.out.println(e.getKey()+" "+e.getValue());
    }
    return mp;
  }
  
  public String findMostSimilar(String to) {
    for(String s:words){
      System.out.println(s+",");
    }
    TreeMap<Integer,String>mp=getMap();
    Integer hash=to.chars().reduce(0,(acc,c)->acc+=(int)c);
    System.out.println(to+" "+hash);
    return mp.containsKey(hash)?mp.get(hash):mp.get(mp.higherKey(hash));
  }
}