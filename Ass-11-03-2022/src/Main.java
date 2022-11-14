import Utils.Log;
import Utils.Utils;
import Utils.Validator;

import java.util.ArrayList;

import Utils.FileUtils;
import Utils.PrintUtils;

public class Main extends Log {

	static boolean endProgram;
	static String filePath;
	static String delim;

	public Main() {
		endProgram = false;
		filePath = "hostvitalist.txt";
		delim = "#";
	}

	public static void main(String[] args) {
		new Main();
		log("HosVitalList");
		log("=============================");

		while (!endProgram) {
			String[] options = { "Add Patient", "View Patients", "Discharge Patient", "Exit" };
			Integer menuInput = Validator.getInputInt((i) -> Validator.validateOptions(new Integer[] { 1, 2, 3, 4 }, i),
					options);
			switch (menuInput) {
			case 1:
				addPatient();
				break;
			case 2:
				viewPatients();
				break;
			case 3:
				dischargePatients();
				break;
			case 4:
				log("Exitted program");
				Utils.getEnter();
				endProgram = true;
				break;
			}
		}
	}

	public static void addPatient() {
		String name = Validator.getInputLine((i) -> (i.startsWith("Mr. ") || i.startsWith("Mrs. ")),
				"Input Patient's name [Starts with 'Mr. ' or 'Mrs. ']: ");
		String disease = Validator.getInputLine((i) -> i.length() >= 5,
				"Input patient's disease [Must be at least 5 char long]: ");

		FileUtils.writeRow(filePath, String.join(delim, new String[] { name, disease }));

		log("Patient had been added successfully");
		Utils.getEnter();
	}

	public static void viewPatients() {
		ArrayList<ArrayList<String>> table = FileUtils.readEntries(filePath, delim);
		Utils.mergeSort(table, 0, table.size() - 1);
		if (table.size() == 0) {
			log("There are no patients");
			return;
		} else {
			PrintUtils.printTable(table, 20, new String[] { "Name", "Disease" }, true);
		}
		Utils.getEnter();
	}

	public static void dischargePatients() {
		ArrayList<ArrayList<String>> table = FileUtils.readEntries(filePath, delim);
		PrintUtils.printTable(table, 20, new String[] { "Name", "Disease" }, true);

		int query = Validator.getInputInt(1, table.size(), "Input patient number you want to discharge");
		FileUtils.deleteRow(filePath, delim, query - 1);
		log("Patient is now healthy and has been discharged");
		Utils.getEnter();
	}
}
