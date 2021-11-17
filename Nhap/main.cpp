
#include<iostream>
#include<string>
#include<vector>
using namespace std;
vector<string> result;
void Permute(string s, int left, int right) {

    if (left == right)
    {
        result.push_back(s);
    }
    else {
        for (int i = left; i <= right; i++)
        {
            swap(s[left], s[i]);
            Permute(s, left + 1, right);
            swap(s[left], s[i]);
        }
    }
}
bool checkInclusion(string s1, string s2) {
    int n1 = s1.size();
    int n2 = s2.size();
    int flag;
    if (n1 < n2) {
        flag = 1;
    }
    else {
        flag = 0;
    }


    if (flag == 1) {
        int start = 0;
        int end;
        Permute(s1, 0, n1 - 1);
        end = start + n1 - 1;
        while (end < n2) {
            string s = "";
            for (int i = start; i <= end; i++) {
                s = s + s2[i];
            }
            for (int j = 0; j < result.size(); j++) {
                if (result[j] == s) {
                    return true;
                }
            }
            start++;
            end++;
        }
    }
    else {
        int start = 0;
        int end;
        Permute(s2, 0, n2 - 1);
        end = start + n2 - 1;
        while (end < n1) {
            string s = "";
            for (int i = start; i <= end; i++) {
                s = s + s1[i];
            }
            for (int j = 0; j < result.size(); j++) {
                if (result[j] == s) {
                    return true;
                }
            }
            start++;
            end++;
        }
    }
    return false;
}

int main() {
    string s1 = "ccc";
    string s2 = "cbac";
    if (checkInclusion(s1, s2)==true) {
        cout << "OK";
    }
    else {
        cout << "fail";
    }
}