# 排序算法
## 内部排序
### 插入
#### 直接插入排序
```cpp
void insert(int arr[],int n){//时间复杂度O(n^2)   空间复杂度 O(1)
	int i,j;
	for(i=1;i<n;i++){
		int key=arr[i];
		for(j=i-1;j>=0&&arr[j]>key;j--){
			arr[j+1]=arr[j];
		}
		arr[j+1]=key;
	}

}
```

#### 折半插入排序
```cpp
void bininsert(int arr[],int n){//时间复杂度O(n^2)  空间复杂度是O(1) 
	int i,j,left,mid,right;
	for(i=1;i<n;i++){
		int key=arr[i];
		for(left=0,right=i-1;left<=right;){
			mid=(left+right)/2;
			if(key<arr[mid]){
				right=mid-1;
			}else{
				left=mid+1;
			}
		}
		for(j=i-1;j>right;j--){
			arr[j+1]=arr[j];
		}
		arr[right+1]=key;
	}

}
```

#### 二路
```cpp
void twoRoad(int arr[],int n){//时间复杂度O(n^2)  空间复杂度O(n) 
	int *brr=(int *)malloc(sizeof(arr[0]*n));
	int left=-1,right=n;
	int i,j;
	for(i=0;i<n;i++){
		if(left==-1||arr[i]>brr[0]){
			for(j=left;j>=0&&arr[i]<brr[j];j--){
				brr[j+1]=brr[j];
			}
			brr[j+1]=arr[i];
			left++;
		}
		else{
			for(j=right;j<n&&arr[i]>brr[j];j++){
				brr[j-1]=brr[j];
			}
			brr[j-1]=arr[i];
			right--;
		}
	}
	for(i=right;i<n;i++){
		arr[i-right]=brr[i];
	}
	for(j=0;j<=left;j++){
		arr[n-right+j]=brr[j];
	}

}
```

#### 希尔
```cpp
void Shell(int arr[],int n){//时间复杂度是O(nlogn)    空间复杂度O(1)
	int i,j,step;
	for(step=n/2;step>0;step/=2){
		for(i=step;i<n;i++){
			int key=arr[i];
			for(j=i-step;j>=0&&arr[j]>key;j-=step){
				arr[j+step]=arr[j];
			}
			arr[j+step]=key;
		}
	}
}
```

### 选择
#### 直接
```cpp
void choice(int arr[],int n){//时间复杂度O(n^2)    空间复杂度O(1)
	int max,i,j;
	for(i=0;i<n-1;i++){
		max=0;
		for(j=1;j<n-i;j++){
			if(arr[max]<arr[j]){
				max=j;
			}
		}
		if(max!=n-1-i){
			int temp=arr[n-1-i];
			arr[n-1-i]=arr[max];
			arr[max]=temp;
		}
	}
}
```

#### 二路
```cpp
void twochoice(int arr[],int n){
	int max,min,i,j;
	for(i=0;i<n/2;i++){//循环次数
		min=max=i;
		for(j=i+1;j<n-i;j++){
			if(arr[max]<arr[j]){
				max=j;
			}else if(arr[min]>arr[j]){
				min=j;
			}
		}
		if(max!=n-1-i){
			int temp=arr[n-1-i];
			arr[n-1-i]=arr[max];
			arr[max]=temp;
		}
		if(min==n-1-i){
			min=max;
		}
		if(min!=i){
			int temp=arr[i];
			arr[i]=arr[min];
			arr[min]=temp;
		}
	}
}
```

#### 堆
```cpp
void reHeap(int arr[],int index,int n){
	int child=index*2+1;
	int key=arr[index];
	while(child<n){
		if(child+1<n&&arr[child+1]>arr[child]){//右孩子存在且比左孩子大 
			++child;
		}if(key<arr[child]){
			arr[index]=arr[child];
			index=child;
			child=2*index+1;
		}else{
			break;
		}
	}
	arr[index]=key;
}
void heapSort(int arr[],int n){//时间复杂度是O(nlogn)  空间复杂度O(1)
	int i;
	for(i=n/2;i>=0;i--){//第一个非叶子结点 n/2   从下往上调整 
		reHeap(arr,i,n);
	}
	for(i=0;i<n-1;i++){
		int temp=arr[0];
		arr[0]=arr[n-i-1];
		arr[n-1-i]=temp;
		reHeap(arr,0,n-1-i);
	}
}
```


### 交换
#### 冒泡
```cpp
void bubbleSort(int arr[],int n){//时间复杂度O(n^2)  空间复杂度O(1) 
	int i,j;
	for(i=0;i<n-1;i++){
		int swap=false;
		for(j=1;j<n-i;j++){
			if(arr[j]<arr[j-1]){
				int tmp = arr[j];
				arr[j] = arr[j-1];
				arr[j-1] = tmp;	
				swap = true;
			}
		}
		if(!swap){
			break;	
		}
	}
}
```

