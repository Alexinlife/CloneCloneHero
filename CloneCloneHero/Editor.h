#include <iostream>
#include <fstream>
#include "Chart.h"

#ifndef EDITOR_H
#define EDITOR_H

using namespace std;

/**
* Author: Alex Lajeunesse
* Date: 27-02-2022
*
* Class: Editor
* Description: Creates charts to be used by the game
**/
class Editor
{
public:
	/**
	* Default constructor for Editor
	*/
	Editor();

	/**
	* Destructor for Editor
	*/
	~Editor();

	/**
	* Reads song and adds it to the chart
	*/
	void readSongFile(string path);

	/**
	* Starts the Editor
	*/
	Chart test();

private:
	Chart chart;
};

#endif