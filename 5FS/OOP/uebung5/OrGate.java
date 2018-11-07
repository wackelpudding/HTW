package oop.uebung5;

public class OrGate extends Gate {
	
	public Wire calcOutput(Wire a, Wire b) {
		y.setCurrent((a.getCurrent() || b.getCurrent()));
		return y;
	}
	
	public OrGate() {
		super(false, false);
	}
	
	public OrGate(boolean a, boolean b) {
		super(a,b);
	}

}
