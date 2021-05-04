function solution(new_id) {
    var answer = '';
    // 1번 조건
    new_id = new_id.toLowerCase();
    
    // 2번 조건
    let str2 = '';
    for(let i = 0 ; i<new_id.length ; i++){
        const ascii = new_id.charCodeAt(i);
        if((ascii >= 97 && ascii <= 122) || (ascii >= 48 && ascii <= 57) || ascii === 45 || ascii === 46 || ascii === 95) str2 += new_id[i];
    }
    // 3번 조건
    let str3 = '';
    let count = 0, flag = 0;
    let start = [], end = [];
    for(let i = 0 ; i<str2.length ; i++){
        if(str2[i] === '.'){
            count++;
            if (count>=2) flag = 1;
        }
        else {
            if(count >= 2){
                start.push(i - count);
                end.push(i - 1);
            }
            count = 0;
            flag = 0;
        }
    }
    if(flag){
        start.push(str2.length - count);
        end.push(str2.length - 1);
    }
    let pointIdx = 0;
    for(let i = 0 ; i<str2.length ; i++){
        if(i > end[pointIdx]){
            if(pointIdx < start.length - 1) pointIdx++;
        }
        if(i === start[pointIdx]){
            str3 += '.';
        }
        if(i >= start[pointIdx] && i <= end[pointIdx]) continue;
        str3 += str2[i];
        
    }
    // 4번 조건
    let str4 = str3;
    if(str4[0] === '.') str4 = str4.slice(1);
    if(str4.endsWith('.')) str4 = str4.slice(0, str4.length - 1);
    
    // 5번 조건
    let str5 = str4;
    if(str5 === '') str5 += 'a';
    
    // 6번 조건
    let str6 = str5;
    if(str6.length >= 16) str6 = str6.slice(0, 15);
    if(str6.endsWith('.')) str6 = str6.slice(0, str6.length - 1);
    
    // 7번 조건
    let str7 = str6;
    if(str7.length <= 2){
        const t = str7[str7.length - 1];
        str7 = str7.padEnd(3, t);
    }
    
    answer = str7;
    return answer;
}
