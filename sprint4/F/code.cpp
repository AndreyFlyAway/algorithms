#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

/*

Вася решил избавиться от проблем с произношением и стать певцом. Он 
обратился за помощью к логопеду. Тот посоветовал Васе выполнять упражнение, 
которое называется анаграммная группировка. В качестве подготовительного этапа 
нужно выбрать из множества строк анаграммы.

Анаграммы –— это строки, которые получаются друг из друга перестановкой
символов. Например, строки «SILENT» и «LISTEN» являются анаграммами.

Помогите Васе найти анаграммы.

Формат ввода
В первой строке записано число n —– количество строк.

Далее в строку через пробел записаны n строк.

n не превосходит 6000. Длина каждой строки не более 100 символов.

Формат вывода
Нужно вывести в отсортированном порядке индексы строк, которые являются
анаграммами.

Каждая группа индексов должна быть выведена в отдельной строке. Индексы внутри
одной группы должны быть отсортированы по возрастанию. Группы между собой должны
быть отсортированы по возрастанию первого индекса.

Обратите внимание, что группа анаграмм может состоять и из одной строки. Например,
если в исходном наборе нет анаграмм, то надо вывести n групп, каждая из которых
состоит из одного индекса.

6
tan eat tea ate nat bat

res:
0 4
1 2 3
5

7
kfumpzsaao ilvnolmacs fpwmgnuonb gfwfwtwmvo bruucwbbjw uzpmkfaoas afkpuamszo

res:
0 5 6
1
2
3
4

81
rjvew ivbmo kwfem zeboo pcdkw tfsbz yuwtm wmxjw nrqus nnqpp gcwpw ornbs pthyj yjolz rvnjg ybqwr hwpes mgzas juliq dyhhz njxgb bwzoh tosuk wobdr gnalw cuorl vukpl xkumi mkzph kkgqj uspch jluhu iljup fjuvk krwsd whpdw eixvf wjxmp jbldf fcxpk htcae vomzc fosvw hoplx fbqzl sgrnk bvywp crlmx twzih wlett bbvvc vbaej ljckp ohidr jzxng emspk dsjpq irvzq ysvlv wcity djyqw ehtqq kpvyp khucp bkulg wzbna fqmri nsaqs tohsd qrdxv bwlty bvpyr cxtds cqhbe nyzak mkebf jadyu sbrpk zykgr eqjns gfhob


*/

// using ull=unsigned long long;

// std::unordered_map<char, int> VALS_HASH = {{'a', 5},{'b', 7},{'c', 11},{'d', 13},{'e', 19},
//                                            {'f', 23},{'g', 29},{'h', 31},{'i', 37},{'j', 41},
//                                            {'k', 43},{'l', 47},{'m', 53},{'n', 59},{'o', 61},
//                                            {'p', 67},{'q', 71},{'r', 73},{'s', 79},{'t', 83},
//                                            {'u', 89},{'v', 97},{'w', 101},{'x', 103},{'y', 107},
//                                            {'z', 109}};

// std::unordered_map<char, int> generate_map() {
//     std::unordered_map<char, int> generated_vals;
//     char c = 'a';
//     int val = 1;
//     while(c <= 'z') {
//         generated_vals[c] = val;
//         std::cout << "{'" << c << "', " << val << "},";
//         val += 2;
//         c++;
//     }
//     return generated_vals;
// }

// ull hash(std::string& s) {
//     // std::unordered_map<char, int> generated_vals = generate_map();
//     ull res = 0;
//     for(char c : s) {
//         res += c * VALS_HASH[c];
//     }
//     // return res ;
//     return res ;
// }

std::vector<std::vector<int> > anagrams(std::vector<std::string>& vals) {
    std::vector<std::vector<int> > res;
    std::vector<std::string> result_order;
    std::unordered_map<std::string, std::vector<int> > angs; 
    int cur_hash = 0;
    for(int i = 0 ; i < vals.size() ; ++i) {
        // cur_hash = hash(vals[i]);
        std::sort(vals[i].begin(), vals[i].end());
        auto it = angs.find(vals[i]);
        if(it != angs.end()) {
            angs[vals[i]].push_back(i);
            // for(int i :  angs[cur_hash]) {
            //     std::cout << vals[i] << " ";
            // }
            // std::cout << std::endl;
        } else {
            angs[vals[i]] = std::vector<int> {i};
            result_order.push_back(vals[i]);
        }
    }
    for(int i = 0 ; i < result_order.size() ; ++i) {
        // std::sort(angs[cur_hash].begin(), angs[cur_hash].end());
        res.push_back(angs[result_order[i]]);
    }
    return res;
}

void print_res(std::vector<std::vector<int>>& res) {
    for(int i = 0 ; i < res.size() ; ++i) {
        for(int j = 0; j < res[i].size() ; ++j) {
            std::cout << res[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

int main() {
    // std::string s1 = "iljup";
    // std::string s2 = "wzbna";
    // std::cout << hash(s1) << " " << hash(s2) <<std::endl;
    // std::string s3 = "tohsd";
    // std::string s4 = "sbrpk";
    // std::cout << hash(s3) << " " << hash(s4) <<std::endl;
    // return 0;
    // generate_map();
    int n;
    std::string value;
    std::cin >> n;
    std::vector<std::string> words;
    for(int i = 0 ; i < n ; ++i) {
        std::cin >> value;
        words.push_back(value);
    }
    std::vector<std::vector<int>> res = anagrams(words);
    print_res(res);
}