import java.util.Collection;
import java.util.List;
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Kata {
  public static List<Character> diff(Collection<Character> a, Collection<Character> b) {
    return Stream
            .concat(
      a.stream()
      .filter(el->!b.contains(el))
      ,
      b.stream()
      .filter(el->!a.contains(el))
      )
            .distinct()
            .sorted()
            .collect(Collectors.toList());
    
  }
}

/////////////////
import java.util.Arrays;
import java.util.Collection;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Kata {
  public static List<Character> diff(Collection<Character> a, Collection<Character> b) {
    return Stream.of(a, b)
                .flatMap(Collection::stream)
                .distinct()
                .filter(c -> !a.contains(c) || !b.contains(c))
                .sorted()
                .collect(Collectors.toList());
  }
}

////////////////
import java.util.Collection;
import java.util.Set;
import java.util.HashSet;
import java.util.List;
import java.util.ArrayList;

class Kata {
    static List<Character> diff(final Collection<Character> aa, final Collection<Character> bb) {
        Set<Character> a = new HashSet<>(aa);
        Set<Character> b = new HashSet<>(bb);
        
        Set<Character> intersection = new HashSet<>(a);
        intersection.retainAll(b);
        
        Set<Character> union = new HashSet<>(a);
        union.addAll(b);

        // union minus intersection equals symmetric-difference
        Set<Character> symmetricDifference = new HashSet<>(union);
        symmetricDifference.removeAll(intersection);
        
        List<Character> result = new ArrayList<>(symmetricDifference);
        result.sort(Character::compareTo);
        
        return result;
    }
}

///////////////
import java.util.*;

public class Kata {
  public static List<Character> diff(Collection<Character> a, Collection<Character> b) {
    Set s1 = new TreeSet(a), s2 = new HashSet(b);
    s1.removeAll(s2);
    s2.removeAll(new HashSet(a));
    s1.addAll(s2);
    return new ArrayList(s1);
  }
}

///////////
import static java.util.stream.Collectors.toList;
import static java.util.stream.Stream.concat;

import java.util.Collection;
import java.util.List;

class Kata {
  static List<Character> diff(Collection<Character> a, Collection<Character> b) {
    return concat(a.stream(), b.stream())
                .distinct()
                .filter(c -> !a.contains(c) || !b.contains(c))
                .sorted()
                .collect(toList());
  }
}

/////////////
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.Stream;

public class Kata {
  public static List<Character> diff(Collection<Character> a, Collection<Character> b) {
    return Stream.concat(a.stream(), b.stream())
      .distinct()
      .filter(x -> !(a.contains(x) && b.contains(x)))
      .sorted()
      .collect(Collectors.toList());
  }
}