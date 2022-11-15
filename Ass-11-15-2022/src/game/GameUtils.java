package game;

public class GameUtils {

	public static String[] sizeTypes = { "Small", "Medium", "Large" };
	public static String[] placeTypes = { "Land", "Water" };
	public static String[] habitatTypes = { "Land", "Salt Water", "Fresh Water" };

	public static Habitat createHabitat(String hab) {
		if (hab.equals(habitatTypes[0])) {
			return new LandHabitat(hab);
		} else {
			return new WaterHabitat(hab);
		}
	}
}
