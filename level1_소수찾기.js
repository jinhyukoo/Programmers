function solution(n) {
    var answer = 0;
    let arr = new Array(1000001).fill(0);
    for(let i = 2 ; i<=1000 ; i++){
        for(let j = i + i ; j<=1000000 ; j+=i){
            arr[j] = 1;
        }
    }
    for(let i = 2 ; i<=n ; i++){
        if(arr[i] === 0) answer++;
    }
    return answer;
}