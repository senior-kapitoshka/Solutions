import java.net.URL;
import java.util.*;
public class UrlMap {
 /* private Map<URL,Long>mp=new TreeMap<>(new Comparator<URL>(){
    @Override
    public int compare(URL lhs,URL rhs){
      return lhs.toString().compareTo(rhs.toString());
    }
  });*/
  private Map<String,Long>mp=new HashMap<>();
  public void setTimestamp(URL url, long t) {
    mp.put(url.toString(),t);
  }

  public long getTimestamp(URL url) {
    //mp.getOrDefault(url.toString(), -1L);
    return mp.containsKey(url.toString())?mp.get(url.toString()):-1;
  }
}

////////////////
import java.net.URL;
import java.util.*;

public class UrlMap extends HashMap<String,Long> {
  public void setTimestamp(URL url, long ts) { put(""+url, ts); }
  public long getTimestamp(URL url) { return getOrDefault(""+url, -1L); }
}