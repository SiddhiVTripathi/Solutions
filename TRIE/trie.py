class TrieNode:
    def __init__(self):
        self.isEnd = False
        self.child = [None]*26

class Trie:
    def __init__(self):
        self.root = TrieNode()

    def insert(self,key):
        copy = self.root
        
        for i in key:
            index = ord(i)-ord('a')
            if copy.child[index]==None:
                copy.child[index]= TrieNode()
            copy = copy.child[index]

        copy.isEnd = True
    
    def search(self,key):
        copy = self.root

        for i in key:
            ind = ord(i)-ord('a')
            if copy.child[ind]==None:
                return False
            copy = copy.child[ind]
        
        return copy.isEnd

    def delete(self,root:TrieNode,key,i:int= 0)->TrieNode:
        if root==None:
            print(f"{key} not found")
            return root

        if i == len(key):
            if root.isEnd:
                print(f"{key} found, deletion begins")
            else:
                print("Key not found")
            root.isEnd = False
            if isEmpty(root):
                root = None
            return root

        index = ord(key[i])-ord('a')
        root.child[index] = self.delete(root.child[index], key, i+1)

        if isEmpty(root) and root.isEnd==False:
            root = None
        return root

def isEmpty(node:TrieNode)->bool:
    for i in node.child:
        if i!=None:
            return False
    return True