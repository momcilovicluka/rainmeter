mediaPlayers = { 'AIMP', 'CAD', 'WMP', 'iTunes', 'Winamp', 'WebNowPlaying' }

function Initialize()
    S_Type = 'vol' -- declares the default slider type
    -- -------------------------------- Position -------------------------------- --
    local pos = SKIN:GetVariable('Position')
    SKIN:Bang('!Draggable', '0')
    local posX = string.sub(pos, 2, 2)
    local posY = string.sub(pos, 1, 1)
    local xpad = SKIN:GetVariable('xpad')
    local ypad = SKIN:GetVariable('ypad')
    local MonitorIndex = SKIN:GetVariable('MonitorIndex')
    local sax = SKIN:GetVariable('SCREENAREAX@' .. MonitorIndex)
    local say = SKIN:GetVariable('SCREENAREAY@' .. MonitorIndex)
    local saw = SKIN:GetVariable('SCREENAREAWIDTH@' .. MonitorIndex)
    local sah = SKIN:GetVariable('SCREENAREAHEIGHT@' .. MonitorIndex)
    moveX = 0
    moveY = 0
    anchorX = 0
    anchorXD = 0
    anchorY = 0
    anchorYD = 0

    if posX == 'L' then moveX = sax + xpad
    elseif posX == 'C' then
        moveX = (sax + saw / 2)
        anchorX = "50%"
        anchorXD = 0.5
    elseif posX == 'R' then
        moveX = (sax + saw - xpad)
        anchorX = "100%"
        anchorXD = 1
    end

    if posY == 'T' then moveY = say + ypad
    elseif posY == 'C' then
        moveY = (say + sah / 2)
        anchorY = "50%"
        anchorYD = 0.5
    elseif posY == 'B' then
        moveY = (say + sah - ypad)
        anchorY = "100%"
        anchorYD = 1
    end

    SKIN:Bang('!SetWindowPosition ' .. moveX .. ' ' .. moveY .. ' ' .. anchorX .. ' ' .. anchorY)

    -- --------------------------- handle media toggle -------------------------- --

    if tonumber(SKIN:GetVariable('Media')) == 1 then
        SKIN:Bang('[!Delay 50][!CommandMeasure Func "checkMedia' .. SKIN:GetVariable('MediaType') .. '()"]')
        if tonumber(SKIN:GetVariable('FetchImage')) == 0 then
            SKIN:Bang('[!SetOptionGroup MediaImage UpdateDivider -1][!HideMeterGroup MediaImage][!SetOptionGroup MediaImage Group ""][!UpdateMeterGroup MediaImage]')
        end
    else
        SKIN:Bang('[!SetOptionGroup Music UpdateDivider -1][!HideMeterGroup Music][!SetOptionGroup Music Group ""][!UpdateMeterGroup Music]')
    end

    -- --------------------------- handle lock toggle --------------------------- --

    if tonumber(SKIN:GetVariable('Locks')) == 0 then
        SKIN:Bang('[!CommandMeasure CapsLock Stop][!CommandMeasure ScrollLock Stop][!CommandMeasure NumLock Stop][!DisableMeasureGroup Locks]')
    else
        SKIN:Bang('[!Delay 100][!SetOptionGroup Locks KeyDownAction """[!CommandMEasure Func "actionLoad(\'Locks\')"][!UpdateMeasure #*CURRENTSECTION*#]"""][!UpdateMeasureGroup Locks]')
    end

    -- ------------------------- handle animation toggle ------------------------ --

    if tonumber(SKIN:GetVariable('Ani')) >= 1 then
        AniSteps = tonumber(SKIN:GetVariable('AniSteps'))
        TweenInterval = 100 / AniSteps
        AnimationDisplacement = SKIN:GetVariable('AnimationDisplacement')
        AniDir = SKIN:GetVariable('AniDir')
        dofile(SELF:GetOption("ScriptFile"):match("(.*[/\\])") .. "tween.lua")
        subject = {
            TweenNode = 0,
            TweenNode1 = 0
        }
        t = tween.new(AniSteps, subject, { TweenNode = 100 }, SKIN:GetVariable('Easetype'))
        if tonumber(SKIN:GetVariable('Ani')) == 2 then
            t2 = tween.new(AniSteps, subject, { TweenNode1 = 100 }, SKIN:GetVariable('Easetype'))
            SKIN:Bang('[!SetVariable TweenNode1 0]')
        end
    end

end

function saveLocation()
    -- local pos = SKIN:GetVariable('Position')
    moveX = tonumber(SKIN:GetX()) + anchorXD * SKIN:GetW()
    moveY = tonumber(SKIN:GetY()) + anchorYD * SKIN:GetH()
    -- anchorX = "50%"
    -- anchorY = 0
