package oop.uebung4;

public class Radio {

	private boolean istAn;
	private int lautstaerke;
	private double frequenz;

	public Radio() {
		this(false, 0, 85.0);
	}

	public Radio(boolean istAn, int lautstaerke, double frequenz) {
		this.istAn = istAn;
		if (lautstaerke <= 10 && lautstaerke >= 0) {
			this.setLautstaerke(lautstaerke);
		} else {
			this.setLautstaerke(0);
		}
		if (frequenz <= 110.0 && frequenz >= 85.0) {
			this.setFrequenz(frequenz);
		} else {
			this.setFrequenz(85.0);
		}
	}

	public double getFrequenz() {
		return frequenz;
	}

	public void setFrequenz(double frequenz) {
		System.out.println("Aufruf von setFrequenz()");
		if (frequenz <= 110.0 && frequenz >= 85.0)
			this.frequenz = frequenz;
		System.out.println(this.toString());
	}

	public int getLautstaerke() {
		return lautstaerke;
	}

	public void setLautstaerke(int lautstaerke) {
		System.out.println("Aufruf von setLautstaerke()");
		if (lautstaerke <= 10 && lautstaerke >= 0)
			this.lautstaerke = lautstaerke;
		System.out.println(this.toString());
	}

	public boolean isIstAn() {
		return istAn;
	}

	public void lauter() {
		System.out.println("Aufruf von lauter()");
		if (this.isIstAn())
			this.setLautstaerke(this.lautstaerke + 1);
		System.out.println(this.toString());

	}

	public void leiser() {
		System.out.println("Aufruf von leiser()");
		if (this.isIstAn())
			this.setLautstaerke(this.lautstaerke - 1);
		System.out.println(this.toString());
	}

	public void aus() {
		System.out.println("Aufruf von aus()");
		if (this.isIstAn())
			this.istAn = false;
		System.out.println(this.toString());
	}

	public void an() {
		System.out.println("Aufruf von an()");
		if (!this.isIstAn())
			this.istAn = true;
		System.out.println(this.toString());
	}

	public String toString() {
		String s1 = "";
		if (this.isIstAn()) {
			s1 = "Radio an: Freq=" + this.getFrequenz() + ", Laut=" + this.getLautstaerke();
		} else {
			s1 = "Radio aus: Freq=" + this.getFrequenz() + ", Laut=" + this.getLautstaerke();
		}
		return s1;
	}

}
