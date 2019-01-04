#include <stdio.h>
#include <conio.h>
#include <string.h>
#include <Windows.h>
#define n 6
int MinYear, i;
struct stu {char FIO [20]; char Place [20]; int Year; char Fac [20];} s; // Объявление структуры s
struct stu uni[n]; //Объявление массива структур uni[n]
main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	printf ("Введите информацию о студентах \n");
	for (i=0; i<n; i++){
		printf ("Фамилия студента, место рождения, год рождения, факультет \n");
		scanf("%s%s%d%s", s.FIO, &s.Place, &s.Year, &s.Fac); //Заполнение информацие структуры s
		uni[i]=s;
		}
	MinYear = uni[0].Year;
	for (i=0; i<n; i++)
		if (uni[i].Year < MinYear) MinYear = uni[i].Year; //Находим минимальное значсение s.Year
	for (i=0; i<n; i++)
		if (uni[i].Year == MinYear) printf ("%s %s %d %s \n", uni[i].FIO, uni[i].Place, uni[i].Year, uni[i].Fac);
	
getch();
}
				
	
	
	

