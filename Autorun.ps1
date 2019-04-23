<#
    List/add/remove autorun entries in start menu or registry for user running script or all users

    Guy Leech, 2016
#>

<#
.SYNOPSIS

List/add/remove autorun entries, so items run at logon, in start menu or registry for user running the script or all users.

.DESCRIPTION

Can remove named entries or search entries for a string such as the executable name.
You will be prompted before anything is removed unless you specify -confirm:$false on the command line.

.PARAMETER allusers

By default the script operates on the invoking user's start menu or HKCU. Using this option changes the behaviour to operate on the all users start menu and HKLM.
To remove entries the script must be run with adequate rights.

.PARAMETER registry

By default the script operates on the start menu. Using this option changes the behaviour to operate on HKCU or HKLM depdending if the -allusers options is specified too.

.PARAMETER wow6432node

When in registry mode on 64 bit system, operate on the 32 bit entries instead of the 64 bit ones.

.PARAMETER run

The command line to run including any parameters. If there are spaces in the command then encase in double quote characters

.PARAMETER name

The name of the registry value or shortcut to be operated on.

.PARAMETER remove

Remove the entries that match the -name or -run options specified.

.PARAMETER list

Show the autoruns entries in the file system or registry. Use with -name to show a specific one or with -run to match some or all of a command line.

.PARAMETER verify

Verify the executable exists when creating a new entry and error if it does not.

.PARAMETER icon

Optional icon file and offset to be used when creating a shortcut, e.g. c:\windows\system32\shell32.dll,10

.PARAMETER description

Optional description/comment to be used when creating a shortcut

.EXAMPLE

& "C:\Scripts\Autorun.ps1" -list -registry -allusers -run evernote

Show all autorun entries in the registry for all users that contain the string "evernote"

.EXAMPLE

& "C:\Scripts\Autorun.ps1" -name "Edit Hosts File" -run "notepad.exe c:\windows\system32\drivers\etc\hosts" -description "Look at the hosts files"

Add a shortcut for the user called "Edit Hosts File" which will run the given command line

.EXAMPLE

& "C:\Scripts\Autorun.ps1" -name "Edit Hosts File" -remove

Remove the shortcut for the user called "Edit Hosts File" 

.NOTES

Will work when start menus are redirected.

#>

[CmdletBinding(SupportsShouldProcess=$True,ConfirmImpact='High')]

Param
(
    [switch]$allusers ,
    [switch]$registry ,
    [switch]$wow6432node ,
    [string]$run ,
    [switch]$remove ,
    [switch]$list ,
    [string]$name ,
    [string]$icon ,
    [string]$description ,
    [switch]$verify
)

[int]$count = 0

