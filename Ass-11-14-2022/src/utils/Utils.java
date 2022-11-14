package utils;

import java.util.ArrayList;
import java.util.Random;
import java.util.Scanner;

import interfaces.StringComparable;

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

	private static void merge(ArrayList<ArrayList<String>> table, int l, int m, int r, int colIndex,
			StringComparable comparator) {
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
			boolean compareRes = comparator.compare(left.get(il).get(colIndex), right.get(ir).get(colIndex));
			if (compareRes) {
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

	private static void mergeSort(ArrayList<ArrayList<String>> table, int l, int r, int colIndex,
			StringComparable comparator) {
		if (l == r)
			return;

		int middle = l + (r - l) / 2;
		mergeSort(table, l, middle, colIndex, comparator);
		mergeSort(table, middle + 1, r, colIndex, comparator);
		merge(table, l, middle, r, colIndex, comparator);
	}

	public static void sort(ArrayList<ArrayList<String>> table, int colIndex, StringComparable comparator) {
		mergeSort(table, 0, table.size() - 1, colIndex, comparator);
	}

}
