// A set_operations template a matematikai halmaz
// fogalmat valósítja meg: egy std::set elemeiből indul ki, a contains
// eldönti, hogy a paraméter a halmazban van-e, lehet  komplementert képezni
// (complement), uniózni (set_union), vizsgálni, hogy a paraméterként kapott
// std::set részhalmaza-e az elemeknek. A += operátor szintén unióként
// működik.

#include <iostream>
#include "setops.h"
#include <set>
#include "setops.h"
#include <algorithm>
#include <iterator>
#include <string>
#include <numeric>

struct string_size_less {

    bool operator()(const std::string &a,
                    const std::string &b) {
        return a.size() < b.size();
    }

};

const int maxF = 1000;

bool checko() {
    std::set<int> si;
    for (int i = 0; i < maxF; ++i) {
        si.insert(i);
    }

    std::set<std::string> msgs;
    msgs.insert("Hi");
    msgs.insert("Hello");
    msgs.insert("Ciao");
    msgs.insert("Aloha");

    set_operations<std::string> ops(msgs);
    const set_operations<std::string> cops(msgs);

    set_operations<int> opi(si);
    for (int i = 0; i < maxF; ++i) {
        opi.complement();
    }

    ops.complement();

    if (!cops.contains("Hi") || !opi.contains(maxF / 2) ||
        ops.contains("Ciao") || ops.contains("Aloha") ||
        opi.contains(2 * maxF) || cops.contains("?") ||
        cops.contains("NullPointerException") || !ops.contains("C++")) {
        return false;
    }

    std::set<std::string> w;
    w.insert(":-)");
    w.insert(":-P");
    w.insert("Ciao");
    ops.set_union(w);

    std::set<int> nums;
    nums.insert(maxF / 2);
    nums.insert(maxF / 3);
    nums.insert(maxF);

    opi.complement();
    opi.set_union(nums);
    opi.complement();


    if (opi.contains(maxF / 2) || !opi.contains(maxF / 4) ||
        !ops.subset(w) || cops.subset(w) ||
        ops.contains("Hi") || !ops.contains("Ciao") ||
        !ops.contains(":-P") || cops.contains(":-P")) {
        ops.complement();
        return false;
    }

    std::set<std::string, string_size_less> x;
    x.insert("Hello");
    x.insert("Ciao");

    std::set<std::string, std::greater<std::string> > a;
    a.insert(":-o");

    set_operations<std::string> m(x);
    m.set_union(a);

    return (!m.contains(":-/") && !m.subset(msgs));
}

int main() {
    std::cout
            << "Your solution is "
            << (checko() ? "" : "not ")
            << "ready for submission."
            << std::endl;
}
