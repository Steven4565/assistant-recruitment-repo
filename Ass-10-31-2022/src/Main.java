//import java.util.*;

public class Main extends Log{
	public static String username;
	static GameData data;
	static boolean runProgram;

	public Main() {
		data = new GameData(100, 0 , 0);
		runProgram = true;
	}
	
	public static void main(String[] args) {
		new Utils();
		new Main();
		
		log("JokeMon");
		log("==================");
		log("");
		
		do {
			System.out.print("Input username (min 2 words): ");
			username = Utils.sc.nextLine();
		} while (!Validator.usernameValidator(username));
		log("Welcome, " + username);
		
		do {
			runMenu();
		} while (runProgram);
		
		
		Utils.sc.close();
	}
	
	static void runMenu() {
		String[] options = {"Play", "Shop", "Quit"};
		int input;
		do {
			Utils.printMenu(options);
			input = Utils.sc.nextInt();
					Utils.sc.nextLine();
		} while (!Validator.inputValidator(new Integer[] {1,2,3}, input));
		
		log(input + "");
		
		switch (input) {
		case 1:
			playGame();
			break;
		case 2:
			openShop();
			break;
		case 3:
			runProgram = false;
			log("Exitted. Press enter to continue");
			Utils.sc.nextLine();
		}
	}
	
	static void playGame() {
		String[] pokemonOptions = {"Charmander (hp: 100, atk: 20)", 
				            "Squirtle (hp: 70, atk: 40)", 
				            "Bulbasaur (hp: 200, atk: 10"};
		int pokeType;
		do {
			log("-------------");
			log("Choose 1 JokeMon");
			Utils.printMenu(pokemonOptions);
			System.out.print("Input only 1 to 3: ");
			pokeType = Utils.sc.nextInt();
					Utils.sc.nextLine();
		} while (!Validator.inputValidator(new Integer[] {1,2,3}, pokeType));
		
		String[] difficultyOptions = {"Easy", "Medium", "Difficult"};
		int chosenDiff = 0;
		String diffInput;
		do {
			log("-------------");
			log("Choose difficulty");
			Utils.printMenu(difficultyOptions);
			System.out.print("Input only Easy, Medium, or Difficult (case sensitive): ");
			diffInput = Utils.sc.nextLine();
			diffInput = diffInput.trim();
			if (diffInput.equals("Easy")) {
				chosenDiff = 0;
			} else if (diffInput.equals("Medium")) {
				chosenDiff = 1;
			} else if (diffInput.equals("Difficult")) {
				chosenDiff = 2;
			}
		} while (!Validator.inputValidator(new String[] {"Easy", "Medium", "Difficult"}, diffInput));
		
		
		Pokemon[] pokemons = {new Pokemon("Charmander", 100, 20), 
							  new Pokemon("Squirtle", 70, 40), 
							  new Pokemon("Bulbasaur", 200, 10)};
		
		
		pokeType--;
		Game game = new Game(data, pokemons[pokeType], chosenDiff);
		game.start();
	}
	
	static void openShop() {
		
	}

}
