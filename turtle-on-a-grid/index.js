"use strict";

function findPath(grid) {
    console.assert(grid && grid[0], 'Grid is valid');
    const R = grid.length;
    const C = grid[0].length;
    for (let i = 0; i < R; i++) {
        for (let j = 0; j < C; j++) {
            if (grid[i][j] == 1) {
                grid[i][j] = -1;
            }
        }
    }
    for (let i = 0; i < R; i++) {
        for (let j = 0; j < C; j++) {
            if (grid[i][j] === -1) {
                continue;
            }
            let top  = i > 0 && grid[i - 1][j] !== -1 ? grid[i - 1][j] : null;
            let left = j > 0 && grid[i][j - 1] !== -1 ? grid[i][j - 1] : null;
            // TODO: avoid walls
            if (top != null && left != null) {
                grid[i][j] = Math.max(top, left) + 1;
            }
            else if(top != null) {
                grid[i][j] = top + 1;
            }
            else if(left != null) {
                grid[i][j] = left + 1;
            }
        }
    }
    return grid;
}

const input = [
    [0, 1, 0, 1, 0],
    [0, 0, 0, 0, 0],
    [0, 1, 0, 1, 0],
    [0, 0, 0, 1, 0],
];

console.log(findPath(input));

/*

Additional notes:
1. there is always a solution
2. there is never a wall in the top left corner, or in the bottom right corner
3. if there are multiple solutions, any solution is fine

0000
1101
0000
1110

0123
XX3X
0145
XXX6

*/
