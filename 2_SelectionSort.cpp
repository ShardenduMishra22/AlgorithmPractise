#include <bits/stdc++.h>
using namespace std;

void PrintArray(vector<int>& arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int SelectionSort(vector<int>& arr){
    for(int i=0; i<arr.size()-1; i++){
        int min_idx = i;
        for(int j=i+1; j<arr.size(); j++){
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        swap(arr[i], arr[min_idx]);
    }
    PrintArray(arr);
}

int main(){ 
    vector<int> arr = {1,7,5,3,2,8,6,10};
    SelectionSort(arr);
}