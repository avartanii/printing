# Homework 4
## 3 May 2016

1. Problem 1
	```java
	import java.util.HashSet;
  import java.util.HashMap;
  import java.util.ArrayList;
  import java.util.Arrays;
  import java.util.LinkedList;

  public class PouringWater {

	  private static HashSet<Node> usedNodes = new HashSet<Node>();
	  private static final int TEN_CAPACITY = 10;
	  private static final int SEVEN_CAPACITY = 7;
	  private static final int FOUR_CAPACITY = 4;
	  private static final int NUMBER_OF_POSSIBLE_CHILDREN = 12;
	  private static final int TOTAL_AMOUNT = 11;

	  static class Node {

  		private Node[] children;
		  private int tenAmount;
		  private int sevenAmount;
		  private int fourAmount;
		  ArrayList<String> stepsTaken;

		  public Node(int ten, int seven, int four) {
  			this.tenAmount = ten;
			  this.sevenAmount = seven;
			  this.fourAmount = four;
			  this.stepsTaken = new ArrayList<String>();
			  this.children = new Node[NUMBER_OF_POSSIBLE_CHILDREN];
		  }

		  public Node(int ten, int seven, int four, ArrayList<String> stepsSoFar) {
  			this.tenAmount = ten;
			  this.sevenAmount = seven;
			  this.fourAmount = four;
			  this.stepsTaken = new ArrayList<String>(stepsSoFar);
			  this.children = new Node[NUMBER_OF_POSSIBLE_CHILDREN];
		  }

		  public int getTenAmount() {
  			return this.tenAmount;
		  }

		  public int getSevenAmount() {
  			return this.sevenAmount;
		  }

		  public int getFourAmount() {
  			return this.fourAmount;
		  }

		  public Node[] getChildren() {
  			return this.children;
	  	}

		  public void addStep(String step) {
  			this.stepsTaken.add(step);
		  }

  		public ArrayList<String> getStepsTaken() {
			  return this.stepsTaken;
		  }

		  public void createChildren() {
			  Node temp;

  			int roomInTen = TEN_CAPACITY - this.tenAmount;
			  int roomInSeven = SEVEN_CAPACITY - this.sevenAmount;
			  int roomInFour = FOUR_CAPACITY - this.fourAmount;
			  int newTen = 0;
			  int newSeven = 0;
			  int newFour = 0;
			  String step = "";
			  for (int i = 0; i < NUMBER_OF_POSSIBLE_CHILDREN; i++) {
  				switch (i) {
	  				case 0: newTen = this.tenAmount - roomInSeven > 0 ? this.tenAmount - roomInSeven : 0;
							  newSeven = this.sevenAmount + this.tenAmount - newTen;
							  newFour = this.fourAmount;
							  step = "T: (10, 7)";
							  break;
					  case 1: newTen = this.tenAmount - roomInFour > 0 ? this.tenAmount - roomInFour : 0;
							  newSeven = this.sevenAmount;
							  newFour = this.fourAmount + this.tenAmount - newTen;
							  step = "T: (10, 4)";
							  break;
					  case 2: newSeven = this.sevenAmount - roomInTen > 0 ? this.sevenAmount - roomInTen : 0;
							  newTen = this.tenAmount + this.sevenAmount - newSeven;
							  newFour = this.fourAmount;
							  step = "T: (7, 10)";
							  break;
					  case 3: newSeven = this.sevenAmount - roomInFour > 0 ? this.sevenAmount - roomInFour : 0;
							  newTen = this.tenAmount;
							  newFour = this.fourAmount + this.sevenAmount - newSeven;
							  step = "T: (7, 4)";
							  break;
					  case 4: newFour = this.fourAmount - roomInTen > 0 ? this.fourAmount - roomInTen : 0;
							  newTen = this.tenAmount + this.fourAmount - newFour;
							  newSeven = this.sevenAmount;
							  step = "T: (4, 10)";
							  break;
					  case 5: newFour = this.fourAmount - roomInSeven > 0 ? this.fourAmount - roomInSeven : 0;
							  newTen = this.tenAmount;
							  newSeven = this.sevenAmount + this.fourAmount - newFour;
							  step = "T: (4, 7)";
							  break;
					  case 6: newTen = 0;
							  step = "E: (10)";
					  case 7: newSeven = 0;
						  	step = "E: (7)";
					  case 8: newFour = 0;
							  step = "E: (4)";
					  case 9: newTen = 10;
							  step = "F: (10)";
					  case 10:newSeven = 7;
						  	step = "F: (7)";
					  case 11:newFour = 4;
							  step = "F: (4)";
				  }
				  temp = new Node(newTen, newSeven, newFour, this.stepsTaken);
				  temp.addStep(step);
				  if (!usedNodes.contains(temp)) {
  					usedNodes.add(temp);
					  this.children[i] = temp;
				  }
			  }
		  }

		  public String toString() {
  			return "(" + this.tenAmount + ", " + this.sevenAmount + ", " + this.fourAmount + ")";
	  	}

		  public int hashCode() {
  			final int prime = 11;
			  int result = 1;
			  result = prime * result + this.tenAmount;
			  result = prime * result + this.sevenAmount;
			  result = prime * result + this.fourAmount;
			  return result;
		  }

		  public boolean equals(Object obj) {
  			if (obj instanceof Node) {
				  Node n = (Node) obj;
				  return this.tenAmount == n.getTenAmount() && this.sevenAmount == n.getSevenAmount() && this.fourAmount == n.getFourAmount();
			  }
			  return false;
		  }
	  }

  	public static String pour() {
		  Node firstNode = new Node(0, 7, 4);
		  Node currentNode = firstNode;
		  LinkedList<Node> backtrackNodes = new LinkedList<Node>();
		  boolean found = false;
		  usedNodes.add(firstNode);
		  backtrackNodes.add(firstNode);

  		while (!found) {
			  currentNode = backtrackNodes.poll();
			  currentNode.createChildren();
			  for (int i = 0; i < NUMBER_OF_POSSIBLE_CHILDREN; i++) {
  				if (currentNode.children[i] != null) {
	  				if (currentNode.children[i].getSevenAmount() == 2 || currentNode.children[i].getFourAmount() == 2) {
		  				currentNode = currentNode.children[i];
			  			found = true;
				  	} else {
						  backtrackNodes.add(currentNode.children[i]);
					  }
				  }
			  }
		  }
		  return Arrays.toString(currentNode.getStepsTaken().toArray());
	  }

	  public static void main(String[] args) {
  		System.out.println(pour());
  	}
  }
  ```

