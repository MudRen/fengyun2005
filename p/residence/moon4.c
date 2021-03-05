inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",4);

  set ("short", "新月楼"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG
  
    刻舟行远人归去   笑靥无凭   私语无踪   魂断香销弃旧情

    玄冰刻悔风吟恨   好梦成空   泪眼迷蒙   遥看春花朔雪中
    
LONG);
        set("exits", ([
  "down" : __DIR__"moon"+(query("floor")-1),
  "up" : __DIR__"moon"+(query("floor")+1), 
]));
        set("coor/x",-15);
        set("coor/y",-35);
        set("coor/z",query("floor")*40);
        setup();
}

/*
*/
