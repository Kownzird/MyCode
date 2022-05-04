package routers

import (
	"gindemo12/controllers/admin"
	"gindemo12/middlewares"

	"github.com/gin-gonic/gin"
)

func AdminRoutersInit(r *gin.Engine) {
	adminRouters := r.Group("/admin", middlewares.InitMiddlewares) //添加
	// adminRouters.Use(middlewares.InitMiddlewares)
	{
		// 调用控制器，需要先实例化
		adminRouters.GET("/", admin.IndexController{}.Index)
		adminRouters.GET("/user", admin.UserController{}.Index)

		//按日期存储图片
		adminRouters.GET("/user/add", admin.UserController{}.Add)
		adminRouters.POST("/user/doUpload", admin.UserController{}.DoUpload)

		adminRouters.GET("/user/edit", admin.UserController{}.Edit)
		adminRouters.POST("/user/doEdit", admin.UserController{}.DoEdit)
		adminRouters.GET("/user/edit2", admin.UserController{}.Edit2)
		adminRouters.POST("/user/doEdit2", admin.UserController{}.DoEdit2)

		adminRouters.GET("/article", admin.ArticleController{}.Index)
		adminRouters.GET("/article/add", admin.ArticleController{}.Add)
		adminRouters.GET("/article/edit", admin.ArticleController{}.Edit)
	}

}
