/*********************************************************
*将vector各方法的实现部分，简洁的引入vector.h
*效果等同于这些实现直接汇入vector.h
*在export尚未被编译器支持前，如此可将定义与实现分离，以便课程讲解
**********************************************************/

// #include "_share/release.h"
// #include "_share/util.h"

#include "vector_bracket.h"
#include "vector_assignment.h"

#include "vector_constructor_by_copying.h"

#include "vector_expand.h"
#include "vector_shrink.h"

#include "vector_insert.h"
#include "vector_remove.h"
#include "vector_removeInterval.h"

#include "vector_find.h"
#include "vector_search.h"
#include "vector_search_binary_C.h"//有A、B、C三版，C最完善
//#include "vector_search_fibonaccian_A.h"//实用版(但返回值有待与接口统一)
#include "vector_search_fibonaccian_B.h"//华丽版

#include "vector_traverse.h"

#include "vector_unsort.h"
#include "vector_sort.h"
//#include "vector_bubbleSort_A.h"
//#include "vector_bubbleSort_B.h"
#include "vector_bubbleSort_C.h"
#include "vector_selectionSort.h"
#include "vector_merge.h"
#include "vector_mergeSort.h"
//#include "vector_partition_LUG.h"
//#include "vector_partition_LUG1.h"
//#include "vector_partition_DUP.h"
//#include "vector_partition_DUP1.h"
#include "vector_partition_LGU.h"
#include "vector_heapSort.h"
//#include "vector_quickSort_recursive.h"
#include "vector_quickSort_iterative.h"
#include "vector_shellSort.h"

#include "vector_uniquify.h" //或者Vector_uniquify_slow.h
#include "vector_deduplicate.h"