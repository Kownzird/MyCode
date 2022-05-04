package foreground

import (
	"net/http"

	"github.com/gin-gonic/gin"
)

type DefaultController struct {
}

func (con DefaultController) Index(c *gin.Context) {
	c.HTML(http.StatusOK, "default/index.html", gin.H{
		"msg": "我是一个msg",
	})
}

func (con DefaultController) News(c *gin.Context) {
	c.String(http.StatusOK, "News")
}
