/* Program simulating the game */

#include <cstdlib> 
#include <iostream>
#include <ctime> 
#include <fstream>
#include <sstream>

using namespace std;

int ( &fillarr( int (&arr)[10] ) )[10]; // Fisher-Yates shuffle algorithm for changing the order of questions

int main() {

 // program loads the text file and turns the content into one big string
	ifstream in("questions.txt");
	stringstream buffer;
	buffer << in.rdbuf();
	string test = buffer.str();
	

	//create variables that will act as "cursors". we'll take everything between them.
	size_t pos1 = 0;
	size_t pos2;

	//create the array to store the strings.
	string str[50];

	for (int x = 0; x < 50; x++) {
		pos2 = test.find("|", pos1); //search for the bar "|". pos2 will be where the bar was found.
		str[x] = test.substr(pos1, (pos2-pos1)); //make a substring, wich is nothing more 
		                                      //than a copy of a fragment of the big string.
		cout << str[x] << endl;
		pos1 = pos2+1; // sets pos1 to the next character after pos2. 
	                     //so, it can start searching the next bar |.
	}


	int tablica[10]; // array with the normal order of questions
	int right_answers[10] = {3,2,4,1,3,4,4,4,2,4};
	for(int j = 0; j < 10; j++) {
		tablica[j] = j;
	}

	fillarr(tablica);

	int points = 0;
	int answer;

	cout<<"Zaczynamy grę. Zobaczysz na ekranie 10 pytań. Każde pytanie ma 4 warianty odpowiedzi. Tylko jedna odpowiedź jest prawidłowa."<<endl;
	cout<<"Aby wskazać prawidłową odpowiedź wybierz na klawiaturze liczbę od 1-4."<<endl;

	for (int j = 0; j < 10; j++) {
	cout<<"Pytanie nr "<< j+1<<endl;
	int pozycja = tablica[j] * 4 + tablica[j];
	cout<<str[pozycja]<<endl<<endl;
		for(int k = pozycja + 1; k < pozycja + 5; k++) {
			cout<<str[k]<<endl;
		}
	cin>>answer;
	if(answer == right_answers[tablica[j]]) {
		points++;
		cout<<"Prawidlowa odpowiedz."<<endl;
	}
	cout<<endl;
	}

	cout<<"Gratulacje. Udało Ci się zdobyć "<<points<<" punktów."<<endl;

	cin.get();
	return 0;
}


int ( &fillarr( int (&arr)[10] ) )[10] { 

	for(int k = 0; k < 10; k++) {
		srand(time(NULL)); // seeding the randomizer
		int losowa =  rand() % (10-k); // generating random number from 0 to 9-k
		cout<<losowa<<endl;

		// the part responsible for swapping two elements of the array
		int c = arr[losowa];
		arr[losowa] = arr[9];
		arr[9] = c;

	}

    return arr;
}

