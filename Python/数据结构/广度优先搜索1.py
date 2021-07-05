from collections import deque


def person_is_seller(name):
        return name[-1] == 'm'


#人物关系图
graph = {}
graph["you"] = ["alice","bob","claire"]
graph["bob"] = ["anuj","peggy"]
graph["alice"] = ["peggy"]
graph["claire"] = ["thom","jonny"]
graph["anuj"] = []
graph["peggy"] = []
graph["thom"] = []
graph["jonny"] = []



#创建一个双端队列
search_queue = deque() 

#将你的邻居都加入到这个搜索队列中
search_queue += graph["you"]

while search_queue: #队列不为空
        person = search_queue.popleft() #取出其中第一人
        if person_is_seller(person):
                print(person," is a mango seller!")
        else:
                search_queue += graph[person] #将该人的朋友加入搜索队列

