#ifndef MY_FUNC_H   //my_func가 정의되있지 않다면
#define MY_FUNC_H
#include <stdio.h>  //stdio 라이브러리
#include <stdlib.h> //stdlib 라이브러리
#include <string.h> //string 라이브러리
#include "my_struct.h"  //구조체 정보 헤더파일
#include "my_define.h"  //my_define 헤더파일
void Registration(TEL **p, int N);    //연락처 등록 함수
void ShowAll(TEL **p, int N);         //연락처 출력 함수
int Delete(TEL **p, int N);           //연락처 삭제 함수
void FindByBirth(TEL **p, int N);     //같은 생일자 출력 함수
int RegFromFile(TEL **p, int MAXNUM, int N);    //파일 read 함수
void sort(TEL **p, int N);              //연락처 정렬 함수
#endif