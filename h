-- Импортируем необходимые сервисы
local UserInputService = game:GetService("UserInputService")
local VirtualInputManager = game:GetService("VirtualInputManager")
local StarterGui = game:GetService("StarterGui")  -- Для использования SetCore

-- Функции для симуляции нажатия и отпускания клавиши Ctrl
local function simulateCtrl(press)
    VirtualInputManager:SendKeyEvent(press, Enum.KeyCode.LeftControl, false, game)
end

-- Функции для обработки нажатия и отпускания клавиши Shift
local function onShiftInput(input, gameProcessed)
    if input.UserInputType == Enum.UserInputType.Keyboard and 
       (input.KeyCode == Enum.KeyCode.LeftShift or input.KeyCode == Enum.KeyCode.RightShift) then
        simulateCtrl(input.UserInputState == Enum.UserInputState.Begin)
    end
end

-- Отправка уведомления при запуске скрипта
StarterGui:SetCore("SendNotification", {
    Title = "Notification";
    Text = "Key simulator is on";
    Duration = 3;  -- Время отображения уведомления в секундах
})

-- Подписываемся на события нажатия и отпускания клавиши
UserInputService.InputBegan:Connect(onShiftInput)
UserInputService.InputEnded:Connect(onShiftInput)
