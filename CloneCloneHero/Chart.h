#include <queue>
#include "MChord.h"

#include <iostream>

using namespace std;

#ifndef CHART_H
#define CHART_H

/**
* Author: Alex Lajeunesse
* Date: 21-02-2022
* 
* Class: Chart
* Description: A chart is a song played by the game. The song is created and edited by the Chart class.
*              It contains chords ordered by the time they will appear on screen. The time of appearance
*              is decided by the signature of the chart, the tempo and an optional delay determined by the chord.
**/
class Chart
{
	public:
		/**
		* Default constructor for Chart
		*/
		Chart();

		Chart(const Chart& copyChart);

		/**
		* Destructor for Chart
		*/
		~Chart();

		Chart& operator=(Chart c);

		/**
		* Adds a chord to the chart. If at least one chord is added,
		* the next one will be added at the end of the other chords
		* 
		* notes: the notes to add to the new chord
		* type: the type of chord
		* delay: the delay of the chord
		* sustain: the sustain of the chord
		*/
		void pushChord(int notes, int type, float delay, float sustain);

		/**
		* Gets the next chord in the queue
		* 
		* Returns: the first Chord in the queue
		*/
		MChord nextChord();

		/**
		* Gets the last chord in the queue
		*
		* Returns: the last Chord in the queue
		*/
		MChord& lastChord();

		/**
		* Removes the first chord and returns it
		*
		* Returns: the first Chord in the queue
		*/
		MChord unqueueChord();

		/**
		* Finds an existing beat and copies it in the chart

		/**
		* Converts the chart to a string that can be used by the Game class
		*/
		string toString();

		/**
		* Indicates if the chart is empty
		* 
		* Returns: true if empty or false if not
		*/
		bool isEmpty();

		/**
		* Gets the length of the song in "milliseconds"
		*/
		float getLength();

		/**
		* Sets the length of the song in "milliseconds"
		*/
		void setLength(int ms);

	private:
		int length;
		queue<MChord> chords;
};

#endif