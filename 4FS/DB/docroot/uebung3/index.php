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
     <h1>Übungsaufgabe 3 - Artikelsuche <br /></h1>
   </header>
   <form action="query.php" method="post">
     <table class="no_style">
   <tr><td>Artikelbezeichnung:</td><td><input type="text" name="name" /></td></tr>
   <tr><td>Mindestpreis:</td><td><input type="text" name="preis" /></td></tr>
   <tr><td></td><td><input class="submit" type="Submit" value="suchen" /></td></tr>
 </table>
   </form>
 </body>
<p></p>
 <footer class="footer_lb">
   <?php echo "Aktuelle Serverzeit: ".date("H:i:s")." Uhr am ".date("d.m.Y").".<br />";?>
 </footer>
</html>
