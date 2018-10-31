package oop.uebung4;

public class TestRadio {
	
	
	public static void main(String[] args) {
		System.out.println("Test area:");
		
		Radio Donut = new Radio();
		Radio Bahamas = new Radio(true,0,100.0);
		
		Donut.an();
		Bahamas.aus();
		Donut.setLautstaerke(8);
		Donut.lauter();
		Bahamas.setLautstaerke(7);
		Bahamas.leiser();
		Donut.setFrequenz(110.0);
		
		
	}
}
