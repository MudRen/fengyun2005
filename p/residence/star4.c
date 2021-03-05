inherit __DIR__"ann_residence.c";

void create ()
{
  set("floor",4);

  set ("short", "摘星楼"+CHINESE_D->chinese_number(query("floor"))+"层");
  set ("long", @LONG
    
    花似伊   柳似伊   叶叶声声是别离   雨急人更急

    湘江西   楚江西   万水千山远路迷   相逢终有期

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
