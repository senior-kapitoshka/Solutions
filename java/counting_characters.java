import java.util.Arrays;

interface Count {
	static int countCharOccurrences(String s, char c) {
    return (int) s.chars().filter(ch -> ch == c).count();
  }
}

/////////////////
interface Count {
 static int countCharOccurrences(String s, char c) {
        return s.length() - s.replaceAll(String.valueOf(c), "").length();
    }
}

///////////////
import org.apache.commons.lang3.StringUtils;

interface Count {
	static int countCharOccurrences(String s, char c) {
    return StringUtils.countMatches(s, c);
  }
}

//////////////////
import java.util.*;
interface Count {
	public static int countCharOccurrences(String s, char c) {
   return Collections.frequency(Arrays.asList (s.split("")), "" +c);
  }
}
