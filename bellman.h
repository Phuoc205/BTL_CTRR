#ifndef _BELLMAN_H_
#define _BELLMAN_H_

#include <bits/stdc++.h>
using namespace std;

void BF( int matran[20][20], int v , char x , int (&current_value)[20] , int (&previou_arrray)[20] );
string BF_Path(int matran[20][20], int v , char init , char end);

#endif //_BELLMAN_H_