package oop.uebung5;

public class Wire {

	private boolean Current;

	public Wire() {
		this(false);
	}

	public Wire(boolean state) {
		this.Current = state;
	}

	public boolean getCurrent() {
		return this.Current;
	}

	public void setCurrent(boolean state) {
		this.Current = state;
	}
}
