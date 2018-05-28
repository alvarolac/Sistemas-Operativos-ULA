struct terminos 
{
  float t1; 
  float t2; 
};

struct t_potencia 
{
  float t1; 
  int exp; 
};

program PROGRAMA_CALCULADORA { 
    version VERSION_CALCULADORA { 
        float suma(terminos) = 1;
        float resta(terminos) = 2; 
        float prod(terminos) = 3;
        float div(terminos) = 4;
        float pot(t_potencia) = 5;        
    } = 1; 
} = 0x12345671;