2. Problem 2
  a)
  
  | A: 0 | C: ∞ | D: ∞ |
  |------|------|------|
  | B: 1 | G: ∞ | H: ∞ |
  | E: 4 |......|......|
  | F: 8 |......|......|
  
  | A: 0 | C: 3 | D: ∞ |
  |------|------|------|
  | B: 1 | G: 7 | H: ∞ |
  | E: 4 |......|......|
  | F: 7 |......|......|
  
  | A: 0 | C: 3 | D: 4 |
  |------|------|------|
  | B: 1 | G: 5 | H: ∞ |
  | E: 4 |......|......|
  | F: 7 |......|......|
  
  | A: 0 | C: 3 | D: 4 |
  | B: 1 | G: 5 | H: 6 |
  | E: 4 |......|......|
  | F: 7 |......|......|
  
  b)
  
  (A) ---1---> (B) ---2---> (C) ---1---> (D)
  
   |............|............|
   
   |............|............|
   
   4............6............2
   
   |............|............|
   
   V............V............V
   
  (E)..........(F)..........(G) ---1---> (H)
  
	
3. Problem 3
  a)

  +------+------+------+------+------+------+------+------+------+------+
  
  | S: 0 | A: 7 | B:11 | C: 6 | D: 8 | E: 6 | F: 5 | G: 9 | H: 7 | I: 8 |
  
  +------+------+------+------+------+------+------+------+------+------+
  
  | S: 0 | A: 7 | B:11 | C: 5 | D: 7 | E: 6 | F: 4 | G: 8 | H: 7 | I: 8 |
  
  +------+------+------+------+------+------+------+------+------+------+
  
  | S: 0 | A: 7 | B:11 | C: 5 | D: 7 | E: 6 | F: 4 | G: 8 | H: 7 | I: 7 |
  
  +------+------+------+------+------+------+------+------+------+------+
  
  | S: 0 | A: 7 | B:11 | C: 5 | D: 7 | E: 6 | F: 4 | G: 8 | H: 7 | I: 7 |
  
  +------+------+------+------+------+------+------+------+------+------+
  
  *b)
  
      S
      
     / \
     
    A   E
    
   / \   \
   
  B   C   F
  
  |   |
  
  H   D
  
  |
  
  G
  
  |
  
  I

