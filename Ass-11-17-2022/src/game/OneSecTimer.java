package game;

import java.util.ArrayList;

public class OneSecTimer extends Thread {
	ArrayList<Customer> customers;
	ArrayList<CookingFood> kitchen;
	ArrayList<CourierFood> courier;
	GamePlay game;
	Integer timer;

	public OneSecTimer(ArrayList<Customer> customers, ArrayList<CookingFood> kitchen, ArrayList<CourierFood> courier,
			Integer timer, GamePlay game) {
		this.customers = customers;
		this.kitchen = kitchen;
		this.courier = courier;
		this.timer = timer;
		this.game = game;
	}

	public void run() {
		for (CourierFood courierFood : this.courier) {
			if (courierFood.distance != 0) {
				courierFood.distance--;
			}
		}
		for (CookingFood cooking : this.kitchen) {
			if (cooking.cookTime != 0) {
				cooking.cookTime--;
			}
		}
		for (Customer cust : this.customers) {
			if (cust.patience != 0) {
				cust.patience--;
			}
		}

		this.timer = new Integer(this.timer.intValue() + 1);
		try {
			Thread.sleep(1000);
		} catch (InterruptedException e) {
			e.printStackTrace();
		}
		game.render();

		run();

	}

}
