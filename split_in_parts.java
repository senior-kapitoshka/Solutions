import java.util.*;
import java.util.stream.*;
public class InParts {
    public static String splitInParts(String s, int sz) {
        int i[]=new int[1];
        return Arrays.stream(s.split(""))
                      .map(c->{
                        if(i[0]%sz==0 && i[0]!=0){
                          i[0]++;
                          return " "+c;
                        }
                        i[0]++;
                        return c;})
                      .collect(Collectors.joining());
    }
}

/////////////
public class InParts {
    public static String splitInParts(String s, int partLength) {
        return s.replaceAll("(.{"+partLength+"})(?!$)", "$1 ");
    }
}