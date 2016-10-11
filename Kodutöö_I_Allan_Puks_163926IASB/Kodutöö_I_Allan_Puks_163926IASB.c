/**
 * File: Kodutoo_I_Allan_Puks_163926IASB.c
 * Author: Allan Puks
 * Created: 02OCT16
 * Last edit: 10OCT16
 *
 * Description: Arvutab funktsiooni väärtused kasutaja poolt antud
 * 				parameetritega määratud punktides.
 *
 */

#include <stdio.h>
#include <math.h>

#define MAXSTEPS 15

int main(void)
{
	double step;
	double table[MAXSTEPS][4];
	int i, steps, start, stop;


	//Võta kasutajalt algandmed
	i=1;
	printf("See programm arvutab funktsiooni f(x)=ln(x+5)/sqrt(7+5x+x^2)\n");
	printf("v22rtused kuni %d punktis.\n", MAXSTEPS);
	while(i)
	{

		printf("Sisestage algv22rtus: \n");
		scanf("%d", &start);
		printf("Sisestage loppv22rtus: \n");
		scanf("%d", &stop);
		if(start >= stop)
		{
			printf("Algv22rtus peab olema v2iksem kui l6ppv22rtus! \n");
		}
		else
		{
			printf("Sisestage sammude arv: \n");
			scanf("%d", &steps);
			if(steps>MAXSTEPS)
			{
				printf("Liiga palju samme, peab olema v2iksem kui %d\n", MAXSTEPS);
			}
			else
			{
				i=0;
			}
		}
	}


	//Arvuta funktsiooni väärtus arvutatud kohtadel
	step=(double)(stop-start)/(steps-1);
	for(i=0; i<steps; i++)
	{
		//arvutab x-i väärtuse
		table[i][0]=start + step*i;
		//arvutab ülemise võrrandi
		table[i][2]=table[i][0]+5;
		//arvutab alumise võrrandi
		table[i][3]=7+5*table[i][0]+pow(table[i][0], 2.0);
		//arvutab y-i
		table[i][1]=log(table[i][2])/sqrt(table[i][3]);

	}

	//väljasta tabelina
	printf("f(x)=ln(x+5)/sqrt(7+5x+x^2)\n");
	printf("-------------------\n");
	printf("|   x    |    y   |\n");
	printf("-------------------\n");
	for(i=0;i<steps; i++)
	{
		printf("| ");
		//juhul kui arv on negatiivne lisatühik
		if(table[i][0] >= 0)
		{
			printf(" ");
		}

		//esimene väärtus
		printf("%2.2f", table[i][0]);
		//vahesein
		printf(" | ");
		//Erijuhtude kontroll
		if(table[i][2] < 0 || table[i][3] < 0)
		{
			printf(" Kompl ");
		}
		else if(table[i][2] == 0 || table[i][3] == 0)
		{
			printf(" Puudub");
		}
		else
		{
			//juhul kui arv on negatiivne, lisatühik
			if(table[i][1] >= 0)
			{
				printf(" ");
			}
			printf("%1.4f",table[i][1]);
		}
		printf(" |\n");
	}
	//lõpetab tabeli
	printf("-------------------\n");


	return 0;
}
