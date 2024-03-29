[Variables]
Sec.W=(500*#Sec.S#)
Sec.H=(300*#Sec.S#)
AniDir=Bottom
BackgroundCheckStatus=0
GlobalCheckStatus=0
HardwareAcceleration=0
[moveX]
Formula=(#SCREENAREAWIDTH#/2)
[moveY]
Formula=(#SCREENAREAHEIGHT#/2)
[anchorX]
Formula=50
[anchorY]
Formula=50

; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;


; ---------------------------------------------------------------------------- ;
;                                  MeterStyles                                 ;
; ---------------------------------------------------------------------------- ;


[Action.Shape:S]
X=(150/2*#Sec.s#+#sec.P#/2)r
Y=(-20*#sec.s#)r
Shape=Rectangle  0,0,(150*#sec.S#),(40*#Sec.S#),(#set.R#/2) | StrokeWidth 0 | Extend Fill | Extend scale
Fill=Fill Color #Set.Ter_Color#
Scale=Scale 1,1
MouseOverAction=[!SetOption "#CURRENTSECTION#" Scale "Scale 1.1,1.1"][!UpdateMeter "#CURRENTSECTION#"][!Redraw]
MouseLeaveAction=[!SetOption "#CURRENTSECTION#" Scale "Scale 1,1"][!UpdateMeter "#CURRENTSECTION#"][!Redraw]
[Action.String:S]
X=(150/2*#Sec.s#)r
Y=(20*#sec.s#)r
FontSize=(10*#Sec.S#)
StringAlign=CenterCenter

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[ImageContainer]
Meter=Shape
Shape=Rectangle 0,0,(#Sec.W#),[Image:H],#Sec.R# | StrokeWidth 0 | Fill LinearGradient This
This=90 | 0,0,0,0 ; 0 | 0,0,0,255 ; 1
DynamicVariables=1

[Image]
Meter=Image
Container=Imagecontainer
ImageName=#@#Images\TourPreview.png
W=#Sec.W#
H=(200*#sec.S#)
PreserveAspectRatio=2
ImageAlpha=175

[Img]
Meter=Image
X=(#Sec.W#/2-[Img:W]/2)
Y=#Sec.P#
W=(100*#Sec.S#)
H=([Img:W])
DynamicVariables=1
ImageName=#@#Images\CoreAssets\#Set.IconStyle#Logo256.png

[Text]
Meter=String
Text=Prioritize game performance!#CRLF#You can tell Rainmeter when to disable itself so it can have minimal impact on your gameplay!
X=(#Sec.W#/2)
Y=(15*#Sec.s#)R
W=(#Sec.W#-#Sec.P#*2)
FontSize=(20*#Sec.S#)
ClipString=2
InlinePattern=.*#CRLF#
InlineSetting=GradientColor | 180 | #Set.Accent_Color# ; 1.0 | #Set.Accent_Color_2# ; 0.0
INlinePattern2=#CRLF#.*
InlineSetting2=Size | (10*#Sec.S#)
INlinePattern3=#CRLF#.*
InlineSetting3=Color | 160,155,145
INlinePattern4=#CRLF#.*
InlineSetting4=Weight | 400
StringAlign=Center
MeterStyle=Sec.String:S
FontWeight=650

; ----------------------------------- Boxes ---------------------------------- ;

; ---------------------------------- Bottom ---------------------------------- ;

[Action1.Shape]
Meter=Shape
X=(#Sec.W#/2-(150*3*#Sec.S#+#Sec.P#)/2)
Y=(#Sec.H#-#Sec.P#-40*#sec.S#)
LeftMouseUpAction=[!manage gamemode][!CommandMEasure fUnc "interactionBox('tour6')"][!Refresh]
MeterStyle=Action.Shape:S
[Action1.String]
Meter=String
Text=Configure now
MeterStyle=Sec.String:S | Action.String:S
[Action2.Shape]
Meter=Shape
Fill=Fill Color #Set.Positive_Color#
LeftMouseUpAction=[!WriteKeyValue GameMode Formula "1" "#ROOTCONFIGPATH#Accessories\Overlay\Variants\Guide.inc"][!CommandMEasure fUnc "interactionBox('tour6')"][!Refresh]
MeterStyle=Action.Shape:S
[Action2.String]
Meter=String
FontColor=#Set.Pri_Color#
FontWeight=600
Text=Configure after
MeterStyle=Sec.String:S | Action.String:S
[Action3.Shape]
Meter=Shape
LeftMouseUpAction=[!WriteKeyValue GameMode Formula "0" "#ROOTCONFIGPATH#Accessories\Overlay\Variants\Guide.inc"][!CommandMEasure fUnc "interactionBox('tour6')"][!Refresh]
MeterStyle=Action.Shape:S
[Action3.String]
Meter=String
Text=Skip
MeterStyle=Sec.String:S | Action.String:S

[Esc]
Meter=
