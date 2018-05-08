#ifndef SORT_H_
#define SORT_H_

 #include <iostream>
 using namespace std;

// AX2MIN表示从大到小排列；MIN2MAX表示从小到大排列
enum {MAX2MIN, MIN2MAX};

// 交換数据
template<typename T>
void myswap(T& x, T& y);

// 冒泡排序算法
template<typename T>
void bubbleSort(T array[], int length, int flag)
{
    int i, j;
    // 从大到小排列
    if(flag == MAX2MIN)
        for(i = 1; i < length; i++)
            for(j = length - 1; j >= i; j--)
                if(array[j] > array[j - 1])
                    myswap(array[j], array[j - 1]);

    // 从小到大排列
    if(flag == MIN2MAX)
        for(i = 1; i < length; i++)
            for(j = length - 1; j >= i; j--)
                if(array[j] < array[j - 1])
                    myswap(array[j], array[j - 1]);
}

// 改进的冒泡排序算法
template<typename T>
void bubbleSortModify(T array[], int length, int flag)
{
    int i, j, k;
    // 从大到小排列
    if(flag == MAX2MIN)
        for(i = 1; i < length/2; i++)    // i的范围为1~length/2
        {
            // 大的数前移
            for(j = length - i; j >= i; j--)
                if(array[j] > array[j - 1])
                    myswap(array[j], array[j - 1]);
            // 小的数后移
            for(k = i; k < length - i; k++)
                if(array[k] < array[k + 1])
                    myswap(array[k], array[k + 1]);
        }

    // 从小到大排列
    if(flag == MIN2MAX)
        for(i = 1; i < length/2; i++)     // i的范围为1~length/2
        {
            // 小的数前移
            for(j = length - i; j >= i; j--)
                if(array[j] < array[j - 1])
                    myswap(array[j], array[j - 1]);
            // 大的数后移
            for(k = i; k < length - i; k++)
                if(array[k] > array[k + 1])
                    myswap(array[k], array[k + 1]);
        }
}

// 快速排序算法
template<typename T>
void quickSort(T array[], int begin, int end, int flag)
{
    // 从大到小排列
    if(begin < end && flag == MAX2MIN)
    {
        T key = array[begin];
        int i = begin;
        int j = end;
        while(i < j)
        {
            while(i < j && array[j] < key)
                j--;
            if(i < j)
            {
                array[i] = array[j];
                i++;
            }
            while(i < j && array[i] > key)
                i++;
            if(i < j)
            {
                array[j] = array[i];
                j--;
            }
        }
        array[i] = key;
        // 递归
        quickSort(array, begin, i - 1, flag);
        quickSort(array, i + 1, end, flag);
    }

    // 从小到大排列
    if(begin < end && flag == MIN2MAX)
    {
        T key = array[begin];
        int i = begin;
        int j = end;
        while(i < j)
        {
            while(i < j && array[j] > key)
                j--;
            if(i < j)
            {
                array[i] = array[j];
                i++;
            }
            while(i < j && array[i] < key)
                i++;
            if(i < j)
            {
                array[j] = array[i];
                j--;
            }
        }
        array[i] = key;
        quickSort(array, begin, i - 1, flag);
        quickSort(array, i + 1, end, flag);
    }
}

// 改进的快速排序算法
template<typename T>
void quickSortModify(T array[], int begin, int end, int flag)
{
    if(begin < end)
    {
        // 找一个适中的开始数据
        T sub1 = array[end/2] - array[begin];
        T sub2 = array[end/2] - array[end];
        T sub3 = array[begin] - array[end];
        int k;
        if(sub1 > 0 && sub2 > 0)
            k = sub3 > 0? begin : end;
        else if(sub1 < 0 && sub2 < 0)
            k = sub3 > 0? end : begin;
        else
            k = end/2;
        if(k != begin)
            myswap(array[k], array[begin]);
        T key = array[begin];
        int i = begin;
        int j = end;

        // 从大到小排列
        if(flag == MAX2MIN)
        {
            while(i < j)
            {
                while(i < j && array[j] < key)
                    j--;
                if(i < j)
                {
                    array[i] = array[j];
                    i++;
                }
                while(i < j && array[i] > key)
                    i++;
                if(i < j)
                {
                    array[j] = array[i];
                    j--;
                }
            }
        }

        // 从小到大排列
        if(flag == MIN2MAX)
        {
            while(i < j)
            {
                while(i < j && array[j] > key)
                    j--;
                if(i < j)
                {
                    array[i] = array[j];
                    i++;
                }
                while(i < j && array[i] < key)
                    i++;
                if(i < j)
                {
                    array[j] = array[i];
                    j--;
                }
            }
        }
        array[i] = key;
        quickSort(array, begin, i - 1, flag);
        quickSort(array, i + 1, end, flag);
    }
}

