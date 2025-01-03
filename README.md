# Data Structure Efficiency and Word Frequency Analysis

## Overview
This project explores the impact of data structure choice on real-world computational performance. By implementing a word frequency analysis algorithm using different data structures, it highlights the trade-offs in asmyptotic time efficiency. 

## Problem Description
The program solves the following computational problem:

- **Input**: 
  - A document (`D`), represented as a sequence of words.
  - A set of stopwords (`S`), which are common words (e.g., "a," "the," "of") excluded from the analysis.
- **Output**: 
  - A frequency distribution of words in `D`, excluding the stopwords. Each word in the output is associated with its frequency of occurrence.

### Key Definitions
- A **word**: A valid string from the English language.
- A **document (`D`)**: A sequence of words.
- A **stopword (`S`)**: A word excluded from the analysis due to its high frequency and lack of semantic significance.
- A **frequency distribution**: A collection of word-frequency pairs `(w, f)` where `f` is a positive integer representing the count of `w`.

---

## Algorithm
The core algorithm implemented is as follows:

```
count_words(S, D):
    stop_words = create a set data structure containing the elements of S
    F = empty data structure containing (w, f) pairs
    for w in D:
        if w not in stop_words:
            if F already contains a pair (w, f):
                f++
            else:
                F.add( (w, 1) )
    return F
```

---

## Data Structures
To compare their performance, the algorithm is implemented using the following data structures for the frequency distribution:

1. **Unsorted Vector**
2. **Unsorted Linked List**
3. **Hash Table**
4. **Binary Search Tree** (here I use the `std::map`)

---

## Goals
1. Observe how data structure efficiency affects real-world performance.
2. Gain hands-on experience using different data structures in a practical software application.


---

## Results

### **Table of Results**

| Data Structure       | Search Asymptotic Efficiency | Observed Elapsed Time (seconds) |
|-----------------------|-----------------------------|---------------------------------|
| Unsorted vector       | \( O(n) \)                  | 2.0208                         |
| Unsorted linked list  | \( O(n) \)                  | 2.41412                        |
| Hash table            | \( O(1) \) (amortized)      | 0.0064498                      |
| Binary search tree    | \( O(\log n) \)             | 0.0185481                      |


### **Comparing Results** 


Based off the table of results, we can see that the theoretical efficiencies align well with our experimental data. The hash table in this instance was fastest with \( O(1) \) amortized efficiency. It was **374 times faster** than the linked-list structure, which was the slowest. Theory also says that vectors are faster than linked lists due to a vector's elements having contiguous memory location compared to the random memory access of linked-lists nodes, and we also see that in our observed times. 


### **Conclusion**

We always hear about the importance of selecting the correct data structures for a given problem, and being able to see first-hand the effects of choosing the correct data structure provided me a clear understanding of the theoretical expectations. 


## License
This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

---
