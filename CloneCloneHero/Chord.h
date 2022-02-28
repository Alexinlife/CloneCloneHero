#include <string>

using namespace std;

#ifndef CHORD_H
#define CHORD_H

/**
* Author: Alex Lajeunesse
* Date: 21-02-2022
*
* Class: Chord
* Description: A chord contains at least 1 note and a maximum of 5. It can be delayed to create tuplets.
*              Notes can be of the following types:
*                  - Default (type 0, 0): at least 1 fret (except for open, see below), needs to be strummed
*                  - Open (type 0, - - - - -): no fret, only a strum
*                  - Tap (type 1, O): at least 1 fret, no strum
*                  - HOPO (type 2, @): at least one fret, no strum as long as the last note was played correctly
*              The chord can be sustained but it currently does not support more complex types
*              (disjointed chord, extended sustain, etc.)
**/
class Chord
{
public:
	/**
	* Default constructor for Chord
	*/
	Chord();

	/**
	* Overridden constructor for Chord
	* 
	* n: notes
	* d: delay
	* t: type
	* s: sustain
	*/
	Chord(int n, int t, float d, float s);

	/**
	* Destructor for Chord
	*/
	~Chord();

	/**
	* Gets the notes of the chord
	* 
	* Returns: a string of the notes to display
	*/
	const string getNotes();

	/**
	* Gets the delay at which the chord should appear if it has any
	* 
	* Returns: the value of the delay
	*/
	const float getDelay();

	/**
	* Gets the sustain of the chord if it has any
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