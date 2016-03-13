#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


bool isAnagram(string s, string t);
bool isAnagram_Map(string s, string t);

int main() {

    cout << "Hello, World!" << endl;

    string a="cdse";
    string b="dsce";

    if(isAnagram_Map(a,b))
        cout<<"YES";
    else
        cout<<"NO";

    return 0;
}

bool isAnagram_Map(string s, string t){

    if(s.size()!=t.size()) return false;

    unordered_map<char,int> count;

    for(int i=0;i<s.size();i++){
        count[s[i]]++;
        count[t[i]]--;
    }

    unordered_map<char,int>::iterator ite;

    for(ite=count.begin();ite!=count.end();ite++){

        cout<<ite->first<<"; "<<ite->second<<endl;

        if(ite->second)
            return false;
    }

    return true;

}


bool isAnagram(string s, string t){

    if(s.size()!=t.size()) return false;

    vector<int> count(26);

    for(int i=0;i<s.size();i++){
        count[s[i]-'a']++;
        count[t[i]-'a']--;
    }

    for(int i=0;i<count.size();i++) {
        if (count[i] != 0)
            return false;
    }

    return true;
}
