#include "Chord.h";

Chord::Chord() {
	notes = 0; // open note
	type = 3;  // open note
	delay = 0; // no delay
	sustain = 0;
}

Chord::Chord(int n, int t, float d, float s) {
	notes = 0; // open note
	type = 3;  // open note
	delay = 0; // no delay

	if (n >= 0 && n <= 31) {
		notes = n;
	}
	if (d >= 0) {
		delay = d;
	}
	if (t >= 0 && t <= 2) {
		type = t;
	}
	sustain = s;
}

Chord::~Chord() {

}

const string Chord::getNotes() {

}

const float Chord::getDelay() {

}

const float Chord::getSustain() {

}
