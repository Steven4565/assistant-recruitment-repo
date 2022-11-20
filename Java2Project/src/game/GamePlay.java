package game;

import java.util.ArrayList;

import game.templates.DishTemplates;
import multithreaded.OneSecondTimer;
import multithreaded.UserInputThread;
import utils.Log;
import utils.Print;

public class GamePlay extends Log {
	ArrayList<Customer> customers;
	int life = 5;
	int score = 0;
	int time = 0;
	OneSecondTimer timer;
	UserInputThread inputThread;
	public boolean gameOver = false;
	public String query = "";

	public GamePlay() {
		this.customers = new ArrayList<>();
		this.timer = new OneSecondTimer(this);
		this.inputThread = new UserInputThread(this);
	}

	public void start() {
		this.timer.start();
	}

	// call in coroutine
	public void reduceCustomerPatience() {
		for (Customer customer : customers) {
			customer.reducePatience();
		}

		handleGame();
	}

	// call in coroutine
	public void attemptOrder(String name) {
		for (Customer customer : customers) {
			if (customer.order(name)) {
				break;
			}
		}

		handleGame();

	}

	public void handleGame() {
		// handle customers
		for (int i = 0; i < customers.size();) {
			if (customers.get(i).getPatience() <= 0) {
				customers.remove(i);
				this.life -= 1;
			} else if (customers.get(i).isDone()) {
				score += customers.get(i).getPrice();
				customers.remove(i);
			} else {
				i += 1;
			}
		}

		if (this.life <= 0) {
			this.gameOver = true;
		}
	}

	public void addCustomer() {
		customers.add(new Customer(DishTemplates.createFood(), DishTemplates.createDrink()));
	}

	public void addTime() {
		this.time += 1;
	}

	public void render() {
		Print.clrscr();
		System.out.printf("Time: %-5d | life: %d | Score: %d\n", time, life, score);
		log("");
		System.out.printf("%-15s | %-30s | %-30s | %-10s\n", "Patience", "Food", "Drink", "Price");
		for (int i = 0; i < 5; i++) {
			if (customers.size() > i) {
				Customer cust = customers.get(i);
				logr("| ");
				cust.printPatience();
				System.out.printf("    | %-30s | %-30s | %-10d\n", cust.getFood(), cust.getDrink(), cust.getPrice());
			} else {
				System.out.printf("%-15s | %-30s | %-30s | %-10s\n", "", "", "", "");
			}
		}

		log("");
		log("Type the order to serve (case sensitive)" + this.query);
		log("Type exit to stop playing");

	}

}
