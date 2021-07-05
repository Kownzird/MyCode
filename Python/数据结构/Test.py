def main():


        
        telephone_num = dict()
        name = []
        
        print("------------")
        print("-- 1.Find --")
        print("-- 2.Add ---")
        print("-- 3.Del ---")
        print("-- 0.Exit --")
        print("------------")

        while True:
                select = int(input("Select your choice :"))
                
                if select == 1:
                        for i in range(len(name)):
                                print(name[i]," : ",telephone_num[name[i]])
                elif select == 2:
                        name_input = input("Please input name :")
                        tele_num_input = input("Please input telephone num :")
                        telephone_num[name_input]=tele_num_input
                        name.append(name_input)
                elif select == 3:
                        del_name = input("Please input the name :")
                        telephone_num.pop(del_name)
                        name.pop(name.index(del_name))
                elif select == 0:
                        print("Exiting...")
                        break
                else:
                        print("Please input the correct num")
                        





if __name__ == "__main__":
        main()
