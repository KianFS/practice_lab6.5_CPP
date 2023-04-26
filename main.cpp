#include <iostream>
#include "string"
#include "algorithm"
#include "cstring"

using namespace std;


int *intersection_finder(int list1[], int list2[], int size1, int size2, int &size3) {
    int temp[size1];
    int index = 0;
    int flag;


    for (int i = 0; i < size1; i++) {
        flag = 0;


        for (int j = 0; j < size2; j++) {
            if (list1[i] == list2[j]) {
                flag = 1;
                break;
            }
        }


        if (flag == 1) {
            temp[index++] = list1[i];
        }
    }


    int *list3 = new int[index];
    size3 = index;


    for (int i = 0; i < index; i++) {
        list3[i] = temp[i];
    }

    return list3;
}

//*********************2nd function*********************
std::string *palindromes_maker(std::string list[], int size, int &size_palindromes) {
    std::string temp[size];
    int index2 = 0;


    for (int i = 0; i < size; i++) {
        std::string word = list[i];
        int n = word.length();


        int flag = 1;
        for (int j = 0; j < n / 2; j++) {
            if (word[j] != word[n - 1 - j]) {
                flag = 0;
                break;
            }
        }


        if (flag == 1) {
            temp[index2++] = word;
        }
    }


    std::string *palindromes = new std::string[index2];
    size_palindromes = index2;


    for (int i = 0; i < index2; i++) {
        palindromes[i] = temp[i];
    }

    return palindromes;
}

//*************************third function ***********************
int *prime_finder(int list[], int size, int &size_primes) {
    int max_num = *std::max_element(list, list + size);
    bool is_prime[max_num + 1];


    for (int i = 0; i <= max_num; i++) {
        is_prime[i] = true;
    }


    is_prime[0] = false;
    is_prime[1] = false;


    for (int i = 2; i * i <= max_num; i++) {
        if (is_prime[i] == true) {
            for (int j = i * i; j <= max_num; j += i) {
                is_prime[j] = false;
            }
        }
    }

    
    int *primes = new int[size];
    size_primes = 0;
    for (int i = 0; i < size; i++) {
        if (is_prime[list[i]] == true) {
            primes[size_primes++] = list[i];
        }
    }

    return primes;
}

//***********************4th question*******************
bool isAnagram(string word1, string word2) {
    int n1 = word1.length();
    int n2 = word2.length();
    if (n1 != n2)
        return false;
    sort(word1.begin(), word1.end());
    sort(word2.begin(), word2.end());
    for (int i = 0; i < n1; i++) {
        if (word1[i] != word2[i])
            return false;
    }
    return true;
}

void anagrams(string word, string word_list[], int n) {
    string sorted_word = word;
    transform(sorted_word.begin(), sorted_word.end(), sorted_word.begin(), ::tolower);
    sorted_word.erase(remove(sorted_word.begin(), sorted_word.end(), ' '), sorted_word.end());
    sort(sorted_word.begin(), sorted_word.end());

    for (int i = 0; i < n; i++) {
        string temp = word_list[i];
        transform(temp.begin(), temp.end(), temp.begin(), ::tolower);
        temp.erase(remove(temp.begin(), temp.end(), ' '), temp.end());
        if (isAnagram(sorted_word, temp)) {
            cout << word_list[i] << " ";
        }
    }
}


int main() {
    int list1[] = {1, 2, 3, 4, 5};
    int list2[] = {3, 4, 5, 6, 7};
    int size1 = 5;
    int size2 = 5;
    int size3 = 0;

    int *list3 = intersection_finder(list1, list2, size1, size2, size3);
    cout << "***********************part1********************" << endl;
    cout << "list of common elements:" << endl;

    for (int i = 0; i < size3; i++) {
        cout << list3[i] << " " << endl;
    }


    delete[] list3;

    cout << "***********************part2********************" << endl;
    string list[] = {"level", "redder", "noon", "stats", "kian", "python"};
    int size = 6;
    int size_palindromes = 0;

    string *palindromes = palindromes_maker(list, size, size_palindromes);

    cout << "initial list members:" << endl;
    for (int i = 0; i < size; i++) {
        cout << list[i] << " " << endl;
    }

    cout << "palindromes list elements:" << endl;
    for (int i = 0; i < size_palindromes; i++) {
        cout << palindromes[i] << " " << endl;
    }


    delete[] palindromes;
    cout << "***********************part3********************" << endl;
    int numberList[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25};
    int size44 = 24;
    int size_primes = 0;

    int *primes = prime_finder(numberList, size44, size_primes);


    for (int i = 0; i < size_primes; i++) {
        std::cout << primes[i] << " " << endl;
    }


    delete[] primes;
    cout << "***********************part4********************" << endl;
    string word = "heart";
    string word_list[] = {"earth", "threa", "tear", "hater", "rathe"};


    int n = sizeof(word_list) / sizeof(word_list[0]);
    cout << "anagram of " << word << ": ";
    anagrams(word, word_list, n);
    cout << endl;
    return 0;
}

