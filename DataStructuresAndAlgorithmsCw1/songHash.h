#pragma once
#pragma once

#include <iostream>
#include <string>
#include "SongObject.h"

using namespace std;

//Prime numbers were used to avoid infinite loops being caused
#define TABLE_SIZE_PRIME 17

class SongHash {
private:
	SongObject** data;
	int size;
	int GetFirstASCIIChar(string key) {
		//This is not implemented...
		//In future development I would order the song list in alphabetical order.
		int ASCIItotal = 0;
		ASCIItotal += (int)key[0];
	}
	int HashFunction(string key) {
		int ASCIIKey = GetFullASCIIKey(key);
		return ASCIIKey % TABLE_SIZE_PRIME;
	}
	//This converts and adds the inputted key string from the hashmap into an ASCII
	int GetFullASCIIKey(string key) {
		int ASCIItotal = 0;
		for (int i = 0; i < key.length(); i++) {
			ASCIItotal += (int)key[i];
		}
		return ASCIItotal;
	}
	
public:
	SongHash() {
		data = new SongObject*[TABLE_SIZE_PRIME];
		for (int i = 0; i < TABLE_SIZE_PRIME; i++) {
			data[i] = NULL;
		}
	}

	//Function - To search for a specific song object within the hash
	SongObject* Search(string key) {
		int hash = HashFunction(key);
		while (data[hash] != NULL) {
			//Searches through the hash if it exists and selectively returns an item back to the user.
			SongObject *item = data[hash];
			cout << item << endl;
			if (item->song == key) {
				return item;
			}
			hash++;
			hash = hash % size;
		}
		return NULL;
	}

	//Function - Displays the song queue to the user.
	void DisplayHashOnConsole() {
		cout << '\n';
		cout << "Here is your finished song queue and order you are going to play them." << endl;
		cout << "======================================================================" << endl;
		for (int i = 0; i < TABLE_SIZE_PRIME; i++) {
			if (data[i] != NULL) {
				cout << "Index: " << i << "   Position: " << data[i]->position << "    Song: " << data[i]->song << endl;
			}
		}
	}

	//Function - To insert a SongObject into hashmap
	void InsertIntoHash(SongObject* item) {
		if (isHashFull()) {
			return;
		}

		//Each key will be filled in by the song name in ASCIITotal and the value that goes with it is the object
		string key = item->song;
		int hash = HashFunction(key);
		while (data[hash] != NULL) {
			++hash;
			hash = hash % size;
		}
		data[hash] = item;
	}

	bool isHashFull() {
		return size == TABLE_SIZE_PRIME;
	}
};