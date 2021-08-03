#include <iostream>
#include <string>

using namespace std;

//Prints the missing letters if there are any
void print_array(char* alphaCheck, int size) {

    cout << "The missing letters are: ";
    for (int i = 0; i < size; ++i) {
        if (alphaCheck[i] != 0) { //Print only if the letter has not been deleted
            cout << alphaCheck[i];
        }
    }
    cout << endl;

}

//Deletes the specifical letter from the array alphaCheck
int delete_in_alphaCheck(char* s, char* alphaCheck,int letterCount, int size, int pos) {

    if ((int)s[pos] != 32) { //Check if the current char is a 'space', in that case ignore it
        if (alphaCheck[(int)s[pos] - 97] != 0) { //Check if the letter was already deleted
            alphaCheck[(int)s[pos] - 97] = 0;
            letterCount++;
        }
    }

    return letterCount;

}

//Uses an array in which it deletes all the letters found in the string. At the end only the letters that were not present in the string s
//will be available in the array alphaCheck.
//It also uses a count variable which is used to check if all the letters have been deleted avoiding an optional for-loop to check that.
void find_missing_alphabet_array(string s, int size) {

    char alphaCheck[] = { 'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z' };
    int letterCount = 0, check = 0;

    for (int i = 0; i < size; ++i) {

        if ((int)s[i] > 97 || (int)s[i] < 123) { //Check if the current character is alphabetical
            if ((letterCount = delete_in_alphaCheck(&s[0], &alphaCheck[0], letterCount, size, i)) == 25) { //Checks if there are already no letters missing
                cout << "There are no missing letters in the string" << endl;
            }
        }
        
    }

    if (letterCount == 0) { //Empty string
        cout << "The string is empty or with no alphabetical characters" << endl;
        return;
    }

    print_array(&alphaCheck[0], 26);

}

int main()
{
    string s;
    cout << "Insert the string" << endl;
    getline(cin, s); //We are using getline() to take also the character 'space' in consideration. By only using 'cin', we should
                     //suppose that 'space' will not be used as character

    find_missing_alphabet_array(s, size(s));

    return 0;
}