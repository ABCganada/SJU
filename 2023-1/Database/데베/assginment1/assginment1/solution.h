#ifndef SOLUTION_H
#define SOLUTION_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_FILENAME_LEN 100    // 파일 이름 길이
#define MAX_CONTENT_LEN 1000    // 파일 내용 길이

int Cmd();      // 프로그램 메뉴
void Load(char *fileName);  // 파일 로드
void Print(char *fileName); // 파일 출력
void Update(char* fileName, char* target, char* replace);   // 파일의 키워드 수정
void Delete(char* fileName, char* keword);  // 파일의 키워드 삭제
void Find(char* fileName, char* keyword);    // 파일의 키워드 찾기
int Save(char *fileName, char *newFileName);    // 파일 새로 저장
int fileIsValid(FILE *fp);  //유효성 검사

#endif