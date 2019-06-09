# Graphs

## Definition

Graph is an abstract data type that is meant to implement the undirected graph and directed graph concepts from mathematics; specifically, the field of graph theory.

### BFS (너비 우선 탐색)

너비 우선 탐색(Breadth-first search, BFS)은 맹목적 탐색방법의 하나로 시작 정점을 방문한 후 시작 정점에 인접한 모든 정점들을 우선 방문하는 방법이다. 더 이상 방문하지 않은 정점이 없을 때까지 방문하지 않은 모든 정점들에 대해서도 너비 우선 검색을 적용한다. OPEN List 는 큐를 사용해야만 레벨 순서대로 접근이 가능하다.

![BFS graph](https://www.google.com/url?sa=i&source=images&cd=&ved=2ahUKEwj98ruJudziAhUKE7wKHR8gD2gQjRx6BAgBEAU&url=https%3A%2F%2Fgmlwjd9405.github.io%2F2018%2F08%2F15%2Falgorithm-bfs.html&psig=AOvVaw2OqLLdXB0K8oJ6c_0q0_4b&ust=1560171280012297)

### DFS (깊이 우선 탐색)

깊이 우선 탐색(depth-first search: DFS)은 맹목적 탐색방법의 하나로 탐색트리의 최근에 첨가된 노드를 선택하고, 이 노드에 적용 가능한 동작자 중 하나를 적용하여 트리에 다음 수준(level)의 한 개의 자식노드를 첨가하며, 첨가된 자식 노드가 목표노드일 때까지 앞의 자식 노드의 첨가 과정을 반복해 가는 방식이다.

![DFS graph](https://www.google.com/url?sa=i&source=images&cd=&ved=2ahUKEwjHsoT7uNziAhUQ57wKHTW-BUEQjRx6BAgBEAU&url=https%3A%2F%2Fgmlwjd9405.github.io%2F2018%2F08%2F14%2Falgorithm-dfs.html&psig=AOvVaw1QusLoXc2jUmoc_-5m_Iyz&ust=1560171245111570)