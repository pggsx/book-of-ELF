/***
CS361
PA5 - e-build
Authors: Cole Bradley, Pavan Gudimetta
***/

void err_sys(const char* x) ;
void err_quit(const char* x)  ;
int clientUDPsock(const char *host, const char *service ) ;
int serverUDPsock(const unsigned short port) ;
typedef struct sockaddr SA ;

// Message struct
typedef struct {
	int be_active;
	int msg_type;
	int line_num;
	int capacity;
	int duration;
} msgBuf;

#define BASEPORT 50000   /* port base for non-root servers */
