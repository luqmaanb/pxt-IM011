IM01.overwriteFile("log.txt", "overwriting file")
IM01.overwriteFile("buttonA.txt", "Creating file for button A")

input.onButtonPressed(Button.A, function () {
    IM01.appendFileLine("buttonA.txt", "Button A has been pressed")
})