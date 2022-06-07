var num = prompt()
        var n = num
        var count = 0
    while (num != 0) {
    num /= 10;     // n = n/10
    ++count;
    }
    if(count >= 3)
        {
            if(n % 10 == (n/10) % 10)
                {
                    if((n/10) % 10 == (n/100) % 10)
                        console.log("true")
                    else
                        console.log("false1")
                }
            else
            {
                console.log("false2")
            }
        }