package multithreaded;

import game.GamePlay;
import utils.General;

public class UserInputThread extends Thread {
	private GamePlay game;

	public UserInputThread(GamePlay game) {
		this.game = game;
	}

	public void run() {
		game.query = General.sc.nextLine();
		System.out.println(game.query);
		if (game.query.equals("exit")) {
			game.gameOver = true;
		} else {
			game.attemptOrder(game.query);
		}
	}

}
