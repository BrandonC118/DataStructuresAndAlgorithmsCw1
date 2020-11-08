#pragma once

#include <iostream>

using namespace std;

class SongObject {
public:
	int position;
	string song;
	SongObject(int position, string song) :position(position), song(song) {}
	~SongObject() {}
	bool operator> (const SongObject& songObject) {
		return this->position < songObject.position;
	}
};