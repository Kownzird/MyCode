package foreground

import (
	"fmt"
	"gindemo09/models"
	"net/http"

	"github.com/gin-gonic/gin"
)

type DefaultController struct {
}

func (con DefaultController) Index(c *gin.Context) {
	fmt.Println(models.UnixToTime(1651333141))
	c.HTML(http.StatusOK, "default/index.html", gin.H{
		"msg": "我是一个msg",
		"t":   1651332958,
	})
}

func (con DefaultController) News(c *gin.Context) {
	c.String(http.StatusOK, "News")
}
