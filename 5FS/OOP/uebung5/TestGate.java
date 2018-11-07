package oop.uebung5;

public class TestGate {

	public static void main(String[] args) {
		
		OrGate otter = new OrGate();
		AndGate jitter = new AndGate();
		System.out.println("Das ODER-Gatter ist am Ausgang:" + otter.y.getCurrent());
		System.out.println("Das Und-Gatter ist am Ausgang:" + jitter.y.getCurrent());
		System.out.println("processing changes....");
		otter.setInputs(true, false); //oder
		System.out.println("Das ODER-Gatter ist am Ausgang:" + otter.y.getCurrent());
		
		jitter.setInputs(true, true); //und
		System.out.println("Das Und-Gatter ist am Ausgang:" + jitter.y.getCurrent());
		
		

	}

}
