package oop.uebung3;

/**
 * Übungsaufgabe für Objektorientierte Programmierung Eine Klasse, die
 * achsenparallele Rechtecke repräsentiert.
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
	 * @param Die y-Koordinate der linken unteren Ecke des neuen Rechtecks
	 * @param Die Breite des neuen Rechtecks
	 * @param Die Höhe des neuen Rechtecks
	 */
	public Rectangle(int x, int y, int width, int height) {
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
	public int area() {
		isAreaCalled = true;
		return width * height;
	}

	/**
	 * Die Methode berechnet den Umfang des Rechtecks
	 * 
	 * @return Der Umfang des Rechtecks
	 */
	public int perimeter() {
		isPerimeterCalled = true;
		return 2 * (width + height);
	}

	/**
	 * Eine Methode um ein Rechteck zu duplizieren
	 * 
	 * @return Ein neues Rechteck mit den gleichen Atrributen
	 */
	public Rectangle cloneRect() {
		isCloneRectCalled = true;
		Rectangle clone = new Rectangle(x, y, width, height);
		return clone;
	}

	/**
	 * Die Methode prüft, ob 2 Rechtecke identisch sind.
	 * 
	 * @param r Das Rechteck, das verglichen werden soll.
	 * @return true, wenn die Rechtecke identisch sind, sonst false
	 */
	public boolean isIdenticalTo(Rectangle r) {
		isIsIdenticalToCalled = true;
		if (x == r.x && y == r.y && height == r.height && width == r.width) {
			return true;
		} else {
			return false;
		}

	}

	/**
	 * Eine Methode, um die Fläche von 2 Rechtecken zu vergleichen Tipp: Verwenden
	 * Sie Methoden, die sie bereits implementiert haben.
	 * 
	 * @param r Das Rechteck, mit dem verglichen werden soll.
	 * @return -1, wenn die Fläche kleiner als die von r ist, 0, wenn die Flächen
	 *         gleich sind, 1, wenn die Fläche von r größer ist
	 */
	public int compareTo(Rectangle r) {
		isCompareToCalled = true;
		if (area() > r.area()) {
			return 1;
		} else if (area() < r.area()) {
			return -1;
		} else {
			return 0;
		}
	}

	/**
	 * Eine Methode, die überprüft, ob das Rechteck r vollständig im Rechteckt, das
	 * die Methode ausführt, enthalten ist
	 * 
	 * @param r Das Rechteck, das enthalten sein kann
	 * @return
	 */
	public boolean contains(Rectangle r) {
		isContainsCalled = true;
		if ((x <= r.x && (x + width) >= (r.x + r.width)) && (y <= r.y && (y + height) >= (r.y + r.height))) {
			return true;
		} else {
			return false;
		}
	}

	/**
	 * Eine Methode die prüft, ob sich 2 Rechtecke überlappen. (Rechtecke überlappen
	 * sich nicht, wenn sie Kante an Kante liegen)
	 * 
	 * @param r Das Rechteck, das auf Überlappung geprüft werden soll.
	 * @return true, wenn die Rechtecke sich überlappen, sonst false
	 */
	public boolean overlaps(Rectangle r) {
		isOverlapsCalled = true;
		if (this.contains(r)
				|| (x >= (r.x + r.width) || y >= (r.y + r.height) || (y + height) <= r.y || (x + width) <= r.x)) {
			return false;
		} else {
			return true;
		}

	}

	/**
	 * Eine Methode, die die rechteckige Schnittfläche berechnet, die entsteht, wenn
	 * sich 2 Rechtecke überlappen
	 * 
	 * @param r Das Rechteck
	 * @return Das Rechteck, das als Schnittfläche entsteht. Wenn sich die Rechtecke
	 *         nicht überlappen: null.
	 */
	public Rectangle section(Rectangle r) {
		isSectionCalled = true;
		Rectangle sectionrect = new Rectangle(0, 0, 0, 0);
		// set x
		if (x <= r.x) {
			sectionrect.x = r.x;
			if ((sectionrect.x + r.width) > (x + width)) {
				sectionrect.width = (x + width) - sectionrect.x;
			} else {
				sectionrect.width = r.width;
			}
		} else {
			sectionrect.x = x;
			if ((sectionrect.x + width) > (r.x + r.width)) {
				sectionrect.width = r.x + r.width - sectionrect.x;
			} else {
				sectionrect.width = width;
			}
		}
		// set y
		if (y <= r.y) {
			sectionrect.y = r.y;
			if ((sectionrect.y + r.height) > (y + height)) {
				sectionrect.height = (y + height) - sectionrect.y;
			} else {
				sectionrect.height = r.height;
			}
		} else {
			sectionrect.y = y;
			if ((sectionrect.y + height) > (r.y + r.height)) {
				sectionrect.height = (r.y + r.height) - sectionrect.y;
			} else {
				sectionrect.height = height;
			}

		}
		
		System.out.println(sectionrect.x + " " + sectionrect.y + " " + sectionrect.width + " " + sectionrect.height);
		
		if (sectionrect.width == 0 || sectionrect.height == 0) {
			sectionrect = null;
		}

		return sectionrect;
	}

	/**
	 * Eine Methode, die das kleinste Rechteck berechnet, dass alle Rechtecke
	 * umschließt.
	 * 
	 * @param recs Ein Array von Rechtecken, für die das umschließende Rechteck
	 *             berechnet werden soll
	 * @return Das umschließende Rechteck, null, wenn das Array recs leer ist
	 */
	public static Rectangle smallestBoundingRectangle(Rectangle[] recs) {
		Rectangle finale = new Rectangle(0, 0, 0, 0);
		
		if (recs.length == 0) {
			finale = null;
		} else {
			
			finale.x = recs[0].x;
			finale.y = recs[0].y;
			finale.width = recs[0].width;
			finale.height = recs[0].height;
			
			for (int i = 0; i < recs.length; i++) {
				if ( recs[i].x < finale.x ) finale.x = recs[i].x ;
				if( recs[i].y < finale.y ) finale.y = recs[i].y;
				if( (recs[i].x + recs[i].width) > (finale.x + finale.width) ) {
					finale.width = Math.abs( finale.x - (recs[i].x + recs[i].width) );
				}
				if ( (recs[i].y + recs[i].height) > (finale.y + finale.height) ) {
					finale.height = Math.abs( finale.y - (recs[i].y + recs[i].height) );
				}
			}
			System.out.println(finale.x + " " + finale.y + " " + finale.width + " " + finale.height);
		}
		
		
		return finale;
	}		

}