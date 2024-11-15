#include<bits/stdc++.h>
using namespace std;

void PrintArray(vector<int>& arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int BubbleSort(vector<int>& arr){
    for(int i=0;i<arr.size();i++){
        for(int j=0; j<arr.size()-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
            }
        }
    }
    PrintArray(arr);
}

int main(){
    vector<int> arr = {1,7,5,3,2,8,6,10};
    BubbleSort(arr);
} 