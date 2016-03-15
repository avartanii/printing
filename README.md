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
			long totalTime = 0;
			for (int k = 2; k < 12; k++) {
				for (int j = 0; j < 20; j++) {
					long startTime = System.nanoTime();

					int[] intArgs = new int[k];
					for (int i = 0; i < k; i++) {
						intArgs[i] = (int) (Math.random() * 20);
					}

					System.out.println(Arrays.toString(bozosort(intArgs)));

					long trialTime = System.nanoTime() - startTime;
					totalTime += trialTime;
				}
			}
			System.out.println("Average Time: " + (totalTime * Math.pow(10, -9) / 160) + " seconds");
		}
	}
	```
	Average time: 0.2149966 seconds
2. Problem 2
	* Requires both plaintext and key to be in all caps Latin letters.
	```java
	public class AutokeyVigenere {
	
		public static String autokey_vigenere(String pt, String k) {
			char[] plaintext = pt.toCharArray();
			char[] key = k.toCharArray();
			char[] cipherText = new char[plaintext.length];
			int currentChar = 128;
			for (int i = 0; i < plaintext.length; i++) {
				Character.toChars((int) (plaintext[i]) - 65, plaintext, i);
			}
			for (int i = 0; i < key.length; i++) {
				Character.toChars((int) (key[i]) - 65, key, i);
			}
			for (int i = 0; i < plaintext.length; i++) {
				if (i >= key.length) {
					currentChar = (((int) (plaintext[i]) + (int) (plaintext[i - key.length])) % 26) + 65;
					Character.toChars(currentChar, cipherText, i);
				} else {
					currentChar = (((int) (plaintext[i]) + (int) (key[i])) % 26) + 65;
					Character.toChars(currentChar, cipherText, i);
				}
			}
			return new String(cipherText);
		}	

		public static void main(String[] args) {
			System.out.println(autokey_vigenere(args[0], args[1]));
		}
	}
