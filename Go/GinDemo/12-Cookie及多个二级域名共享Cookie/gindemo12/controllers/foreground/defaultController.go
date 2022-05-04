package foreground

import (
	"net/http"

	"github.com/gin-gonic/gin"
)

type DefaultController struct {
}

func (con DefaultController) Index(c *gin.Context) {
	//设置Cookie
	c.SetCookie("username", "张三", 3600, "/", ".kownzird.com", false, true)
	c.SetCookie("hobby", "吃饭 睡觉", 5, "/", "localhost", false, true)
	c.HTML(http.StatusOK, "default/index.html", gin.H{
		"msg": "我是一个msg",
		"t":   1651332958,
	})
}

func (con DefaultController) News(c *gin.Context) {
	//获取Cookie
	username, _ := c.Cookie("username")
	hobby, _ := c.Cookie("hobby")
	c.String(http.StatusOK, "username=%v----hobby=%v", username, hobby)
}

func (conn DefaultController) Shop(c *gin.Context) {
	//获取Cookie
	username, _ := c.Cookie("username")
	c.String(http.StatusOK, "Cookie="+username)
}

func (conn DefaultController) Delete(c *gin.Context) {
	//删除Cookie
	c.SetCookie("username", "张三", -1, "/", ".kownzird", false, true)
	c.String(http.StatusOK, "删除成功")
}
