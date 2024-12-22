import java.util.*;

class ShapeUtilities {
    public static double sumAllAreas(List<? extends Shape> shapes) {
        double totalArea = 0.0;
        for (Shape shape : shapes)
            totalArea += shape.getArea();
        return totalArea;
    }
}

///////////////////
import java.util.Collection;

interface ShapeUtilities {
  static double sumAllAreas(Collection<? extends Shape> shapes) {
    return shapes.stream()
                .mapToDouble(Shape::getArea)
                .sum();
  }
}
/////////////
