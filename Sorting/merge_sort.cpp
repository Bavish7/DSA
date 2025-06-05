#include<iostream>
using namespace std;

// TC=O(N*LOGN), SC=O(N)
void Merge(int arr[], int start, int mid, int end){
    int n1,n2;
    n1=mid-start+1;
    n2=end-mid;
    int *a1 = new int[n1];
    int *a2 = new int[n2];
    for(int i=0;i<n1;i++){
        a1[i]=arr[start+i];
    }
    for(int j=0;j<n2;j++){
        a2[j]=arr[mid+1+j];
    }
    int i=0,j=0,k=start;
    while(i<n1 && j<n2){
        if(a1[i]<a2[j]){
            arr[k++]=a1[i++];
        }
        else{
            arr[k++]=a2[j++];
        }
    }
    while(i<n1){
        arr[k++]=a1[i++];
    }
    while(j<n2){
        arr[k++]=a2[j++];
    }
    delete[] a1;
    delete[] a2;
}
void MergeSort(int arr[], int start, int end){
    if(start<end){
        int mid=start+(end-start)/2;
        MergeSort(arr,start,mid);
        MergeSort(arr,mid+1,end);
        Merge(arr,start,mid,end);
    }
}
int main(){
    int n;
    cout<<"Enter no. of elements: ";
    cin>>n;
    int *arr = new int [n];
    cout<<"Enter elements: ";
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    MergeSort(arr,0,n-1);
    cout<<"Sorted array is: ";
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    delete[] arr;
}

// COUNT INVERSIONS - This technique is also used to count the no. of inversions where inversion will be there when arr[i]>arr[j] and i<j

int Merge(int arr[], int start, int mid, int end)
{
    int n1, n2, inversionCount=0;
    n1 = mid - start + 1;
    n2 = end - mid;
    int *a1 = new int[n1];
    int *a2 = new int[n2];
    for (int i = 0; i < n1; i++)
    {
        a1[i] = arr[start + i];
    }
    for (int j = 0; j < n2; j++)
    {
        a2[j] = arr[mid + 1 + j];
    }
    int i = 0, j = 0, k = start;
    while (i < n1 && j < n2)
    {
        if (a1[i] < a2[j])
        {
            arr[k++] = a1[i++];
        }
        else
        {
            arr[k++] = a2[j++];
            inversionCount += n1 - i;
        }
    }
    while (i < n1)
    {
        arr[k++] = a1[i++];
    }
    while (j < n2)
    {
        arr[k++] = a2[j++];
    }
    delete[] a1;
    delete[] a2;
    return inversionCount;
}
int MergeSort(int arr[], int start, int end)
{
    int inversionCount = 0;
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        inversionCount+=MergeSort(arr, start, mid);
        inversionCount+=MergeSort(arr, mid + 1, end);
        inversionCount+=Merge(arr, start, mid, end);
    }
    return inversionCount;
}
int main()
{
    int n;
    cout << "Enter no. of elements: ";
    cin >> n;
    int *arr = new int[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout<<"Inversion Count is: "<<MergeSort(arr, 0, n - 1)<<endl;
    cout << "Sorted array is: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    delete[] arr;
}

// IN-PLACE MERGE SORT - TC=O(N*LOGN), SC=O(1)
void mergeInPlace(vector<int> &nums, int start, int end)
{
    int totalLen = end - start + 1;
    int gap = (totalLen / 2) + (totalLen % 2);
    while (gap > 0)
    {
        int i = start, j = start + gap;
        while (j <= end)
        {
            if (nums[i] > nums[j])
            {
                swap(nums[i], nums[j]);
            }
            i++;
            j++;
        }
        if (gap <= 1)
        {
            break;
        }
        else
        {
            gap = (gap / 2) + (gap % 2);
        }
    }
}
void mergeSort(vector<int> &nums, int start, int end)
{
    if (start >= end)
    {
        return;
    }
    int mid = (start + end) / 2;
    mergeSort(nums, start, mid);
    mergeSort(nums, mid + 1, end);
    mergeInPlace(nums, start, end);
}
vector<int> sortArray(vector<int> &nums)
{
    mergeSort(nums, 0, nums.size() - 1);
    return nums;
}

// REVERSE PAIRS (LEETCODE 493)
// USING MERGE SORT - TC=O(N*LOGN), SC=O(N)

// Steps:
// 1. Use a modified merge sort algorithm to count reverse pairs while sorting the array.
// 2. Split the array into halves recursively until each half contains a single element.
// 3. Count reverse pairs in the current range ([low, mid] and [mid+1, high]) using the helper function `countPairs`:
//    - Iterate through the left half and use a pointer in the right half to count valid reverse pairs where `nums[i] > 2 * nums[j]`.
// 4. Merge the two sorted halves while maintaining their order using the `merge` function.
// 5. Return the total count of reverse pairs after recursively merging and counting pairs for all ranges.

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;
    int left = low;
    int right = mid + 1;
    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }
    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}
int countPairs(vector<int> &arr, int low, int mid, int high)
{
    int count = 0;
    int right = mid + 1;
    for (int i = low; i <= mid; i++)
    {
        while (right <= high && 0.5 * arr[i] > arr[right])
            right++;
        count += (right - (mid + 1));
    }
    return count;
}
int mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return 0;
    int count = 0;
    int mid = (low + high) / 2;
    count += mergeSort(arr, low, mid);
    count += mergeSort(arr, mid + 1, high);
    count += countPairs(arr, low, mid, high);
    merge(arr, low, mid, high);
    return count;
}
int reversePairs(vector<int> &nums)
{
    return mergeSort(nums, 0, nums.size() - 1);
}