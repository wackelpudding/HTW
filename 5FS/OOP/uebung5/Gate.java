package oop.uebung5;

public class Gate {
	Wire a;
	Wire b;
	Wire y;
	
	public Wire calcOutput(Wire a, Wire b) {
		this.y.setCurrent(false);
		return this.y;
	}
	
	public void setInputs(boolean a, boolean b) {
		this.a = new Wire(a);
		this.b = new Wire(b);
		this.calcOutput(new Wire(a), new Wire(b));
	}
	
	public Gate() {
		this(false,false);
	}
	
	public Gate(boolean a, boolean b) {
		this.a = new Wire(a);
		this.b = new Wire(b);
		this.y = new Wire();
	}
}
