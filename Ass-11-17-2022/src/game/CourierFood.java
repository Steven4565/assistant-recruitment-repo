package game;

import game.dishes.DishType;
import utils.General;

public class CourierFood {
	DishType dish;
	int distance;

	public CourierFood(DishType dish) {
		this.dish = dish;
		this.distance = General.getRandRange(5, 10);
	}

}
