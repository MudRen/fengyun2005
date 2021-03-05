inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",8);

  set ("short", "新月楼"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG
  
    纷纷雪落人飘坠

    同死生 共玉碎 

    前尘后世为君问 柔肠百结如醉 

    情丝未断 尘缘难了 萦绕千千岁
    
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