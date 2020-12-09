#include <iostream>
#include <string>
#include <cctype>

using namespace std;

int main()
{
    string sentence, word, piglatin;
    piglatin = "";
    sentence = "Hello Bob, this is Collin.";
    int index = 0;

    // CODE

    for (int i = 0; i < sentence.size(); ++i)
    {
        if (!isspace(sentence[i]))
        {
            word += sentence[i];
        }
        if (isspace(sentence[i]) && word != "" || i == sentence.size()-1)
        {
            if (ispunct(word[word.size()-1]))
            {
                word = word.substr(1, word.size()-2) + word[0] + "ay" + word[word.size()-1];
            }
            else
            {
                word = word.substr(1, word.size()-1) + word[0] + "ay";
            }
            piglatin += word + " ";
            word = "";
        }
    }

    // END
    cout << "pig latin conversion: " << piglatin << endl;

    return 0;
}
