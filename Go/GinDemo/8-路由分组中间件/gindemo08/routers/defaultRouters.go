package routers

import (
	"gindemo08/controllers/foreground"

	"github.com/gin-gonic/gin"
)

func DefaultRoutersInit(r *gin.Engine) {
	defaultRouters := r.Group("/")
	{
		defaultRouters.GET("/", foreground.DefaultController{}.Index)
		defaultRouters.GET("/news", foreground.DefaultController{}.News)
	}
}
