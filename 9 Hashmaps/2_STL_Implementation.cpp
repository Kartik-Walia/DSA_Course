#include<iostream>
#include<map>
#include<unordered_map>
using namespace std;

int main(){
    // ============================================== Creation ==============================================
    unordered_map<string,int> m;


    // ================================== Insertion - can be done in 3 ways ==================================
    // Way 1
    pair<string, int> p = make_pair("Kartik", 3);
    m.insert(p);
    // Way 2
    pair<string, int> pair2("Walia", 2);
    m.insert(pair2);
    // Way 3
    m["mera"] = 1;

    m["mera"] = 2;
    // When you create pair first time, new entry is created 
    // When you change value of pair second time, same entry is updated 

    // There always be a single entry for each key 
    // Duplicate entries doesn't exist for a key 


    // ============================================== Searching ==============================================
    // Way 1
    cout << m["mera"] << endl;
    // Way 2
    cout << m.at("Kartik") << endl;

    // What if we try to access an uncreated key 
    // cout << m.at("unknownKey") << endl;    // Gives error: key not found
    cout << m["unknownKey"] << endl;    // Gives 0 as this way of accessing creates entry for unknownKey correspodnign to 0
    cout << m.at("unknownKey") << endl; // Now this will also give 0, as entry is created for unknownKey above


    // ================================================= Size ================================================  
    cout << m.size() << endl;


    // =========================================== To check presence ==========================================
    cout << m.count("Kartik") << endl;
    // If key isn't present, count function returns 0, otherwise it returns 1


    // ============================================== Erase =============================================
    m.erase("Kartik");
    cout << m.size() << endl;


    // ============================================== Accessing =============================================
    for(auto i:m) {
        cout << i.first << " " << i.second << endl;
    }


    // =============================== Accessing (one by one through Iterator) ==============================
    unordered_map<string, int> :: iterator it = m.begin();
    while(it != m.end()) {  // Jab tak iterator map ke end tak nhi phuch jaata, data ko print krte rho
        cout << it->first << " " << it->second << endl;
        it++;
    }
    // Agar unordered_map banaya hai, toh jis order mei value daali thi ussi order mei print nhi hongi 
    // But agar map bnaya hai, toh ussi order mei print hongi


    return 0;
}