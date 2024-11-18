//неправильное решение

/*import java.util.*;
import java.util.stream.*;
public class Dinglemouse {
  protected static int cnt=1;
  public static void plusCnt(){
    ++cnt;
    if(cnt==5) cnt=0;
  }
  public static int getCnt(){
    return cnt;
  }
   public static class Obj{
    protected char state;
    protected int id;
    public Obj(char st,int i){
      state=st;id=i;
    }
    public char getState(){
      return state;
    }
    public int getId(){
      return id;
    }
     public void incr(){}
     public void change(){} 
  };
  
  public static class Car extends Obj{
    public Car(char st,int i){
      super(st,i);
    }
    @Override
    public void incr(){
      ++id;
    }
  };
  public static class Post extends Obj{
    private boolean light;
    public Post(char st,int i){
      super(st,i);
    }
    @Override
    public void change(){
      if(cnt==1 && state=='O'){
          //cnt=1;
          state ='R';
      }else if(cnt==0){
        if(state=='G')state='O';
        else state='G';
      }
    }
  };

  public static String[] trafficLights(String rd, int n) {
    int sz=rd.length();
    List<Obj>lo=new ArrayList<Obj>();
    for(int i=0;i<rd.length();++i){
      if(Character.isAlphabetic(rd.charAt(i))){
        switch(rd.charAt(i)){
            case 'C': lo.add(new Car('C',i+1));
            break;
            case 'R': lo.add(new Post('R',i));
            break;
            case 'G': lo.add(new Post('G',i));
            break;
        }
      }
    }
    String res[]=new String[n+1];
    Arrays.fill(res,new String("-"));
    res[0]=rd;
   String path[] = Arrays.stream(res,1,n+1)
                    .map(s->{
                      char ch[]=new char[sz];
                      for(int i=0;i<sz;++i){
                        ch[i]='.';
                      }
                      Map<Integer,Character> mp=new HashMap<Integer,Character>();
                      plusCnt();
                      for(Obj o:lo){
                         if(o instanceof Post){
                          if(!mp.containsKey(o.getId())){
                            mp.put(o.getId(),o.getState()); 
                          }
                          o.change();
                        }
                      }
                      for(Obj o:lo){
                        if(o instanceof Car){
                          mp.put(o.getId(),o.getState());
                          if(!mp.containsKey(o.getId()+1) 
                             || (mp.containsKey(o.getId()+1) && mp.get(o.getId()+1)=='G')
                             || (mp.containsKey(o.getId()+1) && mp.get(o.getId()+1)=='R' && getCnt()==5)) o.incr();
                        }
                      }
                      for(Map.Entry<Integer,Character> e:mp.entrySet()){
                        ch[e.getKey()]=e.getValue();
                      }

                      s=new String(ch);
                      return s;
                    })
                    .toArray(String[]::new);
    for(int i=1,j=0;i<n+1;++i,++j){
      res[i]=path[j];
    }
    return res;
  }
  
}*/