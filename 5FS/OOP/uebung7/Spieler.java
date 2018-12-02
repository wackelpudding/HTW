package oop.uebung7;

public class Spieler {
	public String name;
	
	Spieler(){
		this("Test-Spieler");
	}
	
	Spieler(String name){
		this.name = name;
	}
	
	public String getName() {
		return this.name;
	}

}