// 插入排序算法
template<typename T>
void insertSort(T array[], int length, int flag)
{
    if(length > 0)
    {
        // 从大到小排列
        if(flag == MAX2MIN)
        {
            for(int i = 1; i < length; i++)
                for(int j = i; j > 0; j--)
                    if(array[j] > array[j - 1])
                        myswap(array[j], array[j - 1]);
                    else
                        break;
        }
        // 从小到大排列
        if(flag == MIN2MAX)
        {
            for(int i = 1; i < length; i++)
                for(int j = i; j > 0; j--)
                    if(array[j] < array[j - 1])
                        myswap(array[j], array[j - 1]);
                    else
                        break;
        }
    }
}

// 希尔排序算法
template<typename T>
void shellSort(T array[], int length, int flag)
{
    if(length > 0)
    {
        // 从大到小排列
        if(flag == MAX2MIN)
            // k序列还有其他选择
            for(int k = length/2; k > 0; k /= 2)
                // 以下采用插入排序的方法
                for(int i = k; i < length; i++)
                    for(int j = i; j >= k; j -= k)
                        if(array[j - k] < array[j])
                            myswap(array[j - k], array[j]);

        // 从小到大排列
        if(flag == MIN2MAX)
            // k序列还有其他选择
            for(int k = length/2; k > 0; k /= 2)
                // 以下采用插入排序的方法
                for(int i = k; i < length; i++)
                    for(int j = i; j >= k; j -= k)
                        if(array[j - k] > array[j])
                            myswap(array[j - k], array[j]);
    }
}

// 选择排序算法
template<typename T>
void selectSort(T array[], int start, int end, int flag)
{
    if(start < end)    // 递归时判断结束标志
    {
        // 从大到小排列
        if(flag == MAX2MIN)
        {
            int maxIndex = start;
            for(int i = start + 1; i < end; i++)
                if(array[maxIndex] < array[i])
                    maxIndex = i;
            // 当maxIndex不为start时才进行交换
            if(maxIndex != start)
                myswap(array[start], array[maxIndex]);
            start++;
            // 递归重复以上步骤
            selectSort(array, start, end, flag);
        }

        // 从小到大排列
        if(flag == MIN2MAX)
        {
            int minIndex = start;
            for(int i = start + 1; i < end; i++)
                if(array[minIndex] > array[i])
                {
                    minIndex = i;
                }
            // 当minIndex不为start时才进行交换
            if(minIndex != start)
                myswap(array[start], array[minIndex]);
            start++;
            // 递归重复以上步骤
            selectSort(array, start, end, flag);
        }
    }
}

// 改进的选择排序算法
// 每次循环将两个最值(最大值和最小值)放在两端
template<typename T>
void selectSortModify(T array[], int start, int end, int flag)
{
    if(start < end)
    {
        // 从大到小排列
        if(flag == MAX2MIN)
        {
            int maxIndex = start;
            int minIndex = start;
            for(int i = start + 1; i < end; i++)
            {
                // 判断最大位置下标
                if(array[maxIndex] < array[i])
                    maxIndex = i;
                // 判断最小位置下标
                if(array[minIndex] > array[i])
                    minIndex = i;
            }
            if(maxIndex != start)
            {
                myswap(array[start], array[maxIndex]);
                // 如果最小值下标为start，则将最小值下标改为最大值下标
                if(minIndex == start)
                    minIndex = maxIndex;
            }
            if(minIndex != (end - 1))
                myswap(array[end - 1], array[minIndex]);
            // 更改递归区间
            start++;
            end--;
            // 递归
            selectSortModify(array, start, end, flag);
        }

        // 从小到大排列
        if(flag == MIN2MAX)
        {
            int minIndex = start;
            int maxIndex = start;
            for(int i = start + 1; i < end; i++)
            {
                // 判断最小位置下标
                if(array[minIndex] > array[i])
                    minIndex = i;
                // 判断最大位置下标
                if(array[maxIndex] < array[i])
                    maxIndex = i;
            }
            if(minIndex != start)
            {
                myswap(array[start], array[minIndex]);
                // 如果最大值下标为start，则将最大值下标改为最小值下标
                if(maxIndex == start)
                    maxIndex = minIndex;
            }
            if(maxIndex != (end - 1))
                myswap(array[end - 1], array[maxIndex]);
            // 更改递归区间
            start++;
            end--;
            // 递归
            selectSortModify(array, start, end, flag);
        }
    }
}

// 交换函数
template<typename T>
void myswap(T& x, T& y)
{
    T temp = x;
    x = y;
    y = temp;
}

#endif // SORT_H_

