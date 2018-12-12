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
		Paar<String, Integer> winner = new Paar<String, Integer>("", 0);

		words = new ArrayList<>(Arrays.asList(sentence.split(" ")));

		HashMap<String, Integer> ocurredWords = new HashMap<>();
		for (String word : words) {
			if (!ocurredWords.containsKey(word)) {
				ocurredWords.put(word, 1);
			} else {
				ocurredWords.put(word, ocurredWords.get(word) + 1);
			}
		}
		Set<Entry<String, Integer>> set = ocurredWords.entrySet();
		Iterator<Entry<String, Integer>> iterator = set.iterator();
		while (iterator.hasNext()) {
			Map.Entry<String, Integer> mentry = (Entry<String, Integer>) iterator.next();
			if (mentry.getValue() > winner.getSecond()) {
				winner.setFirst(mentry.getKey());
				winner.setSecond(mentry.getValue());
			}
		}
		mostFrequentWord = winner.getFirst();
		numberOfMostFrequentOccurences = winner.getSecond();

		return winner;
	}

}
