#include <iostream>
#include <string>
#include <algorithm>
#include <map>

std::string preprocessing(std::string s)
{
    std::string new_s = "";
    for (int i=0; i < s.length(); i++) {
        if (s[i] == '-') {
            continue;
        }else if(s[i] >= 'A' && s[i] <= 'Z') {
            std::string number;
            if (s[i] == 'A' || s[i] == 'B' || s[i] == 'C') {
                number = "2";
            }else if(s[i] == 'D' || s[i] == 'E' || s[i] == 'F') {
                number = "3";
            }else if(s[i] == 'G' || s[i] == 'H' || s[i] == 'I') {
                number = "4";
            }else if(s[i] == 'J' || s[i] == 'K' || s[i] == 'L') {
                number = "5";
            }else if(s[i] == 'M' || s[i] == 'N' || s[i] == 'O') {
                number = "6";
            }else if(s[i] == 'P' || s[i] == 'R' || s[i] == 'S') {
                number = "7";
            }else if(s[i] == 'T' || s[i] == 'U' || s[i] == 'V') {
                number = "8";
            }else if(s[i] == 'W' || s[i] == 'X' || s[i] == 'Y') {
                number = "9";
            }
            new_s += number;
        }else {
            new_s += s[i];
        }
        if (new_s.length() == 3) {
            new_s += "-";
        }
    }
    return new_s;
}

int main()
{
    int n;
    std::map<std::string, int> res;

    std::cin >> n;
    for (int i=0; i < n; i++) {
        std::string temp;
        std::cin >> temp;
        std::string p_temp = preprocessing(temp);
        if (res.find(p_temp) != res.end()) {
            res[p_temp] += 1;
        }else {
            res[p_temp] = 1;
        }
    }

    int has_result = -1;
    for (std::map<std::string, int>::iterator i = res.begin(); i != res.end(); i++) {
        if (i->second > 1) {
            std::cout << i->first << " " << i->second << std::endl;
            has_result = 0;
        }
    }
    if (has_result == -1) {
        std::cout << "No duplicates." << std::endl;
    }
    return 0;
}








