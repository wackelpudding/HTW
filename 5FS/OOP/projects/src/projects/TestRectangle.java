public class TestRectangle {
	
	public static Rectangle a = new Rectangle(-2, -1, 5, 3);
	public static Rectangle b = new Rectangle(-1, 0, 2, 1);
	public static Rectangle c = new Rectangle(2, -3, 1, 4);
	public static Rectangle d = new Rectangle(2, 3, 1, 1);
	public static Rectangle e = new Rectangle(3, 3, 2, 2);
	
	
	public static void main(String[] args) {
		System.out.println("Test area:");
		int area = a.area();
		if (a.isAreaCalled) {
			 System.out.println("\tA.area() = 15");
			 if (area == 15) {
				 System.out.println("\t\t[OK] Test erfolgreich");
			 }
			 else {
				 System.out.println("\t\t[FAIL] Test nicht erfolgreich, errechnete Fläche: " + area);
			 }
		} else {
				System.out.println("\tDie Methode ist noch nicht implementiert");
		}
		System.out.println();
		
		System.out.println("Test perimeter:");
		int perimeter = c.perimeter();
		if(c.isPerimeterCalled) {
			System.out.println("\tC.perimeter() = 10");
			if (perimeter == 10) {
				 System.out.println("\t\t[OK] Test erfolgreich");
			 }
			 else {
				 System.out.println("\t\t[FAIL] Test nicht erfolgreich, errechneter Umfang: " + perimeter);
			 }
		} else {
			System.out.println("\tDie Methode ist noch nicht implementiert");
		}
		System.out.println();
		
		System.out.println("Test cloneRect:");
		Rectangle clone = e.cloneRect();
		if (e.isCloneRectCalled) {
			if (clone != e && clone.height == e.height && clone.width == e.width && clone.x == e.x && clone.y == e.y) {
				System.out.println("\t\t[OK] Test erfolgreich"); 
			} else {
				System.out.println("\t\t[FAIL] Test nicht erfolgreich");
			}
		} else {
			System.out.println("\tDie Methode ist noch nicht implementiert");
		}
		System.out.println();
		
		System.out.println("Test isIdenticalTo:");
		boolean identity = b.isIdenticalTo(b);
		if (b.isIsIdenticalToCalled) {
			System.out.println("\tB.isIdenticalTo(B) = true");
			if (identity) {
				System.out.println("\t\t[OK] Test erfolgreich"); 
			} else {
				System.out.println("\t\t[FAIL] Test nicht erfolgreich");
			}
			identity = !b.isIdenticalTo(c);
			System.out.println("\tB.isIdenticalTo(C) = false");
			if (identity) {
				System.out.println("\t\t[OK] Test erfolgreich"); 
			} else {
				System.out.println("\t\t[FAIL] Test nicht erfolgreich");
			}
		} else {
			System.out.println("\tDie Methode ist noch nicht implementiert");
		}
		System.out.println();
		
		System.out.println("Test compareTo:");
		boolean compare = e.compareTo(c) == 0;
		if (e.isCompareToCalled) {
			System.out.println("\tE.compareTo(C) = 0");
			if (compare) {
				System.out.println("\t\t[OK] Test erfolgreich"); 
			} else {
				System.out.println("\t\t[FAIL] Test nicht erfolgreich");
			}
			System.out.println("\tD.compareTo(E) = -1");
			if (d.compareTo(e) == -1) {
				System.out.println("\t\t[OK] Test erfolgreich"); 
			} else {
				System.out.println("\t\t[FAIL] Test nicht erfolgreich");
			}
			System.out.println("\tA.compareTo(B) =  1");
			if (a.compareTo(b) == 1) {
				System.out.println("\t\t[OK] Test erfolgreich"); 
			} else {
				System.out.println("\t\t[FAIL] Test nicht erfolgreich");
			}
		} else {
			System.out.println("\tDie Methode ist noch nicht implementiert");
		}
		System.out.println();
		
		System.out.println("Test contains:");
		boolean contain = a.contains(b);
		if (a.isContainsCalled) {
			System.out.println("\tA.contains(B) = true");
			if(contain) {
				System.out.println("\t\t[OK] Test erfolgreich"); 
			} else {
				System.out.println("\t\t[FAIL] Test nicht erfolgreich");
			}
			System.out.println("\tA.contains(C) = false");
			if (!a.contains(c)) {
				System.out.println("\t\t[OK] Test erfolgreich"); 
			} else {
				System.out.println("\t\t[FAIL] Test nicht erfolgreich");
			}
		} else {
			System.out.println("\tDie Methode ist noch nicht implementiert");
		}
		System.out.println();
		
		System.out.println("Test overlaps:");
		boolean overlap = a.overlaps(c);
		if (a.isOverlapsCalled) {
			System.out.println("\tA.overlaps(C) = true");
			if (overlap) {
				System.out.println("\t\t[OK] Test erfolgreich"); 
			} else {
				System.out.println("\t\t[FAIL] Test nicht erfolgreich");
			}
			System.out.println("\tB.overlaps(A) = true");
			if (b.overlaps(a)) {
				System.out.println("\t\t[OK] Test erfolgreich"); 
			} else {
				System.out.println("\t\t[FAIL] Test nicht erfolgreich");
			}
			System.out.println("\tD.overlaps(E) = false");
			if (!d.overlaps(e)) {
				System.out.println("\t\t[OK] Test erfolgreich"); 
			} else {
				System.out.println("\t\t[FAIL] Test nicht erfolgreich");
			}
		} else {
			System.out.println("\tDie Methode ist noch nicht implementiert");
		}
		System.out.println();
		
		System.out.println("Test section:");
		Rectangle sec = a.section(b);
		if (a.isSectionCalled) {
			System.out.println("\tA.section(B)");
			if (sec.x == b.x && sec.y == b.y && sec.width == b.width && sec.height == b.height) {
				System.out.println("\t\t[OK] Test erfolgreich"); 
			} else {
				System.out.println("\t\t[FAIL] Test nicht erfolgreich");
			}
			System.out.println("\tC.section(A)");
			sec = c.section(a);
			if (sec.x == 2 && sec.y == -1 && sec.width == 1 && sec.height == 2) {
				System.out.println("\t\t[OK] Test erfolgreich"); 
			} else {
				System.out.println("\t\t[FAIL] Test nicht erfolgreich");
			}
			System.out.println("\tD.section(E)");
			if (d.section(e) == null) {
				System.out.println("\t\t[OK] Test erfolgreich"); 
			} else {
				System.out.println("\t\t[FAIL] Test nicht erfolgreich");
			}
		} else {
			System.out.println("\tDie Methode ist noch nicht implementiert");
		}
		System.out.println();
		
		System.out.println("Test smallestBoundingRectangle:");
		Rectangle[] recs = {a, b};
		Rectangle bound = Rectangle.smallestBoundingRectangle(recs);
		if (!(bound.x == Integer.MAX_VALUE && bound.y == Integer.MAX_VALUE && bound.width == Integer.MAX_VALUE && bound.height == Integer.MAX_VALUE)) {
			System.out.println("\tsmallestBoundingRectangle({A,B})");
			if (bound.x == a.x && bound.y == a.y && bound.width == a.width && bound.height == a.height) {
				System.out.println("\t\t[OK] Test erfolgreich"); 
			} else {
				System.out.println("\t\t[FAIL] Test nicht erfolgreich");
			}
			System.out.println("\tsmallestBoundingRectangle({B,C,D,E})");
			Rectangle[] recs2 = {b, c, d, e};
			bound = Rectangle.smallestBoundingRectangle(recs2);
			if (bound.x == -1 && bound.y == -3 && bound.width == 6 && bound.height == 8) {
				System.out.println("\t\t[OK] Test erfolgreich"); 
			} else {
				System.out.println("\t\t[FAIL] Test nicht erfolgreich");
			}
			System.out.println("\tsmallestBoundingRectangle({})");
			recs = new Rectangle[0];
			if (Rectangle.smallestBoundingRectangle(recs) == null) {
				System.out.println("\t\t[OK] Test erfolgreich"); 
			} else {
				System.out.println("\t\t[FAIL] Test nicht erfolgreich");
			}
		} else {
			System.out.println("\tDie Methode ist noch nicht implementiert");
		}
	}
}
