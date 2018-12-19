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

            System.out.println("Das Wort 'objektorientierte' kommt so oft vor: " + salyzer.getCountOf("objektorientierte"));


        }catch (IOException ioe){
            System.out.println("Bitte geben Sie eine gültige URL ein!");
        }




    }
}
