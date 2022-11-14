package Game;

import java.util.ArrayList;

import Utils.Log;
import Utils.Utils;

public class Gameplay extends Log {
	Data data;
	Horse player;
	Horse bot1;
	Horse bot2;

	String playerWon;
	ArrayList<String> winners;

	boolean gameOver;

	public Gameplay(Data data) {
		this.data = data;
		this.gameOver = false;

		int skipChance = 30 - data.shoeLv - data.leashLv;
		this.player = new Horse(40, 'P', skipChance);

		skipChance = 30 - Utils.getRandRange(0, data.shoeLv) - Utils.getRandRange(0, data.leashLv);
		this.bot1 = new Horse(40, 'B', skipChance);

		skipChance = 30 - Utils.getRandRange(0, data.shoeLv) - Utils.getRandRange(0, data.leashLv);
		this.bot2 = new Horse(40, 'B', skipChance);

		this.winners = new ArrayList<String>();

	}

	public ArrayList<String> startGame() {
		while (!this.gameOver) {
			render();
			move();
			checkGameOver();
			try {
				Thread.sleep(200);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
		ArrayList<String> results = new ArrayList<String>();
		results.add(this.playerWon);
		results.add("Your last position was " + (this.player.position + 1));
		results.add("Winner: " + String.join(", ", this.winners));
		return results;
	}

	public void render() {
		log("####################################################");
		logr("# Player  |");
		this.player.print();
		log("#");
		log("#--------------------------------------------------#");
		logr("# Bot1    |");
		this.bot1.print();
		log("#");
		log("#--------------------------------------------------#");
		logr("# Bot2    |");
		this.bot2.print();
		log("#");
		log("####################################################");
	}

	public void move() {
		this.player.move();
		this.bot1.move();
		this.bot2.move();
	}

	public void checkGameOver() {

		if (!this.player.finished() && !this.bot1.finished() && !this.bot2.finished()) {
			return;
		}

		boolean playerFinished = this.player.finished();
		boolean bot1Finished = this.bot1.finished();
		boolean bot2Finished = this.bot2.finished();
		if (playerFinished)
			this.winners.add("Player");
		if (bot1Finished)
			this.winners.add("Bot 1");
		if (bot2Finished)
			this.winners.add("Bot 2");

		int winMoney = 0;

		if (playerFinished && (bot1Finished || bot2Finished)) {
			this.playerWon = "Draw";
			log("Tied!");
			winMoney = 100 * (this.player.position + 1);
			this.gameOver = true;
		} else if (playerFinished) {
			this.playerWon = "Won";
			log("Player Won!");
			winMoney = 10000;
			this.gameOver = true;
		} else {
			this.playerWon = "Lost";
			log("Bot Won!");
			winMoney = 100 * (this.player.position + 1);
			this.gameOver = true;
		}

		this.data.bal += winMoney;
		log("You got +" + winMoney);

	}
}
