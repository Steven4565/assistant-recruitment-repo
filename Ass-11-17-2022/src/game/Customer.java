package game;

import game.dishes.*;
import utils.General;

public class Customer {
	FoodType food;
	BevType bev;
	DesType des;
	int patience;

	public Customer(FoodType food, BevType bev, DesType des) {
		this.patience = General.getRandRange(50, 60);
		this.food = food;
		this.bev = bev;
		this.des = des;
	}

}
