//merge sort

#include <iostream>
using namespace std;
void merge(int *ar, int left, int mid, int right){
    int it1, it2, n, i;
    it1 = 0;
    it2 = 0;
    n = right - left;
    int *result = new int[n];
    while ( (left + it1 < mid) && (mid+ it2 < right))
    {
        if (ar[left+it1] < ar[mid+it2]){
            result[it1+it2] = ar[left+it1];
            it1++;
        }
        else {
            result[it1+it2] = ar[mid+it2];
            it2++;
        }
    }
    while (left + it1 < mid) {
        result[it1+it2] = ar[left+it1];
        it1++;
    }
    while (mid + it2 < right)
    {
        result[it1 + it2] = ar[mid + it2];
        it2++;
    }
    for (i = 0; i < (it1 + it2); i++) {
        ar[left+i] = result[i];
    }
}


void mergesort(int *ar, int left, int right) {
    if (left + 1 >= right) {
        return;
    }
    int mid;
    mid = (left + right) / 2;
    mergesort(ar, left, mid);
    mergesort(ar, mid, right);
    merge(ar, left, mid, right);
}

int main(){
    int n, array[100000];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    mergesort(array, 0, n);
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    return 0;
}

//similar arrays

#include <iostream>
#include <vector>
using namespace std;
void merge(int *ar, int left, int mid, int right) {
    int it1, it2, n, i;
    it1 = 0;
    it2 = 0;
    n = right - left;
    int *result = new int[n];
    while ( (left + it1 < mid) && (mid+ it2 < right))
    {
        if (ar[left+it1] < ar[mid+it2]){
            result[it1+it2] = ar[left+it1];
            it1++;
        }
        else {
            result[it1+it2] = ar[mid+it2];
            it2++;
        }
    }
    while (left + it1 < mid) {
        result[it1+it2] = ar[left+it1];
        it1++;
    }
    while (mid + it2 < right)
    {
        result[it1 + it2] = ar[mid + it2];
        it2++;
    }
    for (i = 0; i < (it1 + it2); i++) {
        ar[left+i] = result[i];
    }
}


void mergesort(int *ar, int left, int right) {
    if (left + 1 >= right) {
        return;
    }
    int mid;
    mid = (left + right) / 2;
    mergesort(ar, left, mid);
    mergesort(ar, mid, right);
    merge(ar, left, mid, right);
}

void doset(int *ar, vector<int> &ar_new, int length) {
    ar_new.push_back(ar[0]);
    for (int i = 1; i < length; i++) {
        if (ar[i] != ar[i-1]) {
            ar_new.push_back(ar[i]);
        }
    }

}
int main() {
    int n, k, i;
    vector<int> res_f;
    vector<int> res_s;
    cin >> n;
    int *first = new int[n];
    for (i = 0; i < n; i++) {
        cin >> first[i];
    }
    cin >> k;
    int *second = new int[k];
    for (i = 0; i < k; i++) {
        cin >> second[i];
    }
    mergesort(first, 0, n);
    mergesort(second, 0, k);
    doset(first, res_f, n);
    doset(second, res_s, k);
    if (res_f.size() == res_s.size()) {
        for (i = 0; i < res_f.size(); i++)
            if (res_f[i] != res_s[i]) {
                cout << "NO";
                return 0;
            }
        cout << "YES";
        return 0;
    }
    else
        cout << "NO";
    return 0;
}

