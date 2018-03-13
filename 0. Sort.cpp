/*
 * 常见的排序算法有：直接插入 希尔      -插入排序
 *                 冒泡  快速         -交换排序
 *                 直接选择  堆排序   -选择排序
 *                 归并  
 *                 基数
 * 稳定 ： 直接插入 冒泡 归并 基数 
 * 直接插入：n小时较好
 * 直接选择：n小时较好
 * 堆排序：n大时较好
 * 冒泡排序：n小时较好
 * 归并排序：n大时较好
 */

/*
 * 冒泡排序是最简单的排序算法，冒泡排序的基本思想是从后往前（或从前往后）两两比较相邻元素的值，若为逆序，则交换它们，直到序列比较完毕。每一趟冒泡都会将一个元素放置到最终的位置上。
 * 时间复杂度 平均 n^2 最差 n^2 最好 n 空间复杂度 1 稳定 简单 
 */
void BubbleSortR(vector<int>& nums)
{
    int len = nums.size();
    for(int i = 0; i < len - 1; i++)//一共进行len-1次
    {
        for(int j = 1; j< len - i; j++)
        {
            if(nums[j] < nums[j-1])
            {
                swap(nums[j],nums[j-1]);//每次将一个最大的数字移动到最右侧
            }
        }
    }
}
void BubbleSortL(vector<int>& nums)
{
    int len = nums.size();
    for(int i = 0; i < len - 1; i++)
    {
        for(int j = n - i; j > i; j--)
        {
            if(nums[j] < nums[j-1])
            {
                swap(nums[j], nums[j-1]);//每次将一个最大数移动到最左侧
            }
        }
    }
}
/*
 * 快速排序是对冒泡排序的一种改进。其基本思想是基于分治法：在待排序表L[n]中任取一个元素pivot作为基准，通过一趟排序将序列划分为两部分L[1…K-1] 和L[K+1…n]，使得L[1…K-1]中的所有元素都小于pivot,而L[k+1…n]中的所有元素都大于或等于pivot。则pivot放在了其最终的位置L(k)上。然后，分别递归对两个子序列重复上述过程，直至每部分内只有一个元素或空为止，即所有元素放在了其最终的位置上。
 * 时间复杂度 平均 nlogn 最坏 n^2 最好 nlogn 空间复杂度 nlogn(递归/栈的深度) 不稳定 复杂
 */ 
int Partion(vector<int>& nums, int left, int right)
{
    int key = nums[left];//选择key
    while(left < right)
    {
        while(left < right && nums[right >= key])
        {
            right--;//从右侧起找到一个比key值小的元素 准备放到key的左侧
        }
        nums[left] = nums[right];//把找到的比key小的元素放在key本来的位置
        while(left < right && nums[left] < key)
        {
            left++;//从左侧起找到一个比key值大的元素 准备放到key的右侧
        }
        nums[right] = nums[left];//把找到的比key大的元素放到上次空缺出来的位置
    }//一次便利后key左/右侧都是比key小/大的元素
    nums[left] = key;//将key放到序列'中间'
    return left;//返回下次二分的切割位置
}
void QuickSort(vector<int>& nums, int left, int right)
{
    //int left = 0;
    //int right = nums.size() - 1;
    if(left < right)
    {
        int pos = Partion(nums, left, right);
        QuickSort(nums, left, pos - 1);
        QuickSort(nums, pos + 1, right)
    }
}
/* 
 * 简单选择排序则是对要排序的序列，选出关键字最小的数据，将它和第一个位置的数据交换，接着，选出关键字次小的 数据，将它与第二个位置上的数据交换。以此类推，直到完成整个过程所以如果有n个数据，那么则需要遍历n-1遍。 
 * 时间复杂度 平均 n^2 最坏 n^2 最好 n^2 空间复杂度 1 不稳定 简单
 */
