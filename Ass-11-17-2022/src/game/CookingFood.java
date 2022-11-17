package game;

import game.dishes.DishType;

public class CookingFood {
	DishType dish;
	int cookTime;

	public CookingFood(DishType dish) {
		this.dish = dish;
		this.cookTime = dish.prepTime;
	}

}
