package admin

import (
	"net/http"
	"path"

	"github.com/gin-gonic/gin"
)

type UserController struct {
	//继承控制器
	BaseController
}

func (con UserController) Index(c *gin.Context) {
	// c.String(200, "用户列表--")
	con.Success(c)
}

func (con UserController) Add(c *gin.Context) {
	c.HTML(200, "admin/useradd.html", gin.H{})
}

func (con UserController) Edit(c *gin.Context) {
	c.HTML(200, "admin/useredit.html", gin.H{})
}

func (conn UserController) Edit2(c *gin.Context) {
	c.HTML(200, "admin/useredit2.html", gin.H{})
}

func (con UserController) DoUpload(c *gin.Context) {
	username := c.PostForm("username")

	file, err := c.FormFile("face")

	//file.Filename获取文件名称
	dst := path.Join("./static/upload", file.Filename)
	if err == nil {
		c.SaveUploadedFile(file, dst)
	}
	// c.String(200, "执行上传")
	c.JSON(http.StatusOK, gin.H{
		"success":  true,
		"username": username,
		"dst":      dst,
	})
}

func (conn UserController) DoEdit(c *gin.Context) {
	username := c.PostForm("username")

	face1, err1 := c.FormFile("face1")
	dst1 := path.Join("./static/upload", face1.Filename)
	if err1 == nil {
		c.SaveUploadedFile(face1, dst1)
	}

	face2, err2 := c.FormFile("face2")
	dst2 := path.Join("./static/upload", face2.Filename)
	if err2 == nil {
		c.SaveUploadedFile(face2, dst2)
	}

	c.JSON(http.StatusOK, gin.H{
		"success":  true,
		"username": username,
		"dst1":     dst1,
		"dst2":     dst2,
	})
}

func (conn UserController) DoEdit2(c *gin.Context) {
	username := c.PostForm("username")

	form, _ := c.MultipartForm()
	files := form.File["face[]"]

	for _, file := range files {
		dst := path.Join("./static/upload", file.Filename)
		c.SaveUploadedFile(file, dst)
	}

	c.JSON(http.StatusOK, gin.H{
		"success":  true,
		"username": username,
	})
}