#### 鸡尾酒
```cpp
void cooktailSort(int arr[],int n){//时间复杂度O(n^2)  空间复杂度O(1)
	int i,j,temp;
	for(i=0;i<n/2;i++){
		int swap=false;
		for(j=i+1;j<n-i;j++){
			if(arr[j]<arr[j-1]){
				temp=arr[j];
				arr[j]=arr[j-1];
				arr[j-1]=temp;
				swap=true;
			}
		}
		for(j=j-2;j>i;j--){
			if(arr[j]<arr[j-1]){
				temp=arr[j];
				arr[j]=arr[j-1];
				arr[j-1]=temp;
				swap=true;
			}
		}
		if(!swap){
			break;
		}
	}
}
```

#### 快速
```cpp
void quickSort(int arr[],int n){//时间复杂度O(nlogn)   空间复杂度 O(nlogn)
	if(n<=1){
		return ;
	}
	int key=arr[0];
	int i,j;
	for(i=0,j=n-1;i<j;){
		while(i<j&&arr[j]>=key)--j;//从右边找到一个小于key的值 放到i
		if(i<j) arr[i++]=arr[j];
		while(i<j&&arr[i]<=key)++i;//从在边找到一个大于key的值 放到j
		if(i<j) arr[j--]=arr[i];
	}
	arr[i]=key;
	if(i>1){
		quickSort(arr,i);
	}
	if(n-i-1>1){
		quickSort(arr+1+i,n-i-1);
	}
}
```

### 归并
#### 二路归并
```cpp
void meger(int arr[],int n){
	int mid=n/2;
	int brr[mid];
	int i,j,k;
	for(i=0;i<mid;i++){
		brr[i]=arr[i];
	}
	i=0,j=mid,k=0;
	while(i<mid&&j<n){
		if(brr[i]<arr[j]){
			arr[k++]=brr[i++];
		}else{
			arr[k++]=arr[j++];
		}
	}
	while(i<mid){
		arr[k++]=brr[i++];
	} 
}
void megerSort(int arr[],int n){//时间复杂度O(nlogn)  空间复杂度O(nlogn) 
	if(n<=1){
		return ;
	}
	megerSort(arr,n/2);
	megerSort(arr+n/2,n-n/2);
	meger(arr,n);
}
```

