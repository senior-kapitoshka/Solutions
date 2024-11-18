import java.util.List;
import java.util.function.Function;
import java.util.stream.*;
import java.util.*;

public class Binder<T, I> {
  public List<I> bind(List<T> l, Function<T, List<I>> f) {
    return l.stream()
      .map(i->/*before a i try cast to (I)- error*/f.apply(i))// for each element
      .flatMap(i->i.stream()) //flat prev res
      .collect(Collectors.toList());
  }
}


//////////////
import java.util.List;
import java.util.function.Function;
import java.util.stream.*;

public class Binder<T, I> {
  public List<I> bind(List<T> list, Function<T, List<I>> func) {
    return list.stream()
        .flatMap(value -> func.apply(value).stream())
        .collect(Collectors.toList());
  }
}

/////////////
import java.util.List;
import java.util.function.Function;
import java.util.stream.*;
import java.util.*;

public class Binder<T, I> {
  public List<I> bind(List<T> list, Function<T, List<I>> func) {

    return list.stream()
             .map(func)
             .collect(ArrayList::new, ArrayList::addAll, ArrayList::addAll);
  }
}

///////////
import java.util.ArrayList;
import java.util.List;
import java.util.function.Function;

public class Binder<T, I> {
  public List<I> bind(List<T> list, Function<T, List<I>> func) {
    ArrayList<I> result = new ArrayList<I>();
    for(T elem: list) {
      result.addAll(func.apply(elem));
    }
    return result;
  }
}

/////////////////
import java.util.List;
import java.util.function.Function;
import static java.util.stream.Collectors.toList;

class Binder<T, I> {
    List<I> bind(final List<T> list, final Function<T, List<I>> func) {
        return list.stream()
            .map(func::apply)
            .flatMap(List::stream)
            .collect(toList());
    }
}
