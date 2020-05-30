#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

void dateNumberToWords(char* str, FILE* tmp);


int main(void) 
{
	system("chcp 1251");
	char str[50], ftmpname[] = "tmpfile.txt";
	FILE* oldFile, * tmpFile;
	char* foldname = "date.txt";
	oldFile = fopen(foldname, "r");
	if ((tmpFile = fopen(ftmpname, "w")) == NULL)
	{
		printf("TMP file isn`t created!");
		return 1;
	}
	while (fgets(str, 12, oldFile) != NULL)
	{
		printf("%s", str);
		dateNumberToWords(str, tmpFile);
	}
	fclose(oldFile);
	fclose(tmpFile);
	if (remove(foldname) == 0) { /* витираємо початковий файл */
		rename(ftmpname, foldname); /* перейменовуємо створений */
		printf("Файл %s відредаговано.\n", foldname);
	}
	else
		printf("Створено новий файл - %s \n", ftmpname);
}

void dateNumberToWords(char* str, FILE* tmp)
{
	char buf[5];
	char* month[] = { "січня","лютого","березня","квітня","травня","червня","липня","серпня","вересня","жовтня","листопаду","грудня" };
	buf[0] = str[3];
	buf[1] = str[4];
	buf[2] = '\0';
	int monNumb = atoi(buf);
	buf[0] = str[6];
	buf[1] = str[7];
	buf[2] = str[8];
	buf[3] = str[9];
	buf[4] = '\0';
	int year = atoi(buf);

	if (year % 4 != 0 || year % 100 == 0 && year % 400 != 0) 
		fprintf(tmp, "%c%c %s %i р.\n", str[0], str[1], month[monNumb - 1], year);
	else 
		fprintf(tmp, "%c%c %s %i р. - високосний\n", str[0], str[1], month[monNumb - 1], year);
	printf("\n");

	
}