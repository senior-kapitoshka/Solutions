public class Generator{
  private int x=0;
  public int next(){
    return ++x;
  }
  public int next(int y){
    return y;
  }
}

////////////
public class Generator {

  private int n = 0;
  
  public int next() { return ++n; }
  public int next(final int n) { return this.n = n; }
}

///////////
class Generator {
  private int value;

  int next(Integer... reset) {
    return reset.length > 0 ? reset[0] : ++value;
  }
}