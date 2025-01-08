#include <iostream>
#include <vector>
#include <algorithm> // untuk std::copy_if
using namespace std;

// Fungsi quickSort dalam gaya fungsional
vector<int> quickSort(const vector<int>& arr) {
    // Basis rekursi: Jika array memiliki ukuran <= 1, kembalikan array tersebut
    if (arr.size() <= 1) {
        return arr;
    }

    // Pivot: Elemen pertama dari array
    int pivot = arr[0];

    // Sub-array untuk elemen yang lebih kecil dari pivot
    vector<int> left;
    copy_if(arr.begin() + 1, arr.end(), back_inserter(left), [pivot](int x) { return x <= pivot; });

    // Sub-array untuk elemen yang lebih besar dari pivot
    vector<int> right;
    copy_if(arr.begin() + 1, arr.end(), back_inserter(right), [pivot](int x) { return x > pivot; });

    // Rekursi pada bagian kiri dan kanan, lalu gabungkan hasil
    vector<int> sortedLeft = quickSort(left);
    vector<int> sortedRight = quickSort(right);

    // Gabungkan hasil: sortedLeft + pivot + sortedRight
    sortedLeft.push_back(pivot);
    sortedLeft.insert(sortedLeft.end(), sortedRight.begin(), sortedRight.end());

    return sortedLeft;
}

int main() {
	cout << "Nama : Satrio Purnomo Aji" <<endl;
	cout << "Nim : 231011401204" <<endl;
	cout <<"=======================" <<endl;
	
	
    // Contoh array input
    vector<int> arr = {34, 7, 23, 32, 5, 62};

    cout << "Array sebelum sorting: ";
    for (int num : arr) {
        cout << num << " ";
    }
    cout << endl;

    // Panggil quickSort
    vector<int> sortedArray = quickSort(arr);

    cout << "Array setelah sorting: ";
    for (int num : sortedArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
