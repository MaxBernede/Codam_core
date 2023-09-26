
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* fonction qui ajoute n zeros en début de nombre (le coiffeur)*/
void zeros(char nombre[],int n)
{
  int i=0;
  int len=(int)strlen(nombre);
  char c[len+n];
  char d[n];
  char temp[1];
  while (i<n)
    {
      c[i]='0';
      d[i]='0';
      i=i+1;
    }
  i=0;
  strcat(c,nombre);
  strcat(nombre,d);
  strcpy(nombre,c);
  printf("zeros : arg :%s \n",nombre);
}

int main(int argc, char **argv)
{
  char *a = argv[1] ; /* Nombres pour tester*/
  char *b = argv[2];
  int itemp =0;
  int retenue=0;
  int tempa,tempb,lena,lenb;
  lena =(int)strlen(a);        /*Longueurs des deux nombres*/
  lenb=(int)strlen(b);
  if (lena >lenb)    /*On égalise les longueurs (comme chez le coiffeur)*/
    {
      zeros(b,lena-lenb); 
    }  
  else
    {
      zeros(a,lenb-lena);
    }
  char result[strlen(b)]; 
  int i=(int)strlen(b)-1; /* Initialisation de i*/
  printf("longueur : %d \n",i);
  while (i>=0)
    {
      tempa=a[i]-'0';            /* On lit le ieme chiffre*/
      printf("lecutre a : %d\n",tempa);
      tempb=b[i]-'0';
      printf("lecutre  b: %d\n",tempb);
      itemp=tempa+tempb+retenue; /*chiffre de a + chiffre de b +retenue*/
      if (itemp>9)
    {
      retenue=1;
      itemp=itemp-10;
      printf("chiffre[%d] %d \n",i+1,itemp);
      result[i+1]=itemp+'0';
    }
      else
    {
      retenue=0;
      result[i+1]=itemp+'0';
      printf("chiffre[%d] :  %d \n",i+1,itemp);   
    }

      i=i-1;
    }

  /* Si la retenue n'est pas nulle après la boucle*/
  if (retenue!=0)
    {
      result[0]='1';
      printf("chiffre[0] = 1\n");
    }
  else
    {
      result[0]='0';
  }
  result[strlen(result)]='\0';
  printf("%s \n",result);
}