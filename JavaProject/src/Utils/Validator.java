package Utils;

import Interfaces.IntValidateable;
import Interfaces.StringValidateable;

public class Validator extends Log {

	public static <T> boolean validateOptions(T options[], T input) {
		for (int i = 0; i < options.length; i++) {
			if (options[i].equals(input)) {
				return true;
			}
		}

		return false;
	}

	public static String getInputLine(StringValidateable validator, String[] menus, String prompt) {
		String input;
		do {
			PrintUtils.printMenu(menus);
			logr(prompt);
			input = Utils.sc.nextLine();
		} while (!validator.validate(input));
		return input;
	}

	public static Integer getInputInt(IntValidateable validator, String[] menus, String prompt) {
		Integer input = 0;
		do {
			PrintUtils.printMenu(menus);
			logr(prompt);
			input = Utils.inputInt("Please input an integer");
		} while (!validator.validate(input));
		return input;
	}

	public static Integer getInputInt(int min, int max, String inputMsg) {
		Integer input = 0;
		do {
			log(inputMsg);
			logr(">> ");
			input = Utils.inputInt("Please input an integer");
		} while (!(input.intValue() >= min && input.intValue() <= max));
		return input;
	}

	public static Integer getInputInt(IntValidateable validator, String inputMsg) {
		Integer input = 0;
		do {
			log(inputMsg);
			log(">> ");
			input = Utils.sc.nextInt();
		} while (!validator.validate(input));
		return input;
	}
}
