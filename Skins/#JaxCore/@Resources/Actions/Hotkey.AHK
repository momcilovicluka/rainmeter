#SingleInstance, Force
#NoTrayIcon
SetWorkingDir, %A_ScriptDir%

IniRead, RainmeterPath, AHKCacheVariables.inc, Variables, RMPATH
IniRead, CurrentKey, AHKCacheVariables.inc, Variables, CurrentKey
IniRead, UsedWinBool, AHKCacheVariables.inc, Variables, WinBool
IniRead, UsedRepHotkey, AHKCacheVariables.inc, Variables, RepHotkey
IniRead, Config, AHKCacheVariables.inc, Variables, Config

Menu, tray, Icon , Logo.ico, 1, 1
Gui, New, -MinimizeBox +AlwaysOnTop -SysMenu, JaxCore Hotkey
Gui, Add, Text, +Wrap, Please press your hotkey combination.
Gui, Add, Hotkey, vChosenHotkey, %CurrentKey%
Gui, Add, Text, w150 h0 0x10  ;Horizontal Line > Etched Gray
Gui, Add, Text, +Wrap w400, If your hotkey is unsupported, please select a hotkey below to REPLACE the HOTKEY (not modifiers) above.
Gui, Add, Radio, vRepHotkey, Do not replace
Gui, Add, Radio, , Space
Gui, Add, Radio, , Enter
Gui, Add, Radio, , Tab
Gui, Add, Radio, , BackSpace
Gui, Add, Radio, , Delete
Gui, Add, Text, w150 h0 0x10  ;Horizontal Line > Etched Gray
Gui, Add, Text, +Wrap, Additional modifiers to add to the above hotkey
Gui, Add, CheckBox, vWinBool, Windows / Meta key
Gui, Add, Text, w150 h0 0x10  ;Horizontal Line > Etched Gray
if (UsedWinBool == 1) {
    guicontrol, , WinBool, 1
}
guicontrol,, %UsedRepHotkey%, 1
Gui, Add, Button, Default w80 gsub1, Confirm
Gui, Show, w400
return

sub1:
    {
        Gui, Submit, NoHide
        Run "%RainmeterPath%" [!CommandMeasure mSet Set('%ChosenHotkey%'`,%WinBool%`,%RepHotkey%) %Config%]
        ExitApp
    }
return

Esc::
    {
        Run "%RainmeterPath%" [!CommandMeasure mSet Set() %Config%]
        ExitApp
    }
return