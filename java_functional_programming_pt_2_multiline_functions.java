import java.util.function.ToDoubleFunction;

public class FunctionalProgramming {
  public static ToDoubleFunction<Triangle> f = t -> {
                t.setArea(t.base * t.height * 0.5);
                return t.getArea();
            };
}

//////////////