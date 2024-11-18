/*
import java.util.*;

class Codewarrior {
    public static List<Integer>[] arrayOfLists = new List<Integer>[] {
        Arrays.asList(1, 2, 3),
        Arrays.asList(4, 5, 6),
        Arrays.asList(7, 8, 9),
    };
}
*/

import java.util.*;

class Codewarrior {
    public static List<Integer>[] arrayOfLists = new List[] {
        Arrays.asList(1, 2, 3),//Arrays.asList() создает изменяемый список, поддерживаемый массивом
        Arrays.asList(4, 5, 6),
        Arrays.asList(7, 8, 9),
    };
}

///////////////

import java.util.List;

interface Codewarrior {
  List<Integer>[] arrayOfLists = new List[]{
      List.of(1, 2, 3),
      List.of(4, 5, 6),
      List.of(7, 8, 9)
  };
}

////////////
import java.util.List;

final class Codewarrior {
  static final List<?>[] arrayOfLists = new List[]{
      List.of(1, 2, 3), //List.of() создает неизменяемый список фиксированного размера
      List.of(4, 5, 6),
      List.of(7, 8, 9)
  };

  private Codewarrior() {}
}