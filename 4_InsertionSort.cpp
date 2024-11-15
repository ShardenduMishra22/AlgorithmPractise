#include<bits/stdc++.h>
using namespace std;

void PrintArray(vector<int>& arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int InsertionSort(vector<int>& arr){
    for(int i=1; i<arr.size(); i++){
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] < key){
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
    }
    PrintArray(arr);
}

int main(){ 
    vector<int> arr = {1,7,5,3,2,8,6,10};
    InsertionSort(arr);
}