#include<bits/stdc++.h>
using namespace std;

void PrintArray(vector<int>& arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int MergeSort(vector<int>& arr,int left,int mid,int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> l(n1);
    vector<int> r(n2);

    for(int i=0; i<n1; i++){
        l[i] = arr[left + i];
    }
    
    for(int i=0; i<n2; i++){
        r[i] = arr[mid + 1 + i];
    }

    int i=0,j=0,k=left;
    while(i < n1 && j < n2){
        if(l[i] <= r[j]){
            arr[k] = l[i];
            i++;
        }else{
            arr[k] = r[j];
            j++;
        }
        k++;
    }

    while(i < n1){
        arr[k] = l[i];
        i++;
        k++;
    }

    while(j < n2){
        arr[k] = r[j];
        j++;
        k++;
    }
}

void Merge(vector<int>& arr,int left,int right){
    if(left < right){
        int mid = (left + right)/2;
        Merge(arr,left,mid);
        Merge(arr,mid+1,right);
        MergeSort(arr,left,mid,right);
    }
}

int PrntArray(vector<int>& arr){
    for(int i=0; i<arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
}

int main(){
    vector<int> arr = {1,7,5,3,2,8,6,10};
    Merge(arr,0,arr.size()-1);
    PrintArray(arr);
} 