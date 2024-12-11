#include <iostream>
#include <cstring>
#include <locale>

class String {
private:
    char* data;

public:
    String() {
        data = new char[81];
    }

    String(int size) {
        data = new char[size + 1];
    }

    String(const char* str) {
        data = new char[strlen(str) + 1];
        strcpy_s(data, strlen(str) + 1, str);
    }

    String(const String& other) {
        data = new char[strlen(other.data) + 1];
        strcpy_s(data, strlen(other.data) + 1, other.data);
    }

    void input() {
        std::cout << "Enter a string: ";
        std::cin.getline(data, 80);
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    void display() const {
        std::cout << "String: " << data << std::endl;
    }

    ~String() {
        delete[] data;
    }
};

int main() {
    std::locale::global(std::locale(""));

    String str1;
    str1.input();
    str1.display();

    String str2(50);
    str2.input();
    str2.display();

    String str3("Hello, world!");
    str3.display();

    String str4 = str3;
    str4.display();

    return 0;
}
