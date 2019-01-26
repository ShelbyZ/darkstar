-----------------------------------
--
-- dsp.effect.BARPETRIFY
--
-----------------------------------
require("scripts/globals/status")
-----------------------------------

function onEffectGain(target,effect)
    target:addMod(dsp.mod.PETRIFYRES,effect:getPower())
end

function onEffectTick(target,effect)
end

function onEffectLose(target,effect)
    target:delMod(dsp.mod.PETRIFYRES,effect:getPower())
end