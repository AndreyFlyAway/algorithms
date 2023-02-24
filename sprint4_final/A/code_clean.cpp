/* номре посылки: */
/*
Принцип работы:
1. Обрабатываются все слова из каждого документа. Каждое слово в качестве ключа
помещается в хеш-таблицу (далее просто map), в качесвте значения используется
другой map, в данный map уже помещается номер документа и количество вхождений 
данного слова в документ. 
2. Обрабатывается все запросы, каждый запрос обрабатывается в цикле.
2.1 Для текущего запроса выдлеяю массив пар равный количеству документов + 1, в
него буду помещать пару, где первое значение индекс документа, второе значение
релевантность, все значения инициализирую нулями.
2.2. Каждое слово помещается в множество уникальных объектов (далее set), 
если объект отсутствуе в данном set, то это слово ищется в map слов из всех 
документов из п.1, если найден, то могу получить индекс документа, обращаюсь 
к массив пар из п. 2.1 и по данному иднексу документа в пару выставляю значение 
индекса и добавляю значение вхожденияя данного слово - так получаю релевнтность 
документа для текущего запроса.
2.3. Соритрую результат быстрой сортировкой, помещаю реузльтат в массив результатов.
Возвращаю результаты. 
3. Вывожу результаты.

Врмененная сложность:
Обработать все слова и поместить в map O(n), где n - колиестсвто слов во всех 
документах. Обработать все слова из запроса и отсортировать результат - O(m(k + nlogn)),
где k - колиество слов в запросе для каждогоиз m запросов.
Итогова сложность O(n + m(k + nlog n)).

Пространственна сложность:
O(n) - для всех слов из докуметнов. O(l) - для всех слов из запроса, 
где l - слова из самого большог озапроса.
Итоговая O(n + l).

Доказательство коррекности:
В методе обработки документов получаю вхождение каждого слова из каждого
документа, таким образом смогу брать каждое слово из запроса, получить 
колиество вхождений и посчитать релевантность документа для текущего 
запроса, затем спокойно можно отсартировать результаты. 
*/
#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <set>
#include <algorithm>

using Umap = std::unordered_map<std::string, std::unordered_map<int,int>>;
using Pairs = std::vector<std::vector<std::pair<int, int>>>;

/* 
Компаратор для пар, используется для сортировки результатов.
*/
bool comp(const std::pair<int, int> &a, const std::pair<int, int> &b) {
    if (a.second > b.second) {
        return true;
    } else if(a.second == b.second) {
        return a.first < b.first;
    } else {
        return false;
    }
}

/* 
обрабоотка всех входных документов, каждое слово помещается в хеш-таблицу,
для каждого слова добавляется пара int-значений, где первое значение номер
документа, где встречается слово, второе значение - количество вхождений текущего
слова в документе 
*/
Umap procces_docs(int n) {
    Umap docs_words;
    std::string value;
    for(int i = 1 ; i <= n ; ++i) {
        getline(std::cin, value);
        std::istringstream iss(value);
        std::string item;
        while ( getline(iss, item, ' ' ) ) {
            auto it = docs_words.find(item);
            if (it == docs_words.end()) {
                docs_words[item] = std::unordered_map<int, int> { {i, 1} };
            } else {
                auto p = docs_words[item].try_emplace(i, 1);
                if (!p.second) {
                    docs_words[item][i] += 1;
                }
            }
        }
    }
    return docs_words;
}

/*
обработка всех входящих запросов, каждый запрос обрабатывает в цикле, текущие
результаты помещаются в массив, затем происходит переход к следующему запросу.
Все слова для каждого из запросов помещаются в множество уникальных объектов,
из хеш-таблциы со всеми словами и их вхождениями в документы берутся значения и
помещаются в массив результатов по индексу документа. Сами массив результатов 
изначально хранит в себе n пар значений, чтобы можно было по индексу документа 
считать релевантности документа, т.к. индекс докумениа будет извесетен при 
получении слова из хеш-таботцы. Затем результаты сортируются при помощи 
компаратора.  
*/
Pairs procces_requests(int n, int docs_num, Umap &docs_words) {
    Pairs res;
    std::string value;
    for(int i = 0 ; i < n ; ++i) {
        getline(std::cin, value);
        std::istringstream iss(value);
        std::string item;
        std::vector<std::pair<int, int>> cur_res(docs_num+1, {0,0});
        std::set<std::string> words_in_req;

        while ( getline(iss, item, ' ' ) ) {
            auto p = words_in_req.insert(item);
            if (p.second) {
                auto it = docs_words.find(item);
                if (it != docs_words.end()) {
                    for(const std::pair<int, int>& p_docs: docs_words[item]) {
                        cur_res[p_docs.first].first = p_docs.first;
                        cur_res[p_docs.first].second += p_docs.second;
                    }
                }
            }
        }
        std::sort(cur_res.begin(), cur_res.end(), comp);
        res.push_back(cur_res);
    }

    return res;
}

void print_result(Pairs &res) {
    for(int i = 0 ; i < res.size() ; ++i) {
        for(int j = 0 ; j < res[i].size() && j < 5; ++j) {
            if (res[i][j].second == 0) {
                break;
            }
            std::cout << res[i][j].first << " " ;
        }
        std::cout << std::endl;
    }
}

int main() {
    int n, docs_num;
    std::string value;
    std::cin >> n;
    getline(std::cin, value); /* get empty line after cin*/ 
    docs_num = n;
    Umap docs_words = procces_docs(n);
    std::cin >> n;
    getline(std::cin, value); /* get empty line after cin*/ 
    Pairs res = procces_requests(n, docs_num, docs_words);
    print_result(res);
}
