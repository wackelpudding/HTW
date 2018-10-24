package oop.uebung2;
/**
 * This Class will receive an integer from the user.
 * Otherwise an error will returned and the program ends.
 *
 * @author Ricardo Jimenez Tuero
 * @version 0.42
 */
//import java.util.Scanner;


public class MathPowerArray {
  /**
   * getArray Methode
   *
   * @param n Zu potenzierende Zahl
   * @param array übergebenes Array
   * @return 10er Array array mit potenzierten Eingangswerten.
   */

   public static long[] getArray(int n, long[] array){
     int power = n;
     for (int i = 0;i < 10 ;i++ ) {
       array[i] = n;
       n *= power;
     }
     return array;
   }

   /**
    * printArray Methode
    * gibt den Array array aus.
    *
    * @param array zu übergebenes Array
    */

   public static void printArray(long[] array){
     for (long i : array) {
        System.out.print(i + " ");
     }
     System.out.print("\n");
   }

   /**
    * Main Methode
    * Überprüft die Parameter args auf Korrektheit.
    * Überprüft, ob Parameter args übergeben wurde.
    *
    * @param args Komandozeilenparameter
    */

  public static void main(String[] args) {
    long out[] = new long[10];
    if ( args.length != 0) {
      out = getArray(Integer.parseInt(args[0]), out);
      printArray(out);
    } else {
      System.out.println("Es wurde kein Parameter übergeben!");
    };
    }
}
