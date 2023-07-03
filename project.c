#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>
int generaterandomnumber(int n)
{
    srand(time(NULL));
    return rand() % 3;
}
int greater(char c1, char c2)
{
    // for rock paper scissor-returns 1 if c1>c2 otherwise 0 or c1==c2, returns -1.
    if (c1 == c2)
    {
        return -1;
    }
    else if ((c1 == 'r') && (c2 == 's'))
    {
        return 1;
    }
    else if ((c2 == 'r') && (c1 == 's'))
    {
        return 0;
    }
    else if ((c1 == 'p') && (c2 == 'r'))
    {
        return 1;
    }
    else if ((c2 == 'p') && (c1 == 'r'))
    {
        return 0;
    }
    else if ((c1 == 's') && (c2 == 'p'))
    {
        return 1;
    }
    else if ((c2 == 's') && (c1 == 'p'))
    {
        return 0;
    }
}

int main()
{
    int p1score = 0, compscore = 0;
    char playerchar, compchar;
    int temp;
    char dict[] = {'r', 'p', 's'};
    printf("******Welcome to rock,paper,scissor Game******\n");
    printf("\t\t\tA Player Who Score 5 Point In Game Will Win!!!\n");
    for (int i = 0; i < 5; i++)
    {
        //take players 1 input.
        printf("player\'s turn:-\n");
        printf("choose \'1\' for rock,\'2\' for paper,\'3\' for scissor\n");
        scanf("%d", &temp);
        while(temp > 3)
        {
          printf("you Enter Wrong Please Correct it Below\n");
          scanf("%d",&temp);
        }
        getchar();
        playerchar = dict[temp - 1];
        printf("you choose %c\n", playerchar);

        //generate computers input:-
        printf("computer\'s turn:-\n");
        printf("choose \'1\' for rock,\'2\' for paper,\'3\' for scissor\n");
        temp = generaterandomnumber(3) + 1;
        compchar = dict[temp - 1];
        printf("CPU choose %c\n", compchar);

        //compare this scores.
        if (greater(compchar, playerchar) == 1)
        {
            compscore += 1;
            printf("CPU Got 1 Point!\n");
        }
        else if (greater(compchar, playerchar) == -1)
        {
            compscore += 1;
            p1score += 1;
            printf("Its a Draw!\n");
        }
        else
        {
            p1score += 1;
            printf("You Got 1 Point!\n");
        }
        printf("YOU: %d\nCPU: %d\n", p1score, compscore);
    }

    if (p1score > compscore)
    {
        printf("You Win the Game!!!!\n");
    }
    else if (p1score < compscore)
    {
        printf("CPU win the Game!!!!\n");
    }
    else if (p1score==compscore)
    {
        printf("Match Draw!!!!\n");
    }

    return 0;
}