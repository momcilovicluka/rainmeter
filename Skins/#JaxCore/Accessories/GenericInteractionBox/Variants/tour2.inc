[Variables]
Sec.W=(1200*#Sec.S#)
Sec.H=(900*#Sec.S#)
AniDir=Bottom

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


[Sec.Box:S]
X=((#Sec.W#-(20*8)*#Sec.S#)/14+20*#Sec.S#)r
Y=(-20*#Sec.S#)r
Shape=Rectangle  0,0,((#Sec.W#-(20*8)*#Sec.S#)/7),(40*#Sec.S#),(#set.R#/2) | StrokeWidth 0 | Extend Fill | Extend Scale
Fill=Fill Color #Set.Sec_Color#
Scale=Scale 1,1
MouseOverAction=[!SetOption "#CURRENTSECTION#" Fill "Fill Color #Set.Ter_Color#"][!SetOption "#CURRENTSECTION#" Scale "Scale 1.1,1.1"][!UpdateMeter "#CURRENTSECTION#"][!Redraw]
MouseLeaveAction=[!SetOption "#CURRENTSECTION#" Fill "Fill Color #Set.Sec_Color#"][!SetOption "#CURRENTSECTION#" Scale "Scale 1,1"][!UpdateMeter "#CURRENTSECTION#"][!Redraw]
LeftMouseUpAction=[!WriteKeyValue Variables Set.Lang """[&Func:trim('#CURRENTSECTION#', 'Box', '')]""" "#@#Vars.inc"][!CommandMeasure Func "interactionBox('TranslateWarning')"][!Refresh]
DynamicVariables=1
[Sec.BoxText:S]
X=((#Sec.W#-(20*8)*#Sec.S#)/14)r
Y=(20*#Sec.S#)r
StringAlign=CenterCenter
Text="#CURRENTSECTION#"
FontSize=(10*#Sec.S#)
; ---------------------------------------------------------------------------- ;
;                                  MeterStyleS                                 ;
; ---------------------------------------------------------------------------- ;


; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;

[ImageContainer]
Meter=Shape
Shape=Rectangle 0,0,(#Sec.W#),[Image:H],#Set.R# | StrokeWidth 0 | Fill LinearGradient This
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
H=(100*#Sec.S#)
DynamicVariables=1
ImageName=#@#Images\CoreAssets\#Set.IconStyle#Logo256.png

[Text]
Meter=String
Text=Select a language#CRLF#Languages are auto-translated, might not be 100% accurate.
X=(#Sec.W#/2)
Y=(15*#Sec.s#)R
FontSize=(20*#Sec.S#)
InlinePattern=.*#CRLF#
InlineSetting=GradientColor | 180 | #Set.Accent_Color# ; 1.0 | #Set.Accent_Color_2# ; 0.0
INlinePattern2=#CRLF#.*
InlineSetting2=Size | (10*#Sec.S#)
INlinePattern3=#CRLF#.*
InlineSetting3=Color | 160,155,145
INlinePattern4=#CRLF#.*
InlineSetting4=Weight | 400
StringAlign=center
MeterStyle=Sec.String:S
FontWeight=650

; ---------------------------------------------------------------------------- ;
;                                    Content                                   ;
; ---------------------------------------------------------------------------- ;


[DefaultBox]
Meter=Shape
X=(#Sec.P#)
Y=(20*#Sec.S#)R
MeterStyle=Sec.Box:S
LeftMouseUpAction=[!CommandMEasure fUnc "interactionBox('tour4')"][!Refresh]
[Default]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[EnglishBox]
Meter=Shape
MeterStyle=Sec.Box:S
LeftMouseUpAction=[!CommandMEasure fUnc "interactionBox('tour4')"][!Refresh]
[English]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[Chinese SimplifiedBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Chinese Simplified]
Meter=String
Text=中文(簡體)
MeterStyle=Sec.String:S | Sec.BoxText:S
[HindiBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Hindi]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[SpanishBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Spanish]
Meter=String
Text=español
MeterStyle=Sec.String:S | Sec.BoxText:S
[AfrikaansBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Afrikaans]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[AlbanianBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Albanian]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S

[ArabicBox]
Meter=Shape
X=#Sec.P#
Y=(20*#Sec.S#)R
MeterStyle=Sec.Box:S
[Arabic]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[AzerbaijaniBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Azerbaijani]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[BasqueBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Basque]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[BengaliBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Bengali]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[BelarusianBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Belarusian]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[BulgarianBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Bulgarian]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[CatalanBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Catalan]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S

[Chinese TraditionalBox]
Meter=Shape
X=#Sec.P#
Y=(20*#Sec.S#)R
MeterStyle=Sec.Box:S
[Chinese Traditional]
Meter=String
Text=中文(繁體)
MeterStyle=Sec.String:S | Sec.BoxText:S
[CroatianBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Croatian]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[CzechBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Czech]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[DanishBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Danish]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[DutchBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Dutch]
Meter=String
Text=Nederlands
MeterStyle=Sec.String:S | Sec.BoxText:S
[EsperantoBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Esperanto]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[EstonianBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Estonian]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S

[FilipinoBox]
Meter=Shape
X=#Sec.P#
Y=(20*#Sec.S#)R
MeterStyle=Sec.Box:S
[Filipino]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[FinnishBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Finnish]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[FrenchBox]
Meter=Shape
MeterStyle=Sec.Box:S
[French]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[GalicianBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Galician]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[GeorgianBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Georgian]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[GermanBox]
Meter=Shape
MeterStyle=Sec.Box:S
[German]
Meter=String
Text=Deutsch
MeterStyle=Sec.String:S | Sec.BoxText:S
[GreekBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Greek]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S

[GujaratiBox]
Meter=Shape
X=#Sec.P#
Y=(20*#Sec.S#)R
MeterStyle=Sec.Box:S
[Gujarati]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[HaitianBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Haitian]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[HebrewBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Hebrew]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[HungarianBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Hungarian]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[IcelandicBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Icelandic]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[IndonesianBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Indonesian]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[IrishBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Irish]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S

[ItalianBox]
Meter=Shape
X=#Sec.P#
Y=(20*#Sec.S#)R
MeterStyle=Sec.Box:S
[Italian]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[JapaneseBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Japanese]
Meter=String
Text=日本語
MeterStyle=Sec.String:S | Sec.BoxText:S
[KannadaBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Kannada]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[KoreanBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Korean]
Meter=String
Text=한국어
MeterStyle=Sec.String:S | Sec.BoxText:S
[LatinBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Latin]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[LatvianBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Latvian]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[LithuanianBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Lithuanian]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S

[MacedonianBox]
Meter=Shape
X=#Sec.P#
Y=(20*#Sec.S#)R
MeterStyle=Sec.Box:S
[Macedonian]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[MalayBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Malay]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[MalteseBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Maltese]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[NorwegianBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Norwegian]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[PersianBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Persian]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[PolishBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Polish]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[PortugueseBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Portuguese]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S

[RomanianBox]
Meter=Shape
X=#Sec.P#
Y=(20*#Sec.S#)R
MeterStyle=Sec.Box:S
[Romanian]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[RussianBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Russian]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[SerbianBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Serbian]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[SlovakBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Slovak]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[SlovenianBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Slovenian]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[SwahiliBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Swahili]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[SwedishBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Swedish]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S

[TamilBox]
Meter=Shape
X=#Sec.P#
Y=(20*#Sec.S#)R
MeterStyle=Sec.Box:S
[Tamil]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[TeluguBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Telugu]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[ThaiBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Thai]
Meter=String
Text=ภาษาไทย
MeterStyle=Sec.String:S | Sec.BoxText:S
[TurkishBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Turkish]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[UkrainianBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Ukrainian]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[UrduBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Urdu]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[VietnameseBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Vietnamese]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S

[WelshBox]
Meter=Shape
X=#Sec.P#
Y=(20*#Sec.S#)R
MeterStyle=Sec.Box:S
[Welsh]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S
[YiddishBox]
Meter=Shape
MeterStyle=Sec.Box:S
[Yiddish]
Meter=String
MeterStyle=Sec.String:S | Sec.BoxText:S

[SubtleButton]
Meter=Shape
X=(#Sec.W#/2-60*#sec.s#)
Y=(#Sec.H#-#sec.P#-40*#sec.s#)
Shape=Rectangle  0,0,(120*#sec.S#),(40*#Sec.S#),(#set.R#/2) | StrokeWidth 0 | Extend Fill | Extend scale
Fill=Fill Color #Set.Positive_color#
Scale=Scale 1,1
MouseOverAction=[!SetOption "#CURRENTSECTION#" Scale "Scale 1.1,1.1"][!UpdateMeter "#CURRENTSECTION#"][!Redraw]
MouseLeaveAction=[!SetOption "#CURRENTSECTION#" Scale "Scale 1,1"][!UpdateMeter "#CURRENTSECTION#"][!Redraw]
LeftMouseUpAction=[!CommandMEasure fUnc "interactionBox('tour4')"][!Refresh]
[SubtleText]
Meter=String
X=(#Sec.W#/2)
Y=(#Sec.H#-#Sec.P#-20*#sec.s#)
FontColor=#Set.Pri_color#
StringAlign=CenterCenter
Text=Continue
FontWeight=600
MeterStyle=Sec.String:S

[Esc]
Meter=
