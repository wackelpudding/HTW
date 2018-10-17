/**
 * Ziel dieser Aufgabe ist es ein 2-dimensionales Array mit zufälligen Werten
 * aus {0, 1} zu generieren und es auf der Konsole mit Paritätsbits für
 * die Zeilen auszugeben. Paritätsbits sind extra Bits (0 oder 1),
 * die an eine Bitfolge angehängt werden, um Fehler (bspw. bei der Übertragung)
 * zu erkennen. Beinhaltet die Bitfolge eine ungerade Anzahl an Einsen,
 * ist das Paritätsbit 1, sonst ist es 0.
 *
 * @author Ricardo Jimenez Tuero
 * @version 0.1337
 */

import java.util.concurrent.ThreadLocalRandom;
import java.util.Scanner;

public class ArrayParity {

  /**
   * initializeRandomArray Methode
   *
   * @param len Die größe der Matrix.
   * @return Der Array mit zufallszahlen befüllt.
   */

  public static int[][] initializeRandomArray (int len){
    int[][] array = new int[len][len];
      for (int[] coloumn : array) {
        for (int elem = 0 ; elem < coloumn.length ; elem++) {
          coloumn[elem] = ThreadLocalRandom.current().nextInt(0, 2);
        }
      }
      return array;
  }

  /**
   * printArray Methode
   *
   * @param array Der Array (beliebiger Länger der übergeben wird.)
   */

  public static void printArray(int[][] array){
    System.out.println("Array ohne Parity:");
    for (int[] coloumn : array) {
      for (int elem: coloumn) {
        System.out.print(elem + " ");
      }
      System.out.print("\n");
    }
  }

  /**
   * printArrayWithParity Methode
   * Der Array of Array wird in Matrix-stil ausgegeben.
   *
   * @param array Der Array (beliebiger Länger der übergeben wird.).
   *
   */

  public static void printArrayWithParity(int[][] array){
    int parity;
    System.out.println("Array mit Parity:");
    for (int[] coloumn : array) {
      parity = 0;
      for (int elem: coloumn) {
        parity += elem;
        System.out.print(elem + " ");
      }
      parity = parity % 2;
      System.out.print("| "+ parity + "\n");
    }
  }

  /**
   * Main Methode
   * Parsed den Input auf INT und ruft die 3 Methoden initializeRandomArray,
   * printArray und printArrayWithParity auf.
   *
   * @param args Konsolenparameter
   *
   */

  public static void main(String[] args) {
    int[][] array = initializeRandomArray(Integer.parseInt(args[0]));
    printArray(array);
    printArrayWithParity(array);
  }
}
