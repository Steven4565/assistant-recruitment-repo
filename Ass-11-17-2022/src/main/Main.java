package main;

import java.util.ArrayList;

import utils.Print;
import utils.General;
import utils.Input;
import utils.Log;

import game.*;

import interfaces.VoidSam;

public class Main extends Log {

	static GamePlay game;

	public Main() {
		game = new GamePlay();
	}

	public static void test() {
	}

	public static void main(String[] args) {
		new Main();
		test();

	}

}
