#include <iostream>

bool check_string(std::string str) {
    int check = 0;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == '@')
            ++check;
    }

    if (check == 0 || check > 1)
        return false;

    return true;
}

std::string first_part_string(std::string str) {
    std::string first_part_line = "";

    for (int i = 0; str[i] != '@'; ++i) {
        first_part_line += str[i];
    }

    return first_part_line;
}

std::string second_part_string(std::string str) {
    std::string second_part_line = "";

    for (int i = first_part_string(str).length() + 1; i < str.length(); ++i) {
        second_part_line += str[i];
    }

    return second_part_line;
}

bool check_symbols_first_part(char line) {
    std::string admitted_symbols =
        "!#$%&'*+-/=?^_`{|}~-.0123456789abcdefghijklmnopqrstwxyzABCDEFGHIJKLMNOPQRSTWXYZ";

    for (int j = 0; j < admitted_symbols.length(); ++j) {
        if (line == admitted_symbols[j]) {
            return true;
        }
    }
    return false;
}

bool check_symbols_second_part(char line) {
    std::string admitted_symbols =
        "-.0123456789abcdefghijklmnopqrstwxyzABCDEFGHIJKLMNOPQRSTWXYZ";

    for (int j = 0; j < admitted_symbols.length(); ++j) {
        if (line == admitted_symbols[j]) {
            return true;
        }
    }
    return false;
}

bool check_first_part_string(std::string str) {
    if (str.length() < 1 || str.length() > 64) {
        return false;
    }

    for (int i = 0; i < str.length(); ++i) {
        if (!check_symbols_first_part(char(str[i])) || (str[i] == '.' && str[i + 1] == '.')
            || str[0] == '.' || str[str.length() - 1] == '.') {
            return false;
        }
    }
    return true;
}

bool check_second_part_string(std::string str) {
    if (str.length() < 1 || str.length() > 63) {
        return false;
    }

    for (int i = 0; i < str.length(); ++i) {
        if (!check_symbols_second_part(char(str[i])) || (str[i] == '.' && str[i + 1] == '.')
            || str[0] == '.' || str[str.length() - 1] == '.') {
            return false;
        }
    }
    return true;
}

int main() {
    std::string email;
    std::cout << "Input your email ";
    std::cin >> email;

    (check_string(email) && check_first_part_string(first_part_string(email))
        && check_second_part_string(second_part_string(email))) ?
        (std::cout << "Yes" << std::endl) : (std::cout << "No" << std::endl);
}