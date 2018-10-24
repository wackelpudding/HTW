package oop.uebung3;

public class RectangleParent {

	public boolean isAreaCalled, isPerimeterCalled, isCloneRectCalled, isIsIdenticalToCalled, isCompareToCalled,
			isContainsCalled, isOverlapsCalled, isSectionCalled, isSmallestBoundingRectangleCalled = false;

	public int area() {
		return 0;
	}

	public int perimeter() {
		return 0;
	}

	public Rectangle cloneRect() {
		return null;
	}

	public boolean isIdenticalTo(Rectangle r) {
		return false;
	}

	public int compareTo(Rectangle r) {
		return 0;
	}

	public boolean contains(Rectangle r) {
		return false;
	}

	public boolean overlaps(Rectangle r) {
		return false;
	}

	public Rectangle section(Rectangle r) {
		return null;
	}

	public static Rectangle smallestBoundingRectangle(Rectangle[] recs) {
		return new Rectangle(Integer.MAX_VALUE, Integer.MAX_VALUE, Integer.MAX_VALUE, Integer.MAX_VALUE);
	}

}