end

function tweenAnimation(dir)
    if dir == 'in' then
        local complete = t:update(1)
    else
        local complete = t:update(-1)
    end
    resultantTN = subject.TweenNode
    if resultantTN > 100 then resultantTN = 100 elseif resultantTN < 0 then resultantTN = 0 end
    local bang = '[!SetTransparency ' .. (resultantTN / 100 * 255) .. ']'
    if AniDir == 'Left' then
        bang = bang .. '[!SetWindowPosition ' .. moveX + (resultantTN / 100 - 1) * AnimationDisplacement .. ' ' .. moveY .. ' ' .. anchorX .. ' ' .. anchorY .. ']'
    elseif AniDir == 'Right' then
        bang = bang .. '[!SetWindowPosition ' .. moveX + (1 - resultantTN / 100) * AnimationDisplacement .. ' ' .. moveY .. ' ' .. anchorX .. ' ' .. anchorY .. ']'
    elseif AniDir == 'Top' then
        bang = bang .. '[!SetWindowPosition ' .. moveX .. ' ' .. moveY + (resultantTN / 100 - 1) * AnimationDisplacement .. ' ' .. anchorX .. ' ' .. anchorY .. ']'
    elseif AniDir == 'Bottom' then
        bang = bang .. '[!SetWindowPosition ' .. moveX .. ' ' .. moveY + (1 - resultantTN / 100) * AnimationDisplacement .. ' ' .. anchorX .. ' ' .. anchorY .. ']'
    end
    bang = bang .. '[!UpdateMeasure ActionTimer]'
    SKIN:Bang(bang)
end

function tweenAnimation2(dir)
    if dir == 'in' then
        local complete = t2:update(1)
    else
        local complete = t2:update(-1)
    end
    resultantTN2 = subject.TweenNode1
    if resultantTN2 > 100 then resultantTN2 = 100 elseif resultantTN2 < 0 then resultantTN2 = 0 end
    local bang = '[!SetVariable TweenNode1 ' .. resultantTN2 / 100 .. ']'
    bang = bang .. '[!UpdateMeasure ActionTimer][!UpdateMeterGroup Animated][!Redraw]'
    SKIN:Bang(bang)
end

function actionLoad(type, slidertype)
    local function checkShow()
        if tonumber(SKIN:GetVariable('mToggle')) == 0 then
            SKIN:Bang('[!EnableMeasure Tick][!CommandMeasure ActionTimer "Stop 2"][!CommandMeasure ActionTimer "Execute 1"][!SetVariable mToggle 1]')
        end
    end

    if type ~= 'Locks' then

        -- -------------- handles styles with separated pages of media -------------- --
        SKIN:Bang('[!HideMeterGroup Special]')
        if SKIN:GetVariable('SeparateMedia') ~= nil and type ~= 'up' and type ~= 'down' and type ~= 'mute' and type ~= nil then
            SKIN:Bang('[!HideMeterGroup Standard][!ShowMeterGroup Music]')
        elseif SKIN:GetVariable('SeparateMedia') ~= nil then
            SKIN:Bang('[!ShowMeterGroup Standard][!HideMeterGroup Music]')
        else
            SKIN:Bang('[!ShowMeterGroup Standard]')
        end

        
        -- ---------------------------------- Show ---------------------------------- --
        if checkingPlayerState == 0 then
            SKIN:Bang('[!HideMeterGroup Music]')
        end
        SKIN:Bang('[!UpdateMeterGroup Standard][!Redraw][!CommandMeasure Tick "Reset"]')
        
        checkShow()
        -- ----------------------------- Slider options ----------------------------- --
        if slidertype ~= nil then 
            S_Type = slidertype
            if slidertype == 'vol' then
                if SKIN:GetVariable('CurrentSlider') ~= 'mVolume' then SKIN:Bang('[!SetVariable CurrentSlider "mVolume"][!EnableMeasure mVolume][!DisableMeasure mBrightness][!UpdateMeasure mVolume]') end
                if type == 'up' then
                    SKIN:Bang('[!CommandMeasure "mVolume" "ChangeVolume #MediaKeyChange#"]')
                elseif type == 'down' then
                    SKIN:Bang('[!CommandMeasure "mVolume" "ChangeVolume -#MediaKeyChange#"]')
                elseif type == 'mute' then
                    SKIN:Bang('[!CommandMeasure "mVolume" "ToggleMute"]')
                end
                SKIN:Bang('[!UpdateMeasure mVolume]')
            else
                if SKIN:GetVariable('CurrentSlider') ~= 'mBrightness' then SKIN:Bang('[!SetVariable CurrentSlider "mBrightness"][!EnableMeasure mBrightness][!DisableMeasure mVolume][!UpdateMeasure mBrightness]') end
                if type == 'up' then
                    SKIN:Bang('[!CommandMeasure "mBrightness" "Backlight+"]')
                elseif type == 'down' then
                    SKIN:Bang('[!CommandMeasure "mBrightness" "Backlight-"]')
                end
                SKIN:Bang('[!UpdateMeasure mBrightness]')
            end
        end

        -- ---------------------------- media key actions --------------------------- --
        -- if tonumber(SKIN:GetVariable('OverrideNativeKeyFunction')) == 1 then
        if checkingPlayerState ~= 0 then
            if type == 'pause' then
                SKIN:Bang('[!CommandMeasure "state' .. currentPlayer .. '" "PlayPause"]')
            elseif type == 'next' then
                SKIN:Bang('[!CommandMeasure "state' .. currentPlayer .. '" "Next"]')
            elseif type == 'prev' then
                SKIN:Bang('[!CommandMeasure "state' .. currentPlayer .. '" "Previous"]')
            end
        else
            if type == 'pause' then
                SKIN:Bang('[!CommandMeasure "MeasureMediaKey" "PlayPause"]')
            elseif type == 'next' then
                SKIN:Bang('[!CommandMeasure "MeasureMediaKey" "Nexttrack"]')
            elseif type == 'prev' then
                SKIN:Bang('[!CommandMeasure "MeasureMediaKey" "Prevtrack"]')
            end
        -- end
        end
    else
        SKIN:Bang('[!HideMeterGroup Standard][!ShowMeterGroup ' .. type .. '][!UpdateMeterGroup "Standard | ' .. type .. '"][!Redraw]')
        SKIN:Bang('[!CommandMeasure Tick "Reset"]')

        checkShow()
    end
