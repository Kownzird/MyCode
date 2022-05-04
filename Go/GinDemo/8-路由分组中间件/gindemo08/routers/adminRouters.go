package routers

import (
	"gindemo08/controllers/admin"
	"gindemo08/middlewares"

	"github.com/gin-gonic/gin"
)

func AdminRoutersInit(r *gin.Engine) {
	adminRouters := r.Group("/admin", middlewares.InitMiddlewares) //添加
	// adminRouters.Use(middlewares.InitMiddlewares)
	{
		// 调用控制器，需要先实例化
		adminRouters.GET("/", admin.IndexController{}.Index)
		adminRouters.GET("/user", admin.UserController{}.Index)
		adminRouters.GET("/user/add", admin.UserController{}.Add)
		adminRouters.GET("/user/edit", admin.UserController{}.Edit)

		adminRouters.GET("/article", admin.ArticleController{}.Index)
		adminRouters.GET("/article/add", admin.ArticleController{}.Add)
		adminRouters.GET("/article/edit", admin.ArticleController{}.Edit)
	}

}
