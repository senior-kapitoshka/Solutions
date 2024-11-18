import java.util.Comparator;

public class CatWeightComparator implements Comparator<Cat>
{
  @Override
  public int compare(Cat c1, Cat c2)
  {
    return Double.compare(c1.weight,c2.weight);
  }
}

/////////////
import java.util.Comparator;

public class CatWeightComparator implements Comparator<Cat>
{
  @Override
  public int compare(Cat cat1, Cat cat2)
  {
    return Double.valueOf(cat1.weight).compareTo(Double.valueOf(cat2.weight));
  }
}

/////////////////
import java.util.Comparator;

public class CatWeightComparator implements Comparator<Cat>
{
  @Override
  public int compare(Cat cat1, Cat cat2)
  {
    return (int) Math.signum(cat1.weight - cat2.weight);
  }
}

///////////////
