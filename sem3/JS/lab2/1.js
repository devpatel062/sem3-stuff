var number = prompt("enter the number")
        var count=0;
        for( var i =2;i < number ; i++)
        {
            if(number % i == 0)
                count++;
        }
        if(count == 0)
            console.log(number+" is prime")
        else
            console.log(number+" is not prime")