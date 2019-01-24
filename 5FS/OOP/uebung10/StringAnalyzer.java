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
        return this.string;
    }

    public Map<String, Integer> getWordCount() {
        return wordCount;
    }

    public void setString(String string) {
        this.string = string;
    }

    private void setWordCount(Map<String, Integer> wordCount) {
        this.wordCount = wordCount;
    }

    private void setWords(List<String> words) {
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
            return wordCount.getOrDefault(word, 0);

        } catch (NullPointerException e) {
            return -1;
        }
    }
}
