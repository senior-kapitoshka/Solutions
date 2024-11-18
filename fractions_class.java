public class Fraction implements Comparable<Fraction>
{
    private final long top;
    private final long bottom;

    public Fraction(long numerator, long denominator) {
        top = numerator;
        bottom = denominator;
    }

    @Override
    public int hashCode() { return 17 * Long.hashCode(top) + Long.hashCode(bottom); }    
    @Override
    public boolean equals(Object o) { return compareTo((Fraction)o) == 0; }    
    @Override
    public int compareTo(Fraction f2){ return Long.compare(top * f2.bottom, f2.top * bottom); }
    
    // Your work here!

    //Add two fractions
    public Fraction add(Fraction f2) {  
      long d=lcm(bottom,f2.bottom);
      long t=top*(d/bottom) + f2.top*(d/f2.bottom);
      long g=gcd(d,t); 
      if(t%g==0 )t/=g;
      if(d%g==0 )d/=g;
      return new Fraction(t,d);
    }
    
    //...and make this class string representable
    @Override
    public String toString(){
      return top + "/" + bottom;
    }
    
    private long gcd(long lhs,long rhs){
      if(lhs==rhs) return lhs;
      if(lhs>rhs) return gcd(lhs-rhs,rhs);
      return gcd(lhs,rhs-lhs);
    }
    private long lcm(long lhs,long rhs){
      return java.lang.Math.abs(lhs*rhs)/gcd(lhs,rhs);
    }
}

//////////////////
public class Fraction implements Comparable<Fraction>
{
    private final long top;
    private final long bottom;

    public Fraction(long numerator, long denominator) {
        top = numerator;
        bottom = denominator;
    }

    @Override
    public int hashCode() { return 17 * Long.hashCode(top) + Long.hashCode(bottom); }    
    @Override
    public boolean equals(Object o) { return compareTo((Fraction)o) == 0; }    
    @Override
    public int compareTo(Fraction f2){ return Long.compare(top * f2.bottom, f2.top * bottom); }
    
    // Your work here!

    public long getTop() {
        return this.top;
    }
    
    public long getBottom() {
        return this.bottom;
    }

    private long gcd(long a, long b) {
        return b == 0 ? a : gcd(b, a % b);
    }

    // Add two fractions
    public Fraction add(Fraction f2) {    
        long newTop = getTop() * f2.getBottom() + getBottom() * f2.getTop();
        long newBottom = getBottom() * f2.getBottom();
        
        long fractionGcd = gcd(newTop, newBottom);
        return new Fraction(newTop / fractionGcd, newBottom / fractionGcd);
    }
    
    // ...and make this class string representable
    public String toString() {
        return getTop() + "/" + getBottom();
    }
}

/////////////////
import static java.math.BigInteger.valueOf;

class Fraction {
  final long top;
  final long bottom;

  Fraction(long numerator, long denominator) {
    long gcd = valueOf(numerator).gcd(valueOf(denominator)).longValue();
    top = numerator / gcd;
    bottom = denominator / gcd;
  }

  Fraction add(Fraction f2) {
    return new Fraction(top * f2.bottom + f2.top * bottom, bottom * f2.bottom);
  }

  @Override
  public String toString() {
    return top + "/" + bottom;
  }

  @Override
  public boolean equals(Object o) {
    return top * ((Fraction) o).bottom == ((Fraction) o).top * bottom;
  }
}

//////////////
