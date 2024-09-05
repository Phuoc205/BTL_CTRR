#include "bellman.h"

void copyb(int (&newArr)[20] ,int (&arr)[20] , int n){
    for(int i=0; i<n ; i++){
        newArr[i] = arr[i];
    }
}

void BF( int matran[20][20], int v , char x , int (&current_value)[20] , int (&previous_array)[20] ) {
    int n = int(x) - int('A');
    int save_value[20];
    bool thefirst = true;
    for(int i = 0 ; i < v ; i++){
        if(current_value[i] != -1) {
            thefirst = false;
            break;
        } 
    }
    if(thefirst) current_value[n] = 0;
    else{}
    for(int i = 0 ; i < v ; i++){
        if(current_value[i] == -1) current_value[i] = 99999;
    }

    copyb(save_value,current_value,v);
    // duyệt qua các cạnh trong đồ thị và cập nhật khoảng cách ngắn nhất
    for (int i = 0 ; i < v ; i++) {
        for (int j = 0 ; j < v ; j++) {
            if(matran[i][j] != 0) {
                if(current_value[j] > matran[i][j] + save_value[i]) {
                    current_value[j] = matran[i][j] + save_value[i];
                    previous_array[j] = i;
                }
            }
        }
    }
    for(int i = 0 ; i < v ; i++){
        if(current_value[i] == 99999) current_value[i] = -1;
    }
}

string BF_Path(int matran[20][20], int v , char init , char end) {
    int n = int(init) - int('A');
    int m = int(end) - int('A');
    int current_value[20];
    int previou_arrray[20];
    
    for(int i = 0 ; i < v ; i++){
        current_value[i] = -1;
        previou_arrray[i] = -1;
    }
    
    current_value[n] = 0;
    vector<int> chuoi;
    
    for (int i = 0 ; i < v ; i++) {
        BF( matran , v , init , current_value , previou_arrray);
    }

    bool notpath = false;
    int x = m;
    while(x != n){
        if(x==-1) {
            notpath = true;
            break;
        }
        chuoi.push_back(x);
        x = previou_arrray[x];
    }

    chuoi.push_back(n);
    int * arr = new int[v];
    int count = 0 ;
    while(chuoi.size() != 0){
        arr[count] = chuoi.back();
        chuoi.pop_back();
        count++;
    }

    string s = "";

    for(int i = 0 ; i < count ; i++){
        if(i != count - 1){
            char x = 'A' + arr[i];
            s = s + x + " ";
        } else {
            char x = 'A' + arr[i];
            s = s + x ;
        }
    }
    if(notpath) s = "";
    return s;
}