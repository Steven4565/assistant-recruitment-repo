package utils;

import java.util.ArrayList;
import java.util.Arrays;

import interfaces.IntValidateable;
import interfaces.StringValidateable;
import interfaces.VoidSam;

public class Input extends Log {

	public static <T> boolean validateOptions(T options[], T input) {
		for (int i = 0; i < options.length; i++) {
			if (options[i].equals(input)) {
				return true;
			}
		}

		return false;
	}

	public static boolean pageInput(String title, String[] options, VoidSam[] functions) {
		int length = options.length;
		for (int i = 0; i < length; i++) {
			logr((i + 1) + ". ");
			log(options[i]);
		}
		int input = getInputInt(1, length, "");

		functions[input - 1].invoke();
		if (input == length) {
			return false;
		}
		return true;
	}

	public static int inputInt(String errMsg) {
		boolean valid = false;
		int input = 0;
		do {
			try {
				input = General.sc.nextInt();
				valid = true;
			} catch (Exception e) {
				System.out.println(errMsg);
			}
			General.sc.nextLine();
		} while (!valid);
		return input;
	}

	public static String getInputMenuLine(StringValidateable validator, String[] menus, String prompt) {
		String input;
		do {
			Print.printMenu(menus);
			logr(prompt);
			input = General.sc.nextLine();
		} while (!validator.validate(input));
		return input;
	}

	public static String getInputLine(StringValidateable validator, String prompt) {
		String input;
		do {
			logr(prompt);
			input = General.sc.nextLine();
		} while (!validator.validate(input));
		return input;
	}

	public static String getInputChoice(String[] choices, String prompt) {
		String input;
		do {
			logr(prompt);
			input = General.sc.nextLine();
		} while (!new ArrayList<>(Arrays.asList(choices)).contains(input));
		return input;
	}

	public static String getInputRestrictLength(int min, int max, String prompt) {
		String input;
		do {
			logr(prompt);
			input = General.sc.nextLine();
		} while (!((min > 0 && input.length() >= min) && (max > 0 && input.length() <= max)));
		return input;
	}

	public static Integer getInputInt(IntValidateable validator, String[] menus, String prompt) {
		Integer input = 0;
		do {
			Print.printMenu(menus);
			logr(prompt);
			input = Input.inputInt("Please input an integer");
		} while (!validator.validate(input));
		return input;
	}

	public static Integer getInputInt(int min, int max, String inputMsg) {
		Integer input = 0;
		do {
			log(inputMsg);
			logr(">> ");
			input = Input.inputInt("Please input an integer");
		} while (!(input.intValue() >= min && input.intValue() <= max));
		return input;
	}

	public static Integer getInputInt(IntValidateable validator, String inputMsg) {
		Integer input = 0;
		do {
			log(inputMsg);
			log(">> ");
			input = General.sc.nextInt();
		} while (!validator.validate(input));
		return input;
	}
}
