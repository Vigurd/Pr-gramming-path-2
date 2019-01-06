#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <stdlib.h>

struct sports {char FIO [20];
			   int numbre;
			   int score;} spr;
			   			   
void InputData(FILE *); //Ввод информации о спротсменах
void UpdateData(FILE *); //Добавление новой информации
void PrintData(FILE *); //Вывод списка спортсменов
void DeleteData(FILE *); //Удаление информации о спортсмене с наименьшм количеством очков

void InputData(FILE *sp) {
	char ch;
	sp=fopen("sport.dat", "wb");
	system("cls");
	printf("\n Ввод информации о спортсменах \n");
	do {
		printf("\n Введите данные спортсмена через пробел - фамилия, номер, количество набраных очков \n");
		scanf("%s%d%d", spr.FIO, &spr.numbre, &spr.score);
		fwrite(&spr, sizeof(spr),1,sp);
		printf("\n  Ввести информацию о следующем спортсмене? y/n \n");
		ch=getch();
	}
	while (ch != 'n');
	fclose(sp);
}

void UpdateData(FILE *sp) {
	char ch;
	sp=fopen("sport.dat", "ab");
	system("cls");
	printf("\n Ввод информации о спортсменах \n");
	do {
		printf("\n Введите данные спортсмена через пробел - фамилия, номер, количество набраных очков \n");
		scanf("%s%d%d", spr.FIO, &spr.numbre, &spr.score);
		fwrite(&spr, sizeof(spr),1,sp);
		printf("\n Ввести информацию о следующем спортсмене? y/n \n");
		ch=getch();
	}
	while(ch != 'n');
	fclose(sp);
}

void PrintData(FILE *sp) {
	int i;
	system("cls");
	sp=fopen("sport.dat","rb");
	i=1;
	fread(&spr,sizeof(spr),1,sp);
	while(!feof(sp)) {
		printf("\n%d. Фамилия спортсмена: %s, номер: %d, количество очков: %d", i, spr.FIO, spr.numbre, spr.score);
		fread(&spr,sizeof(spr),1,sp);
		i++;
	}
}

void DeleteData(FILE *sp) {
	int i, min, n;
	struct sports *p;
	sp=fopen("sport.dat","rb");
	fread(&spr,sizeof(spr),1,sp);
	n=0;
    fseek(sp, 0, 2);
    n=ftell(sp) / sizeof(spr);
    fseek(sp, 0, 0);
    p=(struct sports*)malloc(n*sizeof(spr));
    for (i=0; i<n; ++i){
         fread (&spr, sizeof(spr), 1, sp);
         p[i]=spr;
    }
    fclose(sp);
    sp=fopen("sport.dat", "wb");
    min=0;
    for(i=1; i<n; ++i)
        if(p[i].score<p[min].score) min=i;
    for (i=0; i<n; ++i)
        if(i!=min) fwrite(&p[i], sizeof(spr), 1, sp);
    free (p);
    fclose(sp);
    printf("\n  Данные успешно удалены\n");
     
}


main () {
	char c;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	FILE *sp;
	while(1) {
		puts("\n \n1. Ввести данные о спортсменах.");
		puts("2. Добавить информацию о новом спортсмене");
		puts("3. Вывести информацию о спортсменах");
		puts("4. Удалить информацию о спортсмене с наименьшим количество очков");
		puts("0. Выход");
		c=getch();
		switch(c) {
			case '1':InputData(sp); break;
			case '2':UpdateData(sp); break;
			case '3':PrintData(sp); break;
			case '4':DeleteData(sp); break;
			case '0':return 0;
			default : puts ("Неверный пукт меню");
		}	
	}
}
