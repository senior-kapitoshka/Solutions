import java.util.Arrays;

class SectionalArray {
    static int[] sort(final int[] ar, final int st, final int... l) {
        if (l.length == 0){
            Arrays.sort(ar, st, ar.length);
        } else {
            Arrays.sort(ar, st, ar.length - 1);
        }
        return ar;
    }
}

///////////////////
import java.util.Arrays;
class SectionalArray {
    static int[] sort(final int[] array, final int start, final int... length) {
        Arrays.sort(array, start, length.length == 0 || length[0] == 0
                ? array.length
                : Math.min(array.length, start + length[0]));
        return array;
    }
}

//////////////
import java.util.*;
import java.util.stream.Collectors;
import java.util.stream.IntStream;


class SectionalArray {
    static int[] sort(final int[] array, final int start, final int... length) {

        return IntStream.concat(
            IntStream.concat(IntStream.of(array).limit(start),
                IntStream.of(array)
                        .skip(start)
                        .limit(length.length == 0 ? array.length : length[0])
                        .sorted()),
            IntStream.of(array).skip(start).skip(length.length == 0 ? array.length : length[0])
        ).toArray();


    }
}



