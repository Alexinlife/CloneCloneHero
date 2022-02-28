#include <queue>
#include "Chord.h"

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

		/**
		* Overridden constructor for Chart
		*/
		Chart(int notes, int type, int delay, float sustain);

		/**
		* Destructor for Chart
		*/
		~Chart();

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
		Chord nextChord();

		/**
		* Removes the first chord and returns it
		*
		* Returns: the first Chord in the queue
		*/
		Chord unqueueChord();

		/**
		* Finds an existing beat and copies it in the chart
		*/
		void copyBeat(int index);

		/**
		* Finds a measure and copies it in the chart
		*/
		void copyMeasure(int index);

		/**
		* Finds a section of the chart and copies it to the current end
		*/
		void copyPart(float begin, float end);

		/**
		* Converts the chart to a string that can be used by the Game class
		*/
		string toString();

		/**
		* Sets the signature of the chart
		* 
		* b: beats
		* m: measures
		*/
		void setSignature(int b, int m);

		/**
		* Sets the tempo of the chart
		* 
		* t: tempo
		*/
		void setTempo(float t);

	private:
		int beats;
		int measures;
		float tempo;
		queue<Chord> chords;
};

#endif