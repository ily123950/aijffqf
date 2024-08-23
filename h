-- Импортируем необходимые сервисы
local UserInputService = game:GetService("UserInputService")
local VirtualInputManager = game:GetService("VirtualInputManager")  -- Для симуляции ввода

-- Функции для симуляции нажатия и отпускания клавиши Ctrl
local function simulateCtrl(press)
    if press then
        VirtualInputManager:SendKeyEvent(true, Enum.KeyCode.LeftControl, false, game)
        print("Shift pressed")
    else
        VirtualInputManager:SendKeyEvent(false, Enum.KeyCode.LeftControl, false, game)
        print("Shift released")
    end
end

-- Функции для обработки нажатия и отпускания клавиши Shift
local function onShiftInput(input, gameProcessed)
    if input.UserInputType == Enum.UserInputType.Keyboard and 
       (input.KeyCode == Enum.KeyCode.LeftShift or input.KeyCode == Enum.KeyCode.RightShift) then
        simulateCtrl(input.UserInputState == Enum.UserInputState.Begin)
    end
end

-- Подписываемся на события нажатия и отпускания клавиши
UserInputService.InputBegan:Connect(onShiftInput)
UserInputService.InputEnded:Connect(onShiftInput)
