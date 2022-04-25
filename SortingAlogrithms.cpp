#include <iostream>
using namespace std;

void Swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

int GetMax(int A[], int n)
{
    int max = A[0];
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
            max = A[i];
    }
    return max;
}

void MaxandMin(int A[], int n, int &max, int &min)
{
    for (int i = 0; i < n; i++)
    {
        if (A[i] > max)
            max = A[i];
    
        if (A[i] < min)
            min = A[i];
    }
}

int Partition(int A[], int start, int end)
{
    int pivot = A[end];
    int pIndex = start;

    for (int i = start; i < end; i++)
    {
        if (A[i] <= pivot)
        {
            Swap(A[i], A[pIndex]);
            pIndex++;
        }
    }
    Swap(A[pIndex], A[end]);
    return pIndex;
}

int RandomizedPartition(int A[], int start, int end)
{
    int pivot = (rand() % (end - start + 1)) + start;
    Swap(A[pivot], A[end]);
    return Partition(A, start, end);
}

void QuickSort(int A[], int start, int end)
{
    if (start < end)
    {
        int pIndex = RandomizedPartition(A, start, end);
        QuickSort(A, start, pIndex - 1);
        QuickSort(A, pIndex + 1, end);
    }
}

void Merge(int left[], int right[], int A[], int nL, int rL)
{
    int i = 0;
    int j = 0;
    int k = 0;
    
    while (i < nL && j < rL)
    {
        if (left[i] < right[j])
            A[k] = left[i++];
        else
            A[k] = right[j++];
        
        k++;
    }
    
    while (i < nL)
        A[k++] = left[i++];

    while (j < rL)
        A[k++] = right[j++];
}

void MergeSort(int A[], int n)
{
    if (n < 2)
        return;
    
    int mid = n/2;
    int left[mid];
    int right[n - mid];

    for (int i = 0; i < mid; i++)
        left[i] = A[i];
    
    for (int i = mid; i < n; i++)
        right[i - mid] = A[i];
    
    MergeSort(left, mid);
    MergeSort(right, n - mid);
    Merge(left, right, A, mid, n - mid);
}

void CountingSort(int A[], int n, int pos)
{
    int Count[10] = {0};
    int SortedArray[n];

    for (int i = 0; i < n; i++)
        Count[(A[i]/pos) % 10]++;

    for (int i = 1; i < 10; i++)
        Count[i] += Count[i - 1];
    
    for (int i = n - 1; i >= 0; i--)
        SortedArray[--Count[(A[i]/pos) % 10]] = A[i];
    
    for (int i = 0; i < n; i++)
        A[i] = SortedArray[i];
}

void RadixSort(int A[], int n)
{
    int max = GetMax(A, n);

    for (int pos = 1; max/pos > 0; pos *= 10)
        CountingSort(A, n, pos);
}

void CountingSort(int A[], int n)
{
    int k = A[0];
    int min = A[0];
    MaxandMin(A, n, k, min);
    
    if (min < 0)
    {
        min *= -1;
        k += min;
    }

    int Count[k + 1] = {0};
    int SortedArray[n];

    for (int i = 0; i < n; i++)
        Count[A[i] + min]++;
    
    for (int i = 1; i <= k+1; i++)
        Count[i] += Count[i - 1];

    for (int i = n - 1; i >= 0; i--)
        SortedArray[--Count[A[i] + min]] = A[i];

    for (int i = 0; i < n; i++)
        A[i] = SortedArray[i];
}

void BubbleSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[i])
            {
                Swap(A[i], A[j]);
            }
        }
    }
}

void SelectionSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (A[j] < A[min])
                min = j;
        }
        Swap(A[i], A[min]);
    }
}

void InsertionSort(int A[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int value = A[i];
        int hole = i;
        while (hole > 0 && A[hole - 1] > value)
        {
            A[hole] = A[hole - 1];
            hole--;
        }
        A[hole] = value;
    }
}

int main()
{
    int A[] = {5, 9, 2, 8, 1, 0, 7};
    MergeSort(A, sizeof(A)/sizeof(int));

    for (int i = 0; i < 7; i++)
        cout << A[i] << " ";
}