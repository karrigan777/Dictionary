
#include <iostream> 
#include <fstream> 
#include <cstdlib> 
#include <string.h>
    using namespace std;

int main() {
    cout << "Dictionary-Search Program" << endl;

    string dict[1000], word;
    ifstream in_stream;
    in_stream.open("a.txt");
    cout << endl;
    if (in_stream.fail())

    {
        cout << "Error : File cannot be opened.\n";
        exit(1);
    }

    int i = 0;
    while (!in_stream.eof()) {
        getline(in_stream, dict[i]);
        i++;
    }
    char inp = 'y';
    goto search;

    menu:

        cout << endl << "Do you want to search again? (y/n)" << endl;
    cin >> inp;
    if (inp == 'y' || inp == 'Y') {
        goto search;

    } else
        return 0;

    search:
        string WordList[i];
    int a = 0;

    cout << "Search for: ";
    cin >> word;

    for (int k = 0; k < i; k++) {
        int val = dict[k].find(word);
        if (val == 0) {
            if (dict[k].compare(word) == 0) {
                cout << "Word has been found" << endl << word << endl;
                goto menu;
            } else {
                WordList[a] = dict[k];
                a++;

            }
        }
    }
    cout << "ERROR - No word found."<<endl<<"Do you want to print suggestions? (y/n)"<<endl;
    cin >> inp;
    if (inp == 'y' || inp == 'Y') {
        

    } else
        goto menu;
    if (a != 0)
        cout << endl << "Suggestions" << endl << endl;
    for (int k = 0; k < a; k++) {
        cout << WordList[k] << endl;
    }

    goto menu;

}
