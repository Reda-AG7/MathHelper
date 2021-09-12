#include <iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<fstream>
#include<math.h>

using namespace std;


fstream fileObject;
const char* fileName = "input.txt";


int main() {
    fileObject.open(fileName, ios::in);
    string line;
    vector<double> mySet;
    double sum = 0, median = 0, mean = 0, q1 = 0, q3 = 0;
    double sample_variance = 0, standard_dev = 0;
    if (fileObject.is_open()) {
        while (getline(fileObject, line)) {
            double temp = stod(line);
            sum += temp;
            mySet.push_back(temp);
        }
        mean = sum / mySet.size();
        for (auto i : mySet)
            sample_variance += pow(i - mean, 2);
        sample_variance /= (mySet.size() - 1);
        standard_dev = sqrt(sample_variance);
        sort(mySet.begin(), mySet.end());
        if (mySet.size() % 2 != 0) {
            int index = mySet.size() / 2;
            median = mySet[index];
            q1 = mySet[index / 2];
            q3 = mySet[(index + mySet.size()) / 2];
        }

        else {
            int size = mySet.size();
            int index = mySet.size() / 2;
            median = (mySet[index] + mySet[index - 1]) / 2;
            if ((size - 1 - index) % 2 == 0) {
                int newIndex = (size + index) / 2;
                q3 = (mySet[newIndex] + mySet[newIndex + 1]) / 2;
                q1 = (mySet[index / 2] + mySet[index / 2 - 1]) / 2;
            }
            else {
                q3 = mySet[(size + index) / 2];
                q1 = mySet[index / 2 - 1];
            }
        }

        cout << "sum : " << sum << endl;
        cout << "mean : " << mean << endl;
        cout << "median : " << median << endl;
        cout << "sample variance : " << sample_variance << endl;
        cout << "standard deviation : " << standard_dev << endl;
        cout << "q1 : " << q1 << endl;
        cout << "q3 : " << q3 << endl;
        fileObject.close();
    }
    else
        cout << "file not found" << endl;
}