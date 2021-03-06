#SingleInstance Force
#NoTrayIcon
SetTitleMatchMode Regex
DetectHiddenWindows On

IniRead, OutputVar, Hotkeys.ini, Variables, Key
IniRead, OutputVar2, Hotkeys.ini, Variables, Key2
IniRead, OutputVar3, Hotkeys.ini, Variables, Key3
IniRead, RainmeterPath, Hotkeys.ini, Variables, RMPATH
IniRead, Media, ..\Vars.inc, Variables, Media
; IniRead, OverrideNativeKeyFunction, ..\Vars.inc, Variables, OverrideNativeKeyFunction
IniRead, MediaKeys, ..\Vars.inc, Variables, MediaKeys
IniRead, OptionalKey, ..\Vars.inc, Variables, OptionalKey
IniRead, BrightnessKeys, ..\Vars.inc, Variables, BrightnessKeys
IniRead, SmartVolume, ..\Vars.inc, Variables, SmartVolume

Name = ValliStart.ahk

DetectHiddenWindows On
SetTitleMatchMode RegEx
IfWinExist, i)%Name%.* ahk_class AutoHotkey
{
    ValliScriptPath = % RegExReplace(a_scriptdir,"YourFlyouts.*\\?$")"Vallistart\@Resources\Actions\Source code\Vallistart.ahk"
    ValliAhkPath = % RegExReplace(a_scriptdir,"YourFlyouts.*\\?$")"Vallistart\@Resources\Actions\"
    Run, %ValliAhkPath%AHKv1.exe `"%ValliScriptPath%`", %ValliAhkPath%
}

if (Media = 1) and (MediaKeys = 1)
{
    ; if (OverrideNativeKeyFunction = 1)
    ; {
        Hotkey Media_Play_Pause, actionPause
        Hotkey Media_Next, actionNext
        Hotkey Media_Prev, actionPrev
    ; }
    ; else
    ; {
    ;     Hotkey ~Media_Play_Pause, actionPause
    ;     Hotkey ~Media_Next, actionNext
    ;     Hotkey ~Media_Prev, actionPrev
    ; }
}
if (OptionalKey = 1)
{
    Hotkey,%OutputVar%,Button
}
if (SmartVolume = 1)
{
    Hotkey +Volume_Up, MediaUp
    Hotkey +Volume_Down, MediaDown
}

if (BrightnessKeys = 1)
{ 
    Hotkey,%OutputVar2%, BrightDown
    Hotkey,%OutputVar3%, BrightUp
}
Return

Volume_Up::Run "%RainmeterPath% "!CommandMeasure "Func" "actionLoad('up'`, 'vol')" "YourFlyouts\Main" "
Volume_Down::Run "%RainmeterPath% "!CommandMeasure "Func" "actionLoad('down'`, 'vol')" "YourFlyouts\Main" "
Volume_Mute::Run "%RainmeterPath% "!CommandMeasure "Func" "actionLoad('mute'`, 'vol')" "YourFlyouts\Main" "

Button:
    Run "%RainmeterPath% "!CommandMeasure "Func" "actionLoad()" "YourFlyouts\Main" "
Return

BrightUp:
    Run "%RainmeterPath% "!CommandMeasure "Func" "actionLoad('up'`, 'bright')" "YourFlyouts\Main" "
Return

BrightDown:
    Run "%RainmeterPath% "!CommandMeasure "Func" "actionLoad('down'`, 'bright')" "YourFlyouts\Main" "
Return

actionPause:
    Run "%RainmeterPath% "!CommandMeasure "Func" "actionLoad('pause')" "YourFlyouts\Main" "
Return

actionNext:
    Run "%RainmeterPath% "!CommandMeasure "Func" "actionLoad('next')" "YourFlyouts\Main" "
Return

actionPrev:
    Run "%RainmeterPath% "!CommandMeasure "Func" "actionLoad('prev')" "YourFlyouts\Main" "
Return

MediaUp:
    Run "%RainmeterPath% "!CommandMeasure "Func" "mediaVol('up')" "YourFlyouts\Main" "
Return

MediaDown:
    Run "%RainmeterPath% "!CommandMeasure "Func" "mediaVol('down')" "YourFlyouts\Main" "
Return
