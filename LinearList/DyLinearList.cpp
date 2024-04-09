//
// Created by URARA on 2024/4/9.
//

#include <cstdlib>
#include <iostream>
#include "DyLinearList.h"

using namespace std;

class DyLinearList {
public:
    int *data;
    unsigned int maxSize = 10;
    unsigned int length=0;

    DyLinearList();

    bool ListInsert(int value, unsigned int index) {
        if (index >= maxSize) {
            return false;
        } else {
            if (index == maxSize - 1) {
                this->Expand(5);
                for (int i = length - 1; i > index; i--) {
                    data[i] = data[i - 1];
                }
            }
            data[index] = value;
            length += 1;
            return true;
        }
    }

    int ListDelete(unsigned int index) {
        if (index >= length) {
            return 0;
        }
        int ret = data[index];
        for (; index < length - 1; index++) {
            data[index] = data[index + 1];
        }
        length -= 1;
        return ret;
    }

    void Expand(unsigned int size) {
        int *new_data = (int *) malloc(sizeof(int) * (maxSize + size));
        for (int i = 0; i < length; i++) {
            new_data[i] = data[i];
        }
        free(data);
        data = new_data;
        maxSize += size;
    }

    void LocateElem(unsigned int* arr,int value){
        unsigned index=0;
        for (int i = 0; i < length; i++) {
            if (data[i]==value){
                arr[index]=i;
                index+=1;
            }
        }
    }

    int GetElem(unsigned int index){
        if (index<length){
            return data[index];
        } else{
            return 0;
        }
    }

    void PrintList() {
        for (int i = 0; i < length; ++i) {
            cout << (int) (data[i]) << endl;
        }
    }

    bool Empty() {
        return length == 0;
    }

    unsigned int Length(){
        return length;
    }
};

DyLinearList::DyLinearList() {
    data = (int *) malloc(maxSize * sizeof(int));
}

int main() {
    DyLinearList list = DyLinearList();
    for (int i = 0; i < 100; i++) {
        list.ListInsert(i, i);
    }
    list.ListDelete(10);
    list.ListDelete(10);
    list.ListDelete(10);
    list.ListDelete(10);
    list.PrintList();
    int index=(int)list.GetElem(10);
    cout<<index<<endl;
}
