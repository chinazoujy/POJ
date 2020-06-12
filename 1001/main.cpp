#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

std::string remove_zero(std::string s)
{
    std::string new_r = "";
    int begin = 0, end = 0;
    char skip_zero = '0';
    for (int i=0; i < s.length(); i++) {
        if (s[i] != skip_zero) {
            new_r += s[i];
            begin = 1;
        }else {
            if (begin != 0) {
                new_r += s[i];
            }
        }
    }
    return new_r;
}

std::string multi(std::string a, std::string b)
{
    char skip = '.';

    std::vector<std::vector<int> > all_part;

    int skip_count = 0;
    for (int j=a.length()-1; j >= 0; j--) {
        if (a[j] == skip) {
            skip_count = 1;
            continue;
        }

        int c = 0;  // 进位
        std::vector<int> part(a.length()-j-1-skip_count, 0);

        for (int k=b.length()-1; k >= 0; k--) {
            if ((a[j] != skip) && (b[k] != skip)) {
                int tmp = int(a[j] - '0') * int(b[k] - '0') + c;

                c = tmp / 10;
                part.push_back(tmp % 10);
            }
        }
        if (c != 0) {
            part.push_back(c);
        }
        std::reverse(part.begin(), part.end());
        all_part.push_back(part);
    }
    int max_length = 0;
    for (int i=0; i < all_part.size(); i++) {
        int len = all_part[i].size();
        if (len > max_length) {
            max_length = len;
        }
    }

    std::vector<int> result;
    int c = 0;
    for (int i=1; i <= max_length; i++) {
        int sum = 0;

        for (int j=0; j < all_part.size(); j++) {
            if (all_part[j].size() < i) { continue; }
            int idx = all_part[j].size() - i;
            sum += all_part[j][idx];
        }
        sum += c;
        c = sum / 10;
        result.push_back(sum % 10);
    }
    if (c != 0) {
        result.push_back(c);
    }
    std::reverse(result.begin(), result.end());

    int skip_b = 0;
    int pos = a.find(".");
    if (pos != a.npos) {
        skip_b += a.length() - pos - 1;
    }
    int pos2 = b.find(".");
    if (pos2 != b.npos) {
        skip_b += b.length() - pos2 - 1;
    }

    std::string re_s = "";
    for (int i=0; i < result.size(); i++) {
        if (i == result.size()-skip_b) {
            re_s += ".";
        }
        std::stringstream ss;
        ss << result[i];
        re_s += ss.str();
    }
    //std::cout << "re_s: " << re_s << std::endl;
    return re_s;
}

std::string preprocess(std::string s)
{
    std::string new_r = remove_zero(s);
    int has_point = new_r.find(".");
    if (has_point != new_r.npos) {
        std::reverse(new_r.begin(), new_r.end());
        new_r = remove_zero(new_r);
        std::reverse(new_r.begin(), new_r.end());

    }
    if (new_r[new_r.length()-1] == '.') {
        new_r.erase(new_r.length()-1, 1);
    }
    if (new_r.length() == 0) {
        return "0";
    }
    return new_r;

}

// 模拟法
std::string pow(std::string r, int n)
{
    if (n == 0) {
        return "1";
    } else if (n == 1) {
        return preprocess(r);
    }
    std::string result = r;

    for (int i=0; i < n-1; i++) {
        result = multi(result, r);
    }
    //std::cout << "result: " << result << std::endl;
    return preprocess(result);
}


// 分治法
std::string pow2(std::string r, int n)
{
    if (n == 0) {
        return "1";
    } else if (n == 1) {
        return r;
    }else {
        if (n%2 == 0) {
            std::string s = pow2(r, n/2);
            return multi(s, s);
        }else {
            std::string s = pow2(r, (n-1)/2);
            return multi(multi(s, s), r);
        }
    }

}

int main()
{
    std::string r;
    int n;
    while (std::cin >> r >> n)
    {
        std::string result = pow2(r, n);
        std::cout << preprocess(result) << std::endl;
        //std::cout << result << std::endl;
    }
    return 0;
}





