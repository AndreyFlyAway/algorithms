#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include <unordered_map>
#include <set>
#include <list>
#include <algorithm>

using Umap = std::unordered_map<std::string, int>;
using Uset = std::set<std::string>;

class Document
{
public:
    Document(const std::string &expr_in, int index): 
             _index(index) {
        std::istringstream iss(expr_in);
        std::string item;
        while ( getline(iss, item, ' ' ) ) {
            auto p = _words.try_emplace(item, 1);
            if (!p.second) {
                _words[item] += 1;
            }
        }
    }

    int get_rel(const Uset &word_in_req) const {
        int rel = 0;
        if (!_words.empty()) {
            for (auto it = word_in_req.begin(); it != word_in_req.end(); ++it) {
                auto search = _words.find(*it);
                if(search != _words.end()) {
                    rel += search->second;
                }
            }
        }
        return rel;
    }

    int get_index() const { return _index; }

private:
    int _index;
    Umap _words;
};

struct Request {
    Request(const std::string& expr_in) {
        _indexes_rel = std::vector<std::pair<int,int>> (6, {0,0});
        std::istringstream iss(expr_in);
        std::string item;
        while ( getline(iss, item, ' ' ) ) {
            auto p = _w_in_req.insert(item);
        }
    }

    void add_doc_index(const Document &doc) {
        int rel = doc.get_rel(_w_in_req);
        if(rel != 0) {
            _indexes_rel[5] = {doc.get_index(), rel};
            int i = 5;
            while(i > 0 && comp(_indexes_rel[i], _indexes_rel[i-1])) {
                std::swap(_indexes_rel[i], _indexes_rel[i-1]);
                --i;
            }
        }
    }

    // void add_doc_index(const Document &doc) {
    //     int rel = doc.get_rel(_w_in_req);
    //     if(rel != 0) {
    //        _index_to_rel.push_back({doc._index, rel});
    //     }
    // }

    // void add_doc_index(const Document &doc) {
    //     std::pair<int,int> cur_res = {doc._index, doc.get_rel(_w_in_req)};
    //     if(cur_res.second != 0) {
    //         if (_indexes.size() < 5){
    //             _indexes.push_back(cur_res);
    //         } else if(comp(cur_res, _indexes[_indexes.size() - 1])) {
    //             std::swap(cur_res,  _indexes[_indexes.size() - 1]);
    //         }
    //         // buble up
    //         int i = _indexes.size() - 1;
    //         while(i > 0 && comp(_indexes[i],  _indexes[i-1]) ) {
    //             std::swap(_indexes[i], _indexes[i-1]);
    //             --i;
    //         }
    //     //    _index_to_rel.push_back({doc._index, rel});
    //     }
    // }

    // std::vector<int> get_result() {
    //     std::vector<int> res;
    //     std::sort(_index_to_rel.begin(), _index_to_rel.end(), comp);
    //     for(int i = 0 ; i < 5 && i < _indexes.size() ; ++i) {
    //         res.push_back(_indexes[i].first);
    //     }
    //     return res;
    // }

    // std::vector<int> get_result() {
    //     std::vector<int> res;
    //     std::sort(_index_to_rel.begin(), _index_to_rel.end(), comp);
    //     for(int i = 0 ; i < 5 && i < _index_to_rel.size() ; ++i) {
    //         res.push_back(_index_to_rel[i].first);
    //     }
    //     return res;
    // }

    std::vector<int>  get_result() const {
        std::vector<int> res;
        for(int i = 0 ; i < 5 && i < _indexes_rel.size() ; ++i) {
            if (_indexes_rel[i].first == 0) {
                break;
            } 
            res.push_back(_indexes_rel[i].first);
        }
        return res;
    }

private:
    bool comp(const std::pair<int, int> &a, const std::pair<int, int> &b) const {
        if (a.second > b.second) {
            return true;
        } else if(a.second == b.second) {
            return a.first < b.first;
        } else {
            return false;
        }
    }

private:
    std::vector<std::pair<int, int>> _indexes_rel;
    // std::vector<std::pair<int,int>> _indexes;
    // std::vector<std::pair<int, int>> _index_to_rel;
    Uset _w_in_req;
};

int main() {
    // test_string_to_set();
    // return 0;
    int n;
    std::string value;
    // form array of docs, change string to map
    std::cin >> n;
    std::vector<Document> docs;
    /* TODO: get empty line??? */ getline(std::cin, value); 

    for(int i = 0 ; i < n ; ++i) {
        getline(std::cin, value);
        docs.push_back(Document{value, i+1});
    }
    // form set of word in request
    std::cin >> n;
    /* TODO: get empty line??? */  getline(std::cin, value);
    std::vector<Request> requests;
    for(int i = 0 ; i < n ; ++i) {
        getline(std::cin, value);
        requests.push_back(Request{value});
        for(Document &d : docs) {
            requests[i].add_doc_index(d);
        }
    }
    // printing result
    for(Request &r : requests) {
        for(int i : r.get_result()) {
            std::cout << i << " ";
        }
        std::cout << std::endl;
    }
}