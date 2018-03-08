#include <iostream>
#include <algorithm>
#include <string>
#include "Student.h"
#include "SortTestHelper.h"

using namespace std;
///选择排序

template<typename T>

void selectionSort(T arr[],int n){
    for(int i=0;i<n;i++){
        //选择[i,n)ֵ最小的
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(arr[j]<arr[minIndex]){
                minIndex=j;
            }
            swap(arr[i],arr[minIndex]);
        }
    }

}
///插入排序算法
template<typename T>
void insertionSort(T arr[],int n){
    for(int i=1;i<n;i++){
        for(int j=i;j>0;j--){
            if(arr[j]<arr[j-1])
                swap(arr[j],arr[j-1]);
            else
                break;

        }
    }
}
///对于插入排序算法的优化通过数次拷贝取代交换三次赋值多余的运算量
template<typename T>
void insertionSortOp(T arr[],int n){
    for(int i=0;i<n;i++){
        //寻找元素arr[i]应该插入的位置
        T e =arr[i];
        //j 保存元素e应该插入的位置
        int j ;
        for(j=i;j>0&&arr[j-1]>e;j--){
            arr[j]=arr[j-1];

        }
        arr[j]=e;
    }
}

int main()
{
    int n=10000;
    int *arr=SortTestHelper::generateRandomArray(n,0,n);
    int *arr1=SortTestHelper::copyIntArray(arr,n);
    int *arr2=SortTestHelper::copyIntArray(arr,n);
    /*int arr[10]={10,9,8,7,6,5,4,3,2,1};
    selectionSort(arr,10);
    for(int i=0;i<10;i++)
        cout<<arr[i]<<" ";
    cout <<endl;*/

    //int *arr =SortTestHelper::generateRandomArray(n,0,n);
    //selectionSort(arr,n);
    SortTestHelper::testSort("Selection Sort",selectionSort,arr,n);
    SortTestHelper::testSort("Insertion Sort",insertionSort,arr1,n);
    SortTestHelper::testSort("Insertion Sort Optimize",insertionSortOp,arr2,n);
    //SortTestHelper::printArray(arr,n);
    delete [] arr;
    delete [] arr1;
    delete [] arr2;
    /*Student d[4]={{"D",90},{"C",100},{"B",95},{"A",95}};
    selectionSort(d,4);
    for(int i=0;i<4;i++){
        cout<<d[i];
    }
    cout<<endl;
    */
    return 0;
}
