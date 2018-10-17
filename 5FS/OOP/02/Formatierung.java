class Formatierung {
	public static void main (String [] args) {
		System.out.println(0);
		int zero = 0;
		System.out.println(zero);
		int one = 1;
		int whatsThis = zero;
		System.out.println(whatsThis);
	  if (one == 1){
			whatsThis = one;
			System.out.println(whatsThis);
		} else
	    {System.out.println(zero);
		}
	}
}



/*
a)
In der Klasse CallByX wird folgendes ausgegbeben, beginnend mit Konsoleneingabe:
#>java CallByX
#>3
#>3
#>4
#>3

In der Klasse CallByY wird folgendes ausgegbeben, beginnend mit Konsoleneingabe:

#>java CallByY
#>3
#>3
#>4
#>4

b)
CallByX ist Call-By-Value und CallByY ist Call-By-Reference.
in Class 1 wird x mit 3 initialisiert und der Wert an increment übergeben.
In increment wird x' ausgegeben, um 1 erhöht und nochmal ausgegeben.
Anschließend wird das ursprüngliche, nicht editierte x ausgegeben.
In Class 2 wird die Speicheradresse von x an inkrement übergeben.
Somit wird bei der änderung mit inkrement auch der tatsächliche Wert von x geändert.
*/
