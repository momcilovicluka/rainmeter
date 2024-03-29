; ---------------------------------------------------------------------------- ;
;                                     Style                                    ;
; ---------------------------------------------------------------------------- ;

[Variables]
Sec.AnchorName=AnchorSuppli

[Sec.String:S]
Container=DLC.COntainer


[Item.Shape:S]
X=(20*[Set.S])
Y=(40*[SEt.S])r
Shape=Rectangle 0,0,([DLC.Container:W]-#Set.P#),(50*[SEt.S]),(2*[Set.S]) | StrokeWidth 0 | Extend Fill
Fill=Fill Color #Set.Sec_Color#
Stroke=Stroke Color #Set.Ter_Color#
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Ter_Color#"][!SetOption #CURRENTSECTION# Stroke "Stroke Color #Set.Subtext_Color#,50"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Sec_Color#"][!SetOption #CURRENTSECTION# Stroke "Stroke Color #Set.Ter_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
DynamicVariables=1
Container=DLC.Container
[Item.StringIcon:S]
X=(50*[Set.S]/2)r
Y=(50*[Set.S]/2)r
FontSize=((16*[SEt.S]))
StringAlign=leftCenter
FontFace=Material Icons Round
Container=DLC.Container
[Item.String:S]
X=(#Set.P#/2)R
Y=r
W=([DLC.Container:W]-#Set.P#-85*[SEt.S])
ClipString=2
StringAlign=LeftCenter
Container=DLC.Container

[Product.Shape:S]
X=([DLC.Container:W]/2-20*[Set.S])r
Y=(-([DLC.Container:W]/2-20*[Set.S]-#Set.P#)/1.625-#Set.P#)r
Shape=Rectangle 0,0,([DLC.Container:W]/2-20*[Set.S]),(([DLC.Container:W]/2-20*[Set.S])*0.8),(#Set.R#) | StrokeWidth (2*[Set.S]) | Extend Fill | Stroke LinearGradient CoreGrad
Fill=Fill Color #Set.Sec_Color#
CoreGrad=45 | #SEt.Accent_Color# ; 1 | #Set.Accent_color_2# ;0
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Ter_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color #Set.Sec_Color#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=["https://ko-fi.com/jaxoriginals/shop"]
DynamicVariables=1
Container=DLC.Container
[Product.Image:S]
X=(#Set.P#/2)r
Y=(#Set.P#/2)r
W=([DLC.Container:W]/2-20*[Set.S]-#Set.P#)
ImageName=#SKINSPATH##Skin.Name#\@Resources\Images\DLC\[&Func:trim('#CURRENTSECTION#', '.Image:S', '')].png
MaskImageName=#SKINSPATH##Skin.Name#\Core\Layout\Mask.png
DynamicVariables=1
Container=DLC.Container
[Product.String:S]
X=r
Y=(#set.P#/2)R
W=([DLC.Container:W]/2-#Set.P#*2.5)
Text=[&Func:trim('#CURRENTSECTION#', '.String:S', '')] for YourFlyouts
FontWeight=650
FontSize=(20*[Set.S])
ClipString=2
InlinePattern= for YourFlyouts
InlineSetting=Size | (10*[Set.S])
InlinePattern2= for YourFlyouts
InlineSetting2=Weight | 400
Container=DLC.Container

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;
[Bg.Container]
Meter=Shape
X=(#Set.L#)
Y=(#Set.TB#+#Set.WInB#)
Shape=Rectangle (0),(0),(#Set.W#-#Set.L#),(#Set.H#*0.6) | StrokeWidth 0 | Fill LinearGradient This
This=155 | 255,255,255,0 ; 0.4 | 255,255,255 ; 0.6
DynamicVariables=1
[Bg.Img]
Meter=Image
Y=(#Scroll#)
W=[Bg.Container:W]
H=[Bg.Container:H]
Container=Bg.Container
DynamicVariables=1
ImageAlpha=255
ImageName=#SKINSPATH##SKin.Name#\@Resources\Images\DLC\#Bg.Img#.png
PreserveAspectRatio=2

[DLC.Container]
Meter=Shape
X=(#Set.L#+#set.P#)
Y=#Set.P#
Shape=Rectangle (0),(0),(#Set.W#-#Set.L#-#Set.P#*2),(#Set.H#-#Set.P#*2),(#Set.R#/2),(#Set.R#/2) | StrokeWidth 0 | Fill Color 255,255,255
DynamicVariables=1
MouseScrollDownAction=[!SetVariable Scroll "(Clamp(#Scroll#-50,[AnchorChecker],0))"][!UpdateMeter *][!Redraw]
MouseScrollUpAction=[!SetVariable Scroll "(Clamp(#Scroll#+50,[AnchorChecker],0))"][!UpdateMeter *][!Redraw]
MouseActionCursor=0
Group=Background
[Header]
Meter=String
X=(20*[Set.S])
Y=(30*[Set.S]+#Scroll#)
DynamicVariables=1
Text=#SKIN.NAME# Downloadable contents
MeterStyle=Set.String:S | Sec.String:S
FontWeight=300
FontSize=((12*[Set.S]))


[Spotlight.Title.String]
Meter=String
Text="Sleek"
X=r
Y=(#Set.P#*1.5)r
FontSize=((80*[Set.S]))
InlineSetting=GradientColor | 180 | #Set.Accent_Color# ; 0.0 | #Set.Accent_Color_2# ; 1.0
FontWEight=800
MeterStyle=Set.String:S | SEc.String:S
[Spotlight.Des.String]
Meter=String
Text=A beautiful flyout with contemporary design,#CRLF#enlightened by a circle slider.
X=r
Y=R
W=(#SEt.W#-#set.L#-#set.P#*2)
ClipString=2
MeterStyle=Set.String:S | SEc.String:S
[Spotlight.Price.String]
Meter=String
Text=Get it for $0+ pay what you want!#CRLF#But a payment of $3 or more will go toward ongoing support and future updates :)
X=r
Y=(#Set.P#/2)R
W=(#SEt.W#-#set.L#-#set.P#*2-400*[Set.S])
ClipString=2
FontWeight=300
InlinePattern=\$0\+ pay what you want|\$3 or more
InlineSetting=Color | #Set.Accent_Color_2#
InlinePattern2=\$0\+ pay what you want|\$3 or more
InlineSetting2=Weight | 500
MeterStyle=Set.String:S | SEc.String:S
[Spotlight.Button1.Shape]
Meter=Shape
X=r
Y=(#set.P#/2)R
OverColor=#Set.Text_Color#,150
LeaveColor=#Set.Text_Color#,50
DynamicVariables=1
Shape=Rectangle 0,0,200,40,#set.r# | StrokeWidth 0 | Extend Fill | Scale [Set.S],[Set.S],0,0
Fill=Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'LeaveColor')],#Set.Alpha#
MouseOverAction=[!SetOption #CURRENTSECTION# Fill "Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'OverColor')],#Set.Alpha#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
MouseLeaveAction=[!SetOption #CURRENTSECTION# Fill "Fill Color [&Func:LocalVar('#CURRENTSECTION#', 'LeaveColor')],#Set.Alpha#"][!UpdateMeter #CURRENTSECTION#][!Redraw]
LeftMouseUpAction=["https://ko-fi.com/jaxoriginals/shop"]
Container=DLC.Container
[Spotlight.Button1.String]
Meter=String
X=(200*[Set.S]/2)r
Y=(40*[Set.S]/2)r
StringAlign=CenterCenter
Text=See details
MeterStyle=Set.String:S | SEc.String:S

[Div]
Meter=Shape
X=(20*[Set.S])
Y=(#Set.H#*0.6+#Set.P#/2+#Scroll#)
Container=DLC.Container
MeterStyle=Set.DIv:S

[Div.Button1.String]
Meter=String
X=((#Set.W#-#Set.L#-#Set.P#*3)/2-20*[Set.S])r
Y=r
Stringalign=RightCenter
Text=Discover
FontColor=[&Func:returnBool('Page.Page', '1', '#Set.Text_Color#', '#SEt.Subtext_Color#')]
LeftMouseUpAction=[!WriteKeyvalue Variables page.page 1 "#SKINSPATH##Skin.Name#\Core\DLC.inc"][!Refresh]
MeterStyle=Set.String:S | SEc.String:S

[Div.Button2.String]
Meter=String
X=(40*[Set.S])r
Y=r
Stringalign=LeftCenter
Text=Installed
FontColor=[&Func:returnBool('Page.Page', '2', '#Set.Text_Color#', '#SEt.Subtext_Color#')]
LeftMouseUpAction=[!WriteKeyvalue Variables page.page 2 "#SKINSPATH##Skin.Name#\Core\DLC.inc"][!Refresh]
MeterStyle=Set.String:S | SEc.String:S

[Vekl.Shape:S]
Meter=Shape
X=(20*[Set.S])
Y=(40*[SEt.S])r
MeterStyle=Product.Shape:S
[Vekl.Image:S]
Meter=Image
MeterStyle=Product.Image:S
[Vekl.String:S]
Meter=String
MeterStyle=Set.String:S | Product.String:S

[Sleek.Shape:S]
Meter=Shape
MeterStyle=Product.Shape:S
[Sleek.Image:S]
Meter=Image
MeterStyle=Product.Image:S
[Sleek.String:S]
Meter=String
MeterStyle=Set.String:S | Product.String:S

[Item1.Shape]
Meter=Shape
Y=(90*[Set.S])r
MeterStyle=Item.Shape:S
[Item1.StringIcon]
Meter=String
Text=[\xe65f]
Fontcolor=FECC50
MeterStyle=Set.String:S | Item.StringIcon:S
[Item1.String]
Meter=String
Text=Get deluxe exclusive contents to work with the base module!
MeterStyle=Set.String:S | Item.String:S

[Item2.Shape]
Meter=Shape
MeterStyle=Item.Shape:S
[Item2.StringIcon]
Meter=String
Text=[\xf041]
Fontcolor=2FB0CD
MeterStyle=Set.String:S | Item.StringIcon:S
[Item2.String]
Meter=String
Text=Pay what you want! There is no set price (only a recommended price) for everything!
MeterStyle=Set.String:S | Item.String:S

[Item3.Shape]
Meter=Shape
MeterStyle=Item.Shape:S
[Item3.StringIcon]
Meter=String
Text=[\xe9e4]
Fontcolor=183, 255, 123
MeterStyle=Set.String:S | Item.StringIcon:S
[Item3.String]
Meter=String
Text=All the money goes towards the momentum of development!
MeterStyle=Set.String:S | Item.String:S

[AnchorSuppli]
Meter=String
Container=DLC.Container
x=r
Y=R