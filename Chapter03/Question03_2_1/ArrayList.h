#pragma once
#ifndef __ARRAY_LIST_H__
#define __ARRAY_LIST_H__

#include "NameCard.h"

#define TRUE		1		// '참'을 표현하기 위한 매크로 정의
#define FALSE		0		// '거짓'을 표현하기 위한 매크로 정의

#define LIST_LEN	100
typedef NameCard* LData;			// LData에 대한 typedef 선언(다양한 형태를 저장하기 위해, int 부분을 다른 자료형으로 바꾸면 된다.)

typedef struct __ArrayList		// 배열기반 리스트를 정의한 구조체
{
	LData arr[LIST_LEN];		// 리스트의 저장소인 배열
	int numOfData;				// 저장된 데이터의 수
	int curPosition;			// 데이터 참조위치를 기록
} ArrayList;

typedef ArrayList List;		// 사용하는 리스트의 종류를 바꾸기 위해서(main 함수의 변경이 필요 없다.)

void ListInit(List* plist);						// 초기화
void LInsert(List* plist, LData data);			// 데이터 저장

int LFirst(List* plist, LData* pdata);			// 첫 데이터 참조
int LNext(List* plist, LData* pdata);			// 두 번째 이후 데이터 참조

LData LRemove(List* plist);						// 참조한 데이터 삭제
int LCount(List* plist);						// 저장된 데이터의 수 반환

#endif // !__ARRAY_LIST_H__
