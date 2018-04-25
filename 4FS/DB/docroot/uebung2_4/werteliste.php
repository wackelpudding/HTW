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
          echo "Ungültiger oberer Winkel!<br />";
        }
      }
      else {
        echo "Keine Zahl für den oberen Winkel eingegeben.<br />";
      }
    }
    else {
      echo "Keine Eingabe für den oberen Winkel erfolgt.<br />";
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
          echo "Ungültiger unterer Winkel!<br />";
        }
      }
      else {
        echo "Keine Zahl für den unteren Winkel eingegeben.<br />";
      }
    }
    else {
      echo "Keine Eingabe für den unteren Winkel erfolgt.<br />";
    }

    if ($winkel_low >= $winkel_high)
    {
      echo "Unterer Winkel muss kleiner als der obere Winkel sein!";
      $high_validated = false;
      $low_validated = false;
    }

    if ($high_validated AND $low_validated) {
      
    }

    ?>
 </body>
<p></p>
 <footer class="footer_lb">
   <p><?php echo "Aktuelle Serverzeit: ".date("H:i:s")." Uhr am ".date("d.m.Y").".";?><p>
 </footer>
</html>
