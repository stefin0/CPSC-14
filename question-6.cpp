#include <iostream>
#include <vector>

using namespace std;

vector<string> split_string(string str, string range_str) {
    vector<string> result;
    int start_len, end_len;
    sscanf(range_str.c_str(), "%d-%d", &start_len, &end_len);

    // Remove whitespaces from the string
    str.erase(remove(str.begin(), str.end(), ' '), str.end());

    int pos = 0;
    while (pos < str.length()) {
        // Determine the length of the next word
        int len = rand() % (end_len - start_len + 1) + start_len;

        // Make sure we don't go past the end of the string
        if (pos + len > str.length()) {
            len = str.length() - pos;
        }

        // Add the word to the result array
        string word = str.substr(pos, len);
        result.push_back(word);

        pos += len;
    }

    // Sort the words using a custom comparison function
    sort(result.begin(), result.end(), [](const string& a, const string& b) {
        string::const_iterator ita = a.begin(), itb = b.begin();
        while (ita != a.end() && itb != b.end()) {
            if (isdigit(*ita) && !isdigit(*itb)) {
                return true;
            } else if (!isdigit(*ita) && isdigit(*itb)) {
                return false;
            } else if (isupper(*ita) && !isupper(*itb)) {
                return true;
            } else if (!isupper(*ita) && isupper(*itb)) {
                return false;
            } else if (*ita < *itb) {
                return true;
            } else if (*ita > *itb) {
                return false;
            } else {
                ++ita;
                ++itb;
            }
        }
        return a.length() < b.length();
    });

    return result;
}

int main() {
    string str = "abcdEfghijklmnoPqrsTuvwxyz";
    string range_str = "4-6";
    vector<string> result = split_string(str, range_str);
    for (const auto& word : result) {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}