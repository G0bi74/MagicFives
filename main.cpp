#include <algorithm>
#include <iostream>
#include <vector>
int findMedian(std::vector<int> temp_arr) {
    std::sort(temp_arr.begin(), temp_arr.end());
    int size = temp_arr.size();
    if (size % 2 == 0) {
        return (temp_arr[size / 2 - 1] + temp_arr[size / 2]) / 2;
    }
    return temp_arr[temp_arr.size() / 2];
}

int magicFives(std::vector<int> & arr, int k) {
    if (arr.size() <= 5) {
        std::sort(arr.begin(), arr.end());
        return arr[k - 1];
    }

    std::vector<int> medians;
    for (int i = 0; i < (arr.size()/5)+1; i++) {
        std::vector<int> temp;
        int iterator = 0;
        for (int j = 0; j < 5; j++) {
            iterator = i*5 + j;
            if (iterator >= arr.size()) break;
            temp.push_back(arr[i*5+j]);
            //std::cout << arr[i*5+j] << " ";
        }
        //std::cout<< "\n";
        medians.push_back(findMedian(temp));
    }
    // for(int i = 0; i < medians.size(); i++) {
    //     std::cout << medians[i] << " ";
    // }std::cout<< "\n";
    int mediana = findMedian(medians);
    //std::cout << mediana << "\n";

    std::vector<int> less, grater;
    for(int x : arr) {
        if(x > mediana) grater.push_back(x);
        else if(x < mediana) less.push_back(x);
    }
    int medi_caunt = arr.size() - less.size() - grater.size();

    if (k <= less.size()) {
        return magicFives(less, k);
    }else if(k <= grater.size()) {
        return magicFives(grater, (k - less.size() - medi_caunt));
    }else {
        return mediana;
    }
}

int main() {
    std::vector<int> arr = {12, 3, 5, 7, 19, 26, 23, 8, 15, 1, 17, 10};
    int k = 5; // Szukamy 5-tego co do wielkości elementu

    int result = magicFives(arr, k);
    std::cout << "5-ty co do wielkosci element: " << result << std::endl;
    return 0;

}
