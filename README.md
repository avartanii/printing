# Homework 2
## 10 March 2015

1. Problem 1
	```java
	import java.util.Arrays;

	public class Bozosort {
	
		public static int[] bozosort(int[] arr) {
			int[] intArr = arr;
			int index1;
			int index2;
			int temp;
			while(!isSorted(intArr)) {
				index1 = (int) (Math.random() * intArr.length);
				index2 = (int) (Math.random() * intArr.length);
				temp = intArr[index1];
				intArr[index1] = intArr[index2];
				intArr[index2] = temp;
				System.out.println(Arrays.toString(intArr));
	
			}
			return intArr;
		}
	
		public static boolean isSorted(int[] a) {
			for (int i = 0; i < a.length - 1; i++) {
				if (a[i] > a[i + 1]) {return false;}
			}
			return true;
		}
	
		public static void main(String[] args) {
			int[] intArgs = new int[args.length];
			for (int i = 0; i < args.length; i++) {
				intArgs[i] = Integer.parseInt(args[i]);
			}
			System.out.println(Arrays.toString(bozosort(intArgs)));
		}
	}
	```
2. Problem 2
3. Problem 3
	* "THE PROGRESS OF OUR ARMS, UPON WHICH ALL ELSE CHIEFLY DEPENDS, IS AS WELL KNOWN TO THE PUBLIC AS TO MYSELF, AND IT IS, I TRUST, REASONABLY SATISFACTORY AND ENCOURAGING TO ALL. WITH HIGH HOPE FOR THE FUTURE, NO PREDICTION IN REGARD TO IT IS VENTURED"

```java
System.out.println("Hello, world!");
```
