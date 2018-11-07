package oop.uebung5;

public class AndGate extends Gate {
	
	public Wire calcOutput(Wire a, Wire b) {
		y.setCurrent(a.getCurrent() && b.getCurrent());
		return y;
	}
	
	public AndGate() {
		super(false, false);
	}
	
	public AndGate(boolean a, boolean b) {
		super(a,b);
	}

}
