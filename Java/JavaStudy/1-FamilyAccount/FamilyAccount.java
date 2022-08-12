public class FamilyAccount{
    public static void main(String[] args) {

        //标志程序运行状态标志位
        boolean isFlag = true;

        //初始化余额
        long balance = 0;

        //收支明细信息
        String details = "";


        while(isFlag){
            System.out.println("----------------家庭记账工具----------------");
            System.out.println("----------------1  收支明细-----------------");
            System.out.println("----------------2  登记收入-----------------");
            System.out.println("----------------3  登记支出-----------------");
            System.out.println("----------------4  退    出-----------------");
            System.out.print("----------------请选择(1-4):");

            char selection = Utility.readMenuSelection();

            switch(selection){
                case '1':
                    System.out.println("--------------------------------------------");
                    System.out.println("------------ 当前收支明细记录 ---------------");
                    System.out.println("收支" + "\t" + "账户金额" + "\t" + "收支金额" + "\t" + "说明");
                    System.out.println(details);;
                    System.out.println();
                    break;
                case '2':
                    System.out.print("本次收入金额:");
                    int addNumber = Utility.readNumber();
                    System.out.print("本次收入说明:");
                    String addInfo = Utility.readString();
                    balance += addNumber;
                    details += "收入\t" + balance + "\t\t" + addNumber + "\t\t" + addInfo + "\n";
                    break;
                case '3':
                    System.out.print("本次支出金额:");
                    int minusNumber = Utility.readNumber();
                    System.out.print("本次支出说明:");
                    String minusInfo = Utility.readString();
                    balance -= minusNumber;
                    details += "支出\t" + balance + "\t\t" + minusNumber + "\t\t" + minusInfo + "\n";
                    break;
                case '4':
                    System.out.print("确认是否退出(Y/N)?");
                    char isExit = Utility.readConfirmSelection();
                    if(isExit == 'Y'){
                        isFlag = false;
                    }
                    break;
            }
        }
    }
}