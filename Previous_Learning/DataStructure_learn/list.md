# 3 列表
## 3.1 从向量到列表
### 3.1.2 从静态到动态
- 数据结构支持操作：静态和动态
  - 静态：get()、size()
  - 动态：remove()、insert()
- 向量——各元素物理地址连续——静态存储策略
  - 静态操作：常数时间完成
  - 动态操作：可能需要线性时间
- 列表——各元素物理地址不连续——动态存储策略
  - 静态操作
  - 动态操作：常数时间完成
### 3.1.2 由秩到位置
- 访问秩为r的元素，花费的时间成本为r。
- 对于列表，尽量通过位置来访问动态存储结构中的元素

### 3.1.3 列表
列表是链表结构的一般化推广，其元素成为节点node,同时定义前驱和后继等关系。

## 3.2 接口
### 3.2.1 列表节点
- ADT接口

操作接口|功能
---:|:---
data()|当前节点存储对象
prec()|当前节点前驱节点的位置
succ()|当前节点后继节点的位置
insertAsPred(e)|插入前驱结点，存入被引用对象e，返回新节点位置
insertAsSucc(e)|插入后继结点，存入被引用对象e，返回新节点位置

- [ListNode模板类 定义](code/List/listNode.h)
### 3.2.2 列表
- ADT接口——只读访问接口

操作接口|功能|适用对象
---:|:---:|:---
size()|报告列表当前的规模(节点总数)|列表
first()、last()|返回首、末节点的位置|列表
disordered()|判断所有节点是否已按非降序排列|列表
find(e)|查找目标元素e，失败时返回nullptr|列表
search(e)|查找目标元素e，返回不大于e的最大节点|有序列表
- ADT接口——可写访问接口

操作接口|功能|适用对象
---:|:---:|:---
insertAsFirst(e)<br>insertAsLast(e)|将e当作首、末节点插入|列表
insertA(p,e)<br>insertB(p,e)|将e当作节点p的后继、前驱插入|列表
remove(p)|删除位置p的节点，返回其数值|列表
sort()|调整各节点的位置，使之按非降序排列|列表
deduplicate()|删除重复节点|列表
uniquify()|删除重复节点|有序列表
traverse()|遍历并统一处理所有节点，处理方法由函数对象指定|列表
- [List模板类](code/List/List.h)

## 3.3 列表
### 3.3.1 头、尾节点
列表私有的头(header)、尾(trailer)节点始终存在，但对外并不可见。对外部可见的节点如果存在，则其中的第一个和最后一个节点分别作 **首节点**和 **末节点**。
头、尾节点被称为哨兵节点，尽管占据了一定空间，但不必对边界退化的情况做专门处理。
### 3.3.2 默认构造方法
默认构造方法统一调用初始化程序。[init()](code/List/list_initialize.h)
### 3.3.3 由秩到位置的转换
重载"[]"操作符，提供一个转换接口。
[由秩访问元素](code/List/list_backet.h)
### 3.3.4 查找
- [find(e)实现](code/List/list_find.h)
### 3.3.5 插入
- 接口
为将节点插入至列表，提供了四种插入方式，读者可灵活选取。
[列表节点插入实现](code/List/list_insert.h)
- 前插入
  [将新元素e作为当前节点前驱插至列表](code/List/listNode_insertAsPred.h)
- 后插入
  [将新元素e作为当前节点后驱插至列表](code/List/listNode_insertAsSucc.h)
- 复杂度
  常数时间复杂度
### 3.3.6 基于复制的构造
- [copyNode()](code/List/list_copyNodes.h)
- [基于复制的构造](code/List/list_constructor_by_copying.h)
  这里提供了3种复制构造函数的接口
  - 复制列表自位置p起的n项
  - 整体复制列表
  - 复制列表L中自r项起的n项

### 3.3.7 删除
- 实现
  [删除指定位置的节点remove(p)](code/List/list_remove.h)
- 复杂度(常数时间内完成)

### 3.3.8 析构
- 释放资源及清除节点
  列表对象析构需要清空列表，同时释放头、尾节点
  [析构函数~List()](code/List/list_deconstructor.h)

### 3.3.9 唯一化
- 实现
  与向量的无序去重算法类似，这里也是自前向后依次处理各节点p，若在p的前驱中找到与p雷同者，则删除p。
  [deduplicate()](code/List/list_deduplicate.h)
- 正确性
  - 不变性：p的前驱始终无重复
  - 单调性：每经过一次循环，问题规模-1
- 复杂度
  每次查找的复杂度为O(r)，执行n次查找，则时间复杂度为O(n^2);
### 3.3.10 遍历
  列表提供支持节点批量式访问的遍历接口。<br>函数指针适合局部修改，函数对象是和全局修改。
  [遍历traverse()](code/List/list_traverse.h)

## 3.4 有序列表
有序列表的逻辑次序与其大小次序完全一致。
### 3.4.1 唯一化
- [唯一化实现uniquify()](code/List/list_uniquify.h)
### 3.4.2 查找
- 实现[有序列表查找接口search()](code/List/list_search.h)
- 顺序查找，除结束条件外，该算法与无序列表查询算法基本一样
- 复杂度O(n)

## 3.5 排序器
### 3.5.1 统一入口
  为各种排序方法设置了一个统一的排序操作接口。[列表排序sort()接口](code/List/list_sort.h)
### 3.5.2 插入排序
- 构思
  插入排序的思路：任何时刻，相对于当前结点e = S[r],前缀S[0,r)总是业已有序
- 正确性
  - 不变性：前缀有序，前缀为空时，满足；
  - 单调行：前缀的长度越来越长，直到整个列表，列表有有序
- 实现
  [insertionSort()](code/List/list_insertionSort.h)

### 3.5.3 选择排序
- 构思
  与插入排序类似，选择排序将列表分为无序前缀和有序后缀两个部分；每次操作从前缀中选出最大者，移动至后缀中
  **在任何时刻，后缀S(r,n)已有序，且不小于前缀S[0,r]**
- 实现
  [selectionSort()](code/List/list_selectionSort.h)

### 3.5.4 归并排序
- [二路归并排序算法的实现](code/List/list_merge.h)
- 归并时间：O(n+m)
- 分治策略：[mergeSort()](code/List/list_mergeSort.h)
- 排序时间：O(nlogn)