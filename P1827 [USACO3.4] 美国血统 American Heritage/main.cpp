#include <bits/stdc++.h>
typedef std::string str;
void post(str & mid, str & pre) {
    char root = pre[0];
    int root_pos = mid.find_first_of(root);
    str mid_left = mid.substr(0, root_pos), mid_right = mid.substr(root_pos+1, mid.length()-mid_left.length()-1);
    str pre_left = pre.substr(1, mid_left.length()), pre_right = pre.substr(1 + mid_left.length(), mid_right.length());
    if(mid_left.length()) post(mid_left, pre_left);
    if(mid_right.length()) post(mid_right, pre_right);
    putchar(root);
}

int main(void) {
    std::string mid, pre;
    std::cin >> mid >> pre;
    post(mid, pre);
    return 0;
}