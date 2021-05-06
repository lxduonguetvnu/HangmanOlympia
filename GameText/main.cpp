#include <iostream>
#include <fstream>
#include <string>
#include <locale>
#include <vector>
#include <ctime>
#include <algorithm>
#include <sstream>

using namespace std;

bool run;



int countLines(vector<string> words) {
    return words.size();
}

string getWord() {
    ifstream words_file;
    try {
        words_file.open("EnglishWord.txt");
    }
    catch (...) {//words_file.fail()) {
        cout << "Error" << endl;
        run = false;
    }

    string line;

    vector<string> words;

    while (getline(words_file,line)) {
        words.push_back(line);
    }


    int number_of_words = countLines(words);
    // cout << number_of_words << endl;

    string word = words.at(rand() % number_of_words);

    return word;

    //return "Manchester";

}
string runAI() {
    return (getWord());
}


void endGame() {
    cout << "Thank you for playing. Goodbye!" << endl;
    run = false;
}



string updateWord(string word, vector<int> characterLocations, char to_update) {
    char dummy;
    vector<char> word_vec (word.length(),dummy);

    for (int i = 0; i < word.length(); i++) {
        vector<int>::iterator found = find(characterLocations.begin(), characterLocations.end(), i);
        if(found != characterLocations.end()) {
            word_vec[i] = to_update;
            characterLocations.erase(found);
        }
        else {
            word_vec[i] = word[i];
        }
    }


    string result(word_vec.begin(),word_vec.end());

    return result;
}

bool has_only_alpha(string word) {
    char c;
    for (int i = 0; i < word.length(); i++) {
        c = word.at(i);

        if (! ( ( c >= 'a' && c <= 'z' ) ||
                    ( c >= 'A' && c <= 'Z') ) ) {
            return false;
        }
    }
    return true;
}

vector<int> findLocation(string sample, char findIt)
{
    vector<int> characterLocations;
    for(int i =0; i < sample.size(); i++)
        if(sample[i] == findIt)
            characterLocations.push_back(i);

    return characterLocations;
}

void toLower(string& word) {
    transform(word.begin(), word.end(), word.begin(), ::tolower);
}

void printMax(const int PATCH_LINES = 70)
{
    for (int i = 0; i < PATCH_LINES; ++ i)
    {
        cout << endl;
    }
}


int main() {

    srand(time(NULL));
    int score = 0;
    string wrongGuess = "";
    printMax();
    printMax();
    cout << "WELCOME TO HANGMAN OLYMPIA GAME!" << endl;
    cout << "--------------------------------" << endl;
    cout << "Made by Le Duong in April , 2021" << endl;
    cout << endl;

    run = true;

    while (run) {

        string gameMode;

        cout << "Would you like to play against:\n 1) A friend\n \n 2) The computer?" << endl;
        cout << "Type 'quit' to end the game." << endl;

        cin >> gameMode;

        string hidden_word = "";
        string input;

        if (gameMode == "1") {
            printMax();
            bool isValidWord = false;

            cout << "PLAYER 1'S TURN" << endl;
            while (isValidWord == false) {

                cout << "Give me a word: ";
                cin >> input;
                isValidWord = has_only_alpha(input);
                if (isValidWord) {
                    for (int i = 0; i < 100; i++) { // clears the terminal
                        cout << "\n" << endl;
                    }
                    break;
                }
                cout << "Only letters are allowed in words." << endl;
            }

            for (int j = 0; j < input.length(); j++) {
                hidden_word += "-";
            }

            toLower(input);

            cout << "PLAYER 2'S TURN" << endl;

            bool game_over = false;

            int num_tries = input.length() + 3;

            cout << "The word that your friend gave was " << input.length() << " letters long." << endl;

            cout << "Updated Word: " << hidden_word << endl;

            while ((num_tries > 0) && (game_over == false)) {
                char letter;
                cout << "Number of tries left: " << num_tries << endl;
                cout << "Give me a letter you think is in the word: ";
                cin >> letter;

                printMax();
                stringstream stream;
                string str;

                stream << letter;
                stream >> str;

                toLower(str);

                size_t found = input.find(letter);
                if (found != string::npos) {
                    cout << "That letter is in the word!" << endl;
                    vector<int> characterLocations = findLocation(input,letter);



                    hidden_word = updateWord(hidden_word, characterLocations, letter);
                    if (hidden_word == input) {
                        game_over = true;
                        break;
                    }
                    cout << "Updated Word: " << hidden_word << endl;



                }
                else {
                    cout << "That letter is not in the word." << endl;
                }
                num_tries--;
            }



            printMax();
            if (num_tries != 0) {
                cout << "Player 2 wins!" << endl;
            }
            else {
                cout << "Player 1 wins!" << endl;
            }
            cout << "The word you gave me was: " << input  << endl;
            run = false;
        }
        else if (gameMode == "2") {

            printMax();
            input = runAI();
            toLower(input);
            for (int j = 0; j < input.length(); j++) {
                hidden_word += "-";
            }


            cout << "PLAYER'S TURN" << endl;

            bool game_over = false;

            int num_tries = input.length() + 3;
            cout << "The word that the computer gave was " << input.length() << " letters long." << endl;
            while ((num_tries > 0) && (game_over == false)) {
                char letter;
                cout << "If you would like to guess the word, press 1." << endl;
                cout << "Number of tries left: " << num_tries << endl;
                cout << "Give me a letter you think is in the word: ";
                cin >> letter;

                printMax();
                if (letter == '1')
                {
                    string guess;
                    cout << "You pressed 1! Can you tell me what is your guess?\nIf you guess the word right, you will be added 40 points!" << endl;
                    cin >> guess;
                    //printMax();
                    if (input == guess) {
                        score = score + 40;
                        num_tries = -1;
                    }
                    else{ cout << "Wrong!" << endl;}

                }
                else {
                    printMax();
                    size_t found = input.find(letter);
                    if (found != string::npos) {
                        cout << "That letter is in the word!" << endl;
                        score = score + 10;
                        vector<int> characterLocations = findLocation(input,letter);

                        for (int i = 0; i < characterLocations.size(); i++) {
                            cout << characterLocations[i] << endl;;
                        }

                        hidden_word = updateWord(hidden_word, characterLocations, letter);
                        if (hidden_word == input) {
                            game_over = true;
                            break;
                        }
                        cout << "Updated Word: " << hidden_word << endl;



                    }
                    else {
                        cout << "That letter is not in the word." << endl;
                        score = score - 5;
                        cout << "Updated Word: " << hidden_word << endl;
                        wrongGuess += letter;
                    }

                    cout << "Your score: " << score << endl;
                    cout << "Wrong guess(es): " << wrongGuess << endl;
                    num_tries--;
                }
            }



            printMax();
            if (num_tries != 0) {
                cout << "Player wins!" << endl;
            }
            else {
                cout << "The computer wins!" << endl;
            }
            cout << "The word the computer gave was: " << input  << endl;
            cout << "Your score: " << score << endl;
            run = false;
        }
        else if (gameMode == "quit") {
            printMax();
            run = false;
        }
        else {
            printMax();
            cout << "Please input only 1 or 2 or 'quit'." << endl;
        }

    }

    endGame();


    return 0;
}
