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
     <h1>Übungsaufgabe 2<br /></h1>
   </header>
   <?php
   $vorname = $_POST['vorname'];
   $nachname = $_POST['nachname'];
   echo "Hallo $vorname $nachname";
   ?>
</form>
 </body>
<br />

 <footer class="footer_lb">
   <p>
     <?php
        echo "Aktuelle Serverzeit: ".date("H:i:s")." Uhr am ".date("d.m.Y").".";
     ?>
</p>
 </footer>
</html>
