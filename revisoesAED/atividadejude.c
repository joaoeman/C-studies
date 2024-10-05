#include <stdio.h>
int main ()
{
 int operando1, operando2, operador;
 do
 {
 scanf ("%d %d %d", &operador, &operando1, &operando2);
 switch(operador)
 	{
 	case 1: printf("%d+%d=%d\n",operando1, operando2, operando1+operando2);
 		break;
 	case 2: printf("%d-%d=%d\n",operando1, operando2, operando1-operando2);
 		break;
 	case 3: printf("%d*%d=%d\n",operando1, operando2, operando1*operando2);
 		break;
 	case 4:
 	if (operando2)
 		printf("%d/%d=%d\n",operando1, operando2, operando1/operando2);
 	else
 		printf("Erro! Tentativa de divisao por zero!\n");
 			break;
 	default: 
	 	if(operador > 5)
	 		printf("Erro! Operador invalido!\n");
 		break;
 	}
 	}while (operador!=5);
 	return 0;
}
