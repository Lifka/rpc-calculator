struct result{
	double result_value;
	int code;
};

program CALCULADORA {
	version CALCULADORA_1 {
		result suma(double v1, double v2) = 1;
		result multiplica(double v1, double v2) = 2;
		result divide(double v1, double v2) = 3;
		result restar(double v1, double v2) = 4;
	} = 1;
} = 0x20000156;