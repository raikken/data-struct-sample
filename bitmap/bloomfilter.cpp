/**
* @file: bloomfilter.cpp
* @author: xxx
* @mail: xxx@yyy.com
* @date 2021-02-13 22:51:17
* @brief
**/
#include<iostream>
#include<string.h>
using namespace std;

class BitMap{
public:
    BitMap(){
        bitmap = NULL;
        size = 0;
    }
    BitMap(int size){
        bitmap = NULL;
        bitmap = new char[size];
        if (bitmap == NULL) {
            printf("ErroR In BitMap Constractor!\n");
        }else{
            memset(bitmap, 0x0, size * sizeof(char));
            this->size = size;
        }
    }

    int initBitMap(int size){
        bitmap = NULL;
        bitmap = new char[size];
        if (bitmap == NULL) {
            printf("ErroR In BitMap Constractor!\n");
            return 0;
        }else{
            memset(bitmap, 0x0, size * sizeof(char));
            this->size = size;
            return this->size;
        }
    }


    /*
     * set the index bit to 1;
     */
    int bitmapSet(int index){
        int addr = index/8;
        int addroffset = index%8;
        unsigned char temp = 0x1 << addroffset;
        if (addr > (size+1)) {
            return 0;
        }else{
            bitmap[addr] |= temp;
            return 1;
        }
    }

    /*
     * return if the index in bitmap is 1;
     */
    int bitmapGet(int index){
        int addr = index/8;
        int addroffset = index%8;
        unsigned char temp = 0x1 << addroffset;
        if (addr > (size + 1)) {
            return 0;
        }else{
            return (bitmap[addr] & temp) > 0 ? 1 : 0;
        }
    }

    /*
     * del the index from 1 to 0
     */
    int bitmapDel(int index){
        if (bitmapGet(index) == 0) {
            return 0;
        }
        int addr = index/8;
        int addroffset = index%8;
        unsigned char temp = 0x1 << addroffset;
        if (addr > (size + 1)) {
            return 0;
        }else{
            bitmap[addr] ^= temp;
            return 1;
        }
    }

private:
    char *bitmap;
    int size;
};

template <typename Type>
class BloomFilter{
public:
    BloomFilter();
    BloomFilter(int length){
        bitmap.initBitMap(length);
        this->length = length;
    }
    bool Add(const Type &T);
    bool Contains(const Type &T);
    int HasH(const Type &T);
    int SecondHasH(const Type &T);
private:
    BitMap bitmap;
    int length;
};

template <typename Type>
int BloomFilter<Type>::HasH(const Type &T){
    int temp = (int) T;
    return temp%length;
}

template <typename Type>
int BloomFilter<Type>::SecondHasH(const Type &T){
    int temp = (int) T;
    return temp%9973;
    //这里直接选了一个大素数 请各位自己优化自己的 HasH函数
    //不然会出现频繁的哈希冲突，并且把布隆过滤器的大小尽量放大一点几百万都可以
}

template <typename Type>
bool BloomFilter<Type>::Add(const Type &T){
    int first = HasH(T);
    int second = SecondHasH(first);
    if (bitmap.bitmapSet(first) && bitmap.bitmapSet(second)) {
        return true;
    }else{
        return false;
    }

}

template <typename Type>
bool BloomFilter<Type>::Contains(const Type &T){
    int first = HasH(T);
    int second =  SecondHasH(T);
    if (bitmap.bitmapGet(first) && bitmap.bitmapGet(second)) {
        return true;
    }else{
        return false;
    }
}



int main(int argc, const char * argv[]) {

    BloomFilter<int> bloom(10);

    bloom.Add(3);
    if (bloom.Contains(3)) {
        printf("true\n");
    }else{
        printf("false\n");
    }

    if (bloom.Contains(2)) {
        printf("true\n");
    }else{
        printf("false\n");
    }

    return 0;
}

