#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>
#include <string>

using namespace std;

// Struktur node pohon Huffman
struct HuffmanNode {
    char ch;
    int freq;
    HuffmanNode *left, *right;

    HuffmanNode(char character, int frequency) {
        ch = character;
        freq = frequency;
        left = right = nullptr;
    }
};

// Comparator untuk priority queue
struct Compare {
    bool operator()(HuffmanNode* left, HuffmanNode* right) {
        return left->freq > right->freq;
    }
};

// Fungsi untuk membangun pohon Huffman
HuffmanNode* buildHuffmanTree(const unordered_map<char, int>& frequencies) {
    priority_queue<HuffmanNode*, vector<HuffmanNode*>, Compare> pq;

    // Buat simpul untuk setiap karakter
    for (const auto& pair : frequencies) {
        pq.push(new HuffmanNode(pair.first, pair.second));
    }

    // Gabungkan simpul hingga hanya ada satu simpul (akar)
    while (pq.size() > 1) {
        HuffmanNode* left = pq.top(); pq.pop();
        HuffmanNode* right = pq.top(); pq.pop();

        HuffmanNode* merged = new HuffmanNode('\0', left->freq + right->freq);
        merged->left = left;
        merged->right = right;
        pq.push(merged);
    }

    return pq.top();
}

// Fungsi untuk membangun tabel kode Huffman
void buildHuffmanCodes(HuffmanNode* root, const string& str, unordered_map<char, string>& huffmanCodes) {
    if (!root) return;

    // Jika simpul adalah daun, simpan kode biner
    if (!root->left && !root->right) {
        huffmanCodes[root->ch] = str;
    }

    buildHuffmanCodes(root->left, str + "0", huffmanCodes);
    buildHuffmanCodes(root->right, str + "1", huffmanCodes);
}

// Fungsi untuk melakukan encoding
string encode(const string& text, const unordered_map<char, string>& huffmanCodes) {
    string encodedString;
    for (char ch : text) {
        encodedString += huffmanCodes.at(ch);
    }
    return encodedString;
}

// Fungsi untuk melakukan decoding
string decode(HuffmanNode* root, const string& encodedString) {
    string decodedString;
    HuffmanNode* current = root;

    for (char bit : encodedString) {
        if (bit == '0') {
            current = current->left;
        } else {
            current = current->right;
        }

        // Jika mencapai daun, tambahkan karakter ke hasil
        if (!current->left && !current->right) {
            decodedString += current->ch;
            current = root;
        }
    }

    return decodedString;
}

int main() {
    string text;
    cout << "Nama : Satrio Purnomo Aji" <<endl;
    cout << "NIM : 231011401204" <<endl;
    cout << "========================" <<endl;
    cout << "Masukkan string untuk dikompresi: ";
    getline(cin, text);

    // Hitung frekuensi setiap karakter
    unordered_map<char, int> frequencies;
    for (char ch : text) {
        frequencies[ch]++;
    }

    // Bangun pohon Huffman
    HuffmanNode* root = buildHuffmanTree(frequencies);

    // Bangun kode Huffman
    unordered_map<char, string> huffmanCodes;
    buildHuffmanCodes(root, "", huffmanCodes);

    // Tampilkan kode Huffman
    cout << "\nKode Huffman untuk setiap karakter:\n";
    for (const auto& pair : huffmanCodes) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Encode string
    string encodedString = encode(text, huffmanCodes);
    cout << "\nString terkompresi (encoded): " << encodedString << endl;

    // Decode string
    string decodedString = decode(root, encodedString);
    cout << "\nString setelah didekode: " << decodedString << endl;

    return 0;
}
