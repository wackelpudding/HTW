<!doctype html>
<html lang="de">
 <head>
   <link rel="stylesheet" href="style.css">
   <?php date_default_timezone_set('Europe/Berlin');?>
 <meta charset="utf-8">
 <meta name="viewport" content="width=device-width, initialscale=1.0"/>
 <title>Titel</title>
 </head>
 <body>
   <header class="header_lb">
     <h1>Übungsaufgabe 2 - Werteliste <br /></h1>
   </header>
   <?php
    if ($_POST['winkel_low'] == "" AND $_POST['winkel_high'] == "") {
      $winkel_low = $_POST['winkel_low'];
      $winkel_high = $_POST['winkel_high'];
      if (is_numeric($winkel_low) AND is_numeric($winkel_high)) {
        if ($winkel_low >= 0 AND $winkel_high <= 360) {
          $high_validated = TRUE;
        }
        else {
          echo "Ungültige Winkel!";
        }
      }
      else {
        echo "Keine Zahlen eingegeben.";
      }
    }
    else {
      echo "Keine Eingabe erfolgt";
    }
    ?>
 </body>
<p></p>
 <footer class="footer_lb">
   <p><?php echo "Aktuelle Serverzeit: ".date("H:i:s")." Uhr am ".date("d.m.Y").".";?><p>
 </footer>
</html>
