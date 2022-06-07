var num = prompt();
        var fact = 1

        function myf(){
            fact = fact*num;
            num = num-1
        }
        while(num != 1)
        {
            myf()
        }
        console.log(fact)