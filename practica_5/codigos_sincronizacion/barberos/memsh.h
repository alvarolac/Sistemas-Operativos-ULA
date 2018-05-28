#define ID 999
#define ROUTE "/bin/lspci"
#define SEM_ID 0x10000027

typedef struct
{
  pid_t pid;
  int mensaje;
}inf_p;

typedef struct{
  pid_t pid_mon;
	inf_p array_p;
}shmem_data;
