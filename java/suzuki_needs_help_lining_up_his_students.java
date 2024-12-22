import java.util.Comparator;
import java.util.Arrays;

public class Kata
{  
  public static String[] lineupStudents(String s)
    {     
      String[] res = s.split(" "); 
      Arrays.sort(res,new Comparator<String>(){
                    @Override
                    public int compare(final String lhs, final String rhs) {
                    return rhs.length()-lhs.length()==0 ?
                                            rhs.compareTo(lhs) :
                                            rhs.length()-lhs.length();
                    }
      });
    return res;
    }
}

/////////////////
import java.util.*;

public class Kata
{
  public static String[] lineupStudents(String students)
  {     
    return Arrays.stream(students.split(" "))
                 .sorted((x, y) -> x.length() == y.length() ?
                                             y.compareTo(x) :
                                             y.length() - x.length()
                        )
                 .toArray(String[]::new);
  }
}

///////////////////
import java.util.* ;
public class Kata
{
  public static String[] lineupStudents(String students){
    List <String> s = Arrays.asList(students.split(" "));
        Collections.sort(s,
                (s1, s2) -> {
                    int res = s1.length() - s2.length();
                    if (res == 0) return s2.compareTo(s1);
                    return res > 0 ? -1 : 1;
                }
        ); 
  return s.toArray(new String[s.size()]);
  }
}

////////////////////
import static java.util.Comparator.comparingInt;
import static java.util.function.Function.identity;
import java.util.stream.Stream;

public class Kata {
  public static String[] lineupStudents(final String students) {
    return Stream.of(students.split(" "))
      .sorted(comparingInt(String::length).thenComparing(identity()).reversed())
      .toArray(String[]::new);
  }
}
///////////////////
import java.util.Arrays;
import java.util.Comparator;

public class Kata
{
  public static String[] lineupStudents(String students)
    {     
        String[] res = students.split(" ");
        Comparator<String> comparator = new Comparator<String>() {
            @Override
            public int compare(String o1, String o2) {
                return o1.length() == o2.length() ? o2.compareTo(o1) : o2.length() - o1.length();
            }
        };
        Arrays.sort(res, comparator);
        return res;
    }
}

//////////////////
import java.util.*;

public class Kata
{
  public static String[] lineupStudents(String students)
    {     
      String[] res = students.split(" ");
      Arrays.sort(res, Collections.reverseOrder());
      Arrays.sort(res, Comparator.comparingInt(s -> -1 * s.length()));
      return res;
    }
}

////////////////


