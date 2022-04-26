package admin

import "github.com/gin-gonic/gin"

type UserController struct {
	//继承控制器
	BaseController
}

func (con UserController) Index(c *gin.Context) {
	// c.String(200, "用户列表--")
	con.Success(c)
}

func (con UserController) Add(c *gin.Context) {
	c.String(200, "用户列表--add--")
}

func (con UserController) Edit(c *gin.Context) {
	c.String(200, "用户列表--edit--")
}
