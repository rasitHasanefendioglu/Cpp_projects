#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

template <typename key, typename value>
ostream& operator<<(ostream& stream, const map<key, value>& m){
    /// <summary>
    /// This is an operator overloading for printing maps. It is not necessary for the operation but helpfull for debugging purposes.
    /// It is taken from cppreference.com
    /// </summary>
    /// <typeparam name="key"></typeparam> key parameter of the map
    /// <typeparam name="value"></typeparam> value parameter of the map
    /// <param name="stream"></param>
    /// <param name="m"></param>
    /// <returns></returns>
    for (const pair<key, value>& t : m)
    {
        stream << t.first << " " << t.second << " " << endl;
    }
    return stream;
}

void string_preprocess(string &str,bool make_lower, bool remove_space) {
    
    if (make_lower) {
        for (int i = 0; i < str.size(); i++) {
            str[i] = tolower(str[i]);
        }
    }
    
    if (remove_space) {
        /*std::string::iterator end_pos = std::remove(str.begin(), str.end(), ' ');
        str.erase(end_pos, str.end());*/
        str.erase(remove_if(str.begin(), str.end(), isspace), str.end());
    }
    
}

char findMostRepeated(string str, vector <bool> preprocess = { false, false, false }) {
    map<char, int> occurence;
    if (preprocess[0]) {
        string_preprocess(str, preprocess[1], preprocess[2]);
    }
    int size = str.size();
    for (int i = 0; i < size; i++) {
        if (occurence.find(str[i]) == occurence.end()) {
            occurence.insert(make_pair(str[i], 1));
        }
        else {
            occurence[str[i]]++;
        }
    }
    //cout<<occurence;
    int max = 0;
    char result='\0';//initialization is not crucial if the string is not empty
    for (map<char, int >::const_iterator it = occurence.begin(); it != occurence.end(); it++) {
        if (max < it->second) {
            max = it->second;
            result = it->first;
        }
        
    }
    return result;
}

int main(int argc, char* argv[]) {
    
    if (argc == 1) {
        cout << "you entered nothing";
        getchar();
        return 0;
    }
    else if (argc>=3) {
        cout << "Use \" puntuation mark before and after your string or just the first word will be considered!!!" << "\n";
    }
    string str = argv[1];
    cout << findMostRepeated(str, {true,true,true});
    getchar();
    return 0;
}
