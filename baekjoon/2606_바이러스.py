n = int(input())
network = int(input())

graph = [[]*n for _ in range(n+1)]

for _ in range(network):
    a,b = map(int, input().split())
    graph[a].append(b)
    graph[b].append(a)
    
cnt = 0
visited = [0]*(n+1)

def dfs(start):
    global cnt
    visited[start] = 1
    for i in graph[start]:
        if visited[i] == 0:
            cnt += 1
            dfs(i)
            
dfs(1)
print(cnt)
