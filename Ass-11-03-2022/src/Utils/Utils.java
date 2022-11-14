package Utils;

import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

public class Utils extends Log {
	public static Scanner sc;
	public static Random rand;
	static {
		sc = new Scanner(System.in);
		rand = new Random();
		rand.setSeed(System.nanoTime());
	};

	public static int inputInt(String errMsg) {
		boolean valid = false;
		int input = 0;
		do {
			try {
				input = sc.nextInt();
				valid = true;
			} catch (Exception e) {
				System.out.println(errMsg);
			}
			sc.nextLine();
		} while (!valid);
		return input;
	}

	public static void getEnter() {
		log("Press ENTER to continue");
		sc.nextLine();
		for (int i = 0; i < 10; i++) {
			log("");
		}
	}

	public static int getRandRange(int min, int max) {
		int res = rand.nextInt(max + 1) + min;
		return res;
	}

	public static boolean get5050() {
		int res = rand.nextInt(2);
		return (res == 1 ? true : false);
	}

	private static void merge(ArrayList<ArrayList<String>> table, int l, int m, int r) {
		int leftSize = m - l + 1;
		int rightSize = r - m;

		ArrayList<ArrayList<String>> left = new ArrayList<ArrayList<String>>();
		ArrayList<ArrayList<String>> right = new ArrayList<ArrayList<String>>();

		for (int i = 0; i < leftSize; i++) {
			left.add(table.get(i + l));
		}
		for (int i = 0; i < rightSize; i++) {
			right.add(table.get(m + 1 + i));
		}

		// Indices for left, right, and table
		int il = 0;
		int ir = 0;
		int iTable = l;
		while (il < leftSize && ir < rightSize) {
			int compareRes = left.get(il).get(0).compareTo(right.get(ir).get(0));
			if (compareRes < 0) { // left smaller
				// replace left
				table.set(iTable, left.get(il));
				il++;
			} else {
				// replace right
				table.set(iTable, right.get(ir));
				ir++;
			}
			iTable++;
		}

		while (il < leftSize) {
			table.set(iTable, left.get(il));
			il++;
			iTable++;
		}

		while (ir < rightSize) {
			table.set(iTable, right.get(ir));
			ir++;
			iTable++;
		}
	}

	public static void mergeSort(ArrayList<ArrayList<String>> table, int l, int r) {
		if (l == r)
			return;

		int middle = l + (r - l) / 2;
		mergeSort(table, l, middle);
		mergeSort(table, middle + 1, r);
		merge(table, l, middle, r);
	}

}
