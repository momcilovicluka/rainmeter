; ---------------------------------------------------------------------------- ;
;                                   Functions                                  ;
; ---------------------------------------------------------------------------- ;
; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;
[Image]
ImageName=Variants\Splash\#Sec.Arg1#.png


[Title]
Meter=String
Text=YourFlyouts - Now Available!
X=(#SEc.W#/2)
StringAlign=Center
MeterStyle=Sec.String:S | Style.Title:S

[Description.1]
Meter=String
Text=YourFlyouts provides multiple replacements for the old, built-in, Metro Design based Audio / Media / Brightness flyouts in Windows which are shown while pressing the media or volume keys.
X=(#SEc.W#/2)
StringAlign=Center
Inlinepattern=volume & media flyouts|flexibility and features|Discord server|development updates
MeterStyle=Sec.String:S | Style.Description:S




[DA:]
Meter=Shape
X=(#Sec.W#/2-(#Sec.BottomWidth#*3+#Sec.P#)/2)
Y=(#Sec.H#-#Sec.P#-#SEc.BottomHeight#)
Colorover=84, 235, 131
Colorleave=399F59
LeftMouseUpAction=["https://www.deviantart.com/jaxoriginals/art/919259685"]
meterStyle=BottomBox:S | FalseStyleDesk
[DA:String]
Meter=String
StringAlign=CenterCenter
Text=DA post
MeterStyle=Sec.String:S | BottomText:S
[Core:]
Meter=Shape
; X=(#Sec.W#/2-(#Sec.BottomWidth#*2+#Sec.P#/2)/2)
; Y=(#Sec.H#-#Sec.P#-#SEc.BottomHeight#)
LeftMouseUpAction=[!WriteKeyvalue Variables Skin.Name """YourFlyouts""" "#@#SecVar.inc"][!WriteKeyvalue Variables Skin.Set_Page "Info" "#@#SecVar.inc"][!ActivateConfig "#JaxCore\Main" "Settings.ini"][!DeactivateConfig]
; LeftMouseUpAction=[!DeactivateConfig]
meterStyle=BottomBox:S | FalseStyleDesk
[Core:String]
Meter=String
StringAlign=CenterCenter
Text=Get it now
MeterStyle=Sec.String:S | BottomText:S
[DiscordServer:]
Meter=Shape
ColorLeave=88, 101, 242,150
ColorOver=88, 101, 242
LeftMouseUpAction=["https://discord.gg/JmgehPSDD6"]
meterStyle=BottomBox:S | FalseStyleDesk
[DiscordServer:String]
Meter=String
StringAlign=CenterCenter
Text=Join the Discord
MeterStyle=Sec.String:S | BottomText:S