// 7164 KB, 116 ms
const fs = require('fs');
const input = fs.readFileSync('/dev/stdin').toString().trim().split('\n');
// const input = ['7', '6', '1 2', '2 3', '1 5', '5 2', '5 6', '4 7'];

const nodes = Number(input[0]);
const edges = Number(input[1]);

const graph_format = new Array(nodes + 1).fill('');
const graph = graph_format.map(() => []);

const connections = input.splice(2);

connections.map((connection) => {
  const [from, to] = connection.split(' ');

  graph[from].push(Number(to));
  graph[to].push(Number(from));
});

console.log(graph);

let infected_count = 0;

const check_list = new Array(nodes).fill(false);

function dfs(index) {
  if (check_list[index]) return;

  check_list[index] = true;

  graph[index].map((next) => {
    dfs(next);
  });
  infected_count++;
}

dfs(1);

console.log(infected_count - 1);