void SelectSort(vector<int>& nums)
{
    int len = nums.size();
    for(int i = 0;i < len - 1; i++)//只需要考察n-1个元素
    {
        int min = nums[i];
        int cur = i;
        for(int j = i + 1; j < len; j++)
        {
            if(min>nums[j])//找到第i个元素后面所有元素最小元素的索引
            {
                cur = j;
            }
        }
        swap(nums[i],nums[cur]);
    }
}
/* 
* 直接插入排序，为了实现N个数的排序，将后面N-1个数依次插入到前面已经排好的子序列中，假定刚开始第一个数是一个已拍好序的子序列,那么经过N-1趟就能得到一个有序的序列。 
* 时间复杂度 平均 n^2 最坏 n^2 最好 n 空间复杂度 1 稳定 简单
*/
void InsertSort(vector<int>& nums)
{
    int len = nums.size();
    if(len <= 1)
        return;
    for(int i = 1; i < len; i++)
    {
        int key = nums[i];//i指向要插入的元素索引
        int j;
        for(j = i - 1; j>= 0 && key < nums[j]; j--)
        {
            nums[j + 1] = num[j];//如果nums[j]比带插入元素大，则向后移动
        }
        nums[j + 1] = key;//空出来的位置插入新元素(因为上一个比key大的元素移动后做了j--，所以+1)
    }
}
/* 希尔排序是插入排序的一种，是对直接插入排序算法的 改进该方法又称为缩小增量排序。比较相距一定间隔的元素，即形如L[i,i+d,i+2d,…,i+kd]的序列然后缩小间距，再对各分组序列进行排序。直到之比较相邻元素的最后一趟排序为止，即最后的间距为1。
* 空间复杂度 n^1.3 最坏 n^2 最好 n 空间复杂度 1 不稳定 复杂
*/ 
void ShellSort(vector<int>& nums)
{
    int len = nums.size();
    int d = len/2;
    while(d >= 1)
    {
        int temp;
        for(int i = d; i < len; i++)
        {
            temp = nums[i];
            for(j = i - d;j >= 0 && temp < nums[j]; j = j - d)
            {
                nums[j + d] = temp;
            }
            nums[j + d] = temp;
        }
        d = d / 2;
    }
}
/*合并排序采用分治算法，思路是将两个或以上的有序表合并为一个有序表，把待排序的序列分割成若干个子序列，每个子序列有序，然后再把子序列合并为一个有序序列。若将两个有序表合并成一个有序表，则成为2路合并排序。2路归并即使将2个有序表组合成一个新的有序表。假定待排序表有n个元素，则可以看成是n个有序的字表，每个子表长度为1，然后两两归并…不停重复，直到合并成一个长度为n的有序列表为止。Merge()函数是将前后相邻的两个有序表归并为一个有序表，设A[low…mid]和A[mid+1…high]存放在同一顺序表的相邻位置上，先将他们复制到辅助数组B中，每次从对应B中的两个段取出一个元素进行比较，将较小者放入A中。
 * 时间复杂度 平均 nlogn 最坏 nlogn 最好 nlogn 空间复杂度 n 稳定 复杂
 */
void merge(vector<int>& nums, int left, int mid, int right)
{
    int k = right - left + 1;
    vector<int> tempArray(k);
    int p = right, q = mid;
    while(p > mid && q >= left)
    {
        if(nums[p] > nums[q])
        {
            tempArray[--k] = nums[p--];
        }
        else
        {
            tempArray[--k] = nums[q--];
        }
    }
    while(p > mid)
    {
        tempArray[--k] = nums[q--];
    }
    while(q >= left)
    {
        tempArray[--k] = nums[q--];
    }
    k = right - left + 1;
    for(int i = 0; i < k; i++)
    {
        nums[left + i] = tempArray[i];
    }
}
void partion(vector<int>& nums, int left, int right)
{
    if(left < right)
    {
        int mid = left + (right - left) / 2;
        partion(nums, left, mid);
        partion(nums, left, mid + 1, right);
        merge(nums, left, mid, right);
    }
}
void MergeSort(vector<int>& nums)
{
    int len = nums.size();
    partion(nums, 0, len - 1);
}
/* 堆排序
 * 时间复杂度 平均 最坏 最好 nlogn 空间复杂度 n 不稳定 复杂
 */
void HeapAdjust(vector<int>&nums, int root, int size)
{
    //左孩子
    int leftChild = 2 * root + 1;
    //若有左孩子
    if (leftChild <= size - 1)
    {
        //右孩子
        int rightChild = leftChild + 1;
        //若有右孩子
        if (rightChild <= size - 1)
        {
            if (nums[leftChild] < nums[rightChild])
            {
                leftChild = rightChild;
            }
        }

        if (nums[root] < nums[leftChild])
        {
            swap(nums[root], nums[leftChild]);
            HeapAdjust(nums, leftChild, size);
        }
    }
}
void HeapSort(vector<int>& nums)
{
    int size = nums.size();
    for (int i = size / 2 - 1; i >= 0; i--)
    {
        HeapAdjust(nums, i, size);
    }

    for (int i = size - 1; i>0; i--)
    {
        swap(nums[0], nums[i]);
        HeapAdjust(nums, 0, i);
    }
}
/* 基数排序
 * 时间复杂度 平均 最坏 最好 d(n+r) 空间复杂度 (n+r) 稳定 复杂 
 */
void RadixSort(vector<int>& array)
{
    int size = array.size();
    int bucket[10][10] = { 0 };//定义基数桶  
    int order[10] = { 0 };//保存每个基数桶之中的元素个数  
    int key_size = KeySize(array);//计算关键字位数的最大值  
    for (int n = 1; key_size>0; n *= 10, key_size--)
    {
        /*将待排序的元素按照关键值的大小依次放入基数桶之中*/
        for (int i = 0; i<size; i++)
        {
            int lsd = (array[i] / n) % 10;
            bucket[lsd][order[lsd]] = array[i];
            order[lsd]++;
        }
        /*将基数桶中的元素重新串接起来*/
        int k = 0,i;
        for (i = 0; i<10; i++)
        {
            if (order[i] != 0)
            {
                for (int j = 0; j<order[i]; j++)
                {
                    array[k] = bucket[i][j];
                    k++;
                }
                order[i] = 0;
            }
        }
    }
}