4. Problem 4

  *Apply Dijkstra's algorithm with an additional parameter (number of edges) and prioritize lower cost over shorter trip

5. Problem 5

   * Incomplete

6. Problem 6
	```java
	import java.util.Arrays;

	public class SubsetSum {

		public static int[] findSubset(int[] set, int sum) {
			if (sum < 0) {
				return new int[0];
			}
			Arrays.sort(set);
			int firstVal = set.length > 0 ? set[set.length - 1] : 0;
	
			int[] addends;
			int possibleAddends = 0;
			for (int i = 0; i < set.length && set[i] <= sum; i++) {
				possibleAddends += 1;
			}

			if (possibleAddends == 0) {return new int[0];}

			addends = new int[possibleAddends];

			for (int i = 0; i < possibleAddends; i++) {
				addends[i] = set[i];
			}

			int firstAddend = addends[addends.length - 1];

			if (sum(addends) == sum) {
				return addends;
			} else if (set.length <= 1) {
				return new int[0];
			}

			int[] subtracted = findSubset(Arrays.copyOf(addends, addends.length - 1), sum - firstAddend);
			int[] removed = findSubset(Arrays.copyOf(addends, addends.length - 1), sum);

			if (sum(subtracted) + firstAddend == sum) {
				int[] firstAddendArray = new int[]{firstAddend};
				return concat(firstAddendArray, subtracted);
			} else {
				return removed;
			}
		}

		public static int sum(int[] addends) {
			int sum = 0;
			for (int i = 0; i < addends.length; i++) {
				sum += addends[i];
			}
			return sum;
		}

		public static int[] concat(int[] a1, int[] a2) {
			int[] combination = new int[a1.length + a2.length];
			for (int i = 0; i < a1.length; i++) {
				combination[i] = a1[i];
			}
			for (int i = 0; i < a2.length; i++) {
				combination[i + a1.length] = a2[i];
			}
			return combination;
		}

		public static void main(String[] args) {
			int[] set = new int[args.length - 1];
			int sum = Integer.parseInt(args[args.length - 1]);
			for (int i = 0; i < set.length; i++) {
				set[i] = Integer.parseInt(args[i]);
			}
			int[] subset = findSubset(set, sum);
			System.out.println(subset.length > 0 ? Arrays.toString(subset) : "No subset found");
		}
	}
	```java

7. Problem 7
	```java
	import java.util.Arrays;

public class Changer extends SubsetSum {

	private int[] coins;
	
	public Changer(int[] denominations) {
		this.coins = denominations;
	}

	public int[] can_make_change_for(int amount) {
		int[] moreCoins = this.coins;
		while (sum(moreCoins) < this.coins.length * amount) {
			moreCoins = concat(moreCoins, this.coins);
		}
		return findSubset(moreCoins, amount);
	}

	public int[] can_make_change_using_each_coin_once(int amount) {
		return findSubset(this.coins, amount);
	}

	public int[] can_make_change_with_limited_coins(int amount, int maxCoins) {
		int[] moreCoins = this.coins;
		while (sum(moreCoins) < this.coins.length * amount) {
			moreCoins = concat(moreCoins, this.coins);
		}
		int[] change = findSubset(moreCoins, amount);
		while (change.length > maxCoins) {
			moreCoins = Arrays.copyOf(moreCoins, moreCoins.length - 1);
			change = findSubset(moreCoins, amount);
		}
		return change.length <= maxCoins ? change : new int[0];
	}

	public static void main(String[] args) {
		int[] coins = new int[args.length - 1];
		int amount = Integer.parseInt(args[args.length - 1]);
		for (int i = 0; i < coins.length; i++) {
			coins[i] = Integer.parseInt(args[i]);
		}
		Changer change = new Changer(coins);
	}
}
```
