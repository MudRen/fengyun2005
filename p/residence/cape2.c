inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",2);

  set ("short", "天涯海角楼"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG
    
    一棹春风一叶舟，一纶茧缕一轻钩。

    花满渚，酒满瓯，万顷波中得自由。

LONG);
        set("exits", ([

  "down" : __DIR__"cape"+(query("floor")-1),
  "up" : __DIR__"cape"+(query("floor")+1), 
]));
        set("coor/x",-25);
        set("coor/y",-45);
        set("coor/z",query("floor")*40);
        setup();
}

/*
*/
