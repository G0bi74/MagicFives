#include <algorithm>
#include <iostream>
#include <vector>

bool hasEvenUniquePrimeDivisors(int n) {
    int uniquePrimeDivisorsCount = 0;
    //std::cout << "dzielniki liczby: " << n << std::endl;
    for (int d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            //std::cout << d << " ";
            uniquePrimeDivisorsCount++;
            while (n % d == 0) {
                n /= d;
            }
        }
    }
    if (n > 1 ) {
        //std::cout << n << " ";
        uniquePrimeDivisorsCount++;
    }
    //std::cout << "\n";
    return uniquePrimeDivisorsCount % 2 == 0;
}

int findMedian(std::vector<int> &temp_arr) {
    std::sort(temp_arr.begin(), temp_arr.end());
    return temp_arr[temp_arr.size() / 2];
}

int magicFives(std::vector<int> & arr, int k) {
    if (arr.size() <= 5) {
        std::sort(arr.begin(), arr.end());
        return arr[k];
    }

    std::vector<int> medians;
    for (int i = 0; i < arr.size(); i+=5) {
        std::vector<int> temp(arr.begin() + i, arr.begin() + std::min((i + 5), (int)arr.size()));
        medians.push_back(findMedian(temp));

    }
    // for(int i = 0; i < medians.size(); i++) {
    //     std::cout << medians[i] << " ";
    // }std::cout<< "\n";
    int mediana = magicFives(medians, medians.size()/ 2);
    //std::cout << mediana << "\n";

    std::vector<int> less, grater, equal;
    for(int x : arr) {
        if(x > mediana) grater.push_back(x);
        else if(x < mediana) less.push_back(x);
        else equal.push_back(x);
    }
    // std::cout << "Less: ";
    // for (auto a: less) {
    //     std::cout << a << " ";
    // }std::cout << "\n";
    // std::cout << "Grater: ";
    // for (auto a: grater) {
    //     std::cout << a << " ";
    // }std::cout << "\n";

    if (k < less.size()) {
        return magicFives(less, k);
    }else if(k < less.size() + equal.size()) {
        return mediana;
    }else {
        return magicFives(grater, (k - less.size() - equal.size()));
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(nullptr);
    std::cin.tie(nullptr);

    int number_of_tests;
    std::cin >> number_of_tests;
    for (int i = 0; i < number_of_tests; i++) {
        int number_of_values, tmp, k;
        std::vector<int> arr;
        std::cin >> number_of_values;
        while (number_of_values--) {
            std::cin >> tmp;
            if(hasEvenUniquePrimeDivisors(tmp)) {
                arr.push_back(tmp);
                //std::cout << tmp << " ";
            }
        }
        std::cin >> k;
        if(k >= arr.size()) {
            std::cout << "BRAK DANYCH\n";
        }else {
            int result = magicFives(arr, k);
            std::cout << result << "\n";
        }
        arr.clear();
    }
    return 0;
}

/*
1
20
2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20 21
5
 */