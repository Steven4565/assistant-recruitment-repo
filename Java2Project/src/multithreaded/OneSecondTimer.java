package multithreaded;

import game.GamePlay;
import utils.General;

public class OneSecondTimer extends Thread {
	private GamePlay game;

	public OneSecondTimer(GamePlay game) {
		this.game = game;
	}

	public void run() {
		while (!game.gameOver) {
			game.reduceCustomerPatience();
			if (General.getRandRange(1, 10) == 1) {
				game.addCustomer();
			}
			game.render();
			game.handleGame();
			game.addTime();

			try {
				Thread.sleep(1000);
			} catch (InterruptedException e) {
				e.printStackTrace();
			}
		}
	}
}
