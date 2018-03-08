#ifndef SELECTIONSORT_SORTTEST_HELPER_H
#define SELECTIONSORT_SORTTEST_HELPER_H
#include <iostream>
#include <ctime>
#include <cassert>
#include <string>

using namespace std;

namespace SortTestHelper{
    //生成有n个元素的随机数组，每个元素的随机范围为[rangeL,rangeR]
    int * generateRandomArray(int n, int rangeL,int rangeR){
        assert(rangeL <= rangeR);
        int *arr = new int [n];
        srand(time(NULL));//随机树种子
        for(int i=0 ;i<n;i++){
            // 生成区间范围的随机数
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
    //测试sort排序算法排序arr数组所得到结果的正确性和算法运行时间
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
