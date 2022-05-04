package main

import (
	"gindemo10/models"
	"gindemo10/routers"
	"html/template"

	"github.com/gin-gonic/gin"
)

type Article struct {
	Title   string
	Content string
}

func main() {
	r := gin.Default()

	r.SetFuncMap(template.FuncMap{
		"UnixToTime": models.UnixToTime,
	})

	r.LoadHTMLGlob("templates/**/*")

	r.Static("/static", "./static")

	//路由分组
	routers.DefaultRoutersInit(r)
	routers.ApiRoutersInit(r)
	routers.AdminRoutersInit(r)

	r.Run()
}
