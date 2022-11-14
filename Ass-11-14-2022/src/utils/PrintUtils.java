package utils;

import java.util.ArrayList;

public class PrintUtils extends Log {
	public static void printTable(ArrayList<ArrayList<String>> table, int maxEntryLength, String[] colLabels,
			boolean useNumbers) {
		// Table width
		int tableWidth = 1;
		tableWidth += (maxEntryLength + 1) * table.get(0).size();
		tableWidth += (useNumbers ? 6 : 0);

		// Print top border
		for (int i = 0; i < tableWidth; i++) {
			logr("-");
		}
		log("");

		// Print the column names
		logr("|");
		if (useNumbers) {
			System.out.printf("%5s|", "No");
		}
		for (String label : colLabels) {
			System.out.printf("%" + maxEntryLength + "s|", label);
		}
		log("");

		// Print middle border
		for (int i = 0; i < tableWidth; i++) {
			logr("-");
		}
		log("");

		// Print the data
		for (int i = 0; i < table.size(); i++) {
			String formattedRow = "|";

			if (useNumbers) {
				formattedRow += String.format("%5s|", "" + (i + 1));
			}

			for (String entry : table.get(i)) {
				formattedRow += String.format("%" + maxEntryLength + "s|", entry);
			}
			log(formattedRow);
		}

		// print bottom border
		for (int i = 0; i < tableWidth; i++) {
			logr("-");
		}
		log("");
	}

	public static void printMenu(String menus[]) {
		for (int i = 0; i < menus.length; i++) {
			log(i + 1 + ". " + menus[i]);
		}
	}
}
