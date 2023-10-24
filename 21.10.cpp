#include <iostream>
#include <string>
using namespace std;

//  В строке текста записаны слова, разделенные пробелами в произвольном количестве.
//  Сжатие текста состоит в том, что 
//      между словами оставляется по одному пробелу,   
//      после последнего слова пробелы удаляются 
//      пробелы перед первым словом сохраняются.
//      Если строка содержит только пробелы, то все они сохраняются.

string compress(const string& input){
    string result;

    size_t firstWord = input.find_first_not_of(' ');
    if (firstWord == string::npos) {
        return input;
    }
    result.append(input, 0, firstWord);

    bool inWord = false;
    for (size_t i = firstWord; i < input.size(); ++i) {
        if (input[i] != ' ') {
            result += input[i];
            inWord = true;
        }
        else if (inWord) {
            result += ' ';
            inWord = false;
        }
    }

    if (!result.empty() && result.back() == ' ') {
        result.pop_back();
    }

    return result;

};

int main()
{
    string text = "  Hello    World! I'm     Making  the     Dezeshka  ";
    string compressed = compress(text);
    string spaces = "            ";

    cout << "Text [" << text << "]\n";
    cout << "Compressed string: [" << compressed << "]\n\n";

    compressed = compress(spaces);
    cout << "Spaces: [" << spaces << "]\n";
    cout << "Compressed string: [" << compressed << "]\n";
}
