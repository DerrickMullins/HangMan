#include <iostream> // Needed for cin and cout
#include <string>	// Needed to work with strings
#include <vector>	// Needed to work with vectors
#include <cstdlib> //Needed for rand and srand
#include <cctype> //Preprocessor for modifying characters



using namespace std;

int main()
{
	// Declaring vector "words" and adding countries to vector
	vector<string> words;
    words.push_back("RUSSIA");
    words.push_back("YEMEN");
    words.push_back("AMERICA");
    words.push_back("TAHITI");
    words.push_back("CUBA");
    words.push_back("HATAI");
    words.push_back("ENGLAND");
    words.push_back("THAILAND");
    words.push_back("CHINA");
    words.push_back("JAPAN");
    words.push_back("BELGIUM");
    words.push_back("BRAZIL");
    words.push_back("CHILE");
    words.push_back("GREENLAND");
    words.push_back("FINLAND");
    words.push_back("DENMARK");
    words.push_back("KENYA");
    words.push_back("EGYPT");
    words.push_back("LIBERIA");
    words.push_back("NIGERIA");
    words.push_back("POLAND");
    words.push_back("CHAD");
    words.push_back("MONGOLIA");
    words.push_back("IRAN");
    words.push_back("CANADA");
    words.push_back("IRAQ");
    words.push_back("JORDAN");
    words.push_back("PARAGUAY");
    words.push_back("TIBET");
    words.push_back("MOROCCO");
 	//************************************************************************//   
    // (RANDOMLY SELECTING WORD FROM "WORDS" VECTOR)
	// srand(time(NULL)) controls choice of seed (starting number)	
	// rand() returns a random positive int in a range from (0-32,767)
    srand(time(NULL)); 
	int n = rand() % 30;

	// Declaring word to be guessed "guessword" and initializing 
	// it with random word from "words" vector bank
    string guessword = words[n];

    // Delcaring string "unknown" and filling it with '*'
    // using the fill constructor (std::string::string)
    string unknown(guessword.size(), '*');

    // Counts number of wrong guesses
    int wrong = 0;

    // Used to cin users guess
    char guess;

    // Declaring string "lused" to keep track of letters used
    string lused = "";

    // Displays title to user
    cout << "\t\t   HANGMAN!" << endl;
    cout << endl;
    cout << "The word is: "<< unknown;
    cout << endl;
    //************************************************************************//
    
    // Keep looping until user exceeds 8 tries (Main Loop)
    while ((wrong < 8 && unknown != guessword)) 
    {
        cout << "You have " << (8 - wrong) << " guesses left." << endl;
        cout << "For unknown, word: " << unknown << endl;
        cout << endl;
        cout << "Guess a letter: ";

        // Getting users input
        cin >> guess;

        // cctype 'toupper' changes character to being in upper case
        guess = toupper(guess); 
        
        // Enter loop if 'guess' is found in 'lused'. Think of npos 
        // as no-position. As a return value it is usually used to
        // indicate that no matches were found in a string. (Inner Loop)
        while (lused.find(guess) != string::npos) 
        {
            cout << "Letter already guessed." << endl;
            cout << endl;
            cout << "Guess a letter: ";
            cin >> guess;
            guess = toupper(guess);
        }
        // Enter code block if guess appears at least once in guessword
        if (guessword.find(guess) != string::npos) 
        {	// Loop the length of guessword
            for (int i = 0; i < guessword.length(); ++i)
            if (guessword[i] == guess) 
            {
                cout << "Correct! The letter " << guess << " is in the phrase!" << endl;
                unknown[i] = guess;
                lused = lused + guess; // Adding guess to lused
        	}
    	}
        
        // If guess wasn't in lused or guessword
        else
        {
        	cout << "Incorrect." << endl;
            ++wrong; // Increment wrong
            lused = lused + guess; // Adding guess to lused
        }
        
        if (wrong == 0) 
        {
            cout << "    " << endl;
            cout << "    " << endl;
            cout << "    " << endl;
            cout << "    " << endl;
            cout << "    " << endl;
            cout << endl;
        } 
        else if (wrong == 1) 
        {
            cout << "    " << endl;
            cout << "    " << endl;
            cout << " O  " << endl;
            cout << "    " << endl;
            cout << "    " << endl;
            cout << endl;
        } 
        else if (wrong == 2) 
        {
            cout << "    " << endl;
            cout << "    " << endl;
            cout << " O  " << endl;
            cout << " |  " << endl;
            cout << "    " << endl;
            cout << endl;
        } 
        else if (wrong == 3) 
        {
            cout << "    " << endl;
            cout << "    " << endl;
            cout << " O  " << endl;
            cout << "-|  " << endl;
            cout << "    " << endl;
            cout << endl;
        } 
        else if (wrong == 4) 
        {
            cout << "    " << endl;
            cout << "    " << endl;
            cout << " O  " << endl;
            cout << "-|- " << endl;
            cout << "    " << endl;
            cout << endl;
        } 
        else if (wrong == 5) 
        {
            cout << "    " << endl;
            cout << "    " << endl;
            cout << " O  " << endl;
            cout << "-|- " << endl;
            cout << "|   " << endl;
            cout << endl;
        } 
        else if (wrong == 6) 
        {
            cout << "    " << endl;
            cout << "    " << endl;
            cout << " O  " << endl;
            cout << "-|- " << endl;
            cout << "| | " << endl;
            cout << endl;
        } 
        else if (wrong == 7) 
        {
            cout << "    " << endl;
            cout << " |  " << endl;
            cout << " O  " << endl;
            cout << "-|- " << endl;
            cout << "| | " << endl;
            cout << endl;
        } 
        else if (wrong == 8) 
        {
            cout << "  _ " << endl;
            cout << " |  " << endl;
            cout << " O  " << endl;
            cout << "-|- " << endl;
            cout << "| | " << endl;
            cout << endl;
        }
        
        cout << endl;
        cout << "Characters used: " << lused << endl;
        
    }
    
    if (wrong == 8)
    {
    	cout << endl;
        cout << "Unfortunately, you have been hung. The correct phrase: " << guessword << endl;
    }
		 	
    else
    {
    	cout << endl;
        cout << "You got the phrase! " << guessword << endl;
    }			 
    
}