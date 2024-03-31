/*
    This file is intented to solve the Palabreja problem: https://palabreja.com/

    There are some letters forming a honeycomb: there is a middle letter and the others are surrounding it
    You have to form all possible words (in spanish) using ONLY those letters

    The rules are:
        - All words must contain the middle letter
        - The words must have, at least, 4 letters
        - Only infinitive is considerd (no conjugated forms)
        - From names and adjectives, only the masculine is accepted (no feminin or plural)
        - No proper nouns (countries, person names, etc. )
*/

#include <iostream>
#include <fstream>
#include <vector>

// Read input data from txt file
std::string readInputText(std::string inputText){

    std::fstream inputfile;
    std::string inputData;

    inputfile.open(inputText, std::ios::in);
    if (inputfile.is_open()){
        std::string tp;

        while (getline(inputfile, tp)){
            inputData += tp;
            inputData += '\n';
        }
    }
    return inputData;
}

// Function to check if a letter is in the targetLetters vector
bool findLetter(char letter, std::vector<char> targetLetters){
    for(char l: targetLetters){
        if(letter == l)
            return true;
    }
    return false;
}

int main(){

    // Load all the words in RAE (Real Academia Española de la Lengua) in a string
    std::string dictString = readInputText("spanish.lst");

    // Define the vector with the letters and the center letter
    std::vector<char> targetLetters = {'t', 'a', 'p', 'n', 'd', 'o', 'l'};
    char centerLetter = targetLetters[0];

    // Number of possible words
    int count = 0;

    // Variable that will hold each of the words in RAE
    std::string word;

    for(char letter: dictString){
        if(letter != '\n')
            word.push_back(letter);
        else{
            // If there is at least one letter that doesn't appear in my vector, skip the word
            for(char c: word){
                if(!findLetter(c, targetLetters)){
                    word.clear();
                    break;
                }
            }
            // If the word fulfills the conditions, print it
            if(word.size() > 3 && word.find(centerLetter) != std::string::npos){
                count++;
                std::cout << word << '\n';
                word.clear();
            }     
        }
    }

    std::cout << "There are " << count << " possible words\n";

    return 0;
}