package admin

import (
	"fmt"

	"github.com/gin-gonic/gin"
)

type IndexController struct {
}

func (con IndexController) Index(c *gin.Context) {
	//与中间件的数据共享
	username, _ := c.Get("username")
	fmt.Println("username=", username)

	//类型断言
	v, ok := username.(string)
	if ok {
		c.String(200, "前台首页--"+v)
	} else {
		c.String(200, "前台首页--")
	}

}
