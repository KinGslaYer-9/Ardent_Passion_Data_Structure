#include <stdio.h>
#include <stdlib.h>
#include "ArrayList.h"
#include "NameCard.h"

int main(void)
{
	List list;
	NameCard* pcard;

	ListInit(&list);

	pcard = MakeNameCard("kim", "010-1111-2222");
	LInsert(&list, pcard);

	pcard = MakeNameCard("lee", "010-3333-4444");
	LInsert(&list, pcard);

	pcard = MakeNameCard("park", "010-5555-6666");
	LInsert(&list, pcard);

	// 특정 이름을 대상으로 탐색을 진행하여, 그 사람의 정보를 출력한다.
	if (LFirst(&list, &pcard))
	{
		if (NameCompare(pcard, "lee") == 0)
			ShowNameCardInfo(pcard);
		else
		{
			while (LNext(&list, &pcard))
			{
				if (NameCompare(pcard, "lee") == 0)
					ShowNameCardInfo(pcard);
			}
		}
	}
	
	// 특정 이름을 대상으로 탐색을 진행하여, 그 사람의 전화번호를 변경한다.
	if (LFirst(&list, &pcard))
	{
		if (NameCompare(pcard, "park") == 0)
			ChangePhoneNum(pcard, "010-8888-9999");
		else
		{
			while (LNext(&list, &pcard))
			{
				if (NameCompare(pcard, "park") == 0)
					ChangePhoneNum(pcard, "010-8888-9999");
			}
		}
	}

	// 특정 이름을 대상으로 탐색을 진행하여, 그 사람의 정보를 삭제한다.
	if (LFirst(&list, &pcard))
	{
		if (NameCompare(pcard, "lee") == 0)
		{
			pcard = LRemove(&list);
			free(pcard);
		}
		else
		{
			while (LNext(&list, &pcard))
			{
				if (NameCompare(pcard, "lee") == 0)
				{
					pcard = LRemove(&list);
					free(pcard);
				}
			}
		}
	}

	printf("현재 데이터의 수: %d \n", LCount(&list));
	if (LFirst(&list, &pcard))
	{
		ShowNameCardInfo(pcard);

		while (LNext(&list, &pcard))
			ShowNameCardInfo(pcard);
	}
	return 0;
}