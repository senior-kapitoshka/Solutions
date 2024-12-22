public class Null extends Object{
  private Object n;
  public Null(){
    n=null;
  }
  @Override
  public int hashCode(){
    return 0;
  }
  @Override
  public String toString(){
    return "null";
  }
   @Override
    public boolean equals(Object obj) {
        return obj == null || obj instanceof Null;
    }
}