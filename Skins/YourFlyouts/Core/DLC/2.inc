
; ---------------------------------------------------------------------------- ;
;                                   Function                                   ;
; ---------------------------------------------------------------------------- ;

[DragNDropParent]
Measure=Plugin
Plugin=Drag&Drop
Action=Path
OnEnterAction=[!Log Enter][!ShowMeterGroup DND.Overlay][!Redraw]
OnLeaveAction=[!HideMeterGroup DND.Overlay][!Redraw]
OnDropAction=[!CommandMeasure DLCps1 """moveDLC "$File$""""]

[DLCps1]
Measure=Plugin
Plugin=PowershellRm
scriptfile=#SKINSPATh##Skin.name#\Core\DLC.ps1

; ---------------------------------------------------------------------------- ;
;                                     Style                                    ;
; ---------------------------------------------------------------------------- ;

[Item.Shape:S]
X=(20*[Set.S])
Y=(40*[SEt.S])r
Shape=Rectangle 0,0,([ContentContainer:W]-#Set.P#),(70*[SEt.S]),(2*[Set.S]) | StrokeWidth 0 | Extend Fill
Fill=Fill Color #Set.Sec_Color#
Stroke=Stroke Color #Set.Ter_Color#
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Ter_Color#"][!SetOption #CURRENTSECTION# Stroke "Stroke Color #Set.Subtext_Color#,70"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Sec_Color#"][!SetOption #CURRENTSECTION# Stroke "Stroke Color #Set.Ter_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
DynamicVariables=1
Container=ContentContainer
[Item.StringIcon:S]
X=(70*[Set.S]/2)r
Y=(70*[Set.S]/2)r
FontSize=((16*[SEt.S]))
StringAlign=leftCenter
FontFace=Material Icons Round
Container=ContentContainer
[Item.String:S]
X=(#Set.P#/2)R
Y=r
W=([ContentContainer:W]-#Set.P#-85*[SEt.S])
ClipString=2
StringAlign=LeftCenter
Container=ContentContainer
[Item.Button.Shape:S]
X=([ContentContainer:W]-#Set.P#-30*[SEt.S])
Y=(-15*[Set.S])r
Shape=Rectangle 0,0,(30*[Set.S]),(30*[Set.S]),(5*[Set.S]) | StrokeWidth 0 | Extend Stroke
Stroke=Fill Color #Set.Positive_color#,100
MouseOverAction=[!SetOption #CURRENTSECTION# Stroke "Fill Color #Set.Positive_color#,200"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Stroke "Fill Color #Set.Positive_color#,100"][!UpdateMeter #CURRENTSECTION#][!Redraw]
DynamicVariables=1
Container=ContentContainer
[Item.Button.StringIcon:S]
X=(30*[Set.S]/2)r
Y=(30*[Set.S]/2)r
StringAlign=CenterCEnter
Text=[\xe5ce]
FontFace=Material Icons Round
Container=ContentContainer
; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[Div]
Meter=Shape
X=(20*[Set.S])
Y=(#Set.P#)
Container=ContentContainer
MeterStyle=Set.DIv:S

[Div.Button1.String]
Meter=String
X=((#Set.W#-#Set.L#-#Set.P#*3)/2-20*[Set.S])r
Y=r
Stringalign=RightCenter
Text=Discover
DynamicVariables
FontColor=[&Func:returnBool('Page.Page', '1', '#Set.Text_Color#', '#SEt.Subtext_Color#')]
LeftMouseUpAction=[!WriteKeyvalue Variables page.page 1 "#SKINSPATH##Skin.Name#\Core\DLC.inc"][!Refresh]
MeterStyle=Set.String:S
Container=ContentContainer

[Div.Button2.String]
Meter=String
X=(40*[Set.S])r
Y=r
Container=ContentContainer
Stringalign=LeftCenter
Text=Installed
FontColor=[&Func:returnBool('Page.Page', '2', '#Set.Text_Color#', '#SEt.Subtext_Color#')]
LeftMouseUpAction=[!WriteKeyvalue Variables page.page 2 "#SKINSPATH##Skin.Name#\Core\DLC.inc"][!Refresh]
MeterStyle=Set.String:S

@includeInstalledBlockIncluder=Includer.inc

[DND.Shape]
Meter=Shape
X=(20*[Set.S])
Y=(50*[SEt.S])r
Shape=Rectangle 0,0,([ContentContainer:W]-#Set.P#),(120*[SEt.S]),(2*[Set.S]) | StrokeWidth 4 | StrokeDashes (3*[Set.S]),(3*[Set.S]) | Extend This
Container=ContentContainer
DynamicVariables=1
MeterStyle=DND.Shape:0
LeftMouseUpAction=["#SKINSPATH#..\CoreData\YourFlyouts\DLC\"]
[DND.Shape:0]
This=Fill Color #Set.Sec_Color#,150 | Stroke Color #Set.Subtext_Color#
; [DND.Shape:1]
; This=Fill Color #Set.Sec_Color# | Stroke Color #Set.Text_Color#

[DND.String]
Meter=String
X=(([ContentContainer:W]-#Set.P#)/2)r
Y=(60*[Set.S])r
StringAlign=CenterCenter
Text=Drag and drop a DLC package to install / Click to open DLC directory
MeterStyle=Set.String:S
FOntcolor=#Set.Subtext_Color#
Container=ContentContainer

[DND.Overlay.StringBackground]
Meter=String
X=0
Y=#Set.TB#
W=#SEt.W#
H=(#Set.H#-#Set.TB#)
DynamicVariables=1
SolidColor=0,0,0,50
Group=DND.Overlay
Hidden=1

[DND.Overlay.String]
Meter=String
X=(#Set.W#/2)
Y=(#Set.H#/2)
InlineSetting=Shadow | 0 | 0 | 5 | 0,0,0,100
Text=[\xe1a1]
StringAlign=CenterCEnter
FontFace=Material Icons Round
FontSize=((72*[Set.S]))
Group=DND.Overlay
MeterStyle=Set.String:S
Hidden=1

[AnchorSuppli]
Meter=String
Container=ContentContainer
x=r
Y=R
