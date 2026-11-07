# Добавляет C:\msys64\ucrt64\bin в системный PATH. Требуются права администратора.
# Запуск: правой кнопкой → "Запустить от имени администратора" или из админ PowerShell: `.\
emove_msys_path.ps1` (пример)

$Add = 'C:\msys64\ucrt64\bin'

function Test-IsAdmin {
    $id = [Security.Principal.WindowsIdentity]::GetCurrent()
    $p = New-Object Security.Principal.WindowsPrincipal($id)
    return $p.IsInRole([Security.Principal.WindowsBuiltInRole]::Administrator)
}

if (-not (Test-IsAdmin)) {
    Write-Output "Запрос прав администратора..."
    $psi = New-Object System.Diagnostics.ProcessStartInfo
    $psi.FileName = 'powershell'
    $psi.Arguments = "-NoProfile -ExecutionPolicy Bypass -File \"$PSCommandPath\""
    $psi.Verb = 'runas'
    try {
        [System.Diagnostics.Process]::Start($psi) | Out-Null
    } catch {
        Write-Error "Не удалось получить права администратора: $_"
    }
    exit
}

try {
    $current = [Environment]::GetEnvironmentVariable('Path','Machine')
} catch {
    Write-Error "Не удалось прочитать системную переменную PATH: $_"
    exit 1
}

if ($current -and $current.Split(';') -contains $Add) {
    Write-Output "Путь уже присутствует в системном PATH: $Add"
    exit 0
}

$new = if ([string]::IsNullOrEmpty($current)) { $Add } else { "$current;$Add" }

try {
    [Environment]::SetEnvironmentVariable('Path', $new, 'Machine')
    Write-Output "Путь добавлен в системный PATH: $Add"

    # Broadcast WM_SETTINGCHANGE, чтобы приложения узнали об изменении
    $signature = @"
using System;
using System.Runtime.InteropServices;
public static class NativeMethods {
    [DllImport("user32.dll", SetLastError=true, CharSet=CharSet.Auto)]
    public static extern IntPtr SendMessageTimeout(IntPtr hWnd, UInt32 Msg, UIntPtr wParam, string lParam, UInt32 fuFlags, UInt32 uTimeout, out UIntPtr lpdwResult);
}
"@
    Add-Type -MemberDefinition $signature -PassThru | Out-Null
    $HWND_BROADCAST = [IntPtr]0xffff
    $WM_SETTINGCHANGE = 0x1A
    $null = [UIntPtr]::Zero
    [UIntPtr]$result = [UIntPtr]::Zero
    [NativeMethods]::SendMessageTimeout($HWND_BROADCAST, $WM_SETTINGCHANGE, [UIntPtr]::Zero, "Environment", 0x0002, 5000, [ref]$result) | Out-Null

    Write-Output "Готово. Откройте новую консоль, чтобы изменения вступили в силу."
    exit 0
} catch {
    Write-Error "Не удалось записать системный PATH: $_"
    exit 1
}
