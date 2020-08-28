function sort(list) {
    for (var i = 0; i < list.length; i++) {
        for (var j = i + 1; j < list.length; j++) {
            if (list[i] > list[j]) {
                var temp = list[i];
                list[i] = list[j];
                list[j] = temp;
            }
        }
    }
}
var example1 = [2, 22, 0, -222, 0];
sort(example1);
console.log(example1);
