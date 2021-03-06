[Variables]
Spotlight=YourFlyouts

; ---------------------------------------------------------------------------- ;
;                                  MeterStyle                                  ;
; ---------------------------------------------------------------------------- ;

[m.Shape:S]
X=(#Set.P#*2)
Y=(#Set.P#*1)R
Shape=Rectangle 0,0,(#Set.W#-#Set.P#*4),(250*[Set.S]),(#Set.R#) | StrokeWidth (2*[Set.S]) | Extend This
DynamicVariables=1
Container=BC
This=Stroke color #Set.Subtext_Color# | Fill Color 0,0,0,1
MouseOverAction=[!SetOption #CURRENTSECTION# This "Stroke color #Set.Subtext_Color# | Fill Color #Set.Sec_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# This "Stroke color #Set.Subtext_Color# | Fill Color 0,0,0,1"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=[!WriteKeyvalue Variables Skin.Name "[&Func:trim('#CURRENTSECTION#','.Shape','')]" "#@#SecVar.inc"][!WriteKeyvalue Variables Skin.Set_Page Info "#@#SecVar.inc"][!ActivateConfig "#CURRENTCONFIG#" "Settings.ini"]
[m.Shape.Highlight_New:S]
Shape2=Rectangle ((#Set.W#-#Set.P#*4)/2),0,(100*[Set.S]),(35*[Set.S]),(#Set.R#/2) | StrokeWidth 0 | OffSet (-100/2*[Set.S]),(-35/2*[Set.S]) | Fill Color 249, 11, 57
Shape3=Rectangle ((#Set.W#-#Set.P#*4)/2),0,(120*[Set.S]),(55*[Set.S]),(#Set.R#) | StrokeWidth 0 | OffSet (-120/2*[Set.S]),(-55/2*[Set.S])
Shape4=Combine Shape | Exclude Shape3
[m.Shape.Highlight_Recom:S]
Shape2=Rectangle ((#Set.W#-#Set.P#*4)/2),0,(180*[Set.S]),(35*[Set.S]),(#Set.R#/2) | StrokeWidth 0 | OffSet (-180/2*[Set.S]),(-35/2*[Set.S]) | Fill Color #Set.Positive_Color#,200
Shape3=Rectangle ((#Set.W#-#Set.P#*4)/2),0,(200*[Set.S]),(55*[Set.S]),(#Set.R#) | StrokeWidth 0 | OffSet (-200/2*[Set.S]),(-55/2*[Set.S])
Shape4=Combine Shape | Exclude Shape3
[m.Highlight.String:S]
X=((#Set.W#-#Set.P#*4)/2)r
Y=r
Text=NEW!
FontWeight=650
FontSize=(14*[Set.S])
; InlineSetting=CharacterSpacing | 1 | 1
StringAlign=CenterCenter
[m.String:S]
X=(#Set.P#)r
Y=(250/2*[Set.S])r
W=(#Set.W#-#Set.P#*4-500*[Set.S])
H=(250*[Set.S]-#Set.P#*2)
ClipString=2
Container=BC
Stringalign=LeftCenter
InlinePattern=^.*#CRLF#
InlineSetting=Size | (25*[Set.S])
InlinePattern2=^.*#CRLF#
InlineSetting2=Weight | 600
InlinePattern3=^.+#CRLF#.+#CRLF#(.+)$
InlineSetting3=Color | #Set.Accent_Color_2#
[m.Image:S]
X=(#set.W#-#set.p#*2.5-350*[Set.S])
Y=(-250/2*[Set.S]+#Set.P#/2)r
H=(250*[Set.S]-#Set.P#)
W=(350*[Set.S])
DynamicVariables=1
ImageName=#@#Images\Cards\[&Func:trim('#CURRENTSECTION#','.Image','')].png
Container=BC
MaskImageName=#@#Images\RoundedMask.png
Group=Scroll

; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;

[BarClip]
Fill=Fill Color #Set.Pri_Color#,(-#Scroll# > 0 ? #Set.Alpha# : 0)
Group=Scroll

[Image]
Meter=Image
W=(#Set.W#)
H=(#Set.H#*0.5)
Group=Scroll
ImageAlpha=(-#Scroll# > 0 ? 0 : 25)
PreserveAspectRatio=2
DynamicVariables=1
ImageName=#@#Images\Cards\GithubBanner.png
MaskImageName=#@#Images\FadeMask.png
Container=BC

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Title.String]
Meter=String
MeterStyle=Set.String:S
Text=When functionality meets appearance...
X=(#Set.W#/2)
Y=((130*[Set.S])+#Scroll#)
ClipString=2
FontSize=(35*[Set.S])
FontFace=#Set.Font# 
FontWeight=(650)
Group=Scroll
StringAlign=Center
InlineSetting=GradientColor | 180 | #Set.Accent_Color# ; 0.0 | #Set.Accent_Color_2# ; 1.0
[Description.String]
Meter=String
MeterStyle=Set.String:S
StringAlign=Center
X=r
Y=(20*[Set.S])R
Fontsize=(16*[Set.S])
W=(#set.W#-#Set.P#*2)
Clipstring=2
Text=JaxCore modules are tools that can be accessed with hotkeys and buttons. They are designed to help you get the work done!

; ---------------------------------- Section --------------------------------- ;

[YourFlyouts.Shape]
Meter=Shape
Y=(50*[Set.S])R
MeterStyle=m.Shape:S | m.Shape.Highlight_New:S
[YourFlyouts.New.String]
Meter=String
MeterStyle=Set.String:S | m.Highlight.String:S
[YourFlyouts.String]
Meter=String
X=(-(#Set.W#-#Set.P#*4)/2+#Set.P#)r
Text=YourFlyouts#CRLF#YourFlyouts replaces the UI that shows up when you press the volume or media keys.
MeterStyle=Set.String:S | m.String:S
[YourFlyouts.Image]
Meter=Image
MeterStyle=m.Image:S

[YourMixer.Shape]
Meter=Shape
Y=(#Set.P#*1.5)R
MeterStyle=m.Shape:S | m.Shape.Highlight_Recom:S
[YourMixer.Recom.String]
Meter=String
Text=Recommended!
MeterStyle=Set.String:S | m.Highlight.String:S
[YourMixer.String]
Meter=String
X=(-(#Set.W#-#Set.P#*4)/2+#Set.P#)r
Text=YourMixer#CRLF#YourMixer replaces the standard Windows Volume Mixer with a fully customizable volume controller. 
MeterStyle=Set.String:S | m.String:S
[YourMixer.Image]
Meter=Image
MeterStyle=m.Image:S

[ValliStart.Shape]
Meter=Shape
MeterStyle=m.Shape:S
[ValliStart.String]
Meter=String
Text=ValliStart#CRLF#Start menu replacement for Windows, with full customizability, interchangeable modules and more. Light weight and optimized.
MeterStyle=Set.String:S | m.String:S
[ValliStart.Image]
Meter=Image
MeterStyle=m.Image:S

[Keylaunch.Shape]
Meter=Shape
MeterStyle=m.Shape:S
[Keylaunch.String]
Meter=String
Text=Keylaunch#CRLF#Keylaunch lets you easily launch apps with a hotkey. The application hotkey list is extremely simple to configure, and you can even change the action's name and icon.
MeterStyle=Set.String:S | m.String:S
[Keylaunch.Image]
Meter=Image
MeterStyle=m.Image:S

[IdleStyle.Shape]
Meter=Shape
MeterStyle=m.Shape:S
[IdleStyle.String]
Meter=String
Text=IdleStyle#CRLF#Screensavers reimagined! Display various things including skins, animations and videos when you are idle
MeterStyle=Set.String:S | m.String:S
[IdleStyle.Image]
Meter=Image
MeterStyle=m.Image:S

[QuickNote.Shape]
Meter=Shape
MeterStyle=m.Shape:S
[QuickNote.String]
Meter=String
Text=QuickNote#CRLF#A quick access notepad, which you can use it as a wdiget or summon it by either dragging from the top left corner of the screen or by a hotkey press.
MeterStyle=Set.String:S | m.String:S
[QuickNote.Image]
Meter=Image
MeterStyle=m.Image:S

[Keystrokes.Shape]
Meter=Shape
MeterStyle=m.Shape:S
[Keystrokes.String]
Meter=String
Text=Keystrokes#CRLF#Stream your key strokes with style. Featuring built in layout customizer, RGB chroma support and a mouse accelerometer.
MeterStyle=Set.String:S | m.String:S
[Keystrokes.Image]
Meter=Image
MeterStyle=m.Image:S

[MIUI-Shade.Shape]
Meter=Shape
MeterStyle=m.Shape:S
[MIUI-Shade.String]
Meter=String
Text=MIUI-Shade#CRLF#Control center which looks like MIUI's shade.
MeterStyle=Set.String:S | m.String:S
[MIUI-Shade.Image]
Meter=Image
MeterStyle=m.Image:S

[YourTaskbar.Shape]
Meter=Shape
MeterStyle=m.Shape:S
[YourTaskbar.String]
Meter=String
Text=YourTaskbar#CRLF#;)
MeterStyle=Set.String:S | m.String:S
[YourTaskbar.Image]
Meter=Image
ImageName=#@#Images\Cards\Comin' Soon.png
MeterStyle=m.Image:S

[PowerControl.Shape]
Meter=Shape
MeterStyle=m.Shape:S
[PowerControl.String]
Meter=String
Text=PowerControl#CRLF#:D
MeterStyle=Set.String:S | m.String:S
[PowerControl.Image]
Meter=Image
ImageName=#@#Images\Cards\Comin' Soon.png
MeterStyle=m.Image:S