end

function mediaVol(dir)
    if dir == 'up' then
        SKIN:Bang('[!CommandMeasure "state' .. currentPlayer .. '" "SetVolume +#MediaKeyChange#"]')
    else
        SKIN:Bang('[!CommandMeasure "state' .. currentPlayer .. '" "SetVolume -#MediaKeyChange#"]')
    end
end

-- -------------------------------------------------------------------------- --
--                                    Media                                   --
-- -------------------------------------------------------------------------- --

function checkMediaAuto()
    currentPlayer = nil
    for i = 1, 6 do
        if SKIN:GetMeasure('state' .. mediaPlayers[i]):GetValue() == 1 then
            currentPlayer = mediaPlayers[i]
            break
        end
    end
    if currentPlayer == nil then
        for i = 1, 6 do
            if SKIN:GetMeasure('state' .. mediaPlayers[i]):GetValue() == 2 then
                currentPlayer = mediaPlayers[i]
                break
            end
        end
    end
    if currentPlayer == nil then currentPlayer = SKIN:GetVariable('NowPlayingMedia') end

    checkingPlayer = currentPlayer

    checkingPlayerState = SKIN:GetMeasure('state' .. checkingPlayer):GetValue()

    -- print(checkingPlayer, checkingPlayerState)
    if checkingPlayerState ~= 0 then
        if checkingPlayer == 'WebNowPlaying' then
            SKIN:Bang('[!EnableMeasureGroup WNP][!DisableMeasureGroup NP]')
            SKIN:Bang('[!SetVariable PlayerType WNP]')

            if SKIN:GetVariable('FetchImage') == 0 then
                SKIN:Bang('[!DisableMeasure wnpCover]')
            end
        else
            SKIN:Bang('[!EnableMeasureGroup NP][!DisableMeasureGroup WNP]')
            SKIN:Bang('[!SetVariable PlayerType NP]')

            if SKIN:GetVariable('FetchImage') == 0 then
                SKIN:Bang('[!DisableMeasure npCover]')
            end
        end
    else
        SKIN:Bang('[!DisableMeasureGroup NP][!DisableMeasureGroup WNP]')
    end

    SKIN:Bang('[!SetVariable NowPlayingMedia ' .. checkingPlayer .. ']')
    SKIN:Bang('[!UpdateMeasureGroup Music]')

    if checkingPlayerState == 1 then SKIN:Bang('[!SetOption MediaPlayPause MeterStyle "Sec.BottomButton:S | Pause"][!UpdateMeter MediaPlayPause]')
    elseif checkingPlayerState == 2 then SKIN:Bang('[!SetOption MediaPlayPause MeterStyle "Sec.BottomButton:S | Play"][!UpdateMeter MediaPlayPause]')
    elseif checkingPlayerState == 0 then SKIN:Bang('[!SetOption MediaPlayPause MeterStyle "Sec.BottomButton:S | Play"][!UpdateMeter MediaPlayPause]')
    end

    if checkingPlayerState == 0 then
        SKIN:Bang('[!HideMeterGroup Music]')
    else
        SKIN:Bang('[!ShowMeterGroup Music]')
    end

    SKIN:Bang('[!UpdateMeter *][!Redraw]')
