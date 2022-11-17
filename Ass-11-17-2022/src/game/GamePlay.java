package game;

import java.util.ArrayList;

import game.dishes.*;

public class GamePlay {

	ArrayList<Customer> customers;
	ArrayList<CookingFood> kitchen;
	ArrayList<CourierFood> courier;
	Integer timer = 0;
	int money;
	Thread thread;

	public GamePlay() {
		thread = new Thread(new OneSecTimer(customers, kitchen, courier, timer, this));
		thread.start();
	}

	public void render() {
		// run every 1 second
	}

	public void addCustomer() {

	}

}
