#define ID 999
#define ROUTE "/bin/lspci"
#define SEM_ID 0x10101011

typedef struct
{
  pid_t pid;
  long long numero;
  unsigned char termino;
}inf_p;

typedef struct{
  pid_t pid_mon;
	inf_p array_p[10];
}shmem_data;
