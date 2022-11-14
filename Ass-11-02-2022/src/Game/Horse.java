package Game;

import Utils.Log;
import Utils.Utils;

public class Horse extends Log {
	int position;
	int maxPosition;
	char horseChar;

	int shoelv;
	int leashLv;
	int skipChance;

	public Horse(int maxPosition, char horseChar, int skipChance) {
		this.maxPosition = maxPosition;
		this.position = 0;
		this.horseChar = horseChar;

		this.skipChance = skipChance;
	}

	public void print() {
		for (int i = 0; i < this.maxPosition; i++) {
			if (i == this.position) {
				logr("" + this.horseChar);
			} else {
				logr(" ");
			}
		}
	}

	public void move() {
		if (Utils.getRandRange(0, 100) < this.skipChance)
			return;
		this.position += 1;
	}

	public boolean finished() {
		if (this.position == this.maxPosition - 1) {
			return true;
		} else {
			return false;
		}
	}
}
