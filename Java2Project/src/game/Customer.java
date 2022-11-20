package game;

import game.dishes.*;

public class Customer {

	private Food food;
	private Drinks drink;
	private int patience = 10;

	public Customer(Food food, Drinks drink) {
		this.food = food;
		this.drink = drink;
	}

	public boolean order(String name) {
		Dish dish = (!this.food.served ? this.food : this.drink);

		if (dish.name.equals(name)) {
			dish.serve();
			return true;
		} else {
			return false;
		}

	}

	public void printPatience() {
		for (int i = 0; i < patience; i++) {
			System.out.print("#");
		}

		for (int i = 0; i < 10 - patience; i++) {
			System.out.print(" ");
		}
	}

	public boolean isDone() {
		if (this.food.served && this.drink.served) {
			return true;
		} else {
			return false;
		}
	}

	public void reducePatience() {
		this.patience -= 1;
	}

	public int getPatience() {
		return this.patience;
	}

	public String getFood() {
		return this.food.name + "[" + (this.food.served ? "v" : " ") + "]";
	}

	public String getDrink() {
		return this.drink.name + "[" + (this.drink.served ? "v" : " ") + "]";
	}

	public int getPrice() {
		return this.drink.price + this.food.price;
	}

}
