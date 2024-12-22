public class Kata {
    public static long filterString(final String v) {
        return Long.parseLong(v.replaceAll("[a-z|A-Z]",""));
    }
}

///////////
public class Kata {
    public static long filterString(final String value) {
        return Long.valueOf(value.replaceAll("\\D", ""));
    }
}