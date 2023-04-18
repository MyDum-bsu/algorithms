#include <iostream>
#include <vector>
#include <string>
#include <map>

class Trie {
public:
    struct Node {
        char char_to_parent = '0';
        bool is_terminal = false;
        int string_index = -1;
        Node *suffix_link = nullptr;
        Node *closest_terminal = nullptr;
        std::map<char, Node *> next;
        Node *parent = nullptr;

        bool IsRoot() const {
            return char_to_parent == '0';
        }
    };

    explicit Trie(const std::vector<std::string> &vector) {
        nodes_.push_back(new Node());
        root_ = nodes_[0];
        for (int i = 0; i < vector.size(); i++) {
            Add(vector[i], i);
        }
    }

    void Add(const std::string &string, int index) {
        auto current_node = root_;
        for (auto c: string) {
            auto &next_node = current_node->next[c];
            if (next_node == nullptr) {
                next_node = new Node();
                nodes_.push_back(next_node);
                next_node->parent = current_node;
                next_node->char_to_parent = c;
            }
            current_node = next_node;
        }

        current_node->is_terminal = true;
        current_node->string_index = index;
    }

    Node *Go(Node *vertex, char c) {
        auto &next_node = vertex->next[c];
        if (next_node == nullptr) {
            if (vertex == root_) {
                next_node = root_;
            } else {
                next_node = Go(GetSuffixLink(vertex), c);
            }
        }
        return next_node;
    }

    Node *GetSuffixLink(Node *node) {
        if (node->suffix_link != nullptr) {
            return node->suffix_link;
        }

        if (node == root_ || node->parent == root_) {
            node->suffix_link = root_;
        } else {
            node->suffix_link = Go(GetSuffixLink(node->parent), node->char_to_parent);
        }
        return node->suffix_link;
    }

    Node *GetClosestTerminal(Node *node) {
        if (node->closest_terminal != nullptr) {
            return node->closest_terminal;
        }
        if (node->is_terminal) {
            return node;
        }
        if (node->IsRoot()) {
            return node;
        }
        return (node->closest_terminal = GetClosestTerminal(GetSuffixLink(node)));
    }

    Node *GetRoot() {
        return root_;
    }

private:
    std::vector<Node *> nodes_;
    Node *root_;
};

bool IsSubstring(std::string& str1, std::string& str2) {
    if (str1.size() > str2.size()) {
        swap(str1, str2);
    }
    for (int i = 0; i < (int)(str2.size() - str1.size() + 1); i++) {
        if (str2.substr(i, str1.size()) == str1) {
            return true;
        }
    }
    return false;
}


int main() {
    int n;
    std::ios_base::sync_with_stdio(false);
    std::cin >> n;
    if (n == 1) {
        std::cout << "NO";
        return 0;
    }
    if (n == 2) {
        std::string s1, s2;
        std::cin >> s1;
        std::cin >> s2;
        if (s1.find(s2) != std::string::npos || s2.find(s1) != std::string::npos) {
            std::cout << "YES";
        } else {
            std::cout << "NO";
        }
        return 0;
    }

    std::vector<std::string> strings(n);
    for (int i = 0; i < n; i++) {
        std::cin >> strings[i];
    }

    if (n <= 1e3) {
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (IsSubstring(strings[i], strings[j])) {
                    std::cout << "YES";
                    return 0;
                }
            }
        }
        std::cout << "NO";
        return 0;
    }

    Trie trie(strings);

    for (int word_index = 0; word_index < strings.size(); word_index++) {
        auto &word = strings[word_index];
        auto v = trie.GetRoot();

        for (char i: word) {
            v = trie.Go(v, i);
            if (v->string_index == word_index) {
                v = trie.GetSuffixLink(v);
            }
            if (v->is_terminal || !trie.GetClosestTerminal(v)->IsRoot()) {
                std::cout << "YES";
                return 0;
            }
        }
    }
    std::cout << "NO";
    return 0;
}