if( $registry )
{
    $regKey = '\Microsoft\Windows\CurrentVersion\Run'
    if( $wow6432node )
    {
        $regKey = '\Software\Wow6432Node' + $regkey
    }
    else
    {
        $regKey = '\Software' + $regkey
    }

    if( $allusers )
    {
        $regKey = 'HKLM:' + $regKey
    }
    else
    {
        $regKey = 'HKCU:' + $regKey
    }

    if( $remove -or $list )
    {
        ## if we have the name then remove that value else find values containing the run command
        if( ! [string]::IsNullOrEmpty( $name ) )
        {
            if( $list )
            {
                Write-Host "$regKey : $name"
            }
            elseif( $pscmdlet.ShouldProcess( "Key `"$regKey`"" , "Remove `"$name`"" ) )
            {
                Remove-ItemProperty -Path $regKey -Name $name
                if( $? )
                {
                    $count++
                }
            }
        }
        elseif( $list -or ! [string]::IsNullOrEmpty( $run ) ) ## no name so search for command
        {
            Get-Item -Path $regKey | Select-Object -ExpandProperty property | %{ 
                [string]$value = (Get-ItemProperty -Path $regKey -Name $_).$_
                if( $value -match $run )
                {
                    if( $list )
                    {
                        Write-Host "$regKey : $_ : $value"
                    }
                    elseif( $pscmdlet.ShouldProcess( "Value `"$_`"" , "Remove `"$value`"" ) )
                    {
                        Remove-ItemProperty -Path $regKey -Name $_
                        if( $? )
                        {
                            $count++
                        }
                    } 
                }
            }
        }
        else
        {
            Write-Error "Must specify -name or -run when removing an entry"
            return
        }
    }
    else ## adding
    {
        if( [string]::IsNullOrEmpty( $name ) )
        {
            Write-Error "Must specify the name of the registry value via the -name option"
            return
        }
        ## See if it exists already
        [string]$existing = (Get-ItemProperty -Path $regKey -Name $name -ErrorAction SilentlyContinue).$name
        [bool]$carryOn = $true
        if( ! [string]::IsNullOrEmpty( $existing ) )
        {
            if( $existing -eq $run -or ! $pscmdlet.ShouldProcess( "Value `"$name`" already exists as `"$existing`"" , "Overwrite" ) )
            {
                $carryOn = $false
            }
        }
        if( $carryOn )
        {
            if( ! $verify -or ( Get-Command $run ) )
            {
                Set-ItemProperty -Path $regKey -Name $name -Value $run
            }
        }
    }
}
else ## file system not registry
{
    if( $allusers )
    {
        $folder = [environment]::GetFolderPath('CommonStartUp') 
    }
    else
    {
        $folder = [environment]::GetFolderPath('StartUp')
    }
    
    $ShellObject = New-Object -ComObject Wscript.Shell

    if( $remove -or $list )
    {
        if( ! [string]::IsNullOrEmpty( $name ) )
        {
            [string]$fullPath = $folder + '\' + $name + '.lnk' 
            if( $pscmdlet.ShouldProcess( $fullPath , "Delete" ) )
            {
                Remove-Item -Path $fullPath -Force
                if( $? )
                {
                    $count++
                }
            }
        }
        elseif( $list -or ! [string]::IsNullOrEmpty( $run ) ) ## no name so search shortcut content
        {
            Get-ChildItem -Path $folder -Include *.lnk -Recurse | %{
                $shortcut = $ShellObject.CreateShortcut($_.FullName)
                [string]$targetPath =  $shortcut.TargetPath 
                if( $targetPath -match $run )
                {
                    if( $list )
                    {
                        Write-Host "$($_.FullName) : $targetPath $($shortcut.Arguments)"
                    }
                    elseif( $pscmdlet.ShouldProcess( "$($_.FullName)" , "Delete" ) )
                    {
                        Remove-Item -Path $_ -Force
                        if( $? )
                        {
                            $count++
                        }
                    }
                }
            }
        }
        else
        {
            Write-Error "Must specify -name or -run when removing an entry"
        }
    }
    else ## add
    {
        if( [string]::IsNullOrEmpty( $name ) )
        {
            Write-Error "Must specify the name of the shortcut via the -name option"
            return
        }
        [string]$fullPath = $folder + '\' + $name + '.lnk'
        if( ! ( Test-Path $fullPath ) -or $pscmdlet.ShouldProcess( "`"$fullPath`" already exists" , "Overwrite" ) )
        {           
            ## Shortcut needs exe (TargetPath) separate to the arguments so we must split out
            ## If first character is quote then find matching one else we break on whitespace
            [string]$target = $run
            [string]$arguments = $null
            if( $run.StartsWith( "`"" ) )
            {
                $end = $run.Substring( 1 ).IndexOf("`"")
                $target = $run.Substring( 1 , $end )
                $arguments = $run.Substring($end + 2).TrimStart() ## skip passed " and index is zero based
            }
            elseif( $run.IndexOf( ' ' ) -ge 0 )
            {
                $target = $run.Substring( 0 , $run.IndexOf( ' ' ) )
                $arguments = $run.Substring( $run.IndexOf(' ' ) ).TrimStart()
            }
            [string]$fullPath = $folder + '\' + $name + '.lnk'
            $shortcut = $ShellObject.CreateShortcut($fullPath)
            $shortcut.TargetPath = $target
            if( ! [string]::IsNullOrEmpty( $arguments ) )
            {
                $shortcut.Arguments = $arguments
            }
            if( ! [string]::IsNullOrEmpty( $icon ) )
            {
                $shortcut.IconLocation = $icon
            }
            if( ! [string]::IsNullOrEmpty( $description ) )
            {
                $shortcut.Description = $description
            }
            if( ! $verify -or ( Get-Command $target ) )
            {
                $shortcut.Save()
            }
        }
    }
}

if( $remove -and ! $count )
{
    Write-Warning "Removed no items"
}