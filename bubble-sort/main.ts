function sort(list: Array<number>) {
    for (let i = 0; i < list.length; i++) {
        for (let j = i + 1; j < list.length; j++) {
            if (list[i] > list[j]) {
                let temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}

const example1 = [2, 22, 0, -222, 0];
sort(example1);
console.log(example1);
