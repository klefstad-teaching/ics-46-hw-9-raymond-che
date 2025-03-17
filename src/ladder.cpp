#include "ladder.h"
#include <cstddef>
#include <string>

void error(string word1, string word2, string msg) {
  cout << word1 << " " << word2 << " " << msg << endl;
}

void print_word_ladder(const vector<string> &ladder) {
  for (size_t i = 0; i < ladder.size(); i++) {
    cout << ladder[i] << "";
  }
}
#define my_assert(e)                                                           \
  { cout << #e << ((e) ? " passed" : " failed") << endl; }
void verify_word_ladder() {
  set<string> word_list;
  load_words(word_list, "words.txt");
  my_assert(generate_word_ladder("cat", "dog", word_list).size() == 4);
  my_assert(generate_word_ladder("marty", "curls", word_list).size() == 6);
  my_assert(generate_word_ladder("code", "data", word_list).size() == 6);
  my_assert(generate_word_ladder("work", "play", word_list).size() == 6);
  my_assert(generate_word_ladder("sleep", "awake", word_list).size() == 8);
  my_assert(generate_word_ladder("car", "cheat", word_list).size() == 4);
}

void load_words(set<string> &word_list, const string &file_name) {
  ifstream in(file_name);
  if (!in) {
    throw runtime_error("file not found");
  }
  string word;
  while (in >> word) {
    word_list.insert(word);
  }
  in.close();
}

// bool edit_distance_within(const std::string &str1, const std::string &str2,
//                           int d) {}
bool is_adjacent(const string &word1, const string &word2) {
  if (word1.length() - word2.length() > 1) {
    return false;
  }
  // look for only one letter difference
  int count = 0;
  for (size_t i = 0; i < word1.length(); i++) {
    if (word1[i] != word2[i]) {
      count++;
    }
  }
  if (count == 1) {
    return true;
  }
  return false;
}
vector<string> generate_word_ladder(const string &begin_word,
                                    const string &end_word,
                                    const set<string> &word_list) {
  queue<vector<string>> ladder_queue;
  ladder_queue.push({begin_word});
  set<string> visited;
  visited.insert(begin_word);
  while (!ladder_queue.empty()) {
    vector<string> ladder = ladder_queue.front();
    ladder_queue.pop();
    string last_word = ladder.back();
    for (auto word = word_list.begin(); word != word_list.end(); ++word) {
      if (is_adjacent(last_word, *word)) {
        if (visited.find(*word) == visited.end()) {
          visited.insert(*word);
          vector<string> new_ladder = ladder;
          new_ladder.push_back(*word);
          if (*word == end_word) {
            return new_ladder;
          }
          ladder_queue.push(new_ladder);
        }
      }
    }
  }
  return vector<string>();
}