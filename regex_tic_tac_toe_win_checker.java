public class RegexTicTacToeWinChecker {
    public static boolean regexTicTacToeWinChecker(String bd) {
        return bd.substring(0,3).matches("OOO|XXX") ||
          bd.substring(3,6).matches("OOO|XXX") ||
          bd.substring(6,9).matches("OOO|XXX") || 
          ((bd.substring(0,3).matches("O[OX-][OX-]") &&
            bd.substring(3,6).matches("[OX-]O[OX-]") &&
            bd.substring(6,9).matches("[OX-][OX-]O")) || (
            bd.substring(0,3).matches("X[OX-][OX-]") &&
            bd.substring(3,6).matches("[OX-]X[OX-]") &&
            bd.substring(6,9).matches("[OX-][OX-]X")))
          ||((bd.substring(0,3).matches("[OX-]O[OX-]") &&
            bd.substring(3,6).matches("[OX-]O[OX-]") &&
            bd.substring(6,9).matches("[OX-]O[OX-]")) || (
            bd.substring(0,3).matches("[OX-]X[OX-]") &&
            bd.substring(3,6).matches("[OX-]X[OX-]") &&
            bd.substring(6,9).matches("[OX-]X[OX-]")))
          ||((bd.substring(0,3).matches("[OX-][OX-]O") &&
            bd.substring(3,6).matches("[OX-]O[OX-]") &&
            bd.substring(6,9).matches("O[OX-][OX-]")) || (
            bd.substring(0,3).matches("[OX-][OX-]X") &&
            bd.substring(3,6).matches("[OX-]X[OX-]") &&
            bd.substring(6,9).matches("X[OX-][OX-]")))
          ||((bd.substring(0,3).matches("[OX-][OX-]O") &&
            bd.substring(3,6).matches("[OX-][OX-]O") &&
            bd.substring(6,9).matches("[OX-][OX-]O")) || (
            bd.substring(0,3).matches("[OX-][OX-]X") &&
            bd.substring(3,6).matches("[OX-][OX-]X") &&
            bd.substring(6,9).matches("[OX-][OX-]X")))
          ||((bd.substring(0,3).matches("O[OX-][OX-]") &&
            bd.substring(3,6).matches("O[OX-][OX-]") &&
            bd.substring(6,9).matches("O[OX-][OX-]")) || (
            bd.substring(0,3).matches("X[OX-][OX-]") &&
            bd.substring(3,6).matches("X[OX-][OX-]") &&
            bd.substring(6,9).matches("X[OX-][OX-]")))
          ;
    }
}

////////////////
import java.util.regex.*;

public class RegexTicTacToeWinChecker {

    private static final Pattern WIN_PATTERN = Pattern.compile(
      "^(...){0,2}(XXX|OOO)|(X|O)((..\\3){2}|(...\\3){2})|..(X|O).\\7.\\7..");

    public static boolean regexTicTacToeWinChecker(String board) {
        return WIN_PATTERN.matcher(board).find();
    }
}

//////////
public class RegexTicTacToeWinChecker {

    public static boolean regexTicTacToeWinChecker(String board) {
      boolean X = board.matches("XXX.{6}|...XXX...|.{6}XXX|X..X..X..|.X..X..X.|..X..X..X|X...X...X|..X.X.X..");
      boolean O = board.matches("OOO.{6}|...OOO...|.{6}OOO|O..O..O..|.O..O..O.|..O..O..O|O...O...O|..O.O.O..");
      return X||O;
    }
    
}

///////////
class RegexTicTacToeWinChecker {
  static boolean regexTicTacToeWinChecker(String board) {
    return board.matches(".*(\\w)(..(\\1|.\\1.)..\\1.*|.\\1.\\1..|\\1\\1(...)*)");
  }
}

///////////
public class RegexTicTacToeWinChecker {
    public static boolean regexTicTacToeWinChecker(String board) {
        String reg1 = "(XXX.{6})|(...XXX...)|(.{6}XXX)";
        String reg2 = "(OOO.{6})|(...OOO...)|(.{6}OOO)";
        String reg3 = "(X..X..X..)|(.X..X..X.)|(..X..X..X)";
        String reg4 = "(O..O..O..)|(.O..O..O.)|(..O..O..O)";
        String reg5 = "(X...X...X)|(..X.X.X..)|(O...O...O)|(..O.O.O..)";
        return board.matches(reg1) || board.matches(reg2) || board.matches(reg3) || board.matches(reg4) || board.matches(reg5);
    }
}

////////////
public class RegexTicTacToeWinChecker {
  public static boolean regexTicTacToeWinChecker(String board) {
      return board.matches("((.{3}|.{6}|\\A)(XXX|OOO).*)|(.*([OX])..\\5..\\5.*)|(([XO])...\\7...\\7)|(..([XO]).\\9.\\9..)");
  }
}