end

function checkMediaModern()
    currentPlayer = 'Modern'

    checkingPlayerState = SKIN:GetMeasure('stateModern'):GetValue()

    if SKIN:GetVariable('FetchImage') == 0 then
        SKIN:Bang('[!DisableMeasure modernCover]')
    end

    SKIN:Bang('[!UpdateMeasureGroup Music]')

    if checkingPlayerState == 1 then SKIN:Bang('[!SetOption MediaPlayPause MeterStyle "Sec.BottomButton:S | Pause"][!UpdateMeter MediaPlayPause]')
    elseif checkingPlayerState == 2 then SKIN:Bang('[!SetOption MediaPlayPause MeterStyle "Sec.BottomButton:S | Play"][!UpdateMeter MediaPlayPause]')
    elseif checkingPlayerState == 0 then SKIN:Bang('[!SetOption MediaPlayPause MeterStyle "Sec.BottomButton:S | Play"][!UpdateMeter MediaPlayPause]')
    end

    if checkingPlayerState == 0 then
        SKIN:Bang('[!HideMeterGroup Music]')
    else
        SKIN:Bang('[!ShowMeterGroup Music]')
    end

    SKIN:Bang('[!UpdateMeter *][!Redraw]')
end

-- -------------------------------------------------------------------------- --
--                                 Device menu                                --
-- -------------------------------------------------------------------------- --

function GenerateDeviceMenu()
    local deviceList = SKIN:GetMeasure('MeasureDeviceList'):GetStringValue()

    local i = 1
    for name in string.gmatch(deviceList, '{[.%d]*}.{[%x-]*}: ([^\n]*)') do
        local action = '[!CommandMeasure "MeasureWin7Audio" "SetOutPutIndex ' .. i .. '"][!Refresh]'
        if i == 1 then index = '' else index = i end
        SKIN:Bang('!SetOption', 'Rainmeter', 'ContextTitle' .. index, name)
        SKIN:Bang('!SetOption', 'Rainmeter', 'ContextAction' .. index, action)
        i = i + 1
    end
end

-- -------------------------------------------------------------------------- --
--                               Regular slider                               --
-- -------------------------------------------------------------------------- --

function ImportSlider()
    S_Dir = SKIN:GetVariable('SliderRotation')
    S_Start = SKIN:GetMeasure('SliderStart'):GetValue()
    S_End = SKIN:GetMeasure('SliderEnd'):GetValue()
end

function CalcSliderPercentage(mouseX, mouseY)
    -- print(mouseX, S_Start, SKIN:GetMeter('VolumeBar'):GetX())
    local bang = ''
    local percent = 0

    if S_Dir == 'h' then
        mouseX = clamp(mouseX, S_Start, S_Start + S_End)
        percent = (mouseX - S_Start) * 100 / (S_End)
    else
        mouseY = clamp(mouseY, S_Start, S_Start + S_End)
        percent = 100 - (mouseY - S_Start) * 100 / (S_End)
    end

    percent = math.floor(percent + 0.5)

    if S_Type == 'vol' then
        bang = bang .. '[!CommandMeasure "mVolume" "SetVolume ' .. percent .. '"][!UpdateMeasure mVolume]'
    elseif S_Type == 'bright' then
        bang = bang .. '[!CommandMeasure "mBrightness" "SetBacklight ' .. percent .. '"][!UpdateMeasure mBrightness]'
    end
    SKIN:Bang(bang)
end

-- -------------------------------------------------------------------------- --
--                                CircleSlider                                --
-- -------------------------------------------------------------------------- --

function ImportCircleSlider()
    CSCX = SKIN:GetMeasure('CircleSliderCenterX'):GetValue()
    CSCY = SKIN:GetMeasure('CircleSliderCenterY'):GetValue()
    CSR = SKIN:GetMeasure('CircleSliderRadius'):GetValue()

end

