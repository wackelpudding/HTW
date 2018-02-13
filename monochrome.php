<?

$im = imagecreatefrompng("bild.png");
echo createMonochromeImage($im);
function createMonochromeImage($im) {
 $bits = "";
 $bytes = "";
 $pixelcount = 0;
 for ($y = 0;$y<imagesy($im); $y++){
  for ($x = 0;$x<imagesx($im); $x++){
   $rgb = imagecolorat($im, $x, $y);
   $r = ($rgb >> 16) & 0xFF;
   $g = ($rgb >> 8) & 0xFF;
   $b= $rgb & 0xFF;
   $gray = ($r + $g + $b) / 3;
   if ($gray < 0xFF) {
    $bits .= "1";
   }else {
        $bits .= "0";
   }
   $pixelcount++;
   if ($pixelcount % 8 == 0) {
    $bytes .= pack('H*',str_pad(base_convert($bits,2,16),2,"0",STR_PAD_LEFT));
    $bits = "";
   }
  }
 }
 return $bytes;
}
