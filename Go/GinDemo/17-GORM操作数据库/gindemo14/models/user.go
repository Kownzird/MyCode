package models

type User struct { //默认表名是users
	Id       int
	Username string
	Age      int
	Email    string
	AddTime  int
}

//User结构体默认操作users表，若要指定操作表明则需要如下操作
//表示配置操作数据库的表名称
func (User) TableName() string {
	return "user"
}
