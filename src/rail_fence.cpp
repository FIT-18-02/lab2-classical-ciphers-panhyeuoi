#include <cctype>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool is_valid_message(const string &text) {
    for (char c : text) {
        if (!isalpha(static_cast<unsigned char>(c)) && c != ' ') {
            return false;
        }
    }
    return true;
}

// ===== ENCRYPT =====
string rail_fence_encrypt(const string &plaintext, int rails) {
    if (rails <= 1 || plaintext.empty()) return plaintext;

    vector<string> fence(rails, "");
    int rail = 0;
    int direction = 1;

    for (char c : plaintext) {
        // Q6: giữ dấu cách như ký tự bình thường
        fence[rail] += c;

        rail += direction;
        if (rail == rails - 1 || rail == 0)
            direction = -direction;
    }

    string ciphertext;
    for (const string &row : fence)
        ciphertext += row;

    return ciphertext;
}

// ===== DECRYPT =====
string rail_fence_decrypt(const string &ciphertext, int rails) {
    if (rails <= 1 || ciphertext.empty()) return ciphertext;

    int n = ciphertext.length();
    vector<vector<char>> matrix(rails, vector<char>(n, '\n'));

    // đánh dấu zigzag
    int row = 0, direction = 1;
    for (int col = 0; col < n; col++) {
        matrix[row][col] = '*';

        row += direction;
        if (row == 0 || row == rails - 1)
            direction = -direction;
    }

    // điền ký tự vào matrix
    int index = 0;
    for (int i = 0; i < rails; i++) {
        for (int j = 0; j < n; j++) {
            if (matrix[i][j] == '*' && index < n) {
                matrix[i][j] = ciphertext[index++];
            }
        }
    }

    // đọc zigzag để giải mã
    string result;
    row = 0;
    direction = 1;

    for (int col = 0; col < n; col++) {
        result += matrix[row][col];

        row += direction;
        if (row == 0 || row == rails - 1)
            direction = -direction;
    }

    return result;
}

// ===== READ FILE =====
string read_message_from_file(const string &path) {
    ifstream fin(path);
    string line;
    getline(fin, line);
    return line;
}

int main() {
    cout << "=== Rail Fence Cipher Demo ===\n";
    cout << "1. Encrypt\n2. Decrypt\n3. Read from file and encrypt\nChoose: ";

    int choice;
    cin >> choice;
    cin.ignore();

    string message;
    int rails;

    if (choice == 3) {
        message = read_message_from_file("data/input.txt");
        cout << "Message from file: " << message << "\n";
    } else {
        cout << "Enter message: ";
        getline(cin, message);
    }

    cout << "Enter rails: ";
    cin >> rails;

    if (!is_valid_message(message)) {
        cout << "Invalid input. Only letters and spaces are allowed.\n";
        return 0;
    }

    if (choice == 1 || choice == 3) {
        cout << "Ciphertext: " << rail_fence_encrypt(message, rails) << "\n";
    } else if (choice == 2) {
        cout << "Plaintext: " << rail_fence_decrypt(message, rails) << "\n";
    } else {
cout << "Invalid choice.\n";
    }

    return 0;
}
