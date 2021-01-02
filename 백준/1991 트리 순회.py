import sys
N = int(sys.stdin.readline())
tree ={}
for _ in range(N):
	root, left, right = sys.stdin.readline().split()
	tree[root] = (left, right)

def pre(node):
	if node == '.':
		return
	print(node, end = "")
	pre(tree[node][0])
	pre(tree[node][1])
def ino(node):
	if node == '.':
		return
	ino(tree[node][0])
	print(node, end = "")
	ino(tree[node][1])
def post(node):
	if node == '.':
		return
	post(tree[node][0])
	post(tree[node][1])
	print(node, end = "")

pre('A')
print()
ino('A')
print()
post('A')