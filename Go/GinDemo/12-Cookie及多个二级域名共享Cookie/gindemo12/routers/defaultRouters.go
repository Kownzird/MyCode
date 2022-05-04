package routers

import (
	"gindemo12/controllers/foreground"

	"github.com/gin-gonic/gin"
)

func DefaultRoutersInit(r *gin.Engine) {
	defaultRouters := r.Group("/")
	{
		defaultRouters.GET("/", foreground.DefaultController{}.Index)
		defaultRouters.GET("/news", foreground.DefaultController{}.News)
		defaultRouters.GET("/shop", foreground.DefaultController{}.Shop)
		defaultRouters.GET("/deleteCookie", foreground.DefaultController{}.Delete)
	}
}
