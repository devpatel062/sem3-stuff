function checkEvenOdd(f,arr)
        {
             let decision = [];
             for(let i=0;i<arr.length;i++)
             {
                  (f(arr[i])==0)?(decision[i]="even"):(decision[i]="odd");
             }
             return decision;
        }
        
        function reminder(a)
        {
            return a%2;
        }

        let numbers = [25,42,75,87,92,97];
        console.log(checkEvenOdd(reminder,numbers));