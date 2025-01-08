#include <iostream>
#include <complex>
using namespace std;

// Fungsi untuk menghitung apakah titik termasuk dalam Mandelbrot Set
bool isInMandelbrotSet(complex<double> c, int maxIterations) {
    complex<double> z = 0;
    for (int i = 0; i < maxIterations; i++) {
        z = z * z + c;
        if (abs(z) > 2.0) {
            return false; // Jika nilai absolut z lebih dari 2, titik keluar dari himpunan
        }
    }
    return true; // Titik termasuk dalam himpunan
}

// Fungsi utama
int main() {
	cout << "Nama  : Satrio purnomo aji" << endl;
	cout << "NIM   : 231011401204		  " << endl;
	cout << "Kelas : 03TPLP029			  " << endl;
	cout << "==============================" << endl << endl;
	
    const int width = 80;  // Lebar output
    const int height = 40; // Tinggi output
    const int maxIterations = 1000; // Jumlah iterasi maksimum
    const double xmin = -2.5, xmax = 1.0; // Rentang real
    const double ymin = -1.0, ymax = 1.0; // Rentang imajiner

    // Skala untuk koordinat kompleks
    double dx = (xmax - xmin) / width;
    double dy = (ymax - ymin) / height;

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            complex<double> c(xmin + x * dx, ymax - y * dy);
            if (isInMandelbrotSet(c, maxIterations)) {
                cout << "@"; // Titik dalam himpunan
            } else {
                cout << " "; // Titik di luar himpunan
            }
        }
        cout << endl;
    }
    return 0;
}