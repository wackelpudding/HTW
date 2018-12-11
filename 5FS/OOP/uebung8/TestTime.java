package oop.uebung8;

public class TestTime {

	public static void main(String[] args) throws IllegalTimeException {
		
		Time time1 = new Time(23,59,59);
		Time time2 = new Time(0,0,0);
		Time errorTime = new Time(23,50,200);
		int test = 25;
		
		System.out.println("Hier sollte \"23:59:59\" stehen: " + time1);
		System.out.println("Hier sollte \"00:00:00\" stehen: " + time2);
		
		System.out.println();
		
		System.out.println(time1 + " in Sekunden: " + time1.toSeconds());
		System.out.println(time2 + " in Sekunden: " + time2.toSeconds());
		
		System.out.println();
		
		System.out.println(time2 + " ist kleiner als " + time1 + ": " + (time2.compareTo(time1) == (-1)));
		System.out.println(time1 + " ist größer als " + time2 + ": " + (time1.compareTo(time2) == 1));
		
		time1.compareTo(test);
		
		System.out.println();
		
		System.out.print("Stelle " + time2 + " um 1s zurück: ");
		time2.turnBackward(0, 0, 1);
		System.out.print(time2 + "\n");
		
		System.out.println();
		
		System.out.println(time1 + " ist gleich " + time2 + ": " + (time1.compareTo(time2) == 0));
		
		System.out.println();
		
		System.out.print("Stelle " + time1 + " um 3h, 4min, 27s vor: ");
		time1.turnForward(3, 4, 27);
		System.out.print(time1 + "\n");
	}
}
