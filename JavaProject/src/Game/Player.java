package Game;

import java.util.ArrayList;
import java.util.Stack;

import Utils.Log;

public class Player extends Log {

	ArrayList<Card> deck;

	public Player() {
		this.deck = new ArrayList<Card>();
	}

	public void hit(Stack<Card> deck) {
		this.deck.add(deck.pop());
	}

	public int getDeckValue() {
		int sum = 0;
		for (Card card : deck) {
			sum += card.value;
		}
		return sum;
	}

	public void printCards() {
		ArrayList<String> printBuffer = new ArrayList<String>();
		for (Card card : deck) {
			printBuffer.add(card.sprite);
		}
		log(String.join(" | ", printBuffer));
	}

}
