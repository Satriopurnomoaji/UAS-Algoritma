#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// Radix Sort
void countingSort(vector<int>& arr, int exp) {
    int n = arr.size();
    vector<int> output(n);
    int count[10] = {0};

    // Hitung frekuensi digit
    for (int i = 0; i < n; i++) {
        count[(arr[i] / exp) % 10]++;
    }

    // Akumulasi count
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Bangun array output
    for (int i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }

    // Salin ke array asli
    for (int i = 0; i < n; i++) {
        arr[i] = output[i];
    }
}

void radixSort(vector<int>& arr) {
    int maxVal = *max_element(arr.begin(), arr.end());
    for (int exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(arr, exp);
    }
}

// Quick Sort
int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

// Merge Sort
void merge(vector<int>& arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        R[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k++] = L[i++];
        } else {
            arr[k++] = R[j++];
        }
    }

    while (i < n1) {
        arr[k++] = L[i++];
    }

    while (j < n2) {
        arr[k++] = R[j++];
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

// Main function
int main() {
	cout << "Nama : Satrio Purnomo Aji" <<endl;
	cout << "Nim : 231011401204" <<endl;
	cout <<"================"<<endl;
    vector<int> arr = {170, 45, 75, 90, 802, 24, 2, 66};

    cout << "Array sebelum sorting:\n";
    for (int num : arr) cout << num << " ";
    cout << endl;

    // Radix Sort
    vector<int> radixArr = arr;
    radixSort(radixArr);
    cout << "Array setelah Radix Sort:\n";
    for (int num : radixArr) cout << num << " ";
    cout << endl;

    // Quick Sort
    vector<int> quickArr = arr;
    quickSort(quickArr, 0, quickArr.size() - 1);
    cout << "Array setelah Quick Sort:\n";
    for (int num : quickArr) cout << num << " ";
    cout << endl;

    // Merge Sort
    vector<int> mergeArr = arr;
    mergeSort(mergeArr, 0, mergeArr.size() - 1);
    cout << "Array setelah Merge Sort:\n";
    for (int num : mergeArr) cout << num << " ";
    cout << endl;

    return 0;
}
