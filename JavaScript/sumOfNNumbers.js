const sum = (n) => {
    if(n <= 1){
        return n
    }
    return n + sum(n-1)
}

const answer = sum(5)
console.log(answer)