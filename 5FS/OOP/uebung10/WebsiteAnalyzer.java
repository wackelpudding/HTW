package oop.uebung10;

import java.io.IOException;
import java.util.*;

public class WebsiteAnalyzer {

    static Scanner scan = new Scanner(System.in);

    public static void main(String[] args) {
        String userInput,dlContent;

        System.out.println("Bitte geben Sie eine URL ein.");

        userInput = scan.nextLine();

        try {
            dlContent = new Downloader().download(userInput);
            StringAnalyzer salyzer = new StringAnalyzer(dlContent);
            salyzer.countWords();


            // Test ob ordentliche Daten geladen werden.

            for (Map.Entry<String, Integer> entry : salyzer.getWordCount().entrySet()){
                System.out.print("Key: " + entry.getKey() + " Value: ");
                System.out.println(entry.getValue());
            }

            System.out.println("Das Wort 'objektorientierte' kommt so oft vor: " + salyzer.getCountOf("objektorientierte"));



        }catch (IOException ioe){
            System.out.println("Bitte geben Sie eine gültige URL ein!");
        }




    }
}
