public class FamilyAccount{
    public static void main(String[] args) {

        //��־��������״̬��־λ
        boolean isFlag = true;

        //��ʼ�����
        long balance = 0;

        //��֧��ϸ��Ϣ
        String details = "";


        while(isFlag){
            System.out.println("----------------��ͥ���˹���----------------");
            System.out.println("----------------1  ��֧��ϸ-----------------");
            System.out.println("----------------2  �Ǽ�����-----------------");
            System.out.println("----------------3  �Ǽ�֧��-----------------");
            System.out.println("----------------4  ��    ��-----------------");
            System.out.print("----------------��ѡ��(1-4):");

            char selection = Utility.readMenuSelection();

            switch(selection){
                case '1':
                    System.out.println("--------------------------------------------");
                    System.out.println("------------ ��ǰ��֧��ϸ��¼ ---------------");
                    System.out.println("��֧" + "\t" + "�˻����" + "\t" + "��֧���" + "\t" + "˵��");
                    System.out.println(details);;
                    System.out.println();
                    break;
                case '2':
                    System.out.print("����������:");
                    int addNumber = Utility.readNumber();
                    System.out.print("��������˵��:");
                    String addInfo = Utility.readString();
                    balance += addNumber;
                    details += "����\t" + balance + "\t\t" + addNumber + "\t\t" + addInfo + "\n";
                    break;
                case '3':
                    System.out.print("����֧�����:");
                    int minusNumber = Utility.readNumber();
                    System.out.print("����֧��˵��:");
                    String minusInfo = Utility.readString();
                    balance -= minusNumber;
                    details += "֧��\t" + balance + "\t\t" + minusNumber + "\t\t" + minusInfo + "\n";
                    break;
                case '4':
                    System.out.print("ȷ���Ƿ��˳�(Y/N)?");
                    char isExit = Utility.readConfirmSelection();
                    if(isExit == 'Y'){
                        isFlag = false;
                    }
                    break;
            }
        }
    }
}