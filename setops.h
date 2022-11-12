//
// Created by Gottfried Istvan
//
#ifndef BEADANDO
#define BEADANDO

#include <set>
#include <algorithm>

template<typename T, typename S = std::greater<>>
class set_operations {
private:
    std::set<T, S> container_base;
    std::set<T, S> container_complement;
    bool complemented;

    std::set<T, S> const *get_current_container() const {
        return complemented ? &container_complement : &container_base;
    };

    std::set<T, S> const *get_negative_container() const {
        return complemented ? &container_base : &container_complement;
    };

    std::set<T, S> *get_current_container() {
        return complemented ? &container_complement : &container_base;
    };

    std::set<T, S> *get_negative_container() {
        return complemented ? &container_base : &container_complement;
    };

public:
    template<typename K = std::greater<>>
    explicit set_operations(std::set<T, K> const &other_set) {
        complemented = false;
        container_base.insert(other_set.begin(), other_set.end());
    };

    set_operations() {
        complemented = false;
    };

    template<typename K = std::greater<>>
    void set_union(std::set<T, K> const &other_set) {
        std::set<T, S> *add_to = get_current_container();
        std::set<T, S> *remove_from = get_negative_container();

        std::set<T, S> check_set;
        for (const auto &item: other_set) {
            if (remove_from->find(item) != remove_from->end()) {
                check_set.insert(item);
            }
        }
        for (const auto &item: check_set) {
            remove_from->erase(item);
        }
        add_to->insert(other_set.begin(), other_set.end());
    };

    void complement() {
        complemented = !complemented;
    };

    bool contains(const T element) const {
        return (container_base.find(element) == container_base.end()) == complemented;
    };

    bool subset(const std::set<T> other_set) const {
        std::set<T, S> const *current_container = get_current_container();

        std::set<T, S> check_set;
        check_set.insert(current_container->begin(), current_container->end());
        for (const auto &item: other_set) {
            check_set.insert(item);
        }
        return current_container->size() == check_set.size();
    }

    template<typename K = std::greater<>>
    set_operations &operator+=(std::set<T, K> const &other_set) {
        set_union(other_set);
        return *this;
    };

};

#endif //BEADANDO