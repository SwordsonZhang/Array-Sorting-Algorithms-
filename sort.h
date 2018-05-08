#ifndef SORT_H_
#define SORT_H_

 #include <iostream>
 using namespace std;

// AX2MIN��ʾ�Ӵ�С���У�MIN2MAX��ʾ��С��������
enum {MAX2MIN, MIN2MAX};

// ���Q����
template<typename T>
void myswap(T& x, T& y);

// ð�������㷨
template<typename T>
void bubbleSort(T array[], int length, int flag)
{
    int i, j;
    // �Ӵ�С����
    if(flag == MAX2MIN)
        for(i = 1; i < length; i++)
            for(j = length - 1; j >= i; j--)
                if(array[j] > array[j - 1])
                    myswap(array[j], array[j - 1]);

    // ��С��������
    if(flag == MIN2MAX)
        for(i = 1; i < length; i++)
            for(j = length - 1; j >= i; j--)
                if(array[j] < array[j - 1])
                    myswap(array[j], array[j - 1]);
}

// �Ľ���ð�������㷨
template<typename T>
void bubbleSortModify(T array[], int length, int flag)
{
    int i, j, k;
    // �Ӵ�С����
    if(flag == MAX2MIN)
        for(i = 1; i < length/2; i++)    // i�ķ�ΧΪ1~length/2
        {
            // �����ǰ��
            for(j = length - i; j >= i; j--)
                if(array[j] > array[j - 1])
                    myswap(array[j], array[j - 1]);
            // С��������
            for(k = i; k < length - i; k++)
                if(array[k] < array[k + 1])
                    myswap(array[k], array[k + 1]);
        }

    // ��С��������
    if(flag == MIN2MAX)
        for(i = 1; i < length/2; i++)     // i�ķ�ΧΪ1~length/2
        {
            // С����ǰ��
            for(j = length - i; j >= i; j--)
                if(array[j] < array[j - 1])
                    myswap(array[j], array[j - 1]);
            // ���������
            for(k = i; k < length - i; k++)
                if(array[k] > array[k + 1])
                    myswap(array[k], array[k + 1]);
        }
}

// ���������㷨
template<typename T>
void quickSort(T array[], int begin, int end, int flag)
{
    // �Ӵ�С����
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
        // �ݹ�
        quickSort(array, begin, i - 1, flag);
        quickSort(array, i + 1, end, flag);
    }

    // ��С��������
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

// �Ľ��Ŀ��������㷨
template<typename T>
void quickSortModify(T array[], int begin, int end, int flag)
{
    if(begin < end)
    {
        // ��һ�����еĿ�ʼ����
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

        // �Ӵ�С����
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

        // ��С��������
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

// ���������㷨
template<typename T>
void insertSort(T array[], int length, int flag)
{
    if(length > 0)
    {
        // �Ӵ�С����
        if(flag == MAX2MIN)
        {
            for(int i = 1; i < length; i++)
                for(int j = i; j > 0; j--)
                    if(array[j] > array[j - 1])
                        myswap(array[j], array[j - 1]);
                    else
                        break;
        }
        // ��С��������
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

// ϣ�������㷨
template<typename T>
void shellSort(T array[], int length, int flag)
{
    if(length > 0)
    {
        // �Ӵ�С����
        if(flag == MAX2MIN)
            // k���л�������ѡ��
            for(int k = length/2; k > 0; k /= 2)
                // ���²��ò�������ķ���
                for(int i = k; i < length; i++)
                    for(int j = i; j >= k; j -= k)
                        if(array[j - k] < array[j])
                            myswap(array[j - k], array[j]);

        // ��С��������
        if(flag == MIN2MAX)
            // k���л�������ѡ��
            for(int k = length/2; k > 0; k /= 2)
                // ���²��ò�������ķ���
                for(int i = k; i < length; i++)
                    for(int j = i; j >= k; j -= k)
                        if(array[j - k] > array[j])
                            myswap(array[j - k], array[j]);
    }
}

// ѡ�������㷨
template<typename T>
void selectSort(T array[], int start, int end, int flag)
{
    if(start < end)    // �ݹ�ʱ�жϽ�����־
    {
        // �Ӵ�С����
        if(flag == MAX2MIN)
        {
            int maxIndex = start;
            for(int i = start + 1; i < end; i++)
                if(array[maxIndex] < array[i])
                    maxIndex = i;
            // ��maxIndex��Ϊstartʱ�Ž��н���
            if(maxIndex != start)
                myswap(array[start], array[maxIndex]);
            start++;
            // �ݹ��ظ����ϲ���
            selectSort(array, start, end, flag);
        }

        // ��С��������
        if(flag == MIN2MAX)
        {
            int minIndex = start;
            for(int i = start + 1; i < end; i++)
                if(array[minIndex] > array[i])
                {
                    minIndex = i;
                }
            // ��minIndex��Ϊstartʱ�Ž��н���
            if(minIndex != start)
                myswap(array[start], array[minIndex]);
            start++;
            // �ݹ��ظ����ϲ���
            selectSort(array, start, end, flag);
        }
    }
}

// �Ľ���ѡ�������㷨
// ÿ��ѭ����������ֵ(���ֵ����Сֵ)��������
template<typename T>
void selectSortModify(T array[], int start, int end, int flag)
{
    if(start < end)
    {
        // �Ӵ�С����
        if(flag == MAX2MIN)
        {
            int maxIndex = start;
            int minIndex = start;
            for(int i = start + 1; i < end; i++)
            {
                // �ж����λ���±�
                if(array[maxIndex] < array[i])
                    maxIndex = i;
                // �ж���Сλ���±�
                if(array[minIndex] > array[i])
                    minIndex = i;
            }
            if(maxIndex != start)
            {
                myswap(array[start], array[maxIndex]);
                // �����Сֵ�±�Ϊstart������Сֵ�±��Ϊ���ֵ�±�
                if(minIndex == start)
                    minIndex = maxIndex;
            }
            if(minIndex != (end - 1))
                myswap(array[end - 1], array[minIndex]);
            // ���ĵݹ�����
            start++;
            end--;
            // �ݹ�
            selectSortModify(array, start, end, flag);
        }

        // ��С��������
        if(flag == MIN2MAX)
        {
            int minIndex = start;
            int maxIndex = start;
            for(int i = start + 1; i < end; i++)
            {
                // �ж���Сλ���±�
                if(array[minIndex] > array[i])
                    minIndex = i;
                // �ж����λ���±�
                if(array[maxIndex] < array[i])
                    maxIndex = i;
            }
            if(minIndex != start)
            {
                myswap(array[start], array[minIndex]);
                // ������ֵ�±�Ϊstart�������ֵ�±��Ϊ��Сֵ�±�
                if(maxIndex == start)
                    maxIndex = minIndex;
            }
            if(maxIndex != (end - 1))
                myswap(array[end - 1], array[maxIndex]);
            // ���ĵݹ�����
            start++;
            end--;
            // �ݹ�
            selectSortModify(array, start, end, flag);
        }
    }
}

// ��������
template<typename T>
void myswap(T& x, T& y)
{
    T temp = x;
    x = y;
    y = temp;
}

#endif // SORT_H_

