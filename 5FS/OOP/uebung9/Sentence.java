package oop.uebung9;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;
import java.util.Map.Entry;
import java.util.Iterator;
import java.util.Set;

public class Sentence {

	public String sentence, mostFrequentWord;
	public int numberOfMostFrequentOccurences;
	public ArrayList<String> words = new ArrayList<>();

	Sentence(String satz) {
		sentence = satz;
	}

	public Paar<String, Integer> findMostFrequentWord() {
		Paar<String, Integer> winner = new Paar<>("", 0);

		words = new ArrayList<>(Arrays.asList(sentence.split(" ")));

		HashMap<String, Integer> ocurredWords = new HashMap<>();
		for (String word : words) {
			if (!ocurredWords.containsKey(word)) {
				ocurredWords.put(word, 1);
			} else {
				ocurredWords.put(word, ocurredWords.get(word) + 1);
			}
		}
		for (Map.Entry<String, Integer> entry : ocurredWords.entrySet()){
			if (entry.getValue() > winner.getSecond()) {
				winner.setFirst(entry.getKey());
				winner.setSecond(entry.getValue());
			}
		}
		mostFrequentWord = winner.getFirst();
		numberOfMostFrequentOccurences = winner.getSecond();

		return winner;
	}

}
