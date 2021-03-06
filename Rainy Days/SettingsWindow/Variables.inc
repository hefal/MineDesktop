[Variables]


; Shorthand bangs and abbreviations
A=!ActivateConfig
S=!SetOptionGroup
SO=!SetOption
SV=!SetVariable
U=!UpdateMeasureGroup
UM=!UpdateMeasure
W=!WriteKeyValue

MA=MatchActions
WV=WriteVariableRounded
V=Variables


; Default audio settings
DefAverageSize=0
DefLoudnessEqualization=1
DefFFTSize=1024
DefFFTOverlap=(#**FFTSize**#-512)
DefFFTAttack=0
DefFFTDecay=0
DefFreqMin=30
DefFreqMax=10000
DefSensitivity=24


; Substitute patterns based on the active type of Setting

StateSubstitute="1":"Display","2":"Audio","3":"Extras","4":"","5":""
SetHeaderTabNames=[#SO# HeaderTab1 Text "Display"][#SO# HeaderTab2 Text "Audio"][#SO# HeaderTab3 Text "Extras"][#SO# HeaderTab4 Text " "][#SO# HeaderTab5 Text " "]

; Name of variable written to file
Var///1="Display":"Bands","Audio":"-1","Extras":"-1"
Var///2="Display":"BarWidth","Audio":"Sensitivity","Extras":"-1"
Var///3="Display":"BarGap","Audio":"FFTAttack","Extras":"-1"
Var///4="Display":"BarHeight","Audio":"FFTDecay","Extras":"-1"
Var///5="Display":"-1","Audio":"AverageSize","Extras":"-1"
Var///6="Display":"-1","Audio":"FreqMin","Extras":"-1"
Var///7="Display":"-1","Audio":"FreqMax","Extras":"-1"
Var///8="Display":"RainSpeed","Audio":"-1","Extras":"-1"
Var///9="Display":"RainConstant","Audio":"-1","Extras":"-1"
Var///10="Display":"-1","Audio":"-1","Extras":"-1"
Var///11="Display":"-1","Audio":"-1","Extras":"-1"
Var///12="Display":"-1","Audio":"-1","Extras":"-1"
Var///13="Display":"-1","Audio":"-1","Extras":"-1"

; Calc measure MaxValue for Bar meters
CalcMV///1="Display":"128","Audio":"-1","Extras":"-1"
CalcMV///2="Display":"48","Audio":"60","Extras":"-1"
CalcMV///3="Display":"128","Audio":"500","Extras":"-1"
CalcMV///4="Display":"256","Audio":"500","Extras":"-1"
CalcMV///5="Display":"-1","Audio":"8","Extras":"-1"
CalcMV///6="Display":"-1","Audio":"320","Extras":"-1"
CalcMV///7="Display":"-1","Audio":"24000","Extras":"-1"
CalcMV///8="Display":"100","Audio":"-1","Extras":"-1"
CalcMV///9="Display":"50","Audio":"-1","Extras":"-1"
CalcMV///10="Display":"-1","Audio":"-1","Extras":"-1"
CalcMV///11="Display":"-1","Audio":"-1","Extras":"-1"
CalcMV///12="Display":"-1","Audio":"-1","Extras":"-1"
CalcMV///13="Display":"-1","Audio":"-1","Extras":"-1"

; LeftMouseDownAction for String meters
StringLMDA///1="Audio":'[#W# #V# LoudnessEqualization "(#LoudnessEqualization# = 0 ? 1 : 0)" "#@##V#.inc"]',"Extras":'[#A# "#ROOTCONFIG#\Clone"]'
StringLMDA///2="Extras":'[#A# "#ROOTCONFIG#\Clone_2"]'
StringLMDA///3="Extras":'[#A# "#ROOTCONFIG#\SettingsMisc" "ExtrasCreateStandaloneSkin.ini"]'
StringLMDA///4=
StringLMDA///5=
StringLMDA///6="Display":'[#W# #V# Invert "(#Invert# = 0 ? 1 : 0)" "#@##V#.inc"][#W# #V# Invert "(#Invert# = 0 ? 1 : 0)" "#ConfigPath#"]'
StringLMDA///7="Display":'[#A# "#ROOTCONFIG#\SettingsMisc" "DisplaySlant.ini"]'
StringLMDA///8="Audio":'[#A# "#ROOTCONFIG#\SettingsMisc" "AudioFFTSize.ini"]'
StringLMDA///9="Audio":'[#A# "#ROOTCONFIG#\SettingsMisc" "AudioChannel.ini"]'
StringLMDA///10="Audio":'[#A# "#ROOTCONFIG#\SettingsMisc" "AudioMusicPlayer.ini"]'
StringLMDA///11="Audio":'[#W# #V# Port #*PortVariable*# "#@##V#.inc"][#W# #V# Port #*PortVariable*# "#ConfigPath#"]'
StringLMDA///12="Audio":'[#A# "#ROOTCONFIG#\SettingsMisc" "AudioDeviceList.ini"]'
StringLMDA///13="Audio":'[#W# #V# AverageSize #DefAverageSize# "#@##V#.inc"][#W# #V# LoudnessEqualization #DefLoudnessEqualization# "#@##V#.inc"][#W# #V# FFTSize #DefFFTSize# "#@##V#.inc"][#W# #V# FFTOverlap """"#DefFFTOverlap#"""" "#@##V#.inc"][#W# #V# FFTAttack #DefFFTAttack# "#@##V#.inc"][#W# #V# FFTDecay #DefFFTDecay# "#@##V#.inc"][#W# #V# FreqMin #DefFreqMin# "#@##V#.inc"][#W# #V# FreqMax #DefFreqMax# "#@##V#.inc"][#W# #V# Sensitivity #DefSensitivity# "#@##V#.inc"]'

; Display text
Text///1="Display":"Number of raindrops: #Bands#","Audio":"#LoudnessEqualization#  Loudness equalization","Extras":"Show duplicate skin...","1  Loudness equalization":"☑  Loudness equalization","#LoudnessEqualization#  Loudness equalization":"☐  Loudness equalization"
Text///2="Display":"Raindrop width: #BarWidth# px","Audio":"Sensitivity: #Sensitivity# dB","Extras":"Show duplicate skin (2)..."
Text///3="Display":"Raindrop spacing: #BarGap# px","Audio":"Attack speed: #FFTAttack# ms","Extras":"Create standalone skin..."
Text///4="Display":"Raindrop height: #BarHeight# px","Audio":"Decay speed: #FFTDecay# ms","Extras":""
Text///5="Display":"Color:","Audio":"Smoothness: #AverageSize# past values","Extras":"","1 past values":"1 past value"
Text///6="Display":"#Invert#  Invert spectrum","Audio":"Min frequency: #FreqMin# Hz","Extras":"","1  Invert spectrum":"☑  Invert spectrum","#Invert#  Invert spectrum":"☐  Invert spectrum"
Text///7="Display":"Slant: #Slant#  ▼","Audio":"Max frequency: #FreqMax# Hz","Extras":""
Text///8="Display":"Speed: #RainSpeed#","Audio":"Resolution: #FFTSize# points  ▼","Extras":""
Text///9="Display":"Constant: #RainConstant#","Audio":"Channel: #Channel#  ▼","Extras":""
Text///10="Display":"","Audio":"Music player: #MusicPlayer#  ▼","Extras":""
Text///11="Display":"","Audio":"Switch to #Port#...","Extras":"","Output":"input","Input":"output"
Text///12="Display":"","Audio":"Set audio device...","Extras":""
Text///13="Display":"","Audio":"Reset audio settings...","Extras":""

; Help text
HelpText///1="Display":"Number of audio bands. Higher values increases precision.","Audio":"Increases visibility for quiet audio sources when applicable.","Extras":"Show a skin clone with separate direction and source options."
HelpText///2="Display":"Size of one raindrop.","Audio":"Spectrum visibility based on sound level threshold.","Extras":"Show another skin clone with separate direction and source options."
HelpText///3="Display":"Space between the raindrops.","Audio":"Determines how fast the raindrops 'jump' down.","Extras":"Create a skin copy with all separate options. (Not related to above)"
HelpText///4="Display":"Maximum raindrop height at the equator of the screen.","Audio":"Determines how fast the raindrops 'sustain' falling.","Extras":" "
HelpText///5="Display":"Change skin color.","Audio":"Average sound levels over time to provide continuity.","Extras":" "
HelpText///6="Display":"Reverses the order of the raindrops.","Audio":"Threshold for lowest pitched sounds.","Extras":" "
HelpText///7="Display":"Determines the angle of the raindrops.","Audio":"Threshold for highest pitched sounds.","Extras":" "
HelpText///8="Display":"Falling speed.","Audio":"Spectrum accuracy. Note: Higher values will increase delay.","Extras":" "
HelpText///9="Display":"Falling speed - when no sound is playing - '0' hides the skin.","Audio":"Speaker source.","Extras":" "
HelpText///10="Display":" ","Audio":"Note: When the player is open, all sounds will be displayed.","Extras":" "
HelpText///11="Display":" ","Audio":"Switch between your microphone or speakers.","Extras":" "
HelpText///12="Display":" ","Audio":"Select another audio device.","Extras":" "
HelpText///13="Display":" ","Audio":"Reset audio settings to the default values.","Extras":" "


; Rounding options based on the active type of Setting and Section
RoundDisplayBands=[#SO# #WV# IfCondition2 "(#***Section***# = 1)"][#SO# #WV# IfTrueAction2 """[#SO# WriteVariable OnChangeAction """[#W# #V# [///#****Section****#] [****WriteVariable****] "#@##V#.inc"][#A# "#ROOTCONFIG#\GenerateBands"]"""]"""]
RoundDisplayFinal=[#SO# #WV# IfCondition3 "(#WV# >= 0)"][#SO# #WV# IfTrueAction3 """[#UM# WriteVariable]"""]

RoundDisplay=#RoundDisplayBands##RoundDisplayFinal#


; Extra bangs to modify the Settings window based on the active type of Setting

DisplayBangs=#RoundDisplay#[#SO# "5" X 16R][#SO# "5" Y 2r][#SO# "5" W 16][#SO# "5" H 16][#SO# "5" SolidColor #Color#][#SO# "5" LeftMouseUpAction """[!WriteKeyValue Variables WriteVariable Color "#@#Variables.inc"][!ActivateConfig "#ROOTCONFIG#\RGBCode"][!Move "(#**CURRENTCONFIGX**# + [#***CURRENTSECTION***#:X])" "(#**CURRENTCONFIGY**# + [#***CURRENTSECTION***#:Y] + 24)" "#ROOTCONFIG#\RGBCode"]"""]

AudioBangs=[#SO# #MA# String "#Port#"][#UM# #MA#][#SO# #MA# IfMatch "Output"][#SO# #MA# IfMatchAction """[#SV# PortVariable "Input"]"""][#SO# #MA# IfMatch2 "Input"][#SO# #MA# IfMatchAction2 """[#SV# PortVariable "Output"]"""][#UM# #MA#]

ExtrasBangs=

IfMatchDisplay=[#SO# #MA# IfMatch "Display"][#SO# #MA# IfMatchAction """#DisplayBangs#"""]
IfMatchAudio=[#SO# #MA# IfMatch2 "Audio"][#SO# #MA# IfMatchAction2 """#AudioBangs#"""]
IfMatchExtras=[#SO# #MA# IfMatch3 "Extras"][#SO# #MA# IfMatchAction3 """#ExtrasBangs#"""]
SetOptionsByState=[#SO# #MA# String [StateReference]][#UM# #MA#]#IfMatchDisplay##IfMatchAudio##IfMatchExtras#[#UM# #MA#]
