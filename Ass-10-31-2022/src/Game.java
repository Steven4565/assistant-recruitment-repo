

public class Game extends Log{
	Pokemon player;
	Pokemon enemy;
	GameData data;
	int moneyReward;
	boolean gameOver;
	
	// difficulty is from 0 to 2
	public Game(GameData data, Pokemon player, float difficulty) {
		float addMultiplier = 0.7f + (0.3f) * (difficulty+1);
		float reduceMultiplier = 1.3f - (0.3f) * (difficulty+1);
		
		this.player = new Pokemon(player.pokemonType, player.health, (int)(player.attack * reduceMultiplier));
		this.enemy = new Pokemon("enemy", (int)(70 * addMultiplier), 20);
		
		this.data = data;
		this.moneyReward = (int)(50 * reduceMultiplier);
		
		this.gameOver = false;
	}
	
	
	public boolean start() {
		 while(!this.gameOver) {
			 this.printState();
			 
			 // Player's turn
			 int action = this.inputAction();
			 switch (action) {
			 case 1:
				 if (Utils.get5050() == 1)  {
					 player.attack(enemy);	
					 log("JokeMon damaged enemy " + player.attack + " damage!");
				 } else {
					 log("JokeMon didn't damage enemy");
				 }
				 log("Press ENTER to continue");
				 Utils.sc.nextLine();
				 
				 // enemy turn
				 if (!checkGameOver()) {
					 this.enemyAttack();
				 }
				 break;
			 case 2:
				 if (this.data.money >= 90) {
					 this.data.money -= 90;
					 this.gameOver = true;
					 log("You escaped the game");
					 log("Your money is deducted by 90");

					 // enemy turn
					 if (!checkGameOver()) {
						 this.enemyAttack();
					 }
				 } else {
					 log("Unable to escape. You need 90 jokedollar to escape.");
				 }
				 log("Press ENTER to continue");
				 Utils.sc.nextLine();
				 
				 break;
			 case 3:
				 // use item
				 break;
			 }
			 
	
		 }
		 return true;
	}
	
	public void enemyAttack() {
		 if (Utils.get5050() == 1)  {
			 enemy.attack(player);	
			 log("Enemy damaged player for" + enemy.attack + " damage!");
		 } else {
			 log("Enemy didn't damage player");
		 }
		 log("Press ENTER to continue");
		 Utils.sc.nextLine();
	}
	
	public void printState() {
		log("----------------------");
		log("             Your turn");
		log("Jokemon health : " + this.player.health);
		log("Jokemon attack : " + this.player.attack);
		log("Enemy health   : " + this.enemy.health);
		log("Enemy attack   : " + this.enemy.attack);
		log("Money          : " + this.data.money);
	}
	
	public int inputAction() {		
		String[] actionChoice = {"Attack enemy", "Escape", "Use item"};
		int choice = 0;
		do {
			log("");
			Utils.printMenu(actionChoice);
			System.out.print(">> ");
			choice = Utils.sc.nextInt();
			Utils.sc.nextLine();
		} while (!Validator.inputValidator(new Integer[] {1,2,3}, choice));
		
		return choice;
	}
	
	public boolean checkGameOver() {
		if (enemy.health <= 0) {
			log("Congrats, you won.");
			log(this.moneyReward + " is added to your wallet,");
			log("Press ENTER to continue");
			this.data.money += this.moneyReward;
			Utils.sc.nextLine();
			this.gameOver = true;
			return true;
		}
		
		if (player.health <= 0) {
			log("You have lost the game.");
			log("Press ENTER to continue");
			Utils.sc.nextLine();
			this.gameOver = true;
			return true;
		}
		return false;
	}

}
