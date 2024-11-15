#include<bits/stdc++.h>
using namespace std;

void PrintArray(vector<int>& arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int Partition(vector<int>& arr,int low,int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j=low; j<high; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void QuickSort(vector<int>& arr,int low,int high){
    if(low < high){
        int pi = Partition(arr,low,high);
        QuickSort(arr,low,pi-1);
        QuickSort(arr,pi+1,high);
    }
}

int main(){
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    QuickSort(arr,0,arr.size()-1);
    PrintArray(arr);
} 