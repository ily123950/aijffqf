-- Импортируем необходимые сервисы
local UserInputService = game:GetService("UserInputService")

-- Функция для имитации нажатия клавиши Ctrl
local function simulateCtrlPress()
    keypress(17)  -- Имитируем нажатие клавиши Ctrl
end

-- Функция для имитации отпускания клавиши Ctrl
local function simulateCtrlRelease()
    keyrelease(17)  -- Имитируем отпускание клавиши Ctrl
end

-- Функция для обработки нажатия клавиши Shift
local function onShiftPressed(input, gameProcessed)
    if input.KeyCode == Enum.KeyCode.LeftShift or input.KeyCode == Enum.KeyCode.RightShift then
        simulateCtrlPress()
    end
end

-- Функция для обработки отпускания клавиши Shift
local function onShiftReleased(input, gameProcessed)
    if input.KeyCode == Enum.KeyCode.LeftShift or input.KeyCode == Enum.KeyCode.RightShift then
        simulateCtrlRelease()
    end
end

-- Подписываемся на событие нажатия клавиши
UserInputService.InputBegan:Connect(onShiftPressed)

-- Подписываемся на событие отпускания клавиши
UserInputService.InputEnded:Connect(onShiftReleased)
