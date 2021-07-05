
#图的散列表
graph = {}
graph["start"] = {}
graph["start"]["a"] = 6
graph["start"]["b"] = 2

graph["a"] = {}
graph["a"]["fin"] = 1

graph["b"] = {}
graph["b"]["a"] = 3
graph["b"]["fin"] = 5

graph["fin"] = {}



#创建开销表
infinity = float("inf") #无穷大
costs = {}
costs["a"] = 6
costs["b"] = 2
costs["fin"] = infinity


#存储父节点的散列表
parents = {}
parents["a"] = "start"
parents["b"] = "start"
parents["fin"] = "None"

processed = []

def find_lowest_cost_node(costs):
        lowest_cost = float("inf")
        lowest_cost_node = None
        for node in costs:
                cost = costs[node]
                if cost < lowest_cost and node not in processed:
                        lowest_cost = cost
                        lowest_cost_node = node
        return lowest_cost_node


def main():
        #在未处理的节点中找出最小的节点
        node = find_lowest_cost_node(costs)
                
        while node is not None:
                cost = costs[node]
                neighbors = graph[node]

                #遍历当前节点所有邻居
                for n in neighbors.keys():
                        new_cost = cost + neighbors[n]

                        #如果经当前节点前往该邻居更近，更新该邻居的开销
                        if costs[n] > new_cost:
                                costs[n] = new_cost
                                parents[n] = node #将该邻居的父节点设置为当前节点
                processed.append(node)
                node = find_lowest_cost_node(costs) #找出接下来要处理的节点，并循环

        print(parents)


if __name__=="__main__":
        main()



                
