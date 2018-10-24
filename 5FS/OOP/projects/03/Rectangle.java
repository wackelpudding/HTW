/**
 * Übungsaufgabe für Objektorientierte Programmierung
 * Eine Klasse, die achsenparallele Rechtecke repräsentiert. 
 *  
 * @author Alexander Schulz
 */

public class Rectangle extends RectangleParent {
	
	/** Die x-Koordinate der linken unteren Ecke des Rechtecks */
	public int x;
	/** Die x-Koordinate der linken unteren Ecke des Rechtecks */
	public int y; 
	/** Die Breite des Rechtecks */
	public int width; 
	/** Die Höhe des Rechtecks */
	public int height;
	
	
	/**
	 * Ein Konstruktor, um ein neues Rechteck zu erzeugen.
	 * 
	 * @param Die x-Koordinate der linken unteren Ecke des neuen Rechtecks
	 * @param Die x-Koordinate der linken unteren Ecke des neuen Rechtecks
	 * @param Die Breite des neuen Rechtecks
	 * @param Die Höhe des neuen Rechtecks
	 */
	public Rectangle( int x, int y, int width, int height ) {
		this.x = x;
		this.y = y;
		this.width = width;
		this.height = height;
	}
	
	
	/**
	 * Die Methode berechnet die Fläche des Rechtecks
	 * 
	 * @return Die Größe der Fläche des Rechtecks
	 */
//	public int area(){
//		isAreaCalled = true;
//	}
	
	
	/**
	 * Die Methode berechnet den Umfang des Rechtecks
	 * 
	 * @return Der Umfang des Rechtecks
	 */
//	public int perimeter(){
//		isPerimeterCalled = true;
//	}
	
	
	/**
	 * Eine Methode um ein Rechteck zu duplizieren
	 * 
	 * @return Ein neues Rechteck mit den gleichen Atrributen
	 */
//	public Rectangle cloneRect(){
//	
//	}
	
	
	/**
	 * Die Methode prüft, ob 2 Rechtecke identisch sind.
	 * 
	 * @param r Das Rechteck, das verglichen werden soll.
	 * @return true, wenn die Rechtecke identisch sind, sonst false
	 */
//	public boolean isIdenticalTo(Rectangle r){
//		isIsIdenticalToCalled = true;
//	}
	
	
	/**
	 * Eine Methode, um die Fläche von 2 Rechtecken zu vergleichen
	 * Tipp: Verwenden Sie Methoden, die sie bereits implementiert haben.  
	 * 
	 * @param r Das Rechteck, mit dem verglichen werden soll.
	 * @return -1, wenn die Fläche kleiner als die von r ist, 
	 * 			0, wenn die Flächen gleich sind, 
	 * 			1, wenn die Fläche von r größer ist
	 */
//	public int compareTo(Rectangle r){
//		isCompareToCalled = true;
//	}
	
	
	/**
	 * Eine Methode, die überprüft, ob das Rechteck r vollständig im Rechteckt, das die Methode ausführt, enthalten ist
	 * 
	 * @param r Das Rechteck, das enthalten sein kann
	 * @return
	 */
//	public boolean contains(Rectangle r){
//		isContainsCalled = true;
//	}
	
	
	/**
	 * Eine Methode die prüft, ob sich 2 Rechtecke überlappen. (Rechtecke überlappen sich nicht, wenn sie Kante an Kante liegen)
	 * 
	 * @param r Das Rechteck, das auf Überlappung geprüft werden soll. 
	 * @return true, wenn die Rechtecke sich überlappen, sonst false
	 */
//	public boolean overlaps(Rectangle r){
//		isOverlapsCalled = true;
//	}
	
	
	/**
	 * Eine Methode, die die rechteckige Schnittfläche berechnet, die entsteht, wenn sich 2 Rechtecke überlappen
	 * 
	 * @param r Das Recht
	 * @return Das Rechteck, das als Schnittfläche entsteht. Wenn sich die Rechtecke nicht überlappen: null.
	 */
//	public Rectangle section(Rectangle r) {
//		isSectionCalled = true;
//	}
	
	
	/**
	 * Eine Methode, die das kleinste Rechteck berechnet, dass alle Rechtecke umschließt.
	 * 
	 * @param recs Ein Array von Rechtecken, für die das umschließende Rechteck berechnet werden soll
	 * @return Das umschließende Rechteck, null, wenn das Array recs leer ist
	 */
//	public static Rectangle smallestBoundingRectangle(Rectangle[] recs) {
//		
//	}		

}