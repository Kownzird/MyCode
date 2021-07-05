
#传入一个数组，转化为集合
states_needed = set(["mt","wa","or","id","nv","ut","ca","az","ny"])

stations = {}
stations["kone"] = set(["id","mv","ut"])
stations["ktwo"] = set(["wa","id","mt"])
stations["kthree"] = set(["or","nv","ca","ny"])
stations["kfour"] = set(["nv","ut"])
stations["kfive"] = set(["ca","az"])

final_stations = set()

while states_needed:
        best_station = None
        states_covered = set()
        for station,states in stations.items():
                covered = states_needed & states
                if len(covered) > len(states_covered):
                        best_station = station
                        states_covered = covered
        states_needed -= states_covered
        final_stations.add(best_station)
