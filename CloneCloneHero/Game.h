#include "Chart.h"

#ifndef GAME_H
#define GAME_H

/**
* Author: Alex Lajeunesse
* Date: 27-02-2022
*
* Class: Game
* Description: Drives the console output, input by itself and does chart management via a Chart object.
**/
class Game
{
public:
	/**
	* Default constructor for Game
	*/
	Game();

	/**
	* Destructor for Game
	*/
	~Game();

	/**
	* Starts the game
	*/
	void play();

private:
	Chart chart;
};

#endif