#include <iostream>

using namespace std;

void print(float arr[], int size){
    //.....
    for (int i = 0; i < size; i++){
        cout << arr[i];
        if (i < size - 1) {
            cout << ", ";
        }
    }
    cout << endl;
}

float findMaxPos(float nums[], int size){
    float maxValue = nums[0];
    int maxPos = 0;

    for (int i = 1; i < size; i++){
        if (nums[i] > maxValue){
            maxValue = nums[i];
            maxPos = i;
        }
    }

    return maxPos;
}

string hottestDay(float temps[], int size){
    int highestTempDay = findMaxPos(temps, size);
    string weelkDays[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

    return weelkDays[highestTempDay % 7];

}

int main(){
    float data[7] = {64.0, 62.8, 61.6, 60.4, 62.1, 63.8, 65.6};
    float moreData[28] = {92.8,91.6,90.4,89.2,88.0,86.8,85.6,84.4,83.2,82.0,80.8,79.6,78.4,77.2,76.0,74.8,73.6,72.4,71.2,70.0,68.8,67.6,66.4,65.2,64.0,62.8,61.6,600.4};

    cout << hottestDay(moreData, 28) << endl;

    return 0;
}
