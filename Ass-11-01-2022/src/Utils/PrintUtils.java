package Utils;

import java.util.ArrayList;

public class PrintUtils extends Log{
	public static void printTable(ArrayList<ArrayList<String>> table) {
		for (int i = 0; i < table.size(); i++) {
			String rowString = (i + 1) + " | ";
			for (String element : table.get(i)) {
				rowString += element+ " | ";
			}
			log(rowString.trim());
		}
	}
}
