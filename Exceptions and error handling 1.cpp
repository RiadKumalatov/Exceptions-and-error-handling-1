#include <iostream>
#include <string>
#include <stdexcept>

class bad_length : public std::exception {
public:
    const char* what() const noexcept override {
        return "�� ����� ����� ��������� �����! �� ��������";
    }
};

int function(std::string str, int forbidden_length) {
    if (str.length() == forbidden_length) {
        throw bad_length();
    }
    return str.length();
}

int main() {
    setlocale(LC_ALL, "Russian");

    int forbidden_length;
    std::cout << "������� ��������� �����: ";
    std::cin >> forbidden_length;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');  

    std::string word;
    while (true) {
        std::cout << "������� �����: ";
        std::getline(std::cin, word);

        try {
            int length = function(word, forbidden_length);
            std::cout << "����� ����� \"" << word << "\" ����� " << length << std::endl;
        }
        catch (const bad_length& e) {
            std::cout << e.what() << std::endl;
            break;
        }
    }

    return 0;
}
