/**
 * @author: Frans
 * @Time: 2020/5/20
*/

#include <bits/stdc++.h>
using namespace std;

#define MAXTABLESIZE 10000 //允许开辟的最大散列表长度
typedef string ElementType;
typedef enum{
    Legitimate,
    Empty,
    Deleted
} EntryType; //散列单元的状态类型

struct HashEntry{
    ElementType data; //存放的元素
    EntryType state;  //单元状态
};

typedef struct HashEntry Cell;

struct TblNode{
    int tablesize; //表的最大长度
    Cell *cells;   //存放散列单元数据的数组
};
typedef struct TblNode *HashTable;

/*返回大于n且不超过MAXTABLESIZE的最小素数*/
int NextPrime(int n){
    int p = (n % 2) ? n + 2 : n + 1; //从大于n的下一个奇数开始
    int i;
    while (p <= MAXTABLESIZE){
        for (i = (int)sqrt(p); i > 2; i--){
            if ((p % i) == 0) break;
        }
        if (i == 2) break; //说明是素数，结束
        else p += 2;
    }
    return p;
}

/*创建新的哈希表*/
HashTable CreateTable(int table_size) {
    HashTable h = (HashTable)malloc(sizeof(TblNode));
    h -> tablesize = NextPrime(table_size);
    h -> cells = (Cell *)malloc(h -> tablesize * sizeof(Cell));
    //初始化哈希表状态为空单元
    for (int i = 0; i < h -> tablesize; i++) {
        h -> cells[i].state = Empty;
    }
    return h;
}

/*查找数据的初始位置*/
int Hash(ElementType key, int n) {
    return key % 11; //假设为11
}

/*查找元素位置*/
int Find(HashTable h, ElementType key)
{
    int current_pos, new_pos;
    int collision_num = 0; //记录冲突次数

    new_pos = current_pos = Hash(key, h->tablesize); //初始散列位置

    //当该位置元素为非空并且不是要找的元素的时候，发生冲突
    while (h->cells[new_pos].state != Empty && h->cells[new_pos].data != key) {
        collision_num++;
        if (collision_num % 2){ //处理奇数冲突
            new_pos = current_pos + (collision_num + 1) * (collision_num + 1) / 4;
            if (new_pos >= h->tablesize) new_pos = new_pos % h->tablesize;
        }
        else{ //处理偶数冲突
            new_pos = current_pos - (collision_num) * (collision_num) / 4;
            while (new_pos < 0) new_pos += h->tablesize; //调整到合适大小
        }
    }
    return new_pos;
}


/*插入新的元素*/
bool Insert(HashTable h,ElementType key){
    int pos = Find(h,key);  //先查找key是否存在
    if(h->cells[pos].state != Legitimate) {
        h->cells[pos].state = Legitimate;
        h->cells[pos].data = key;
        return true;
    }
    else {
        cout << "键值已存在！"<<endl;
        return false;
    }
}

/*

int main(int argc, char const *argv[]){
    int a[] = {47,7,29,11,9,84,54,20,30};
    int n = 9;
    HashTable h = CreateTable(n);
    for(int i = 0;i < n;i++)
    {
        Insert(h,a[i]);  //插入元素
    }
    for(int i = 0;i < h->tablesize;i++)
    {
        cout << h->cells[i].data << " ";  //打印哈希表元素
    }
    cout << endl;
    return 0;
}

*/