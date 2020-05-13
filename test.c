#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int* save_the_princess(char** mapa, int n, int m, int t, int* dlzka_cesty);

 /*
  * Main function like the one that was in the aid material for this homework
  * We can get the path from two maps. 1st map and option is to read a map from an external test.txt file,
  * 2nd map and option is to read the already predefined map from the code(if this is the option we need to change n,m,t variables to corespond to the map). 
  */
int main()
{
    char **mapa;
    int i, test, journey_length, time;
    int* road;
    int n = 0, m = 0, t = 0;
    FILE *f;
    while (1)
    {
        printf("Enter the test number (0 end the program):\n");
        printf("Press 1 if you want to read map from the text file, press 2 if you want to read predifined map from code.\n");
        scanf("%d", &test);
        journey_length = 0;
        n = m = t = 0;
        switch (test)
        {
        case 0: //end the program
            return 0;
        case 1: //loading map from file
            f = fopen("test.txt", "r");
            if (f)
                fscanf(f, "%d %d %d", &n, &m, &t);
            else
                continue;
            mapa = (char **)malloc(n * sizeof(char *));
            for (i = 0; i < n; i++)
            {
                mapa[i] = (char *)malloc(m * sizeof(char));
                for (int j = 0; j < m; j++)
                {
                    char box = fgetc(f);
                    if (box == '\n')
                        box = fgetc(f);
                    mapa[i][j] = box;
                }
            }
            fclose(f);
            road = save_the_princess(mapa, n, m, t, &journey_length);
            break;
        case 2: //loading a predefined map
            n = 10;
            m = 10;
            t = 12; 
            
            mapa = (char **)malloc(n * sizeof(char *));
            
            mapa[0] = "CCHCNHCCHN";
            mapa[1] = "NNCCCHHCCC";
            mapa[2] = "DNCCNNHHHC";
            mapa[3] = "CHHHCCCCCC";
            mapa[4] = "CCCCCNHHHH";
            mapa[5] = "PCHCCCNNNN";
            mapa[6] = "NNNNNHCCCC";
            mapa[7] = "CCCCCPCCCC";
            mapa[8] = "CCCNNHHHHH";
            mapa[9] = "HHHPCCCCCC";
            road = save_the_princess(mapa, n, m, t, &journey_length);
            break;
        
        default:
            continue;
        }
        time = 0;
        if(road == NULL)
            continue;
        printf("\n\nCoordinates for the map\n\n");    
        for (i = 0; i < journey_length; i++)
        {
        	//printf("%d %d, timestamp:%d\n", road[i * 2], road[i * 2 + 1],time); //if we want to see timestamp
            printf("%d %d\n", road[i * 2], road[i * 2 + 1]);
            if (mapa[road[i * 2 + 1]][road[i * 2]] == 'H')
                time += 2; //if we are crossing throug the bush
            else
                time += 1; //if we are crossing through the normal path
            if (mapa[road[i * 2 + 1]][road[i * 2]] == 'D' && time > t)
                printf("You didn't have time to kill the dragon!\n");
            if (mapa[road[i * 2 + 1]][road[i * 2]] == 'N')
                printf("Crossing an impassable obstacle!\n");
            if (i > 0 && abs(road[i * 2 + 1] - road[(i - 1) * 2 + 1]) + abs(road[i * 2] - road[(i - 1) * 2]) > 1)
                printf("Invalid knight turn!\n");
        }
        printf("TIME-> %d\n", time);
        free(road);
        for (i = 0; i < n; i++)
        {
            //free(mapa[i]);
        }
        free(mapa);
    }
    return 0;
}
