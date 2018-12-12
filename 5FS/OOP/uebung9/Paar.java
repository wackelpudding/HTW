package oop.uebung9;

public class Paar<X, Y> {

	private X ding1;
	private Y ding2;

	public X getFirst() {
		return ding1;
	}

	public void setFirst(X ding1) {
		this.ding1 = ding1;
	}

	public Y getSecond() {
		return ding2;
	}

	public void setSecond(Y ding2) {
		this.ding2 = ding2;
	}

	Paar(X teil, Y rums) {
		this.ding1 = teil;
		this.ding2 = rums;
	}

	public Paar<Y, X> flip() {
		Paar<Y, X> flipped = new Paar<Y, X>(ding2, ding1);
		return flipped;
	}
	
	public static void main(String[] args) {
		System.out.println("Paar erstellen: '7' und 'hallo'");
		Paar<Integer, String> test = new Paar<Integer, String>(7,"hallo");
		System.out.println(Integer.toString(test.getFirst()) + " und " + test.getSecond());
		Paar<String, Integer> test2 = test.flip();
		System.out.println("Tauschen..");
		System.out.println(test2.getFirst() + " und " + Integer.toString(test2.getSecond()));
		
		
		Sentence testsatz = new Sentence("Menno Bla Bla Hallo Hallo Hallo das Hallo Hallo ist ein das Hallo Test. Bla Bla Bla Bla Bla Hallo");
		testsatz.findMostFrequentWord();
		System.out.println("\n\t'" + testsatz.mostFrequentWord + "' -> Häufigkeit: " + Integer.toString(testsatz.numberOfMostFrequentOccurences));
		
	}

}
