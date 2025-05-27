public class Kata {
    public static boolean isCyrillic(char l) {
        return (l+"").matches("[ЀЁЂЃЄЅІЇЈЉЊЋЌЍЎЏАБВГДЕЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯабвгдежзийклмнопрстуфхцчшщъыьэюяѐёђѓєѕіїјљњћќѝўџѠѡѢѣѤѥѦѧѨѩѪѫѬѭѮѯѰѱѲѳѴѵѶѷѸѹѺѻѼѽѾѿҀҁ҂◌҃◌҄◌҅◌҆◌҇◌҈◌҉ҊҋҌҍҎҏҐґҒғҔҕҖҗҘҙҚқҜҝҞҟҠҡҢңҤҥҦҧҨҩҪҫҬҭҮүҰұҲҳҴҵҶҷҸҹҺһҼҽҾҿӀӁӂӃӄӅӆӇӈӉӊӋӌӍӎӏӐӑӒӓӔӕӖӗӘәӚӛӜӝӞӟӠӡӢӣӤӥӦӧӨөӪӫӬӭӮӯӰӱӲӳӴӵӶӷӸӹӺӻӼӽӾӿ]") ; 
    }
}
////////

////////////
import static java.lang.Character.UnicodeBlock.*;

interface Kata {
  static boolean isCyrillic(char letter) {
    return of(letter).equals(CYRILLIC);
  }
}
///////////
interface Kata {
  static boolean isCyrillic(char letter) {
    return letter > 'Ͽ' && letter < 'Ԁ';
  }
}

//////////
public class Kata {
    public static boolean isCyrillic(char letter) {
        int id = letter - '0';
        return id >= 976 && id <= 1231;
    }
}