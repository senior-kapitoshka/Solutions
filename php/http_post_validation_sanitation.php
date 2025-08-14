//fail tests

$_POST["name"]    = 'Jane Anderson';
$_POST["email"]   = 'ja1234@example.tld';
$_POST["message"] = 'Hello World!';
$_POST["age"] = '25';
$_POST["rating"] = '9';
function user_script() {
 
  if ($_SERVER['REQUEST_METHOD'] !== 'POST') { return; }
  if (empty($_POST['name'])) { echo '<span style="color: red">Name field is required</span>'; return; }
  if (empty($_POST['age']) || filter_var($_POST['age'], FILTER_VALIDATE_INT) == false) { echo '<span style="color: red">Invalid Age provided</span>'; return; }
  if (empty($_POST['email']) || filter_var($_POST['email'], FILTER_VALIDATE_EMAIL) == false) { echo '<span style="color: red">Email Address is Invalid</span>'; return; }
  if (empty($_POST['rating']) || filter_var($_POST['rating'], FILTER_VALIDATE_INT, ['options' => [ 'min_range' => 1, 'max_range' => 10, ]]) == false) { echo '<span style="color: red">Rating is invalid, please provide a number from 1 to 10</span>'; return; }
  foreach ($_POST as $key => $value) {
      $value = trim($value);
      $value = stripslashes($value);
      $value = htmlspecialchars($value);

      $_POST[$key] = $value;


      /*
      When all inputs are valid, the correct global variables should be set!
      */
       //тест ожидает именно, что будут созданы глобальные переменные:
       /*
            $name = ...;
            $email = ...;
            $age = ...;
            $rating = ...;
            или эквивалент:

            $GLOBALS['name'] = ...;
            $GLOBALS['email'] = ...;
       */
  }
}

////////////////


$_POST['name'] = 'Jane Anderson';
$_POST['email'] = 'ja1234@example.tld';
$_POST['message'] = 'Hello World!';

function user_script() {
  if ($_SERVER["REQUEST_METHOD"] === "POST") {
    if (empty($_POST["name"])) {
      echo "<span style=\"color: red\">Name field is required</span>";
    } elseif (!filter_var($_POST["email"], FILTER_VALIDATE_EMAIL)) {
      echo "<span style=\"color: red\">Email Address is Invalid</span>";
    } elseif(!ctype_digit($_POST['age'])) {
      echo "<span style=\"color: red\">Invalid Age provided</span>";
    } elseif($_POST['rating'] < 1 || $_POST['rating'] > 10 ) {
      echo "<span style=\"color: red\">Rating is invalid, please provide a number from 1 to 10</span>";
    } else {
      foreach($_POST as $k => $v) {
        $GLOBALS[$k] = htmlspecialchars(stripslashes(trim($v)));
      }
    }
  }
}