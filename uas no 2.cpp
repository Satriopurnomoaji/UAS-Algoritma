#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

// Fungsi untuk menemukan pasangan dengan jumlah K
vector<pair<int, int>> findPairsWithSumK(const vector<int>& arr1, const vector<int>& arr2, int K) {
    unordered_set<int> elements; // Hash table untuk menyimpan elemen arr1
    vector<pair<int, int>> result; // Untuk menyimpan pasangan yang valid

    // Masukkan semua elemen dari arr1 ke dalam hash table
    for (int num : arr1) {
        elements.insert(num);
    }

    // Iterasi melalui arr2 dan cari pasangan
    for (int num : arr2) {
        int complement = K - num;
        if (elements.find(complement) != elements.end()) {
            result.emplace_back(complement, num);
        }
    }

    return result;
}

int main() {
	cout << "Nama : bagas arya dhika" <<endl;
	cout << "NIM : 231011401197" <<endl;
	cout << "=============================" <<endl;
    vector<int> arr1 = {1, 2, 3, 4, 5};
    vector<int> arr2 = {6, 7, 8, 9, 10};
    int K;

    cout << "Masukkan nilai K: ";
    cin >> K;

    // Cari pasangan dengan jumlah K
    vector<pair<int, int>> pairs = findPairsWithSumK(arr1, arr2, K);

    // Cetak hasil
    cout << "Pasangan dengan jumlah " << K << ":\n";
    for (const auto& p : pairs) {
        cout << "(" << p.first << ", " << p.second << ")\n";
    }

    if (pairs.empty()) {
        cout << "Tidak ada pasangan dengan jumlah " << K << endl;
    }

    return 0;
}
