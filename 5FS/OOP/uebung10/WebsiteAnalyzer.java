package oop.uebung10;

import java.io.IOException;
import java.util.Map;
import java.util.Scanner;

public class WebsiteAnalyzer {

    private static Scanner scan = new Scanner(System.in);

    public static void main(String[] args) {
        String userInput, dlContent;

        System.out.print("Bitte geben Sie eine URL ein: ");

        userInput = scan.nextLine();

        try {
            dlContent = new Downloader().download(userInput);
            StringAnalyzer salyzer = new StringAnalyzer(dlContent);
            salyzer.countWords();


            // Test ob ordentliche Daten geladen werden.


            for (Map.Entry<String, Integer> entry : salyzer.getWordCount().entrySet()) {
                System.out.printf("Key: %s Value: ", entry.getKey());
                System.out.println(entry.getValue());
            }


            // Standarttest
            System.out.println("\nDas Wort 'objektorientierte' kommt '" + salyzer.getCountOf("objektorientierte") + "' mal vor.\n");

            //Customtest
            System.out.print("Nach welchen Wort soll gesucht werden? : ");
            userInput = scan.nextLine();
            System.out.print("Das Wort '" + userInput + "' kommt '" + salyzer.getCountOf(userInput) + "' mal vor.\n");

        } catch (IOException ioe) {
            System.out.println("Bitte geben Sie eine gültige URL ein!");
        }


    }
}
