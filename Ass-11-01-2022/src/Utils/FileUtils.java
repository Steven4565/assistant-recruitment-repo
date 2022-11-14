package Utils;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class FileUtils extends Log{
	public static ArrayList<ArrayList<String>> readEntries(String path, String delim) {
		ArrayList<String> entryList = new ArrayList<String>();
		try {
			File handle = new File(path);
			Scanner sc = new Scanner(handle);
			
			while (sc.hasNextLine()) {
				entryList.add(sc.nextLine());
			}
			
			sc.close();
		} catch (FileNotFoundException e) {
			log("Error opening file");
		}
		
		List<ArrayList<String>> table = entryList.stream().map((entry) -> new ArrayList<String>(Arrays.asList(entry.split(delim)))).collect(Collectors.toList());
		ArrayList<ArrayList<String>> table2 = new ArrayList<ArrayList<String>>(table);
		return table2;
	}
	
	public static ArrayList<String> writeEntry(String path, String entry) {
		ArrayList<String> inputs = new ArrayList<String>();
		try {
			FileWriter fw = new FileWriter(path, true);
			fw.write(entry + "\n");
			
			fw.close();
		} catch (IOException e) {
			log("Error opening file");
		}
		
		return inputs;
	}
	
	public static void writeFile(String path, ArrayList<String> entries) {

		try { 
			FileWriter fw = new FileWriter(path, false);
			
			for (String entry: entries) {
				fw.write(entry + "\n");
			}
			
			fw.close();
		} catch (IOException e) {
			log("Error opening file");
		}
		
	}

	/*
	 * Filter entry based on a query on the (columnIndex)-th column. 
	 * @param	path 	relative URl to file directory from CWD
	 * @param	delim	String containing delimiter of the file
	 * @param	columnIndex	Index of column to be filtered
	 * @param 	StringValidateable validator function with an input string and a boolean return type 	
	 */
	public static void deleteEntry(String path, String delim, int columnIndex, Interfaces.StringValidateable validator) {
		ArrayList<ArrayList<String>> table = readEntries(path, delim);
		table = new ArrayList<ArrayList<String>> (table.stream().filter((ArrayList<String> row) -> !validator.validate(row.get(columnIndex))).collect(Collectors.toList()));
		PrintUtils.printTable(table);
		Utils.getEnter();
	}
	
	public static void deleteEntry(String path, String delim, int rowIndex) {
		ArrayList<ArrayList<String>> table = readEntries(path, delim);
		ArrayList<String> newEntries = new ArrayList<String>();
		for (int i = 0; i < table.size(); i++) {
			if (rowIndex != i) {
				String newEntry = String.join(";", table.get(i));
				newEntries.add(newEntry);
			}
		}
		FileUtils.writeFile(path, newEntries);
	}
	
	public static ArrayList<String> findEntry(String path, String delim, int rowIndex) {
		ArrayList<ArrayList<String>> table = readEntries(path, delim);
		for (int i = 0; i < table.size(); i++) {
			if (rowIndex == i) {
				return table.get(i);
			}
		}
		return new ArrayList<String>();
	}
	
	
}
