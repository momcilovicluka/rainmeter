[General:Category]
Meter=String
MeterStyle=Set.String:S | Pagecat:S
Text=GENERAL
Y=(#Set.P#+64*[Set.S])

[Info]
Meter=Shape
Y=(10*[Set.S])R
MeterStyle=PageBox:S
Fill=Fill Color #Set.Accent_Color#,(#BarHandler# = 1 ? 255: 0)
Handle=1
[InfoIcon]
Meter=Image
MeterStyle=PageIcon:S
Greyscale=(#BarHandler# = 1 ? 1 : 0)
[1]
Meter=String
Text=Info
DynamicVariables-1
MeterStyle=Set.String:S | PageText:S

[DLC]
Meter=Shape
Y=(10*[Set.S])R
MeterStyle=PageBox:S
LeftMouseUpAction=[!WriteKeyvalue Variables page.page 0 "#SKINSPATH##Skin.Name#\Core\DLC.inc"][!WriteKeyvalue Variables "Skin.Set_Page" "DLC" "#@#SecVar.inc"][!Refresh]
Fill=Fill Color #Set.Accent_Color#,(#BarHandler# = 9 ? 255: 0)
Handle=9
[DLCIcon]
Meter=Image
MeterStyle=PageIcon:S
Greyscale=(#BarHandler# = 9 ? 1 : 0)
[9]
Meter=String
Text=DLC
DynamicVariables-1
MeterStyle=Set.String:S | PageText:S

[General]
Meter=Shape
Y=(10*[Set.S])R
MeterStyle=PageBox:S
Fill=Fill Color #Set.Accent_Color#,(#BarHandler# = 2 ? 255: 0)
Handle=2
[GeneralIcon]
Meter=Image
MeterStyle=PageIcon:S
Greyscale=(#BarHandler# = 2 ? 1 : 0)
[2]
Meter=String
Text=General
DynamicVariables-1
MeterStyle=Set.String:S | PageText:S

[Layout]
Meter=Shape
Y=(10*[Set.S])R
MeterStyle=PageBox:S
Fill=Fill Color #Set.Accent_Color#,(#BarHandler# = 4 ? 255: 0)
Handle=4
[LayoutIcon]
Meter=Image
MeterStyle=PageIcon:S
Greyscale=(#BarHandler# = 4 ? 1 : 0)
[4]
Meter=String
Text=Layout
DynamicVariables-1
MeterStyle=Set.String:S | PageText:S

[Appearance]
Meter=Shape
Y=(10*[Set.S])R
MeterStyle=PageBox:S
Fill=Fill Color #Set.Accent_Color#,(#BarHandler# = 3 ? 255: 0)
Handle=3
[AppearanceIcon]
Meter=Image
MeterStyle=PageIcon:S
Greyscale=(#BarHandler# = 3 ? 1 : 0)
[3]
Meter=String
Text=Appearance
DynamicVariables-1
MeterStyle=Set.String:S | PageText:S

[Position]
Meter=Shape
Y=(10*[Set.S])R
MeterStyle=PageBox:S
Fill=Fill Color #Set.Accent_Color#,(#BarHandler# = 8 ? 255: 0)
Handle=4
[PositionIcon]
Meter=Image
MeterStyle=PageIcon:S
Greyscale=(#BarHandler# = 8 ? 1 : 0)
[8]
Meter=String
Text=Position
DynamicVariables-1
MeterStyle=Set.String:S | PageText:S

[NewMedia]
Meter=Shape
Y=(10*[Set.S])R
MeterStyle=PageBox:S
Fill=Fill Color #Set.Accent_Color#,(#BarHandler# = 5.5 ? 255: 0)
Handle=5
Hidden=(#Media# = 1 ? 0 : 1)
[MediaIcon]
Meter=Image
MeterStyle=PageIcon:S
Greyscale=(#BarHandler# = 5.5 ? 1 : 0)
Hidden=(#Media# = 1 ? 0 : 1)
[5.5]
Meter=String
Text=Media
DynamicVariables-1
MeterStyle=Set.String:S | PageText:S
Hidden=(#Media# = 1 ? 0 : 1)