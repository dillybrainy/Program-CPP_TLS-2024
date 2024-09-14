#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

double celsiusToFahrenheit(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

double celsiusToKelvin(double celsius) {
    return celsius + 273.15;
}

double fahrenheitToCelsius(double fahrenheit) {
    return (fahrenheit - 32.0) * 5.0 / 9.0;
}

double kelvinToCelsius(double kelvin) {
    return kelvin - 273.15;
}

int main() {
    int pilihan;
    double suhu, hasil;

    cout << "Program Konversi Suhu\n";
    cout << "1. Celsius ke Fahrenheit\n";
    cout << "2. Celsius ke Kelvin\n";
    cout << "3. Fahrenheit ke Celsius\n";
    cout << "4. Kelvin ke Celsius\n";
    cout << "Pilih konversi (1-4): ";
    cin >> pilihan;

    if (pilihan < 1 || pilihan > 4 || cin.fail()) {
        cout << "Pilihan tidak valid.\n";
        return 1; // Keluar dari program dengan kode error
    }

    cout << "Masukkan suhu: ";
    cin >> suhu;

    if (cin.fail()) {
        cout << "Input suhu tidak valid.\n";
        return 1; // Keluar dari program dengan kode error
    }

    cout << fixed << setprecision(2);  // Set presisi untuk output

    switch (pilihan) {
        case 1:
            hasil = celsiusToFahrenheit(suhu);
            cout << suhu << " Celsius = " << hasil << " Fahrenheit\n";
            break;
        case 2:
            hasil = celsiusToKelvin(suhu);
            cout << suhu << " Celsius = " << hasil << " Kelvin\n";
            break;
        case 3:
            hasil = fahrenheitToCelsius(suhu);
            cout << suhu << " Fahrenheit = " << hasil << " Celsius\n";
            break;
        case 4:
            hasil = kelvinToCelsius(suhu);
            cout << suhu << " Kelvin = " << hasil << " Celsius\n";
            break;
    }

    // Menampilkan informasi tambahan tentang suhu
    double celsiusEquiv = (pilihan == 1 || pilihan == 2) ? suhu : hasil;
    if (abs(celsiusEquiv) < 0.5) {
        cout << "Suhu mendekati titik beku air (0°C)\n";
    } else if (abs(celsiusEquiv - 100) < 0.5) {
        cout << "Suhu mendekati titik didih air (100°C)\n";
    } else if (celsiusEquiv < -273.15) {
        cout << "Perhatian: Suhu di bawah nol mutlak tidak mungkin dalam fisika klasik\n";
    }

    return 0;
}