function CalcCircleSliderPercentage(mouseX, mouseY)

    local angle = math.atan2(mouseY - CSCY, mouseX - CSCX) * 180 / math.pi
    angle = angle + 90
    if angle < 0 then angle = angle + 360 end
    angle = math.floor(angle + 0.5)
    local percent = math.floor(angle / 360 * 100 + 0.5)

    local bang = ''
    if S_Type == 'vol' then
        bang = bang .. '[!CommandMeasure "mVolume" "SetVolume ' .. percent .. '"][!UpdateMeasure mVolume]'
    elseif S_Type == 'bright' then
        bang = bang .. '[!CommandMeasure "mBrightness" "SetBacklight ' .. percent .. '"][!UpdateMeasure mBrightness]'
    end
    SKIN:Bang(bang)
end

function DrawCircleSlider(percent)
    local angle = 360 * percent / 100
    local toX = CSR * math.sin(math.rad(angle)) + CSCX
    local toY = CSCY - CSR * math.cos(math.rad(angle))
    local rflx = 0
    local bang = ''
    if angle < 360 then
        if angle > 180 then
            rflx = 1
        end
        bang = bang .. '[!SetOption VolumeBar Shape3 "Arc ' .. CSCX .. ',' .. CSCY - CSR .. ',' .. toX .. ', ' .. toY .. ',' .. CSR .. ',' .. CSR .. ',0,0,' .. rflx .. ' | Extend CircleSliderLIne"]'
    elseif angle == 360 then
        bang = bang .. '[!SetOption VolumeBar Shape3 "Ellipse ' .. CSCX .. ',' .. CSCY .. ',' .. CSR .. ' | Extend CircleSliderLIne"]'
    end
    bang = bang .. '[!UpdateMeterGroup Dynamic][!Redraw]'
    SKIN:Bang(bang)
end

-- -------------------------------------------------------------------------- --
--                       Dropdown and utility functions                       --
-- -------------------------------------------------------------------------- --



function startDrop(variant, handler, offset)
    local File = SKIN:GetVariable('ROOTCONFIGPATH') .. 'Main\\Accessories\\Drop.ini'
    local MyMeter = SKIN:GetMeter(handler)
    local scale = tonumber(SKIN:GetVariable('Scale'))
    local PosX = SKIN:GetX() + MyMeter:GetX() + offset * scale
    local PosY = SKIN:GetY() + MyMeter:GetY() + offset * scale
    SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.name', skin, File)
    SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.Variant', variant, File)
    SKIN:Bang('!WriteKeyvalue', 'Variables', 'Sec.S', scale, File)
    SKIN:Bang('!PauseMeasure', 'mToggle')
    SKIN:Bang('!ZPos', '0')
    SKIN:Bang('!Activateconfig', 'QuickNote\\Main\\Accessories', 'Drop.ini')
    SKIN:Bang('!Move', PosX, PosY, 'QuickNote\\Main\\Accessories')
end

function returnDiv(divChar)
    local divLength = SKIN:GetVariable('DividerLength')
    local this = divChar
    for i = 1, divLength - 1 do
        this = this .. divChar
    end
    return this
end

function returnBar(measureName, multiplier)
    local function DIV(a, b)
        return (a - a % b) / b
    end

    if multiplier == nil then multiplier = 1 end
    local VolumeLevel = SKIN:GetMeasure(measureName):GetValue() * multiplier
    local barChar = SKIN:GetVariable('BarCharacter')
    local barLength = SKIN:GetVariable('BarLength')
    local resultBarLength = DIV((barLength * VolumeLevel), 100)
    -- local this = ''
    -- for i = 1, resultBarLength do
    --     this = this..barChar
    -- end
    return resultBarLength
end

function checkEscape(char)
    if char == '|' or char == '\\' or char == '/' or char == '*' or char == '.' then
        return '\\' .. char
    else
        return char
    end
end

function returnBool(String, Match, ReturnStringT, ReturnStringF)
    local ReturnStringT = ReturnStringT or '1'
    local ReturnStringF = ReturnStringF or '0'
    if string.find(String, Match) then
        return (ReturnStringT)
    else
        return (ReturnStringF)
    end
end

function returnCorner()
    local BlurCorner = SKIN:GetVariable('BlurCorner')
    if BlurCorner == 'Round' then
        return 8
    elseif BlurCorner == 'RoundSmall' then
        return 4
    else
        return 0
    end
end

function volumeLevel(rep, suf)
    rep = rep or '0'
    suf = suf or ''
    if S_Type == 'vol' then
        local level = SKIN:GetMeasure('mVolume'):GetValue()
        if level == -1 then
            return rep
        else
            return level .. suf
        end
    else
        return SKIN:GetMeasure('mBrightness'):GetValue() .. suf
    end
end


function clamp(v, min, max)
    if v < min then
        return min
    end
    if v > max then
        return max
    end
    return v
end