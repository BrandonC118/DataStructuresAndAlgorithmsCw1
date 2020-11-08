#pragma once
using namespace std;

template <class T>
class MusicBot {
private:
	int size;
	T **data;
	int count;
public:
	MusicBot(int size) :size(size) {
		data = new T*[size];
		count = 0;
	}
	~MusicBot() {}
	void Insert(T* songObject) {
		// Queue is empty
		if (IsEmpty) {
			data[count++] = songObject;
		}
		else {
			int i;
			// Start at the end work backwards 
			for (i = (count - 1); i >= 0; i--) {
				// If the new item is larger than current
				if (*songObject > *data[i]) {
					// Shift the current up
					data[i + 1] = data[i];
				}
				else {
					// Finished shifting
					break;
				}
			}
			data[i + 1] = songObject;
			count++;
		}
	}
	T*  Remove() {
		return data[--count];
	}
	bool IsEmpty() {
		return count == 0;
	}
	bool IsFull() {
		return count == size;
	}
	int Size() {
		return size;
	}
};
