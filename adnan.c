#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define NUM 30

struct employee
{
    char id[100];
    char name[100];
    double basic;
    double hrent;
    double medical;
    double total;

} emp[NUM], temp;  //created 30 employee structure

void calcTotal(void)
{
    for(int i=0; i<NUM; i++)
    {
        emp[i].medical= emp[i].basic*0.05;
        if(emp[i].basic<=5000) emp[i].hrent= emp[i].basic*0.6;
        else if(emp[i].basic<=10000) emp[i].hrent= emp[i].basic*0.5;
        else emp[i].hrent= emp[i].basic*0.4;

        emp[i].total = emp[i].basic + emp[i].medical + emp[i].hrent;
    }
}

void sortID(void)
{
    for(int i=1; i<NUM ; i++)
    {
        for(int j=0; j<NUM-i; j++)
        {
            if(strcmp(emp[j].id,emp[j+1].id)>0)
            {
                temp=emp[j];
                emp[j]=emp[j+1];
                emp[j+1]=temp;
            }

        }
    }
}

void sortName(void)
{
    for(int i=1; i<NUM ; i++)
    {
        for(int j=0; j<NUM-i; j++)
        {
            if(strcmp(emp[j].name,emp[j+1].name)>0)
            {
                temp=emp[j];
                emp[j]=emp[j+1];
                emp[j+1]=temp;
            }

        }
    }
}

void sortTotal(void)
{
    for(int i=1; i<NUM ; i++)
    {
        for(int j=0; j<NUM-i; j++)
        {
            if(emp[j].total>emp[j+1].total)
            {
                temp=emp[j];
                emp[j]=emp[j+1];
                emp[j+1]=temp;
            }

        }
    }
}

int average(void)
{
    int sum=0;
    for(int i=0; i<NUM; i++)
        sum+=emp[i].total;
    return sum/NUM;
}

void view(int i)
{
    printf("\tEmployee %d: %s %s %.2lf\n", i+1, emp[i].id, emp[i].name, emp[i].total);
}

int main()
{
    //1
    for(int i=0; i<NUM; i++)
    {
        printf("Input emplyee %d info: ",i+1);
        scanf("%s %s %lf",emp[i].id, emp[i].name, &emp[i].basic);
    }
    //2
    calcTotal();
    printf("Emplyee list:\n");
    for(int i=0; i<NUM; i++)
    {
        view(i);
    }
    //3
    char nameQ[100];
    printf("Search an employee by name:");
    scanf("%s",nameQ);
    for(int i=0; i<NUM; i++)
    {
        if(!strcmp(nameQ,emp[i].name))
        {
            printf("\tFound: ID: %s Name: %s Basic: %.2lf Hrent: %.2lf Med: %.2lf Total: %.2lf\n", emp[i].id, emp[i].name, emp[i].basic, emp[i].hrent, emp[i].medical, emp[i].total);
            break;
        }
        else if(i==NUM-1)
            printf("\tNot found\n");
    }
    //4
    sortID();
    printf("Emplyee list sorted according to id:\n");
    for(int i=0; i<NUM; i++)
    {
        view(i);
    }
    //5
    sortName();
    printf("Emplyee list sorted according to name:\n");
    for(int i=0; i<NUM; i++)
    {
        view(i);
    }
    //6
    sortTotal();
    printf("Emplyee list sorted according to total salary:\n");
    for(int i=0; i<NUM; i++)
    {
        view(i);
    }
    //7
    int averageS= average();
    printf("More than average salary:\n");
    for(int i=0; i<NUM; i++)
    {
        if(emp[i].total>averageS)
            view(i);
    }

}

