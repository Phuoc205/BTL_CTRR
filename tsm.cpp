#include "tsm.h"

int Step[20];
int d;
int result;
bool visited[20];
int saveStep[20];

void copys(int (&newArr)[20] ,int (&arr)[20] , int n){
    for(int i=0; i<n ; i++){
        newArr[i] = arr[i];
    }
}

void Find( int matran[20][20] , int v , int x , int mindis) {
    for(int i = 0 ; i < v ; i++) {
        if(!visited[i] && matran[Step[x-1]][i] != 0) {
            visited[i] = true;
            Step[x] = i;
            d = d + matran[Step[x-1]][Step[x]];
            if(x == v-1 && matran[Step[x]][Step[0]]!=0) {
                result = min(result, d + matran[Step[x]][Step[0]]);
                if(result == d + matran[Step[x]][Step[0]]) copys(saveStep,Step,v);
            }
            else if (d + (v-x) * mindis < result ) {
                Find(matran,v,x+1,mindis);
            }
            visited[i] = false;
            d = d - matran[Step[x-1]][Step[x]];
        }
    }
}

string Traveling(int matran[20][20] , int v , char init) {
    
    int mindis = 999999;
    for (int i = 0 ; i < v ; i++){
        for(int j = 0 ; j < v ; j++){
            if(matran[i][j] !=0 && mindis > matran[i][j]) mindis = matran[i][j];
        }
    }
    fill(visited, visited + v, false);
    fill(Step, Step + v, -1);
    fill(saveStep, saveStep + v, -1);
    d = 0;
    result = 999999;

    Step[0] = init - 'A';
    visited[init - 'A'] = 1;
    Find(matran,v,1,mindis);
    string s = "";

    for(int i = 0 ; i < v ; i++){
        char x = 'A' + saveStep[i];
        s = s + x + " ";
    }
    s = s + init;
    return s;
}

// use for test
int getresult(int matran[20][20] , int v , char init){
    Traveling(matran , v , init);
    return result;
}
