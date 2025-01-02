///////////////////////////////////////////////////////////////////////////////
// words.cpp
//
// Computing the frequency distribution of a list of words, skipping stopwords.
//
// Students: you do not need to modify this file.
///////////////////////////////////////////////////////////////////////////////

// instructor's includes, delete from starter code
#include "words.hpp"
#include <unordered_set>
#include <unordered_map>
#include <set>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>
#include <map>


namespace words {

  word_vector read_words(const std::string& path) {
    word_vector result;
    std::ifstream file(path);
    if (!file) {
      throw io_exception(path);
    }
    for (std::string word; file >> word;) {
      result.emplace_back(std::move(word));
    }
    file.close();
    if (file.bad()) {
      throw io_exception(path);
    }
    return result;
  }

  std::string lowercase(const std::string& str) {
    auto result(str);
    std::for_each(result.begin(), result.end(),
                  [](char& c) { c = tolower(c); });
    return result;
  }

  /////////////////////////////////////////////////////////////////////////////
  // START OF CODE TO MODIFY
  /////////////////////////////////////////////////////////////////////////////


  // Helper to populate stopwords
  std::unordered_set<std::string> populate_stopwords(const word_vector& stop_words) {
    return std::unordered_set<std::string>(stop_words.begin(), stop_words.end());
  }

  frequency_distribution
  most_frequent(
    const frequency_distribution& dist,
    size_t k
  ) noexcept {

    
     std::vector<words::word_frequency> tempdist;
     std::vector<words::word_frequency> topk;
     tempdist = dist;
     std::vector<words::word_frequency>::iterator max_ele;

     for (int i = 0; i < k; i++){
      max_ele = std::max_element(tempdist.begin(), tempdist.end(),
        [&](const words::word_frequency& word1, const words::word_frequency& word2) {
          return (word1.count() < word2.count());} );                 // find max element k times
      topk.push_back(*max_ele);
      tempdist.erase(max_ele);                                        // removes max element fromtemp dist to find the next max element
     }
       
    

    // std::sort(tempdist.rbegin(), tempdist.rend(),         
    // [&](const words::word_frequency& word1, const words::word_frequency& word2)
    // { return (word1.count() < word2.count());} );     // sort the vector of word_frequency by count 
    //                                                   // and reverse the iterators to get descending order

    // for (int i = 0; i < k; i++){    
    //   topk.push_back(tempdist.at(i));                 // get top k elements 
    // }

    return topk;
  }
  
  frequency_distribution
  vector_word_counter::count(const word_vector& stop_words, const word_vector& document) const noexcept {
    auto stopWords = populate_stopwords(stop_words);
    std::vector<words::word_frequency> frequencyDistribution;
    frequencyDistribution.reserve(document.size()); // Reserve space based on document size

    for (const auto& word : document) {
        if (stopWords.find(word) == stopWords.end()) {
            auto it = std::find_if(frequencyDistribution.begin(), frequencyDistribution.end(),
                                   [&](const words::word_frequency& wf) { return wf.word() == word; });
            if (it != frequencyDistribution.end()) {
                it->increment_count();
            } else {
                frequencyDistribution.emplace_back(word, 1);
            }
        }
    }
    return frequencyDistribution;
}
  // Refactored count for list
frequency_distribution
list_word_counter::count(const word_vector& stop_words, const word_vector& document) const noexcept {
    auto stopWords = populate_stopwords(stop_words);
    std::list<words::word_frequency> frequencyDistribution;

    for (const auto& word : document) {
        if (stopWords.find(word) == stopWords.end()) {
            auto it = std::find_if(frequencyDistribution.begin(), frequencyDistribution.end(),
                                   [&](const words::word_frequency& wf) { return wf.word() == word; });
            if (it != frequencyDistribution.end()) {
                it->increment_count();
            } else {
                frequencyDistribution.emplace_back(word, 1);
            }
        }
    }

    std::vector<words::word_frequency> dists;
    dists.reserve(frequencyDistribution.size()); // Reserve space before populating vector
    std::copy(frequencyDistribution.begin(), frequencyDistribution.end(), std::back_inserter(dists));
    return dists;
}

// Refactored count for hash
frequency_distribution
hash_word_counter::count(const word_vector& stop_words, const word_vector& document) const noexcept {
    auto stopWords = populate_stopwords(stop_words);
    std::unordered_map<std::string, int> frequencyDistribution;
    frequencyDistribution.reserve(document.size()); // Reserve space based on document size

    for (const auto& word : document) {
        if (stopWords.find(word) == stopWords.end()) {
            frequencyDistribution[word]++;
        }
    }

    std::vector<words::word_frequency> dists;
    dists.reserve(frequencyDistribution.size()); // Reserve space before populating vector
    for (const auto& pair : frequencyDistribution) {
        dists.emplace_back(pair.first, pair.second);
    }
    return dists;
}

// Refactored count for tree
frequency_distribution
tree_word_counter::count(const word_vector& stop_words, const word_vector& document) const noexcept {
    auto stopWords = populate_stopwords(stop_words);
    std::map<std::string, int> frequencyDistribution;

    for (const auto& word : document) {
        if (stopWords.find(word) == stopWords.end()) {
            frequencyDistribution[word]++;
        }
    }

    std::vector<words::word_frequency> dists;
    dists.reserve(frequencyDistribution.size()); // Reserve space before populating vector
    for (const auto& pair : frequencyDistribution) {
        dists.emplace_back(pair.first, pair.second);
    }
    return dists;
}

} // namespace words


  /////////////////////////////////////////////////////////////////////////////
  // END OF CODE TO MODIFY
  /////////////////////////////////////////////////////////////////////////////


