#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "NameCard.h"

NameCard* MakeNameCard(char* name, char* phone)
{
	NameCard* newNameCard = (NameCard*)malloc(sizeof(NameCard));
	if (newNameCard != NULL)
	{
		strcpy_s(newNameCard->name, sizeof(newNameCard->name), name);
		strcpy_s(newNameCard->phone, sizeof(newNameCard->phone), phone);
	}
	return newNameCard;
}

void ShowNameCardInfo(NameCard* pcard)
{
	printf("�̸�: %s \n", pcard->name);
	printf("��ȭ��ȣ: %s \n\n", pcard->phone);
}

int NameCompare(NameCard* pcard, char* name)
{
	return strcmp(pcard->name, name);
}

void ChangePhoneNum(NameCard* pcard, char* phone)
{
	strcpy_s(pcard->phone, sizeof(pcard->phone), phone);
}