#ifndef SELECTIONSORT_SORTTEST_HELPER_H
#define SELECTIONSORT_SORTTEST_HELPER_H
#include <iostream>
#include <ctime>
#include <cassert>
#include <string>

using namespace std;

namespace SortTestHelper{
    //������n��Ԫ�ص�������飬ÿ��Ԫ�ص������ΧΪ[rangeL,rangeR]
    int * generateRandomArray(int n, int rangeL,int rangeR){
        assert(rangeL <= rangeR);
        int *arr = new int [n];
        srand(time(NULL));//���������
        for(int i=0 ;i<n;i++){
            // �������䷶Χ�������
            arr[i] =rand()%(rangeR-rangeL+1)+rangeL;

        }
        return arr;

    }

    template<typename T>
    void printArray(T arr[],int n){
        for(int i;i<n;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
        return;
    }

    template<typename T>
    bool isSorted(T arr[], int n){
        for(int i=0;i<n-1;i++){
            if(arr[i]>arr[i+1])
                return false;
            else
                return true;
        }
    }
    //����sort�����㷨����arr�������õ��������ȷ�Ժ��㷨����ʱ��
    template<typename T>
    void testSort(const string &sortName, void (*sort)(T[],int),T arr[], int n){
        clock_t startTime =clock();
        sort(arr,n);
        clock_t endTime =clock();
        assert(isSorted(arr,n));
        cout<<sortName<<":"<<double (endTime-startTime)/CLOCKS_PER_SEC<<"s"<<endl;
        return;

    }
    int* copyIntArray(int a[],int n){
        int *arr =new int [n];
        copy(a,a+n,arr);
        return arr;
    }
}

#endif // SELECTIONSORT_SORTTESTHELPER_H
