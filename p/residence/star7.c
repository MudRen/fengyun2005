inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",7);

  set ("short", "摘星楼"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG
  
    伤心脉脉难诉   风剪寸寸柔肠   
    
    神仙人鬼两茫茫   情短恨长

LONG);
        set("exits", ([

  "down" : __DIR__"star"+(query("floor")-1),
  "up" : __DIR__"star"+(query("floor")+1), 
]));
        set("coor/x",-25);
        set("coor/y",-35);
        set("coor/z",query("floor")*40);
        setup();
}

/*
*/
