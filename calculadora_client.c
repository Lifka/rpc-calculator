/*
		Javier Izquierdo Vera
		javierizquierdovera@gmail.com
		UGR
 */

#include "calculadora.h"

#define suma_tipo 0
#define multiplica_tipo 1
#define divide_tipo 2
#define resta_tipo 3
#define RED  "\x1B[31m"
#define GRE  "\x1B[32m"
#define YEL  "\x1B[33m"
#define BLU  "\x1B[34m"
#define RESET "\033[0m"




double calculadora_1(char *host, double v1, double v2, int tipo){
	CLIENT *clnt;
	result  *result_1;

			#ifndef	DEBUG
				clnt = clnt_create (host, CALCULADORA, CALCULADORA_1, "udp");
				if (clnt == NULL) {
					clnt_pcreateerror (host);
					exit (1);
				}
			#endif	/* DEBUG */

	if (tipo == suma_tipo){
		result_1 = suma_1(v1, v2, clnt);
		if (result_1 == (result *) NULL) {
			clnt_perror (clnt, "sumar call failed");
			printf ("%s(!)%s No es posible conectar con el servidor \"%s\"\n",RED,RESET,host);
			exit (1);
		}
	} else if (tipo == multiplica_tipo){
		result_1 = multiplica_1(v1, v2, clnt);
		if (result_1 == (result *) NULL) {
			clnt_perror (clnt, "multiplica call failed");
			printf ("%s(!)%s No es posible conectar con el servidor \"%s\"\n",RED,RESET,host);
			exit (1);
		}
	} else if (tipo == divide_tipo){
		result_1 = divide_1(v1, v2, clnt);
		if (result_1 == (result *) NULL) {
			clnt_perror (clnt, "divide call failed");
			printf ("%s(!)%s No es posible conectar con el servidor \"%s\"\n",RED,RESET,host);
			exit (1);
		}
	} else if (tipo == resta_tipo){
		result_1 = restar_1(v1, v2, clnt);
		if (result_1 == (result *) NULL) {
			clnt_perror (clnt, "restar call failed");
			printf ("%s(!)%s No es posible conectar con el servidor \"%s\"\n",RED,RESET,host);
			exit (1);
		}
	}


		#ifndef	DEBUG
			clnt_destroy (clnt);
		#endif	 /* DEBUG */


	int error = result_1->code;

	if (error > 0){
		printf("%s(!)%s Operación no válida: código de error %d\n",RED,RESET,error);

		if (error == 1){
			printf("%s(!)%s División por cero\n", RED,RESET);
		}

		exit (1);
	}

	return result_1->result_value;
}


int main (int argc, char* argv[]){
	char* host;
	char operador;
	double v1, v2;
	double resultado = 0.0;

	if (argc < 5) {
		printf ("usage: %s <maquina> <entero> <operador> <entero>\n", argv[0]);
		exit (1);
	}
	host = argv[1];
	operador = argv[3][0];
	v1 = atof(argv[2]);
	v2 = atof(argv[4]);


	int tipo;

	if (operador == '+'){
		tipo = suma_tipo;
	} else if(operador == '-'){
		tipo = resta_tipo;
	} else if(operador == 'x'){
		tipo = multiplica_tipo;
	} else if(operador == '/'){
		tipo = divide_tipo;
	} else {
		printf("%s(!)%s Operador no válido\n",RED,RESET);
		exit (1);
	}

	resultado = calculadora_1 (host, v1, v2, tipo);
	printf("El resultado de %s%f %c %f%s es %s%f%s\n\n",
		YEL, v1, operador, v2, RESET, YEL, resultado, RESET);
	exit (0);
}
