"use strict";

function removeDuplicates(input) {
    if (!input) {
        return;
    }

    const bag = {};
    let j = 0;
    for (let i = 0; i < input.length; i++) {
        const element = input[i];
        if (bag[element]) {
            // element already added
            console.log(element);
            continue;
        }
        bag[element] = true;
        input[j++] = element;
    }

    console.log(bag);
    return input.splice(0, j);
}

let input = [1, 2, 3, 3, 5, 7, 8, 9, 1, 1, 2, 3, 3, 5, 7, 8, 9, -10, 10];
console.log(removeDuplicates(input));