#### 基数
```cpp
void baseSort(int arr[],int n){//O(d(n+rd))  r代表关键字基数，d代表长度，n代表关键字个数 空间复杂度O(r+n) 
	SlinketList list[10]={NULL};
	int i,j;
	for(i=0;i<n;i++){
		list[i]=slinket_list_create();
	}
	int max=arr[0];
	for(j=0;j<n;j++){
		if(arr[j]>max){
			max=arr[j];
		}
	}
	int div=1;
	for(;max/div!=0;div*=10){
		for(i=0;i<n;i++){
			int w=arr[i]/div%10;
			slinket_list_insert_back(list[w],arr[i]);
		}
		for(i=0,j=0;i<10;i++){
			while(!slinket_list_is_empty(list[i])){
				slinket_list_delete_front(list[i],&arr[j]);
				++j;
			}
		}
	}for(i=0;i<10;i++){
		slinket_list_destroy(list[i]);
	}
}










#include "linkedlist.h"

//单向链表结点
/*
typedef int ETYPE;

typedef struct Node{
	ETYPE elem;     //元素
	struct Node *next; //下一个节点的位置	
}SNode,*SLinketList; 
*/
SLinketList slinket_list_create(void){
	struct Node* head = (struct Node*)malloc(NODESIZE);//头结点  
	if(head==NULL){
		return NULL;
	}
	head->next = NULL;
	return head;
}
//判断单向链表是否为空 
bool slinket_list_is_empty(SLinketList head){//head 指针 指向头结点    *head头结点 
	return head->next == NULL; //(*head).next == NULL     
}
//单向链表中元素的个数
size_t slinket_list_size(SLinketList head){
	size_t size = 0;
	struct Node *node = head->next;//head指向头结点   head->next指向第一个结点 
	while(node != NULL){
		size++;
		node = node->next;//让node指针指向下一个节点 
	} 
	return size; 
}
//获取pos位置的前一个结点  如果pos过大，返回NULL 
static struct Node * slinket_list_get_prev_node(SLinketList head,size_t pos){
	struct Node *node = head; 
	size_t i;
	for(i=0;node!=NULL&&i<pos;i++){
		node = node->next;
	}
	return node;
} 
//在指定位置pos插入一个元素elem  第一个位置默认为0 
int slinket_list_insert(SLinketList head,size_t pos,ETYPE elem){	//要获取pos-1节点的指针  pos==0 头结点
	struct Node *prev = slinket_list_get_prev_node(head,pos);
	if(prev == NULL){
		return -1;
	}
	struct Node *node = (struct Node *)malloc(NODESIZE);
	if(node==NULL){
		return -2;
	}
	node->elem = elem;
	node->next = prev->next;
	prev->next = node;
	return 0;
}
//在单向链表前面插入一个元素elem
int slinket_list_insert_front(SLinketList head,ETYPE elem){
	struct Node *node = (struct Node *)malloc(NODESIZE);
	if(node==NULL){
		return -1;
	}
	node->elem = elem;
	node->next = head->next;
	head->next = node;
	return 0;
}
//在单向链表末尾插入一个元素elem
int slinket_list_insert_back(SLinketList head,ETYPE elem){
	//size_t size = slinket_list_size(head);
	//return slinket_list_insert(head,sie,elem);
	struct Node *last = head;
	while(last->next!=NULL){
		last = last->next;
	}
	//last->next == NULL
	//last->next = (struct Node *)malloc(NODESIZE);
	//last->next->elem = elem;  last->next->next = NULL;
	struct Node *node = (struct Node *)malloc(NODESIZE);
	node->elem = elem;
	node->next = NULL;
	last->next = node;
	return 0;
}
//删除指定位置pos的元素
int slinket_list_delete(SLinketList head,size_t pos,ETYPE *pelem){
	struct Node *prev = slinket_list_get_prev_node(head,pos);
	if(prev == NULL || prev->next == NULL){
		return -1;
	}
	struct Node *curr = prev->next;
	prev->next = curr->next;
	*pelem = curr->elem;
	free(curr);
	return 0;
}
//删除单向链表第一个元素
int slinket_list_delete_front(SLinketList head,ETYPE *pelem){
	if(head->next == NULL){
		return -1;
	}
	*pelem = head->next->elem;
	struct Node *first = head->next;
	head->next = first->next;
	free(first);
	return 0;
}
//删除末尾的元素
int slinket_list_delete_back(SLinketList head,ETYPE *pelem){
	if(head->next == NULL){
		return -1;
	} 
	//size_t size = slinket_list_size(head);
	//return slinket_lsit_delete(head,size-1,pelem);
	struct Node *lastSec = head;
	while(lastSec->next->next != NULL){
		lastSec = lastSec->next;
	}
	//lastSec记录的是倒数第二个结点
	*pelem = lastSec->next->elem; 
	free(lastSec->next);//释放最后一个结点的内存 
	lastSec->next = NULL; 
	return 0; 
}
//获取指定位置pos的元素 
int slinket_list_get(SLinketList head,size_t pos,ETYPE *pelem){
	struct Node *node = slinket_list_get_prev_node(head,pos+1);
	if(node == NULL){
		return -1;
	}
	*pelem = node->elem;
	return 0;
}
//获取第一个元素
int slinket_list_get_front(SLinketList head,ETYPE *pelem){
	if(head->next == NULL){
		return -1;
	}
	*pelem = head->next->elem;
	return 0;
}
//获取最后一个元素
int slinket_list_get_back(SLinketList head,ETYPE *pelem){
	if(head->next == NULL){
		return -1;
	}
	struct Node *last = head->next;
	while(last->next != NULL){
		last = last->next;
	}
	*pelem = last->elem;
	return 0;
}
//根据值key来查找   返回-1表示没有该值  否则返回位置 
int slinket_list_find(SLinketList head,ETYPE *pelem){
	struct Node *node = head->next;
	size_t i;
	for(i=0;node!=NULL;node=node->next,i++){
		if(node->elem == *pelem){
			return i;
		} 
	}
	return -1;
}
//遍历单向链表
void slinket_list_travel(SLinketList head,void (*travel)(int)){
	struct Node *node = head->next;
	while(node!=NULL){
		travel(node->elem);
		node = node->next;
	}
}

//删除所有元素  清空所有元素 
void slinket_list_clear(SLinketList head){
	struct Node *node,*next;
	for(node=head->next;node!=NULL;node=next){
		next = node->next;//提前保存node后面一个节点的位置 
		free(node);//释放node所指向的结点内存 
	}
	head->next = NULL;
}
//销毁单向链表
void slinket_list_destroy(SLinketList head){
	slinket_list_clear(head);
	free(head);//释放头结点的内存空间 
} 
```

#### 计数
```cpp
void countSort(int arr[],int n){//时间复杂度O(max-min+n)   空间复杂度O(max-min+1) 
	int i,j;
	int min=arr[0],max=arr[0];
	for(i=0;i<n;i++){
		if(arr[i]>max){
			max=arr[i];
		}
		if(arr[i]<min){
			min=arr[i];
		}
	}
	int count=max-min+1;
	int *cout=calloc(count,sizeof(int));
	for(i=0;i<n;i++){
		cout[arr[i]-min]++;
	}
	for(i=0,j=0;i<count;i++){
		while(cout[i]){
			arr[j++]=i+min;
			--cout[i];
		}
	}
	free(cout);

}
```

## 外部排序
```cpp
二/多路归并排序
		提升外部排序性能：减少IO次数
			增加归并路数   败者树
			减少初始归并段数   置换选择排序
```