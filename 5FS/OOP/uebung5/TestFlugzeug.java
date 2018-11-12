package oop.uebung5;

public class TestFlugzeug {

	public static void main(String[] args) {
		
		//Flugzeug
		
		System.out.println("Flieger eins erzeugen: Flugzeug");
		System.out.println("falsch:");
		Flugzeug einsb = new Flugzeug ("A-B2324", 10000, 20000, 25000, 20000);
		System.out.println("richtig");
		Flugzeug eins = new Flugzeug ("A-B2324", 50000, 20000, 25000, 20000);
		System.out.println(eins.toString());
		System.out.println("\nunzulässiges tanken von Flieger eins: 20000");
		eins.tanken(20000);
		System.out.println("\nzulässiges tanken von Flieger eins: 5000");
		eins.tanken(5000);
		System.out.println(eins.toString());
		
		//Frachtflugzeug
		
		System.out.println("\n##############################"
				+ "\nFlieger zwei erzeugen: Frachtflugzeug");
		System.out.println("falsch:");
		Frachtflugzeug zweib = new Frachtflugzeug("B-C3456", 10000, 20000, 25000, 20000, 324234);
		System.out.println("richtig");
		Frachtflugzeug zwei = new Frachtflugzeug("B-C3456", 50000, 20000, 25000, 20000, 0);
		System.out.println(zwei.toString());
		
		System.out.println("unzulässiges Beladen:");
		zwei.beladen(534243);
		
		System.out.println("zulässiges Be- und Entladen:");
		zwei.beladen(500);
		System.out.println(zwei.toString());
		zwei.entladen();
		System.out.println(zwei.toString());
		
		//Passagierflugzeug
		
		System.out.println("\n##############################"
				+ "\nFlieger drei erstellen: Passagierflugzeug");
		System.out.println("falsch:");
		Passagierflugzeug dreib = new Passagierflugzeug("B-C3456", 10000, 20000, 25000, 20000, 0, 234565);
		System.out.println("richtig");
		Passagierflugzeug drei = new Passagierflugzeug("B-C3456", 65000, 20000, 25000, 20000, 0,300);
		System.out.println(drei.toString());
		System.out.println("\nunzulässiges Ein- und Aussteigen:");
		drei.einsteigen(400);
		drei.aussteigen(400);
		System.out.println("\nzulässiges Ein- und Aussteigen:");
		drei.einsteigen(250);
		System.out.println(drei.toString());
		drei.aussteigen(100);
		System.out.println(drei.toString());
	
	}
}
