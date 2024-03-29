[General:Category]
Meter=String
MeterStyle=Set.String:S | Pagecat:S
Text=GENERAL
Y=(#Set.P#+64*[Set.S])

[General]
Meter=Shape
Y=(10*[Set.S])R
MeterStyle=PageBox:S
Fill=Fill Color #Set.Accent_Color#,(#BarHandler# = 2 ? 255: 0)
Handle=2
[GeneralIcon]
Meter=Image
MeterStyle=PageIcon:S
[2]
Meter=String
Text=General
MeterStyle=Set.String:S | PageText:S

[GlobalVars]
Meter=Shape
Y=(10*[Set.S])R
MeterStyle=PageBox:S
Fill=Fill Color #Set.Accent_Color#,(#BarHandler# = 83 ? 255: 0)
Handle=83
[GlobalVarsIcon]
Meter=Image
MeterStyle=PageIcon:S
[83]
Meter=String
Text=Global
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
[3]
Meter=String
Text=Appearance
MeterStyle=Set.String:S | PageText:S

[Addons]
Meter=Shape
Y=(10*[Set.S])R
MeterStyle=PageBox:S
Fill=Fill Color #Set.Accent_Color#,(#BarHandler# = 81 ? 255: 0)
Handle=81
[AddonsIcon]
Meter=Image
MeterStyle=PageIcon:S
[81]
Meter=String
Text=Addons
MeterStyle=Set.String:S | PageText:S

[:Language]
Meter=Shape
Y=(10*[Set.S])R
MeterStyle=PageBox:S
Fill=Fill Color #Set.Accent_Color#,(#BarHandler# = 82 ? 255: 0)
Leftmouseupaction=[!WriteKeyvalue Variables "Skin.Set_Page" "Language" "#@#SecVar.inc"][!Refresh]
[:LanguageIcon]
Meter=Image
ImageName=#@#Icons\Settings\LanguageIcon.png
MeterStyle=PageIcon:S
[:82]
Meter=String
Text=Language [Beta]
FontColor=[&Func:returnBool('BarHandler', '82', '#Set.Text_Color#', '#Set.SubText_Color#')]
MeterStyle=Set.String:S | PageText:S

[Language]
Hidden=1
[LanguageIcon]
Hidden=1
[82]
Hidden=1