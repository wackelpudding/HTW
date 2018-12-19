package oop.uebung10;

import java.util.*;

public class StringAnalyzer {

    private String string;
    private Map<String, Integer> wordCount;
    private List<String> words;

    public StringAnalyzer(String string) {
        this.setString(string);
    }

    public String getString() {
        return string;
    }

    public Map<String, Integer> getWordCount() {
        return wordCount;
    }

    public List<String> getWords() {
        return words;
    }

    public void setString(String string) {
        this.string = string;
    }

    public void setWordCount(Map<String, Integer> wordCount) {
        this.wordCount = wordCount;
    }

    public void setWords(List<String> words) {
        this.words = words;
    }

    public void countWords() {

        this.setWords(new ArrayList<>(Arrays.asList(this.getString().split("[\\W]"))));

        Map<String, Integer> tempWordCount = new HashMap<>();
        for (String word : words) {
            if (!tempWordCount.containsKey(word)) {
                tempWordCount.put(word, 1);
            } else {
                tempWordCount.put(word, tempWordCount.get(word) + 1);
            }
        }

        this.setWordCount(tempWordCount);
    }

    public int getCountOf(String word) {
        try {
            if (wordCount.containsKey(word)) {
                return wordCount.get(word);
            } else {
                return 0;
            }

        } catch (NullPointerException e) {
            return -1;
        }
    }
}
