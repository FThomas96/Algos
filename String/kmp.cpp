/*
    Knuth-Morris-Pratt (KMP) algorithm:
    A string searching algorithm that searches for a given "pattern" in a "text".
    It uses the fact that when a mismatch occurs, one can jump further in the text
    than a naive algorithm would (i.e. 1 step). The KMP algorithm can jump up to
    all the length of the search pattern.

    Time complexity:
    O(N + M), where N is the pattern size and M is the text size.

    Space complexity:
    O(N), where N is the pattern size.
*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> preprocess(string pattern) {
    // table of partial matches (to know where to jump in case of a mismatch)
    vector<int> table(pattern.length(), -1);
    size_t i = 0;
    int j = -1;

    // look for matches
    while (i < pattern.length()) {
        while (j >= 0 and pattern[i] != pattern[j])     // if there's a mismatch
            j = table[j];       // reset j with the table

        i++, j++;   // advance both counters when there's a match, or when j is reset
        table[i] = j;   // set the index to jump to
    }

    return table;
}

vector<int> search(string pattern, string text) {
    vector<int> table = preprocess(pattern);    // get the table of partial matches

    vector<int> indices(0);    // starting indices of text where the complete pattern is found
    size_t i = 0;
    int j = 0;

    // iterate over the entire text
    while (i < text.length()) {
        while (j >= 0 and text[i] != pattern[j])    // if there's a mismatch
            j = table[j];       // reset j with the table

        i++, j++;   // advance both counters when there's a match, or when j is reset

        if ((size_t) j == pattern.length()) {      // when the complete pattern is found,
            indices.push_back(i - j);   // save the starting index, and
            j = table[j];       // jump to the next index of a partial match
        }
    }

    return indices;
}

int main() {
    string text;
    cout << "Enter some text : ";
    getline(cin, text);

    string pattern;
    cout << "\nEnter the pattern to search : ";
    getline(cin, pattern);

    vector<int> indices = search(pattern, text);

    if (indices.size() == 1)
        cout << "\nPattern found at index " << indices[0] << "\n";
    else if (indices.size() > 1) {
        cout << "\nPattern found at indices : ";
        for (int index : indices)
            cout << index << ", ";
        cout << "\b\b \n";      // remove comma from the end
    }
    else
        cout << "\nCouldn\'t find the pattern!\n";

    return 0;
}

