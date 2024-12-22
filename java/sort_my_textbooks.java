import java.util.*;
import java.util.Collections;

class sorter {
  public static List<String> sort(List<String> textbooks) {
     Collections.sort(textbooks, String.CASE_INSENSITIVE_ORDER); 
     return textbooks;
     
  }
}

////////////////
import static java.util.stream.Collectors.toList;

import java.util.List;

public class sorter {
  public static List<String> sort(List<String> textbooks) {
    return textbooks.stream()
                    .sorted(String.CASE_INSENSITIVE_ORDER)
                    .collect(toList());
  }
}

//////////////////
import java.util.List;

class sorter {
    static List<String> sort(final List<String> textbooks) {
        textbooks.sort(String::compareToIgnoreCase);
        return textbooks;
    }
}