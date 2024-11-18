import java.util.List;
import java.util.stream.*;
import java.util.stream.Collectors;
class FindList {
    public static List<String> findChildren(List<String> sl, List<String> ch) {
        return ch.stream()
                  .filter(i-> sl.contains(i))
                  .distinct()
                  .sorted()
                  .collect(Collectors.toList());
    }
}

///////////////
import java.util.List;
import java.util.stream.Collectors;

class findList {
    public static List<String> findChildren(List<String> santasList, List<String> children) {
        return children.stream()
                    .distinct()
                    .filter(santasList::contains)
                    .sorted()
                    .collect(Collectors.toList());
    }
}