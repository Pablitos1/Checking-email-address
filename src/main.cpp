#include <iostream>

bool check_string(std::string str) {
    int check = 0;
    for (int i = 0; i < str.length(); ++i) {
        if (str[i] == '@')
            ++check;
    }
    return (check == 0 || check > 1) ? false : true;
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

bool check_symbols(std::string str1, std::string str2) {
    int current1 = 0;
    int current2 = 0;
    std::string admitted_symbols1 =
        "!#$%&'*+-/=?^_`{|}~-.0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTWXYZ";
    std::string admitted_symbols2 =
        "-.0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTWXYZ";

    for (int i = 0; i < str1.length(); ++i) {
        for (int j = 0; j < admitted_symbols1.length(); ++j) {
            (str1[i] == admitted_symbols1[j]) ? current1++ : current1;
        }
    }

    for (int i = 0; i < str2.length(); ++i) {
        for (int j = 0; j < admitted_symbols2.length(); ++j) {
            (str2[i] == admitted_symbols2[j]) ? current2++ : current2;
        }
    }
    return (current1 < str1.length() || current2 < str2.length()) ? false : true;
}

bool check_parts_string(std::string str1, std::string str2) {
    if (str1.length() < 1 || str1.length() > 64
        || str2.length() < 1 || str2.length() > 63) {
        return false;
    }

    for (int i = 0; i < str1.length(); ++i) {
        if (!check_symbols(str1, str2) || (str1[i] == '.' && str1[i + 1] == '.')
            || (str2[i] == '.' && str2[i + 1] == '.') || str1[0] == '.'
            || str2[0] == '.' || str1[str1.length() - 1] == '.'
            || str2[str2.length() - 1] == '.')
            return false;
    }
    return true;
}

bool check_all_email(std::string email) {
    return (check_string(email)
        and check_parts_string(first_part_string(email), second_part_string(email))) ? true : false;
}

int main() {
    std::string email;
    std::cout << "Input your email ";
    std::cin >> email;
    (check_all_email(email)) ? (std::cout << "Yes" << std::endl) : (std::cout << "No" << std::endl);
}