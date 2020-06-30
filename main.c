#include  <stdio.h>

int main (void)
{
	int yy, mm, dd;
	int dd1, dd10; //day 일의 자리와 십의 자리 표현
	
	printf("년월일을 차례대로 입력하세요 : ");
	scanf("%d %d %d",&yy, &mm, &dd);

	printf("\nDated this ");

	
    dd1 = dd % 10; dd10 = dd / 10;


	switch (dd1)
	{	
		case 1 : if(dd10 != 1) printf("%dst ",dd);
				 else printf("%dth ",dd); break;

		case 2 : if(dd10 != 1) printf("%dnd ",dd);
			     else printf("%dth ",dd); break;

		case 3 : if(dd10 != 1)printf("%drd ",dd); 
			     else printf("%dth ", dd); break;

		default : printf("%dth ",dd); break;
	}

	printf("day of ");


	switch (mm)
	{
		case 1 : printf("January"); break;
		case 2 : printf("February"); break;
		case 3 : printf("March"); break;
		case 4 : printf("April"); break;
		case 5 : printf("May"); break;
		case 6 : printf("June"); break;
		case 7 : printf("July"); break;
		case 8 : printf("August"); break;
		case 9 : printf("September"); break;
		case 10 : printf("October"); break;
		case 11 : printf("November"); break;
		case 12 : printf("December"); break;
	}

	printf(", %d.\n",yy);

	return 0;
}


















