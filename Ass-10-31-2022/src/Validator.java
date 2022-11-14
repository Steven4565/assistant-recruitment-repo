
public class Validator extends Log {
	
	static <T> boolean inputValidator(T options[], T input) {
		for (int i = 0; i < options.length; i++) {
			if (options[i].equals(input)) {	
				return true;
			}
		}
		
		return false;
	}
	
	public static boolean usernameValidator(String input) {
		if (input.contains(" ")) {
			return true;
		}
		return false;
	}
}
