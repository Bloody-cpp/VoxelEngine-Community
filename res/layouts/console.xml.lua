function submit(text)
    local x,y,z = player.get_pos(0)
    console.set('pos.x', x)
    console.set('pos.y', y)
    console.set('pos.z', z)
    local status, result = pcall(function() return console.execute(text) end)
    if result ~= nil then
        document.log.text = document.log.text..tostring(result)..'\n'
    end
    document.prompt.text = ""
end

function on_open()
    document.prompt.focused = true
end
