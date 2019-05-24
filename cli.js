#!/usr/bin/env node

// 读取文件，解析出文章数据 提交到服务器
var Fs = require('fs-extra');
var request = require('superagent');
var Path = require('path')
var argv = process.argv
// console.log(argv)
if(argv.length < 2){
    console.log('参数错误')
}else {
    var p = argv[2]
    var filePath = Path.resolve(__dirname,p)
    // console.log(filePath)
    Fs.readFile(filePath).then(data=>{
        // console.log(data.toString())
        var str = data.toString();
        var seg = str.split(/\n={5,}\n/);
        if(seg.length>=2){
            var metaStr = seg[0]
            var content = seg.slice(1).join("=====").trim()
            var metaObj = {}
            metaStr.split(/\n+/).map(s=>{
                if(s.match(':')){
                    var mp = s.split(':')
                    metaObj[mp[0]] = mp.slice(1).join(':').trim()
                }
            });
            if(metaObj.title && metaObj.keywords){
                console.log(`文章: ${metaObj.title}, 所属分支${metaObj.keywords}`)
                request
                .post('http://maiev.org/wikiapi/addkarticle')
                .send({
                    title:metaObj.title,
                    keywords:metaObj.keywords,
                    content:content,
                    type:'local'
                })
                .end((err,res)=>{
                    if(err){
                        console.log(err)
                    }else{
                        // console.log(res.text)
                        var data = {};
                        try {
                            data = JSON.parse(res.text)
                        } catch (e) {
                            console.log(res.text)
                        }

                        if(data.code == 0){
                            console.log('提交成功')
                        }else{
                            console.log(data.msg || '')
                        }

                    }
                })
            }
        }
    })
    .catch(err=>{
        console.log(err)
    })
}
