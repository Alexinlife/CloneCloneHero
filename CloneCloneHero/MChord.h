#include <string>

using namespace std;

#ifndef MCHORD_H
#define MCHORD_H

/**
* Author: Alex Lajeunesse
* Date: 21-02-2022
*
* Class: MChord
* Description: A musical chord contains at least 1 note and a maximum of 5. It can be delayed to create tuplets.
*              Notes can be of the following types:
*                  - Default (type 0, 0): at least 1 fret (except for open, see below), needs to be strummed
*                  - Open (type 0, - - - - -): no fret, only a strum
*                  - Tap (type 1, O): at least 1 fret, no strum
*                  - HOPO (type 2, @): at least one fret, no strum as long as the last note was played correctly
*              The musical chord can be sustained but it currently does not support more complex types
*              (disjointed chord, extended sustain, etc.)
**/
class MChord
{
public:
	/**
	* Default constructor for MChord
	*/
	MChord();

	/**
	* Copy constructor for MChord
	*/
	//MChord(const MChord& c);

	/**
	* Overridden constructor for MChord
	* 
	* n: notes
	* t: type
	* d: delay
	* s: sustain
	*/
	MChord(int n, int t, float d, float s);

	/**
	* Destructor for MChord
	*/
	~MChord();

	/**
	* DEPRECATED
	* Gets the notes of the musical chord
	* 
	* Returns: a string of the notes to display
	*/
	// const string getNotes();

	/**
	* Gets the notes of the musical chord
	*
	* Returns: the notes in decimal form
	*/
	const int getNotes();

	/**
	* Gets the type of the musical chord
	* 
	* Returns: the value corresponding to the musical chord type
	*/
	const int getType();

	/**
	* Gets the delay at which the musical chord should appear if it has any
	* 
	* Returns: the value of the delay
	*/
	const float getDelay();

	/**
	* Gets the sustain of the musical chord if it has any
	* 
	* Returns: the value of the sustain
	*/
	const float getSustain();

private:
	int notes;
	int type;
	float delay;
	float sustain;
};

#endif