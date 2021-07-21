#include <stdio.h>

#include <stdlib.h>

#include <time.h>

#ifdef __ANDROID__
 #include <conio.h>
#endif
int main(int narg, char *argv[]) {

  int n; //qty of prime numbers
  int i; //index of prime numbers vector
  int num; //may be a prime number
  int it; //iterator - for
  char answer;
  int ic; // Special increment. Avoid multiples of 3 and 2.
  int primo;

  /*let's measure run time!*/
  //clock_t t0, tf;
  double tempo_gasto;
  long int *time;
  /*.......................*/

  int * p; //vector of prime numbers


double tempo;
FILE *f;
char url[] = "Nprimos_time.txt";


  printf("\n--Gerador de Numeros Primos--\n");

   while (answer != 'e' && answer != 'E'){

f = fopen(url, "w");
if (f == NULL)
		printf("Erro, nao foi possivel abrir o arquivo\n");

    i = 3;
    num = 7;
    ic = -1;
    //it = 1;

    //printf("%d", it);
    printf("\nDigite um inteiro maior que ZERO: ");
    scanf("%d", & n);

    time = malloc(n * sizeof(long int));
    long int t0 = clock(); // marking the start time

        if (n > 0) {
      p = malloc(n * sizeof(int)); // malloc allows to allocate millions of positions


      p[0] = 2; //first prime number
      time[0] = clock();
      p[1] = 3; //second prime number
      time[1] = clock();
      p[2] = 5;
      time[2] = clock();
      do {

        it = 1;
        do {
          it++;
          primo = p[it]; // p[2] === 5, p[3] == 7, p[4] == 11, ...

          if(!(num % primo)) { //se é divisivel por algum primo
            ic *= -1;
            num += (3 + ic); // Avoid the divisibility test by 3 or 2.
            it = 1; 
            continue;
          }

        } while ( !(primo > num/primo) );


        p[i] = num;
        time[i] = clock();

        ic *= -1;
        num += (3 + ic);
      

        // printf("%dth prime number: %d\n", i, p[i-1]);
        i++; // ->"time[i+1]""
      } while (i < n);

      //long int tf = clock();
      
      printf("\n%dth prime number: %d \n", n, p[n - 1]);
	
      tempo_gasto = ((double)(time[i-1] - t0)) / CLOCKS_PER_SEC; // converting the unit of measurement and calculating
      printf("Tempo gasto: %lf s\n", tempo_gasto);

      // Salvando dados de tempo no arquivo


      int resolucaoX = 1366;
      int step = (n/(13*resolucaoX) )+1;
      //step = 1;
      for(i = 0; i < n; i+=step){
      fprintf(f, "%d\t%lf\n" , i+1,  ((double)(time[i] - t0)) / CLOCKS_PER_SEC);
      }
      fclose(f);
      printf("---------------------------------------");	
      printf("\nArquivo para plotagem salvo: %s", url);
      free(time);

      do {
        printf("\n\nExibir numeros primos encontrados? (S/N) (x = restart) (e = exit)\n");
        scanf(" %c", & answer);
        if (answer == 'x' || answer == 'X') {
          answer = 'k';

          #ifdef _WIN32
          system("cls");
          #elif __ANDROID__
          clrscr();
          #else
          system("clear");
          #endif // _WIN32

          printf("\n--Gerador de Numeros Primos--\n");
        } else
        if (answer == 'S' || answer == 's') {
          for (it = 0; it < n; it++)
            printf("%dth prime number: %d \n", it + 1, p[it]);
          answer = 'k';
        } else if (answer == 'N' || answer == 'n') {
          answer = 'k';
        } 
      } while (answer != 'k' && answer != 'e' && answer != 'E');
    } //<--end if n >0
    free(p);
  }

  //FIM
  return EXIT_SUCCESS;
}
