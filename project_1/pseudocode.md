'''code 
 
CONCENTRATION = 0.006
ENERGY_DRINK_CAN_WEIGHT = 350
weightDrinker
weightMouse
lethalDoseDrinker
lethalDoseMouse
gramsCaffeinePerCan
cansNumSafe
cansNumLethal

promptAndInput(weightMouse)
promptAndInput(weightDrinker)
promptAndInput(lethalDoseMouse)

gramsCaffeinePerCan = ENERGY_DRINK_CAN_WEIGHT * CONCENTRATION

lethalDoseDrinker = lethalDoseMouse * weightDrinker / weightMouse
cansNumLethal = lethalDoseDrinker / gramsCaffeinePerCan

cansNumSafe = cansNumLethal - 1

displayHeading
formatDisplay(weightMouse)
formatDisplay(lethalDoseMouse)
formatDisplay(weightDrinker)
formatDisplay(lethalDoseDrinker)
formatDisplay(cansNumLethal)
formatDisplay(cansNumSafe)

'''