#include <bits/stdc++.h>
//#include <string>
#include <iostream>
using namespace std;
#define MAX_LEN 40

bool solver(string str, vector<string>&words)
{
    map<char, string> injection;
    map<string, char> surjection;
    //cout << injection.count('b')<< endl         << surjection["rat"].value << endl;
    if(str.length() != words.size())
        return false;
    // control being here connotates that, it passed the test..
    cout << "[INFO] mapping check starts.." << endl;
    for(int i=0; i<str.length(); i++)
    {
        // If no mapping exists earlier..
        if(injection.count(str[i]) == 0 && surjection.count(words[i]) == 0){
            injection[str[i]] = words[i];
            surjection[words[i]] = str[i];
            cout << "[INFO] first mapping" << endl;
        }
        // If occured once..
        //auto iter;
        //  if(injection.count(str[i]) > 0 || surjection.count(words[i]) >0){
        //     if(injection[str[i]] == (surjection.find(str[i]) -> first))
        //         cout <<  injection[str[i]] <<endl;// " -- " << surjection[str[i]] << endl;
        // }   
        //auto iter = surjection.find("apple");
        cout << (surjection.find("") -> second);
    }
        // If mapping exists earlier..
        //if( injection.find(words[i]) )
    for(const auto &[key, value]: injection)
        cout << key <<": " << value<< endl;
    for(const auto &[key, value]: surjection)
        cout << key <<": " << value << endl;
    
    return true;
}

int main()
{
    cout << __cplusplus << endl;
    string s1, s2, temp;
    //cin >> s1;
    getline(cin, s1);
    getline(cin, s2);
    //cout << s1<< s2;
    vector<string> words;

    // Place the words in list..
    stringstream X(s2);
    while(getline(X, temp, ' '))
        words.push_back(temp);
    
    // Logic starts..
    cout <<( solver(s1, words)? "true":"false" );
    
}