/*
		Javier Izquierdo Vera
		javierizquierdovera@gmail.com
		UGR
 */

#include "calculadora.h"
#define RED  "\x1B[31m"
#define GRE  "\x1B[32m"
#define YEL  "\x1B[33m"
#define BLU  "\x1B[34m"
#define RESET "\033[0m"


result* suma_1_svc(double v1, double v2,  struct svc_req *rqstp){
	static result  result;

	result.result_value = v1 + v2;
	result.code = 0;

	printf("%s[*]%s %s%f + %f%s = %s%f%s\n\n", GRE, RESET,
		YEL, v1, v2, RESET, YEL, result.result_value, RESET);

	return &result;
}

result* multiplica_1_svc(double v1, double v2,  struct svc_req *rqstp){
	static result  result;

	result.result_value = v1 * v2;
	result.code = 0;

	printf("%s[*]%s %s%f x %f%s = %s%f%s\n\n", GRE, RESET,
		YEL, v1, v2, RESET, YEL, result.result_value, RESET);

	return &result;
}

result* divide_1_svc(double v1, double v2,  struct svc_req *rqstp){
	static result  result;

	if (v2 == 0){
		result.code = 1;
			printf("%s(!)%s División por cero\n\n", RED,RESET);
	} else {
		result.result_value = v1 / v2;
		result.code = 0;
		printf("%s[*]%s %s%f / %f%s = %s%f%s\n\n", GRE, RESET,
			YEL, v1, v2, RESET, YEL, result.result_value, RESET);
	}

	return &result;
}

result* restar_1_svc(double v1, double v2,  struct svc_req *rqstp){
	static result  result;

	result.result_value = v1 - v2;
	result.code = 0;
	printf("%s[*]%s %s%f - %f%s = %s%f%s\n\n", GRE, RESET,
		YEL, v1, v2, RESET, YEL, result.result_value, RESET);

	return &result;
}
