
[Header.String]
Text=Behavioral customization

[Description.String]
Text=You can modify the volume to change, when & how long the flyout shows up and animations in the general settings.
InlinePattern=general settings

[Button.1.Shape]
Meter=Shape
X=(#W#/2-(300*[S])/2)
Y=(#Set.P#)R
LeftMouseUpAction=[!WriteKeyValue Variables Sec.arg2 "8" "#CURRENTPATH#Main.ini"][!Refresh]
MeterStyle=Pos_Button.Shape:S
[Button.1.String]
Meter=String
Text=Got it
MeterStyle=Sec.String:S | Button.String:S