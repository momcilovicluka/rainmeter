[B]
Meter=Shape
X=(#Set.WinB#/2)
Y=(#Set.WinB#/2)
Shape=Rectangle 0,0, #Set.W#, #Set.H#, #Set.WinR# | StrokeWidth #Set.WinB# | Fill Color #Set.Pri_Color#,#Set.Alpha# | Stroke Color #Set.Ter_Color#
Shape2=Line #Set.L#, (#Set.P#+#SEt.TB#), #Set.L#, (#Set.H#-#Set.P#) | StrokeWidth 2 | Stroke LinearGradient This
Shape3=Rectangle (#Set.L#-5*[SEt.S]),(#Set.P#+#Set.TB#),(10*[SEt.S]),(10*[SEt.S]) | Rotate 45 | StrokeWidth 0 | Fill Color #Set.Accent_Color#
This=270 | #Set.Accent_Color# ; 0 | #Set.Ter_Color#,100 ; 0.1 | #Set.Pri_Color#,0 ; 1.0
MouseActionCursor=0
DynamicVariables=1

[DragBar.Shape]
Meter=Shape
X=(#Set.WinB#/2)
Y=(#Set.WinB#/2)
Shape=Rectangle 0,0,#Set.W#,(#Set.TB#),#Set.WinR# | StrokeWidth #Set.WinB# | Fill Color #Set.Ter_Color# | Stroke Color #Set.Ter_Color#
MouseOverAction=[!CommandMeasure WindowHandler ToggleDrag(1)]
MouseLeaveAction=[!CommandMeasure WindowHandler ToggleDrag(0)]
LeftMouseDoubleClickAction=[!CommandMeasure WindowHandler ToggleMaximize()]
MouseActionCursor=0
DynamicVariables=1
[DragBar.Image]
Meter=Image
ImageName=#@#Images\CoreAssets\#Set.IconStyle#Logo64.png
X=(5*[Set.S])r
Y=(5*[Set.S])r
W=(#Set.Tb#-10*[Set.S])
H=(#Set.Tb#-10*[Set.S])
DynamicVariables=1
[DragBar.String]
Meter=String
X=(10*[Set.S])R
y=(#Set.WinB#/2+#Set.Tb#/2)
FontSize=(8*[Set.S])
FontColor=#Set.SubText_Color# 
MeterStyle=Set.String:s | DragBar.String:S1
StringAlign=LeftCenter
MouseOverAction=[!SetOption #CURRENTSECTION# MeterStyle "Set.String:s | DragBar.String:S2"][!Updatemeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# MeterStyle "Set.String:s | DragBar.String:S1"][!Updatemeter #CURRENTSECTION#][!Redraw]
[DragBar.String:S1]
Text=JaxCore Config Hub - #Skin.Name#
[DragBar.String:S2]
Text=#CURRENTPATH##CURRENTFILE#  - Scaled at [Set.S]x

[SettingsText]
Meter=String
MeterStyle=Set.String:S
Text=#Skin.Name#
X=(#Set.P#)
Y=(#Set.P#+#set.TB#)
W=(#Set.L#-#Set.P#*1.5)
ClipString=1
Fontface=#Set.Font# 
FontWeight=(650)
StringAlign=LeftTop
FontSize=(14*[Set.S])
DynamicVariables=1
Group=Shorthand

; [ImageContainer]

[ContentContainer]
Meter=Shape
X=(#Set.L#+#set.P#)
Y=#Set.P#
Shape=Rectangle (0),(0),(#Set.W#-#Set.L#-#Set.P#*2),(#Set.H#-#Set.P#*2),(#Set.R#/2),(#Set.R#/2) | StrokeWidth 0 | Fill Color 255,255,255
DynamicVariables=1
MouseScrollDownAction=[!SetVariable Scroll "(Clamp(#Scroll#-50,[AnchorChecker],0))"][!UpdateMeter *][!Redraw]
MouseScrollUpAction=[!SetVariable Scroll "(Clamp(#Scroll#+50,[AnchorChecker],0))"][!UpdateMeter *][!Redraw]
MouseActionCursor=0
Group=Background

[ScrollBar:Scrolling]
Fill=Stroke Color #Set.Subtext_Color#
[ScrollBar:Idle]
LeftMouseDownAction=[!SetVariable ScrollClickedPos "$MouseY$"][!SetOption ScrollBar MeterStyle ScrollBar:Scrolling][!EnableMeasure MouseScrollBar][!UpdateMeasure MouseScrollBar][!CommandMeasure MouseScrollBar "Start"]
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Stroke Color #Set.Subtext_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Stroke Color #Set.Ter_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
[ScrollBar]
Meter=Shape
X=([ContentContainer:XW]+25*[Set.S])
Y=(#Set.P#+(#Scroll#/([AnchorChecker]+1)*([ContentContainer:H]-([ContentContainer:H]/([ContentContainer:H]-[AnchorChecker])*[ContentContainer:H]))))
Shape=Line 0,0,0,([ContentContainer:H]/([ContentContainer:H]-[AnchorChecker])*[ContentContainer:H]) | StrokeWidth (4*[Set.S]) | StrokeStartCap Round | StrokeEndCap Round | Extend Fill
Fill=Stroke Color #Set.Ter_Color#
DynamicVariables=1
Group=Background | Scrollbar
Hidden=1
MeterStyle=ScrolLBar:Idle