```
3. Problem 3
	(Messy program written specifically to help solve only this substitution cipher. Can be used for other substitution ciphers, but the string used and replacements were for this problem only).
	```java
	import java.util.Map;
	import java.util.HashMap;
	import java.util.ArrayList;
	
	public class MonoCounter {
		public static void main(String[] args) {
			String plaintext = "RYW QVKOVWPP KT KLV FVBP, LQKU DYZIY FEE WEPW IYZWTEG HWQWUHP, ZP FP DWEE AUKDU RK RYW QLXEZI FP RK BGPWET, FUH ZR ZP, Z RVLPR, VWFPKUFXEG PFRZPTFIRKVG FUH WUIKLVFOZUO RK FEE. DZRY YZOY YKQW TKV RYW TLRLVW, UK QVWHZIRZKU ZU VWOFVH RK ZR ZP JWURLVWH";
			Map<String,Integer> map = new HashMap<String,Integer>();
			Map<String,Integer> map2 = new HashMap<String,Integer>();
			Map<String,Integer> map3 = new HashMap<String,Integer>();
			ArrayList<String> bigrams = new ArrayList<String>();
			ArrayList<String> trigrams = new ArrayList<String>();
			char[] currChar;
			String current;
			Integer count;
			for (int i = 0; i < 26; i++) {
				currChar = Character.toChars(i + 65);
				map.put(Character.toString(currChar[0]), new Integer("0"));
			}
			for (int i = 0; i < plaintext.length(); i++) {
				current = plaintext.substring(i, i + 1);
				if (!current.equals(" ") && !current.equals(",") && !current.equals(".")) {
					//System.out.println("Current: " + current);
					count = map.get(current);
					map.remove(current);
					map.put(current, new Integer(count.intValue() + 1));
				}
			}
			for (int i = 0; i < plaintext.length() - 2; i++) {
				if (plaintext.substring(i, i + 1).equals(" ")) {
					i += 1;
				} else if (plaintext.substring(i + 1, i + 2).equals(" ")) {
					i += 2;
				}
				current = plaintext.substring(i, i + 2);
				System.out.println("Current: " + current);
				//if (!current.equals(" ") && !current.equals(",") && !current.equals(".")) {
					if (map2.containsKey(current)) {
						count = map2.get(current);
						System.out.println("Count: " + map2.get(current));
						map2.remove(current);
						map2.put(current, new Integer(count.intValue() + 1));
					} else {
						map2.put(current, new Integer(1));
						System.out.println("Count: " + map2.get(current));
					}
				//}
			}
			for (int i = 0; i < plaintext.length() - 3; i++) {
				if (plaintext.substring(i, i + 1).equals(" ")) {
					i += 1;
				} else if (plaintext.substring(i + 1, i + 2).equals(" ")) {
					i += 2;
				} else if (plaintext.substring(i + 2, i + 3).equals(" ")) {
					i += 2;
				}
				current = plaintext.substring(i, i + 3);
				//System.out.println("Current: " + current);
				if (!current.equals(" ") && !current.equals(",") && !current.equals(".")) {
					if (map3.containsKey(current)) {
						count = map3.get(current);
						map3.remove(current);
						map3.put(current, new Integer(count.intValue() + 1));
					} else {
						map3.put(current, new Integer(1));
					}
				}
			}
			bigrams.addAll(map2.keySet());
			trigrams.addAll(map3.keySet());
			for (int i = 0; i < 26; i++) {
				currChar = Character.toChars(i + 65);
				String ch = new String(currChar);
				System.out.println(ch + ": " + map.get(ch));
			}
			System.out.println("----------------------------");
			for (int i = 0; i < bigrams.size(); i++) {
				System.out.println(bigrams.get(i) + ": " + map2.get(bigrams.get(i)));
			}
			System.out.println("----------------------------");
			for (int i = 0; i < trigrams.size(); i++) {
				System.out.println(trigrams.get(i) + ": " + map3.get(trigrams.get(i)));
			}
	
			plaintext = plaintext.replaceAll("W", "e");
			plaintext = plaintext.replaceAll("R", "t");
			plaintext = plaintext.replaceAll("Y", "h");
			plaintext = plaintext.replaceAll("K", "o");
			plaintext = plaintext.replaceAll("T", "f");
			plaintext = plaintext.replaceAll("L", "u");
			plaintext = plaintext.replaceAll("V", "r");
			plaintext = plaintext.replaceAll("Z", "i");
			plaintext = plaintext.replaceAll("P", "s");
			plaintext = plaintext.replaceAll("F", "a");
			plaintext = plaintext.replaceAll("Q", "p");
			plaintext = plaintext.replaceAll("O", "g");
			plaintext = plaintext.replaceAll("E", "l");
			plaintext = plaintext.replaceAll("U", "n");
			plaintext = plaintext.replaceAll("H", "d");
			plaintext = plaintext.replaceAll("D", "w");
			plaintext = plaintext.replaceAll("I", "c");
			plaintext = plaintext.replaceAll("G", "y");
			plaintext = plaintext.replaceAll("A", "k");
			plaintext = plaintext.replaceAll("B", "m");
			plaintext = plaintext.replaceAll("X", "b");
			plaintext = plaintext.replaceAll("J", "v");
			System.out.println(plaintext);
	
		}
	}
	```
	* Solved by writing program that counts individual characters, bigrams, and trigrams, then used that frequency data to guess towards answer, slowly but surely.
	* "THE PROGRESS OF OUR ARMS, UPON WHICH ALL ELSE CHIEFLY DEPENDS, IS AS WELL KNOWN TO THE PUBLIC AS TO MYSELF, AND IT IS, I TRUST, REASONABLY SATISFACTORY AND ENCOURAGING TO ALL. WITH HIGH HOPE FOR THE FUTURE, NO PREDICTION IN REGARD TO IT IS VENTURED"
4. Problem 4
	(Mess Bifid Solver)
	```java
	import java.util.Map;
	import java.util.HashMap;
	import java.util.Arrays;
	
	public class BifidSolver {
	
		public static String bifid_solver(String ciphertext, String key) {
			Map<String,Integer> letters = new HashMap<String,Integer>();
			Map<Integer,String> indeces = new HashMap<Integer,String>();
			String currSubString;
			String[] initialPositions = new String[ciphertext.length() * 2];
			String[] finalPositions = new String[ciphertext.length() * 2];
			StringBuilder build;
			int currentInt;
			int index;
			String plaintext = "";
			for (int i = 0, j = 0; i < key.length(); i++) {
				if (i < key.length()) {
					currSubString = key.substring(i, i + 1);
					if (!letters.containsKey(currSubString)) {
						letters.put(currSubString, new Integer(j));
						indeces.put(new Integer(j), currSubString);
						j += 1;
					}
				}
			}
			if (letters.size() != 26) {
				for (int i = 0, j = letters.size(); letters.size() < 26; i++) {
					i += i == 9 ? 1 : 0;
					currSubString = new String(Character.toChars(65 + i));
					if (!letters.containsKey(currSubString)) {
						letters.put(currSubString, new Integer(j));
						indeces.put(new Integer(j), currSubString);
						j += 1;
					}
				}
			}
			for (int i = 0, j = 0; i < ciphertext.length() * 2; i += 2, j++) {
				currentInt = letters.get(ciphertext.substring(j, j + 1)).intValue();
				initialPositions[i] = "" + (currentInt / 5);
				initialPositions[i + 1] = "" + (currentInt % 5);
			}
			for (int i = 0, j = 0; j < ciphertext.length(); i += 2, j++) {
				finalPositions[i] = initialPositions[j];
				finalPositions[i + 1] = initialPositions[j + (ciphertext.length())];
				index = (Integer.parseInt(finalPositions[i]) * 5) + Integer.parseInt(finalPositions[i + 1]);
				plaintext += indeces.get(new Integer(index));
			}
	
			return plaintext;
		}
	
		public static void main(String[] args) {
			System.out.println(bifid_solver(args[0], args[1]));
	
		}
	}
	```
	* D A R N O
	* T H E C Y
	* P L S J Q
	* U B F G K
	* M V W X Z

	* 10423110212101122004001030311042311021100021000041220303111212102122
	* 34000022233233232340422114003400002220113120243404321140002122340222

	* COMPUTERSCIENCEISNOMOREABOUTCOMPUTERSTHANASTRONOMYISABOUTTELESCOPESS
5. Problem 5
	* N = (23847623789462398745236743254827634647 * 80147623789462398745236743254827634711) = 1911330379750465988511865475607817924950038631764482538080744390093883432017
	* e = 7
	* Public Key: (1911330379750465988511865475607817924950038631764482538080744390093883432017, 7)
	* d = 546094394214418853860532993030805121384583824053016497311505972452636617903
	* Private Key: (1911330379750465988511865475607817924950038631764482538080744390093883432017, 546094394214418853860532993030805121384583824053016497311505972452636617903)
6. Problem 6
	* 729880581317 = (822893 * 886969) = (p - 1)(q - 1)
	* N = 729882291180
	* d = 291952232527
	* Private Key: (729882291180, 291952232527)
7. Problem 7
	* a) To verify that a certain message came from someone who is not an adversary trying to cause miscommunication.
	* b) Given (N,e), one can simply check to see if s<sup>e</sup> (mod N) = m
	* c) "code" {o:4, e:2, c:3, d:1}
	* p = 11
	* q = 13
	* e = 7
	* N = pq = 143
	* D = invMod(7, 120) = 103
	* Public Key = (143, 7)
	* Private Key = (143, 103)
	* Encoded: {3^103 (mod 143), 4^103 (mod 143), 1^103 (mod 143), 2^103 (mod 143)] = {16, 108, 1, 63}
	* Check: {16^7 (mod 143), 108^7 (mod 143), 1^7 (mod 143), 63^7 (mod 143)} = {3, 4, 1, 2}
	* d)
	* e = 17
	* (p - 1)(q - 1) = 391
	* p = 17
	* q = 23
	* (p - 1)(q - 1) = 22 * 16 = 352
	* invMod(17, 352) = 145
8. Problem 8
	* a) Signing anything will give Eve Bob's secret key to Eve (since signing involves the use of d). Eve can then use that value and pq known from Bob's public key to decode any messages sent or received by Bob.
	* b) Given that Eve knows the public key (N, e), she can use m^e (mod N) on the message from Alice. She can then pick a value b coprime to N and use that to calculate b^e (mod N) and multiply the cipher text by it (making it seem random). Bob then signs the seemingly random message and Even can continue to compute d = invMod(b, N) and then multiply the signed ciphertext by b^e (mod N) and decrypt the message.
9. Problem 9
	* This involves the master theorem. Applied to the question, t(n) = 2T(n / 2) + 1. This is a linear function since log(2)(2) = 1. The program prints n - 1 lines.
10. Problem 10
	* a) Our base cases are:
	* size 0 = no majority element;
	* size 1 = majority element is the only element;
	* If we recursively split our array into two smaller arrays, we can reach our base cases and "merge sort" back up to find the majority element of the whole array.
	* b) If there exists a majority element e such that e exists in more than half of the indeces of an array of length n, then it is guaranteed that over pairs of elements, at least 1 pair will have duplicate elements, leading to the conclusion that e is indeed the majority element within the array. With this procedure, there are at most n / 2 elements left since there is a possibility that every pair has duplicate elements, leaving only 1 from each of n / 2 pairs, aka n / 2 elements.
	
	
