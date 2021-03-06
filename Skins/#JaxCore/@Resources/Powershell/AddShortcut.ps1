$DesktopPath = [Environment]::GetFolderPath("Desktop")
$Startpath = $env:APPDATA

# ---------------------------------------------------------------------------- #
#                                   Functions                                  #
# ---------------------------------------------------------------------------- #

function Get-IniContent ($filePath) {
    $ini = [ordered]@{}
    if (![System.IO.File]::Exists($filePath)) {
        throw "$filePath invalid"
    }
    # $section = ';ItIsNotAFuckingSection;'
    # $ini.Add($section, [ordered]@{})

    foreach ($line in [System.IO.File]::ReadLines($filePath)) {
        if ($line -match "^\s*\[(.+?)\]\s*$") {
            $section = $matches[1]
            $secDup = 1
            while ($ini.Keys -contains $section) {
                $section = $section + '||ps' + $secDup
            }
            $ini.Add($section, [ordered]@{})
        }
        elseif ($line -match "^\s*;.*$") {
            $notSectionCount = 0
            while ($ini[$section].Keys -contains ';NotSection' + $notSectionCount) {
                $notSectionCount++
            }
            $ini[$section][';NotSection' + $notSectionCount] = $matches[1]
        }
        elseif ($line -match "^\s*(.+?)\s*=\s*(.+?)$") {
            $key, $value = $matches[1..2]
            $ini[$section][$key] = $value
        }
        else {
            $notSectionCount = 0
            while ($ini[$section].Keys -contains ';NotSection' + $notSectionCount) {
                $notSectionCount++
            }
            $ini[$section][';NotSection' + $notSectionCount] = $line
        }
    }

    return $ini
}

function Set-IniContent($ini, $filePath) {
    $str = @()

    foreach ($section in $ini.GetEnumerator()) {
        if ($section -ne ';ItIsNotAFuckingSection;') {
            $str += "[" + ($section.Key -replace '\|\|ps\d+$', '') + "]"
        }
        foreach ($keyvaluepair in $section.Value.GetEnumerator()) {
            if ($keyvaluepair.Key -match "^;NotSection\d+$") {
                $str += $keyvaluepair.Value
            }
            else {
                $str += $keyvaluepair.Key + "=" + $keyvaluepair.Value
            }
        }
    }

    $finalStr = $str -join [System.Environment]::NewLine

    $finalStr | Out-File -filePath $filePath -Force -Encoding unicode
}

# ---------------------------------------------------------------------------- #
#                                    Actions                                   #
# ---------------------------------------------------------------------------- #

function Check {
    If (Test-Path -Path "$Startpath\Microsoft\Windows\Start Menu\Programs\JaxCore.lnk") {
        $RmAPI.Bang('[!SetOption Section4.Button2.Shape MeterStyle "SectionButton:S | Section4.ButtonProg.True"]')
        $RmAPI.Bang('[!UpdateMeter Section4.Button2.Shape]')
        $RmAPI.Bang('[!Redraw]')
        $RmAPI.Log("Found: CoreHome in programs")
    }
    else {
        $RmAPI.Log("Failed to find corehome in programs")
    }
    If (Test-Path -Path "$DesktopPath\JaxCore.lnk") {
        $RmAPI.Bang('[!SetOption Section4.Button1.Shape MeterStyle "SectionButton:S | Section4.ButtonDesk.True"]')
        $RmAPI.Bang('[!UpdateMeter Section4.Button1.Shape]')
        $RmAPI.Bang('[!Redraw]')
        $RmAPI.Log("Found: CoreHome on desktop")
    }
    else {
        $RmAPI.Log("Failed to find corehome on desktop")
    }
    $Ini = Get-IniContent "$($RmAPI.VariableStr('SETTINGSPATH'))Rainmeter.ini"
    If ($Ini['Rainmeter']['HardwareAcceleration'] -contains '1') {
        $RmAPI.Bang('[!SetVariable HardwareAcceleration 1]')
        $RmAPI.Bang('[!UpdateMeter HardwareAcceleration]')
        $RmAPI.Bang('[!Redraw]')
    }
}

function ToggleHA {
    $Ini = Get-IniContent "$($RmAPI.VariableStr('SETTINGSPATH'))Rainmeter.ini"
    If ($Ini['Rainmeter']['HardwareAcceleration'] -contains '1') {
        $Ini['Rainmeter']['HardwareAcceleration'] = '0'
    }
    else {
        $Ini['Rainmeter']['HardwareAcceleration'] = '1'
    }
    Set-IniContent $Ini "$($RmAPI.VariableStr('SETTINGSPATH'))Rainmeter.ini"
    $RmAPI.Bang("[`"$($RmAPI.VariableStr('@'))Addons\RestartRainmeter.exe`"]")
}

function Desktop {
    $RainmeterExe = $RmAPI.VariableStr('PROGRAMPATH')
    $ResourceFolder = $RmAPI.VariableStr('@')
    & "$($ResourceFolder)Actions\AHKv1.exe" "$($ResourceFolder)Addons\CoreShortcut.ahk" "$DesktopPath\JaxCore.lnk" "$($RainmeterExe)Rainmeter.exe" '!ActivateConfig #JaxCore\Main Home.ini' "$($ResourceFolder)Images\Logo.ico"
}

function StartFolder {
    $RainmeterExe = $RmAPI.VariableStr('PROGRAMPATH')
    $ResourceFolder = $RmAPI.VariableStr('@')
    & "$($ResourceFolder)Actions\AHKv1.exe" "$($ResourceFolder)Addons\CoreShortcut.ahk" "$Startpath\Microsoft\Windows\Start Menu\Programs\JaxCore.lnk" "$($RainmeterExe)Rainmeter.exe" '!ActivateConfig #JaxCore\Main Home.ini' "$($ResourceFolder)Images\Logo.ico"
}

function RemoveDeskop {
    Remove-Item "$DesktopPath\JaxCore.lnk" -Recurse
}

function RemoveStartFolder {
    Remove-Item "$Startpath\Microsoft\Windows\Start Menu\Programs\JaxCore.lnk" -Recurse
}
