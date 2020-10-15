// 7160 KB, 108 ms
const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');

const nodes = Number(input[0]);
const edges = Number(input[1]);

const graph = new Array(nodes + 1).fill('').map(() => []);

const connections = input.splice(2);

connections.map((connection) => {
  const [from, to] = connection.split(' ');

  graph[from].push(Number(to));
  graph[to].push(Number(from));
});

let infected_count = 0;

const check_list = new Array(nodes).fill(false);

function dfs(index) {
  if (check_list[index]) return;

  check_list[index] = true;
  infected_count++;

  graph[index].map((next) => {
    dfs(next);
  });
}

dfs(1);

console.log(infected_count - 1);
