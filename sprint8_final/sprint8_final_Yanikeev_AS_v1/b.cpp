/* номре посылки: 82407413 */
/*
Принцип работы и доказательство коррекности:
Создаетсяя префиксное дерево на основе существующих слов, производится проверка
искомой строки по символьно в существующем дереве. Для каждого символа буду 
помечать являетсяя ли оно концом слова, исходя из данных в дереве (является
ли узел в дереве терминирующим, т.е. концом слова). Конец искомой фразы должен 
быть терминирующим, т.к. в ином случае, это будем показатель, что какое слово 
не полное.

Врмененная сложность:
O(L) - где  L — суммарная длина всех слов. O(n*n) в алгоритме проверки фразы (функция 
can_split), где n - количество символов в строке.

Пространственна сложность:
O(L) для префикосного дерева, где L — суммарная длина всех слов.
O(n) в алгоритме проверки фразы (функция can_split), где n - количество символов 
в строке.
Итоговая O(L + n)

*/

#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <memory>

class CharNode
{
public:
    CharNode(char value): value_(value) {}

    std::shared_ptr<CharNode> add_or_get(char key) {
        auto it = ders_.find(key);
        if (it == ders_.end()) {
            ders_[key] = std::make_shared<CharNode> (key);
        }
        return ders_[key];
    }

    std::shared_ptr<CharNode> get_next(char key) {
        auto it = ders_.find(key);
        return it == ders_.end() ? nullptr : ders_[key];
    }

    bool is_terminal() {
        return terminal_;
    }

    void make_terminal() {
        terminal_ = true;
    }

private:
    const char value_;
    std::unordered_map<char, std::shared_ptr<CharNode> > ders_;
    bool terminal_;
    int word_len_;
};

std::shared_ptr<CharNode> create_tree(const std::vector<std::string>& values) {
    std::shared_ptr<CharNode> head = std::make_shared<CharNode> ('#');

    for(const std::string& s: values) {
        std::shared_ptr<CharNode> cur_node = head;
        int cur_len = s.length();
        for(int i = 0 ; i < cur_len; ++i ) {
            cur_node = cur_node->add_or_get(s[i]);
        }
        cur_node->make_terminal();
    }
    return head;
}

bool can_split(const std::string& to_check, const std::vector<std::string>& values) {
    std::shared_ptr<CharNode> head = create_tree(values);
    std::vector<bool> dp(to_check.size() + 1, false);
    dp[0] = true;
    for(int i = 0 ; i < to_check.size() ; ++i) {
        std::shared_ptr<CharNode> node = head;
        if (dp[i]) {
            for(int j = i ; j < to_check.size() + 1 ; ++j) {
                if (node->is_terminal()) {
                    dp[j] = true;
                }
                node = node->get_next(to_check[j]);
                if (j == to_check.size() || node == nullptr) {
                    break;
                }
            }
        }
    }
    return dp[dp.size() - 1];
}


int main() {
    int n;
    std::string to_check;
    std::cin >> to_check;
    std::cin >> n;
    std::vector<std::string> values(n);
    for(std::string& v: values) {
        std::cin >> v;
    }
    bool res = can_split(to_check, values);
    std::cout << (res ? "YES" : "NO") << std::endl;
}
