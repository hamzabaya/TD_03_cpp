#include <iostream>
#include <vector>
#include <map>
using namespace std;


void countFrequencyBruteForce(const vector<int>& numbers) {
    map<int, int> freq_map;
    for (int i = 0; i < numbers.size(); i++){
        int nbr_count = 0;
        for (int j = 0; j < numbers.size(); j++){
            if (numbers[i]==numbers[j]) {
                nbr_count ++;
            }
        }
        freq_map[numbers[i]] = nbr_count;
    }

    for (const auto&entry : freq_map){
        cout << entry.first << " : " << entry.second << " times " << endl;
    }
}



map<int, int> countFrequencyOptimal(const vector<int>& numbers) {
    map <int, int> freq_map;
    for (const int& num : numbers){
        freq_map[num] ++;
    }
    return freq_map;
}



int main() {
    vector<int> numbers = {1, 2, 3, 2, 4, 1, 5, 5, 6};
    // Test countFrequencyBruteForce
    cout << "Frequency (Brute Force): " << endl;
    countFrequencyBruteForce(numbers);
    // Test countFrequencyOptimal
    cout << "\nFrequency (Optimal): " << endl;
    map<int, int> frequencyMapOptimal = countFrequencyOptimal(numbers);
    for (const auto& entry : frequencyMapOptimal) {
        cout << entry.first << ": " << entry.second << " times" << endl;
    }
    return 0;
}
