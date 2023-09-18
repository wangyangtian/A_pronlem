#include <iostream>
#include <vector>
#include <locale>
using namespace std;
void insertion_sort(int arr[],int len){
    for(int i=1;i<len;i++){
        int key=arr[i];
        int j=i-1;
        while((j>=0) && (key<arr[j])){
            arr[j+1]=arr[j];
            j--;
            }
        arr[j+1]=key;
        }
};

//
void insertion_sort(vector<int>* vec){
    vector<int>::iterator it;
        for(it=vec->begin()+1;it!=vec->end();it++){
            int key=*it;
			it=vec->erase(it);
            vector<int>::iterator it2=it-1;
            while((it2>=vec->begin()) && (key<*it2)){
                it2--;
            }
		    it2=vec->insert(it2+1,key);
        }
};


template<typename T>
void merge_sort(T arr[], int len) {
    T *a = arr;
    T *b = new T[len];
    for (int seg = 1; seg < len; seg += seg) {
        for (int start = 0; start < len; start += seg + seg) {
            int low = start, mid = min(start + seg, len), high = min(start + seg + seg, len);
            int k = low;
            int start1 = low, end1 = mid;
            int start2 = mid, end2 = high;
            while (start1 < end1 && start2 < end2)
                b[k++] = a[start1] < a[start2] ? a[start1++] : a[start2++];
            while (start1 < end1)
                b[k++] = a[start1++];
            while (start2 < end2)
                b[k++] = a[start2++];
        }
        T *temp = a;
        a = b;
        b = temp;
    }
    if (a != arr) {
        for (int i = 0; i < len; i++)
            b[i] = a[i];
        b = a;
    }
    delete[] b;
}

vector<int> mergeSort(vector<int> left,vector<int> right){
    vector<int> result;
    int i=0,j=0;
    while(i<left.size()&&j<right.size()){
        if(left[i]<right[j]){
            result.push_back(left[i]);
            i++;
        }
        else{
            result.push_back(right[j]);
            j++;
        }
    }
    for(;i<left.size();i++) 
        result.push_back(left[i]);
    for(;j<right.size();j++)
        result.push_back(right[j]);
    return result;
}
vector<int> merge_sort(vector<int> arr){
    if(arr.size()<=1)   
        return arr;
    vector<int> left,right;
    int len=arr.size();
    for(int i=0;i<len/2;i++)
        left.push_back(arr[i]);
    for(int i=len/2;i<len;i++)
        right.push_back(arr[i]);
    return mergeSort(merge_sort(left),merge_sort(right));

}
int main(){
    int a[]={1,3,5,7,9,2,4,6,8,10,1,5,0};
    vector<int> vec;
    int len=sizeof(a)/sizeof(int);
    for(int i=0;i<len;i++)
        vec.push_back(a[i]);
    //insertion_sort(a,len);
    //insertion_sort(&vec);
    vec=merge_sort(vec);
    cout<<"the number of element is "<<sizeof(a)/sizeof(int)<<""<<endl;
    for(int i:vec)
        cout<<i<<" ";
    cout<<225*225*225;
    return 0;
}