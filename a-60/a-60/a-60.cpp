#include <iostream>
#include <vector>;

using namespace std;

vector<int> arr;
int n;


void mergesort(int st, int mid, int ed);

void merge(int st, int ed) {
    if (st == ed) {
        return;
    }
    int mid = (st + ed) / 2;
    merge(st, mid);
    merge(mid + 1, ed);
    mergesort(st, mid, ed);
}
void mergesort(int st, int mid, int ed) {
    vector<int> tmp;
    vector<int> tmp2;
    tmp.resize(mid - st + 1);
    tmp2.resize(ed - mid);
    copy(arr.begin(), arr.begin() + mid + 1, tmp.begin());
    copy(arr.begin() + mid + 1, arr.end() + 1, tmp2.begin());


    int i = 0; int j = 0;
    int tmpszze = tmp.size();
    int tmp2szze = tmp2.size();
    while (i < tmpszze && j < tmpszze) {
        if(tmp[i]<=tmp2[j]){
            arr[st++] = tmp[i++];
        }
        else {
            arr[st++] = tmp2[j++];
        }
    }
    if (i >= tmpszze) {
        while (j < tmp2szze) {
            arr[st++] = tmp[j++];
        }
    }
    else {
        while (i < tmp2szze) {
            arr[st++] = tmp[i++];
        }
    }
}


int main()
{
    cin >> n;
    merge(0, n - 1);
    for (int i = 0; i < n; i++) {
        cout <<arr[i] << ' ';
    }
}