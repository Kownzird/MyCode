package foreground

import (
	"net/http"

	"github.com/gin-contrib/sessions"
	"github.com/gin-gonic/gin"
)

type DefaultController struct {
}

func (con DefaultController) Index(c *gin.Context) {
	//设置Session
	session := sessions.Default(c)

	//配置session过期时间
	session.Options(sessions.Options{
		MaxAge: 3600 * 6, //6h
	})
	session.Set("username", "张三111")
	session.Save() //必须调用

	c.HTML(http.StatusOK, "default/index.html", gin.H{
		"msg": "我是一个msg",
		"t":   1651332958,
	})
}

func (con DefaultController) News(c *gin.Context) {
	//获取session
	session := sessions.Default(c)
	username := session.Get("username")
	c.String(http.StatusOK, "username=%v", username)
}
