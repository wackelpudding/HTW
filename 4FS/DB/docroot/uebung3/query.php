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
     <h1>Übungsaufgabe 3 - Query <br /></h1>
   </header>
   <br />
   <?php

   $host = "141.45.91.40";
   $dbname = "s0558882_db";
   $user = "s0558882";
   $pw = "99oe:qtr";

   $pdo = new PDO("mysql:host=$host;dbname=$dbname","$user", "$pw");


   $name = $_POST['name'];
   $preis = $_POST['preis'];

   $artikel = "%$name%";

   if (($name != "" AND $preis != "") AND is_numeric($preis)) {
      $query = $pdo->prepare("SELECT * FROM artikel WHERE Artikelbezeichnung LIKE ? AND Preis >= ?");
      $query ->execute(array($artikel,$preis));
      $query_rows = $query->rowCount();
   }
   if ($name == "" AND $preis == Null) {
     $query = $pdo->prepare("SELECT * FROM artikel");
     $query ->execute();
   }



   echo "<section><div class='div_table'>";
   echo "<table class='table_format'>";
   echo "<tr><th>Artikelnummer</th><th>Artikelbezeichnung</th><th>Herstellername</th><th>Preis in €</th></tr>";

   while ($row = $query->fetch())
   {
     echo "<tr><td>$row[Artikelnummer]</td><td>$row[Artikelbezeichnung]</td><td>$row[Herstellername]</td><td>$row[Preis]</td></tr>";
   }
   echo "</table></div></section>";

   echo "<form action='index.php' method='post'><input class='submit' type='Submit' value='Zurrück' /></form>";

   $pdo = null;
   ?>
 </body>
<p></p>
 <footer class="footer_lb">
   <?php echo "Aktuelle Serverzeit: ".date("H:i:s")." Uhr am ".date("d.m.Y").".<br />";?>
 </footer>
</html>
