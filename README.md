# algorithm
백준 문제 풀이 저장 + 개념 정리







# CHAPTER 1 
## Union Find
그래프 알고리즘
여러노드가 존재할 때 어떤 두개의 노드를 같은 집합으로 묶어주고, 다시 어떤 두 노드가 같은 집합에 있는지 확인하는 알고리즘이다.

1) Find

노드 x 가 어떤 집합에 포함되어 있느니 찾는 연산

2) Union

노드 x가 포함된 집합과 노드 y가 포함된 집합을 합치는 연산

## 구현

parent[i] i 노드의 부모 노드

parent[i] = i 인 경우, 루트 노드를 의미

```cpp
int parent[MAX_SIZE];
for(int i=0;i<MAX_SIZE;i++){
	parent[i] =i;
}
```

```cpp
int find(int x){
	if(x==parent[x]) return x;
	else {
	int y= find(parent[x]);
	parent[x] =y;
	return y;
}
}
```

```cpp
int rank[MAX_SIZE];
for(int i=0;i<MAX_SIZE;i++) rank[i]=1;

void union(int x, int y){
	x= find(x);
	y = find(y);
	if(x==y) return;
	if(rank[x] > rank[y]){
	parent[y] = x;
	rank[x] += rank[y];
	// 높이가 더 높은 트리가 높이가 낮은 트리 밑으로 들어가면 트리가 깊어진다.
	// 때문에 트리의 높이가 낮은 트리가 높이가 높은 트리 밑으로 들어가도록 한다.
}
else{
	parent[x] =y;
	rank[y]+=rank[x];
}

}
}

// y의 집합을 x의 집합에 합치는 과정.
// y의 parent가 x가 되는 것
//x와 y의 루트를 찾고 루트가 다른 경우 y의 부모노드를 x로 바꿔준다.

```

## Weighted Union Find

parent배열과 size배열이 존재 → 메모리를 두 배로 사용

```cpp
int parent[MAX_SIZE];
for(int i=0;i<MAX_SIZE;i++){
	parent[i] =-1;
}

int find(int x){
	if(parent[x] < 0) {
	return x;
}
else{
	int y = find(parent[x]);
	parent[x]= y;
	return y;

}

}

void union(int x, int y){
	x= find(x);
	y= find(y);
	if(x==y) return;
	if(parent[x] < parent[y]){
	parent[x]+=parent[y];
	parent[y]= x;
//y의 부모가 x가 됨
}
else{
	parent[y]+=parent[x];
	parent[x] =y;
}

}
```

## 예제 문제

BOJ 1717
