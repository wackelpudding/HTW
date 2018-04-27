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
   <br />
   <?php
    if ($_POST['winkel_high'] != "")
    {
      $winkel_high = $_POST['winkel_high'];
      if (is_numeric($winkel_high))
      {
        if ($winkel_high <= 360)
        {
          $high_validated = TRUE;
        }
        else {
          $high_validated = FALSE;
          $output = "Oberer Winkel ist größer als 360!<br />";
        }
      }
      else {
        $high_validated = FALSE;
        $output = "Keine Zahl für den oberen Winkel eingegeben.<br />";
      }
    }
    else {
      $high_validated = FALSE;
      $output = "Keine Eingabe für den oberen Winkel erfolgt.<br />";
    }

    if ($_POST['winkel_low'] != "")
    {
      $winkel_low = $_POST['winkel_low'];
      if (is_numeric($winkel_low))
      {
        if ($winkel_low >= 0)
        {
          $low_validated = TRUE;
        }
        else {
          $low_validated = FALSE;
          $output = "Unterer Winkel ist kleiner als 0!<br />";
        }
      }
      else {
        $low_validated = FALSE;
        $output = "Keine Zahl für den unteren Winkel eingegeben.<br />";
      }
    }
    else {
      $low_validated = FALSE;
      $output = "Keine Eingabe für den unteren Winkel erfolgt.<br />";
    }

    if ($low_validated AND $high_validated) {
      if ($winkel_low >= $winkel_high)
      {
        $output = "Unterer Winkel muss kleiner als der obere Winkel sein!";
        $high_validated = false;
        $low_validated = false;
      }
    }
    echo "<form action='index.php' method='post'><input class='submit' type='Submit' value='Zurrück' /></form><br />";
    if (isset($output)) {
      echo "<section><div class='div_alert'>$output</div></section>";
    }


    if ($high_validated AND $low_validated) {
      echo "<section><div class='div_table'>";
      echo "<table><tr><th>Winkel in Grad</th><th>Sin</th><th>Cos</th><th>Tan</th></tr>";

      $i = $winkel_low;
      while ($i <= $winkel_high) {
        $sin = sin(deg2rad($i));
        $cos = Cos(deg2rad($i));
        $tan = tan(deg2rad($i));
        echo " <tr><td>$i</td><td>$sin</td><td>$cos</td><td>$tan</td></tr>";
        $i++;
      }



      echo "</table><div></section>";
    }

    echo "<form action='index.php' method='post'><input class='submit' type='Submit' value='Zurrück' /></form>";
    ?>
 </body>
<p></p>
 <footer class="footer_lb">
   <?php echo "Aktuelle Serverzeit: ".date("H:i:s")." Uhr am ".date("d.m.Y").".<br />";?>
 </footer>
</html>
