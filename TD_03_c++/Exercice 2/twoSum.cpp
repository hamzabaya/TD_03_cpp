#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> twoSumBruteForce(const vector<int>& nums, int target) {
    vector<int> indice_map;

    for (int i=0; i < nums.size(); i++ ){
        for (int j = i+1; j < nums.size(); j++){
            if (nums[i] + nums[j] == target){
                indice_map.push_back(i);
                indice_map.push_back(j);
                return indice_map;
            }
        }
    }
    return indice_map;
}

vector<int> twoSumOptimal(const vector<int>& nums, int target) {
    unordered_map<int, int> num_map;
    vector<int> indices;

    for (int i=0; i<nums.size(); i++){
        int complement = target - nums[i];
        if (num_map.find(complement) != num_map.end()){
        // num_map.find(complement) recherche la clé complement dans la unordered_map num_map.
        // num_map.end() retourne un itérateur qui pointe juste après le dernier élément de la map, indiquant la fin de la map.
        //Donc, si num_map.find(complement) ne retourne pas num_map.end(), cela signifie que la clé complement existe dans la map.
            
            indices.push_back(num_map[complement]); // Add the index of the complement
            indices.push_back(i); // Add the index of the current number

            return indices;
        }
        num_map[nums[i]] = i; // Store the current number with its index in the map
    }
    return indices; 
}


int main() {
    vector<int> nums = {2, 7, 11, 15};
    int target = 9;

    vector<int> indicesBruteForce = twoSumBruteForce(nums, target);
    cout << "Brute Force Solution: [ "
        << indicesBruteForce[0] << ", "
        << indicesBruteForce[1] << " ]" << endl;

    vector<int> indicesOptimal = twoSumOptimal(nums, target);
    cout << "Optimal Solution: [ "
        << indicesOptimal[0] << ", "
        << indicesOptimal[1] << " ]" << endl;

    return 0;
}
