#! /bin/bash
# check http server start|stop|starus
# by author rivers on 2021-9-27
while true
do
    echo -e "
    \033[31m start \033[0m
    \033[32m stop \033[0m 
    \033[33m restart \033[0m
    \033[34m status \033[0m 
    \033[35m quit \033[0m 
"
    read -p "请输入你的选择 start|stop|restart|status|quit:" char
    case $char in
        start)
            systemctl start httpd && echo "httpd 服务已经开启" || echo "开启失败"
            ;;
        stop)
            systemctl stop httpd && echo "httpd 服务已经关闭" || echo "关闭失败"
            ;;
        restart)
            systemctl restart httpd && echo "httpd 服务已经重启" || echo "重启失败"
            ;;
        status)
            systemctl status httpd && echo -e "\n httpd 的服务状态 \n"
            ;;
        quit)
            break;
            ;;
        *)
            echo "无效的命令，请重新输入！"
            ;;
    esac
done
