import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;
import java.util.stream.IntStream;


import Utils.PrintUtils;
import Utils.FileUtils;
import Utils.Log;
import Utils.Utils;

public class Main extends Log{

	public static void main(String[] args) {
		
		boolean endProgram = false;
		while (!endProgram) {
			String[] menuMessage = new String[] {"Add car to repair list", "Repair car", "Take out car", "Exit"};
			Integer menuInput = Validator.getInputInt((i) -> Validator.validateOptions(new Integer[] {1, 2, 3, 4}, i), menuMessage);
						
			
			switch (menuInput) {
			case 1:
				addCar();
				break;
			case 2:
				repairCar();
				break;
			case 3:
				takeCar();
				break;
			case 4:
				endProgram = true;
				log("Program Exitted");
				Utils.getEnter();
				break;
			}
		}
	}
	
	public static void addCar() {
		String[] inputMessages = {"Input car's owner [starts with 'Mr.' / 'Mrs.']: ", 
								  "Input car's name [>= 3 chars]: ",
								  "Input car's brand [>= 5 chars]: ",
								  "Input car's type [Sedan, Coupe, SUV] (case sensitive): "};
		
		String owner = Validator.getInputLine((i) -> (i.startsWith("Mr. ") || i.startsWith("Mrs. ") ? true : false), inputMessages[0]);
		String carName = Validator.getInputLine((i) -> (i.length() >= 3 ? true : false), inputMessages[1]);
		String brand = Validator.getInputLine((i) -> (i.length() >= 5 ? true : false), inputMessages[2]);
		String type = Validator.getInputLine((i) -> Validator.validateOptions(new String[] {"Sedan", "Coupe", "SUV"}, i), inputMessages[3]);
		
		String[] entry = {owner, carName, brand, type};
		FileUtils.writeEntry("reparationList.txt", String.join(";", entry));
		
		log("Successfully added car to list!");
		Utils.getEnter();
	}
	
	public static void repairCar() {
		String path = "reparationList.txt";
		String delim = ";";
		
		// Get table
		ArrayList<ArrayList<String>> table = FileUtils.readEntries(path, delim);
		if (table.size() <= 0) {
			log("No car in the repair list");
			Utils.getEnter();
			return;
		}
		
		// Print table
		log("BWengkel Car's list");
		PrintUtils.printTable(table);
		log("");
		
		// Input index
		String inputMsg = "Choose car's index to be repaired ['0' to go back]: ";		
		Integer[] inputOptions = IntStream.range(0, table.size()+1).boxed().toArray(Integer[]::new);
		Integer index = Validator.getInputInt((i) -> Validator.validateOptions(inputOptions, i), inputMsg);
		log("input : " + index);
		if (index == 0) {
			log("No index is inputted");
			Utils.getEnter();
			return;
		}
		
		// Get entry by index 
		ArrayList<String> entry = FileUtils.findEntry(path, delim, index-1);
		String owner = entry.get(0);
		String carName = entry.get(1);
		String brand = entry.get(2);
		String type = entry.get(3);
		
		int typePrice;
		if (type.equals("Sedan")) typePrice = 50000;
		else if (type.equals("Coupe")) typePrice = 30000;
		else typePrice = 45000;
		
		long reparationTime = (long)Utils.getRandRange(1, 10);
		log(reparationTime + "");
		Utils.getEnter();
		long reparationCost = (long)Utils.getRandRange(10000, 50000) + reparationTime * (long)typePrice;
		log("The car took " + reparationTime + " days and cost " + reparationCost);
		Utils.getEnter();
		
		// Delete entry by index
		FileUtils.deleteEntry(path, delim, index-1);
		
		// Input new entry
		String[] newEntry = {owner, carName, brand, type, String.valueOf(reparationCost), String.valueOf(reparationTime) + " days"};
		log(String.join(delim, newEntry));
		Utils.getEnter();
		FileUtils.writeEntry("takeCarList.txt", String.join(delim, newEntry));
	}
	
	public static void takeCar() {
		String path = "takeCarList.txt";
		String delim = ";";
		
		// Get table
		ArrayList<ArrayList<String>> table = FileUtils.readEntries(path, delim);
		if (table.size() <= 0) {
			log("No car repaired");
			Utils.getEnter();
			return;
		}
		
		// Print table
		log("BWengkel repaired car list");
		PrintUtils.printTable(table);
		log("");
		
		// Input index
		String inputMsg = "Choose car's index to be repaired ['0' to go back]: ";		
		Integer[] inputOptions = IntStream.range(0, table.size()+1).boxed().toArray(Integer[]::new);
		Integer index = Validator.getInputInt((i) -> Validator.validateOptions(inputOptions, i), inputMsg);
		log("input : " + index);
		if (index == 0) {
			log("No index is inputted");
			Utils.getEnter();
			return;
		}
		
		log("Transaction succeeded");
		Utils.getEnter();
		
		// Delete entry by index
		FileUtils.deleteEntry(path, delim, index-1);
	}
	
	
}
