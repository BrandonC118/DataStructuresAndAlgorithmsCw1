// DataStructuresAndAlgorithmsCw1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include "MusicBot.h"
#include "SongObject.h"
#include "songHash.h"
#include <iostream>
#include <string>


using namespace std;

int main()
{
	//Output to User to give them a background of the software.
	cout << "========================================================" << endl;
	cout << "Song Queue" << endl;
	cout << "========================================================" << endl;
	cout << "Please input your chosen songs and give them a Position you what to play them in" << endl;
	cout << "In ascending order. no. 1 will play first and the rest will follow" << endl;
	cout << "Please type Go! when you have finished inputting songs" << endl;

	//Instantiate musicbot with size of the array.
	MusicBot<SongObject> *musicBot = new MusicBot<SongObject>(20);

	bool stillAdding = true;
	const string endAdding = "Go!";
	int sorting;

	SongHash *songHash = new SongHash();

	//Runs during still <stillAdding> is true which is by default.
	while (stillAdding) {
		string songInput;
		int positionInput;

		//User puts in song but if user types <Go!> it will break out of the while loop.
		cout << "Enter song to play: ";
		cin >> songInput;

		if (songInput == endAdding) {
			stillAdding = false;
			break;
		}

		cout << "Enter the order to play this song: ";
		cin >> positionInput;

		if (to_string(positionInput) == endAdding) {
			stillAdding = false;
			break;
		}

		//Once user has added both parts of details it will be added within the MusicBot Object.
		musicBot->Insert(new SongObject(positionInput, songInput));
	}
	
	cout << "You have entered into queue" << endl;
	cout << "============================================================" << endl;
	while (!musicBot->IsEmpty()) {
		//If the music bot is not empty, it will iterate through the array and comment out to the user and adds it within the song Hashmap to be searched through.
		SongObject *songObject = musicBot->Remove();
		cout << "Position In Queue: " << songObject->position << "   Song: " << songObject->song << endl;
		songHash->InsertIntoHash(songObject);
	}

	string searchString;
	cout << "Would you like to sort your queue by Alphabetical Order or search for a specific song?" << endl;
	cout << "Please Input 1 to search for a specific song or Input 2 to see your finished queue of songs" << endl;
	cin >> sorting;

	if (sorting == 1) {
		SongObject *searchedObject;
		//Once the user inputs 1 into the terminal it will allow the user to search for a song name they have entered.
		cout << "What would song would you like to search for?" << endl;
		cin >> searchString;

		searchedObject = songHash->Search(searchString);
		if (searchedObject && searchedObject->song == searchString) {
			cout << "Found Song here! -> " << searchedObject->song << " with position of -> " << searchedObject->position << endl;
		}
		else {
			cout << "\nSong (" << searchString << ") could not be found." << endl;
		}
	}

	songHash->DisplayHashOnConsole();
	return 0;
}

