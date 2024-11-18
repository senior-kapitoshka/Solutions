
import java.util.HashMap;
import java.util.Map;

public class Dinglemouse {
    private static final Map<String, MyNumber> cache = new HashMap<>();

    static enum MyNumber {
        ONE(1, "one", "ichi", "un"),
        TWO(2, "two", "ni", "deux"),
        THREE(3, "three", "san", "trois"),
        FOUR(4, "four", "shi", "quatre")
        ;

        private final int val;

        private MyNumber(int val, String ...names) {
            this.val = val;
            for (final String n : names) cache.put(n, this);
        }

        public int intValue() {
            return this.val;
        }

    }

    static MyNumber dummy = MyNumber.ONE; // Reference the static enum so it initialises!

    static MyNumber getNumber(final String name) {

        return cache.get(name);
    }

}

/////////////////
import java.util.*;

public class Dinglemouse {

  private static final Map<String, MyNumber> cache = new HashMap<>();
  
  static enum MyNumber {
    ONE(1, "one", "ichi", "un"),
    TWO(2, "two", "ni", "deux"),
    THREE(3, "three", "san", "trois"),
    FOUR(4, "four", "shi", "quatre")
    ;
    
    private final int val;
    private final String[] names;
    
    private MyNumber(int val, String ...names) {
      this.val = val;
      this.names = names;
    }
    
    public int intValue() {
      return this.val;
    }
  }
   
  static {
    for (final MyNumber mn : MyNumber.values())
      for (final String n : mn.names)
        cache.put(n, mn);
  }
  
  static MyNumber getNumber(final String name) {
    return cache.get(name);
  }
  
}

///////////////////
import java.util.Map;
import java.util.stream.Stream;

import static java.util.Map.entry;
import static java.util.stream.Collectors.toMap;

public class Dinglemouse {

  static enum MyNumber {
    ONE(1),
    TWO(2),
    THREE(3),
    FOUR(4);
    
    private final int val;
    
    private MyNumber(final int val) {
      this.val = val;
    }
    
    public int intValue() {
      return this.val;
    }
  }
  
  private static final Map<String, MyNumber> cache = Stream.of(
      entries(MyNumber.ONE,   "one",   "ichi", "un"),
      entries(MyNumber.TWO,   "two",   "ni",   "deux"),
      entries(MyNumber.THREE, "three", "san",  "trois"),
      entries(MyNumber.FOUR,  "four",  "shi",  "quatre")
  ) .flatMap(entries -> entries)
    .collect(toMap(Map.Entry::getKey, Map.Entry::getValue));
  
  private static <K, V> Stream<Map.Entry<K, V>> entries(final V value, final K... keys) {
    return Stream.of(keys).map(key -> entry(key, value));
  }
  
  static MyNumber getNumber(final String name) {
    return cache.get(name);
  }
}

////////////////
import static java.util.List.of;

class Dinglemouse {
  enum MyNumber {
    ONE, TWO, THREE, FOUR;

    int intValue() {
      return ordinal() + 1;
    }
  }

  static MyNumber getNumber(String name) {
    return of(MyNumber.values()).get(("_oneichiun____twonideux____threesantroisfourshiquatre")
                                .indexOf(name) / 13);
  }
}

/////////////////
